// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Hardware/CPU/CPUID.hpp>
#include <cstdint>
#include <utility>
#include <array>
#include <memory>
#include <cstring>
#include <max/Hardware/CPU/TLB.hpp>
#include <max/Hardware/CPU/CacheLevel.hpp>
#include <max/Hardware/CPU/TraceCache.hpp>
#include <max/Hardware/CPU/Prefetch.hpp>
#include <max/Hardware/CPU/CacheInfo.hpp>
#include <max/Hardware/CPU/Associativity.hpp>
#include <max/Compiling/Configuration.hpp>

#if defined( MAX_COMPILER_VC )
	#include <max/Hardware/CPU/CPUIDPolicies/VCIntrinsicCPUIDPolicy.hpp>
	#if defined( MAX_X86_64 )
		#include <max/Hardware/CPU/IsCPUIDAvailablePolicies/X64AssemblyIsCPUIDAvailablePolicy.hpp>
	#elif defined( MAX_X86 )
		#include <max/Hardware/CPU/IsCPUIDAvailablePolicies/X86AssemblyIsCPUIDAvailablePolicy.hpp>
	#else
		static_assert( false, "Unsupported platform" );
	#endif
#elif defined( MAX_COMPILER_GCC ) || defined( MAX_COMPILER_CLANG )
	#if defined( MAX_X86_64 )
		#include <max/Hardware/CPU/IsCPUIDAvailablePolicies/X64GCCAssemblyIsCPUIDAvailablePolicy.hpp>
		#include <max/Hardware/CPU/CPUIDPolicies/X64GCCAssemblyCPUIDPolicy.hpp>
	#elif defined( MAX_X86 )
		#include <max/Hardware/CPU/IsCPUIDAvailablePolicies/X86GCCAssemblyIsCPUIDAvailablePolicy.hpp>
		#include <max/Hardware/CPU/CPUIDPolicies/X86GCCAssemblyCPUIDPolicy.hpp>
	#elif defined( MAX_AARCH64 ) || defined( MAX_ARM ) || defined( MAX_THUMB )
		#include <max/Hardware/CPU/IsCPUIDAvailablePolicies/ArmIsCPUIDAvailablePolicy.hpp>
		#include <max/Hardware/CPU/CPUIDPolicies/AArch64CPUIDPolicy.hpp>
	#else
		static_assert( false, "Unsupported platform" );
	#endif
#else
		static_assert( false, "Unsupported compiler" );
#endif

namespace max
{
namespace CPU
{

	namespace
	{

		max::CPU::CPUIDSubleafArgumentsAndResult FindSubleaf( const std::vector< max::CPU::CPUIDSubleafArgumentsAndResult > & CPUIDResults,
		                                                      const uint32_t LeafNumber,
		                                                      const uint32_t SubleafNumber ) noexcept;

	} // anonymous namespace

	std::string CPUID::Vendor() const noexcept
	{
		char VendorChars[ 13 ] = {}; // 12 + null terminator

		auto SubleafArgumentsAndResult = FindSubleaf( SubleafResults, 0, 0 );
		memcpy( & VendorChars[ 0 ], & SubleafArgumentsAndResult.Result.EBX, sizeof( uint32_t ) );
		memcpy( & VendorChars[ 4 ], & SubleafArgumentsAndResult.Result.EDX, sizeof( uint32_t ) );
		memcpy( & VendorChars[ 8 ], & SubleafArgumentsAndResult.Result.ECX, sizeof( uint32_t ) );
		// Notice that the EDX comes before the ECX
		return std::string( VendorChars );
	}

	uint32_t CPUID::Stepping() const noexcept
	{
		return FindSubleaf( SubleafResults, 1, 0 ).Result.EAX & 0b1111;
	}

	uint32_t CPUID::Model() const noexcept
	{
		// According to page 3-194 of the
		// Intel® 64 and IA-32 Architectures Software Developer’s Manual V2
		// http://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-software-developer-instruction-set-reference-manual-325383.pdf
		// if we have a family value of 0x6 or 0xf, we need to add the model and 4-place-left-shifted extended model values

		uint32_t RawModel = ( FindSubleaf( SubleafResults, 1, 0 ).Result.EAX >> 4 ) & 0b1111;
		uint32_t ActualModel = RawModel;

		uint32_t RawFamily = ( FindSubleaf( SubleafResults, 1, 0 ).Result.EAX >> 8 ) & 0b1111;
		if( RawFamily == 0x6 || RawFamily == 0xf ) {
			uint32_t RawExtendedModel = ( FindSubleaf( SubleafResults, 1, 0 ).Result.EAX >> 16 ) & 0b1111;
			ActualModel = RawModel + ( RawExtendedModel << 4 );
		}

		return ActualModel;
	}

	uint32_t CPUID::Family() const noexcept
	{
		// According to page 3-194 of the
		// Intel® 64 and IA-32 Architectures Software Developer’s Manual V2
		// http://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-software-developer-instruction-set-reference-manual-325383.pdf
		// if we have a family value of 0xf, we need to add the family and extended family values

		uint32_t RawFamily = ( FindSubleaf( SubleafResults, 1, 0 ).Result.EAX >> 8 ) & 0b1111;
		uint32_t ActualFamily = RawFamily;
		
		if( RawFamily == 0xf ) {
			uint32_t RawExtendedFamily = ( FindSubleaf( SubleafResults, 1, 0 ).Result.EAX >> 20 ) & 0b1111'1111;
			ActualFamily = RawFamily + RawExtendedFamily;
		}

		return ActualFamily;
	}

	uint32_t CPUID::ProcessorType() const noexcept
	{
		return ( FindSubleaf( SubleafResults, 1, 0 ).Result.EAX >> 12 ) & 0b11;
	}

	uint32_t CPUID::BrandIndex() const noexcept
	{
		return FindSubleaf( SubleafResults, 1, 0 ).Result.EBX & 0b1111;
	}

	uint32_t CPUID::CLFLUSHLineSizeInBytes() const noexcept
	{
		return ( ( FindSubleaf( SubleafResults, 1, 0 ).Result.EBX >> 8 ) & 0b1111'1111 ) * 8;
	}

	uint32_t CPUID::MaximumAddressableIDs() const noexcept
	{
		if( ! SupportsHTT() )
		{
			return 1;
		}

		return ( FindSubleaf( SubleafResults, 1, 0 ).Result.EBX >> 16 ) & 0b1111'1111;
	}

	uint32_t CPUID::InitialAPICID() const noexcept
	{
		return( FindSubleaf( SubleafResults, 1, 0 ).Result.EBX >> 24 ) & 0b1111'1111;
	}

	namespace
	{

		enum class CPUIDRegisterName
		{
			EAX,
			EBX,
			ECX,
			EDX
		};

		bool IsCPUIDResultBitSet( const std::vector< max::CPU::CPUIDSubleafArgumentsAndResult > & CPUIDResults,
		                          const uint32_t          LeafNumber,
		                          const uint32_t          SubleafNumber,
		                          const CPUIDRegisterName RegisterName,
		                          const uint32_t          BitNumber     ) noexcept;

	}

	bool CPUID::SupportsSSE3() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 0 );
	}

	bool CPUID::SupportsPCLMULQDQ() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 1 );
	}

	bool CPUID::SupportsDTES64() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 2 );
	}

	bool CPUID::SupportsMONITOR() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 3 );
	}

	bool CPUID::SupportsDSCPL() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 4 ); //-V112
	}

	bool CPUID::SupportsVMX() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 5 );
	}

	bool CPUID::SupportsSMX() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 6 );
	}

	bool CPUID::SupportsEST() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 7 );
	}

	bool CPUID::SupportsTM2() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 8 );
	}

	bool CPUID::SupportsSSSE3() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 9 );
	}

	bool CPUID::SupportsCNXTID() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 10 );
	}

	bool CPUID::SupportsSDBG() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 11 );
	}

	bool CPUID::SupportsFMA() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 12 );
	}

	bool CPUID::SupportsCX16() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 13 );
	}

	bool CPUID::SupportsXTPR() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 14 );
	}

	bool CPUID::SupportsPDCM() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 15 );
	}

	bool CPUID::SupportsPCID() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 17 );
	}

	bool CPUID::SupportsDCA() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 18 );
	}

	bool CPUID::SupportsSSE41() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 19 );
	}

	bool CPUID::SupportsSSE42() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 20 );
	}

	bool CPUID::SupportsX2APIC() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 21 );
	}

	bool CPUID::SupportsMOVBE() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 22 );
	}

	bool CPUID::SupportsPOPCNT() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 23 );
	}

	bool CPUID::SupportsTSCDeadline() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 24 );
	}

	bool CPUID::SupportsAES() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 25 );
	}

	bool CPUID::SupportsXSAVE() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 26 );
	}

	bool CPUID::SupportsOSXSAVE() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 27 );
	}

	bool CPUID::SupportsAVX() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 28 );
	}

	bool CPUID::SupportsF16C() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 29 );
	}

	bool CPUID::SupportsRDRAND() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 30 );
	}

	bool CPUID::SupportsHypervisor() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::ECX, 31 );
	}

	bool CPUID::SupportsFPU() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 0 );
	}

	bool CPUID::SupportsVME() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 1 );
	}

	bool CPUID::SupportsDE() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 2 );
	}

	bool CPUID::SupportsPSE() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 3 );
	}

	bool CPUID::SupportsTSC() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 4 ); //-V112
	}

	bool CPUID::SupportsMSR() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 5 );
	}

	bool CPUID::SupportsPAE() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 6 );
	}

	bool CPUID::SupportsMCE() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 7 );
	}

	bool CPUID::SupportsCX8() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 8 );
	}

	bool CPUID::SupportsAPIC() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 9 );
	}

	bool CPUID::SupportsSEP() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 11 );
	}

	bool CPUID::SupportsMTRR() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 12 );
	}

	bool CPUID::SupportsPGE() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 13 );
	}

	bool CPUID::SupportsMCA() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 14 );
	}

	bool CPUID::SupportsCMOV() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 15 );
	}

	bool CPUID::SupportsPAT() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 16 );
	}

	bool CPUID::SupportsPSE36() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 17 );
	}

	bool CPUID::SupportsPSN() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 18 );
	}

	bool CPUID::SupportsCLFSH() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 19 );
	}

	bool CPUID::SupportsDS() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 21 );
	}

	bool CPUID::SupportsACPI() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 22 );
	}

	bool CPUID::SupportsMMX() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 23 );
	}

	bool CPUID::SupportsFXSR() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 24 );
	}

	bool CPUID::SupportsSSE() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 25 );
	}

	bool CPUID::SupportsSSE2() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 26 );
	}

	bool CPUID::SupportsSS() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 27 );
	}

	bool CPUID::SupportsHTT() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 28 );
	}

	bool CPUID::SupportsTM() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 29 );
	}

	bool CPUID::SupportsIA64() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 30 );
	}

	bool CPUID::SupportsPBE() const noexcept
	{
		return IsCPUIDResultBitSet( SubleafResults, 1, 0, CPUIDRegisterName::EDX, 31 );
	}

	namespace
	{

		std::vector< std::unique_ptr< max::CPU::CacheInfo > > GetCacheInfoForRegister( const uint32_t RegisterValue,
		                                                                               const bool     IsRegisterEAX,
		                                                                               const uint32_t Family,
		                                                                               const uint32_t Model ) noexcept;

		uint32_t FindSubleafCount( const std::vector< max::CPU::CPUIDSubleafArgumentsAndResult > & SubleafResults,
		                           const uint32_t Leaf ) noexcept;

	} // anonymous namespace

	std::vector< std::unique_ptr< max::CPU::CacheInfo > > CPUID::CacheDetails() const noexcept
	{
		std::vector< std::unique_ptr< max::CPU::CacheInfo > > Returning = {};

		auto Family = this->Family();
		auto Model  = this->Model();



		// Leaf 2 contains information in EAX/EBX/ECX/EDX indicating some of the cache information.
		auto EAXResult = GetCacheInfoForRegister( FindSubleaf( SubleafResults, 2, 0 ).Result.EAX, true, Family, Model );
		std::move( std::begin( EAXResult ), std::end( EAXResult ), std::back_inserter( Returning ) );

		auto EBXResult = GetCacheInfoForRegister( FindSubleaf( SubleafResults, 2, 0 ).Result.EBX, false, Family, Model );
		std::move( std::begin( EBXResult ), std::end( EBXResult ), std::back_inserter( Returning ) );

		auto ECXResult = GetCacheInfoForRegister( FindSubleaf( SubleafResults, 2, 0 ).Result.ECX, false, Family, Model );
		std::move( std::begin( ECXResult ), std::end( ECXResult ), std::back_inserter( Returning ) );

		auto EDXResult = GetCacheInfoForRegister( FindSubleaf( SubleafResults, 2, 0 ).Result.EDX, false, Family, Model );
		std::move( std::begin( EDXResult ), std::end( EDXResult ), std::back_inserter( Returning ) );



		// Leaf 4 contains subleaves with more cache information.
		auto SubleafCount = FindSubleafCount( SubleafResults, 4 ); //-V112
		for( uint32_t Subleaf = 0; Subleaf <= SubleafCount; Subleaf++ )
		{
			auto LeafFourSubleaf = FindSubleaf( SubleafResults, 4, Subleaf ); //-V112

			CacheInfo::CacheContentType CacheType;
			switch( LeafFourSubleaf.Result.EAX & 0b1'1111 )
			{
			case 1: // Data cache
				CacheType = CacheInfo::CacheContentType::Data;
				break;
			case 2: // Instruction cache
				CacheType = CacheInfo::CacheContentType::Instruction;
				break;
			case 3: // Unified cache
				CacheType = CacheInfo::CacheContentType::Unified;
				break;
			}

			uint32_t CacheLevel = ( LeafFourSubleaf.Result.EAX >> 5 ) & 0b111;

			// EAX 0b1000'0000 - Self Initializing cache level (does not need SW initialization).

			bool FullyAssociative = ( LeafFourSubleaf.Result.EAX >> 9 ) & 0b1;

			// EAX 0b1'1111'1111'1110'0000'0000'0000 - Maximum number of addressable IDs for logical processors sharing this cache**, ***.
			// EAX 0b1111'1110'0000'0000'0000'0000'0000'0000 - Maximum number of addressable IDs for processor cores in the physical

			uint32_t CacheLineSizeInBytes = (   LeafFourSubleaf.Result.EBX         & 0b1111'1111'1111 ) + 1;
			uint32_t CacheLinesPerSector  = ( ( LeafFourSubleaf.Result.EBX >> 12 ) & 0b11'1111'1111   ) + 1;
			uint32_t WaysOfAssociativity  = ( ( LeafFourSubleaf.Result.EBX >> 22 ) & 0b11'1111'1111   ) + 1;
			uint32_t SetCount = LeafFourSubleaf.Result.ECX + 1;

			uint32_t CacheSizeInBytes = CacheLineSizeInBytes * CacheLinesPerSector * WaysOfAssociativity * SetCount;

			// EDX
			// Bit 00: Write-Back Invalidate/Invalidate.
			//	0 = WBINVD/INVD from threads sharing this cache acts upon lower level caches for threads sharing this cache.
			//	1 = WBINVD/INVD is not guaranteed to act upon lower level caches of non-originating threads sharing this cache.
			// Bit 01: Cache Inclusiveness.
			//	0 = Cache is not inclusive of lower cache levels.
			//	1 = Cache is inclusive of lower cache levels.
			// Bit 02: Complex Cache Indexing.
			//	0 = Direct mapped cache.
			//	1 = A complex function is used to index the cache, potentially using all address bits.

			Associativity CacheAssociativity{ Associativity::UnknownAssociativity{} };
			if( FullyAssociative ) {
				CacheAssociativity = Associativity{ Associativity::FullyAssociative{} };
			} else {
				CacheAssociativity = Associativity{ WaysOfAssociativity };
			}
			Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( CacheLevel, CacheType, CacheSizeInBytes, CacheAssociativity, CacheLineSizeInBytes, CacheLinesPerSector ) ) );
		}


		return Returning;
	}

	namespace
	{

		template< typename CPUIDPolicy >
		std::vector< max::CPU::CPUIDSubleafArgumentsAndResult > GetCPUIDSubleafResults() noexcept;

	} // anonymous namespace

	CPUID::CPUID( std::vector< CPUIDSubleafArgumentsAndResult > && SubleafResults ) noexcept
		: SubleafResults( std::move( SubleafResults ) )
	{
	}

	namespace
	{

		max::CPU::CPUIDSubleafArgumentsAndResult FindSubleaf( const std::vector< max::CPU::CPUIDSubleafArgumentsAndResult > & CPUIDResults,
		                                                      const uint32_t LeafNumber,
		                                                      const uint32_t SubleafNumber ) noexcept
		{
			for( auto CurrentSubleaf : CPUIDResults )
			{
				if( CurrentSubleaf.Leaf == LeafNumber && CurrentSubleaf.Subleaf == SubleafNumber )
				{
					return CurrentSubleaf;
				}
			}

			return max::CPU::CPUIDSubleafArgumentsAndResult{};
		}

		uint32_t FindSubleafCount( const std::vector< max::CPU::CPUIDSubleafArgumentsAndResult > & SubleafResults,
		                           const uint32_t Leaf ) noexcept
		{
			uint32_t MaxSubleaf = 0;

			for( auto CurrentSubleaf : SubleafResults )
			{
				if( CurrentSubleaf.Leaf == Leaf )
				{
					MaxSubleaf = std::max( CurrentSubleaf.Subleaf, MaxSubleaf );
				}
			}

			return MaxSubleaf;
		}

		bool IsCPUIDResultBitSet( const std::vector< max::CPU::CPUIDSubleafArgumentsAndResult > & CPUIDResults,
		                          const uint32_t          LeafNumber,
		                          const uint32_t          SubleafNumber,
		                          const CPUIDRegisterName RegisterName,
		                          const uint32_t          BitNumber     ) noexcept
		{
			auto SubleafArgumentsAndResult = FindSubleaf( CPUIDResults, LeafNumber, SubleafNumber );

			// Get the value of the requested register from the leaf
			auto RegisterValue = UINT32_C( 0 );
			switch( RegisterName )
			{
			case CPUIDRegisterName::EAX:
				RegisterValue = SubleafArgumentsAndResult.Result.EAX;
				break;
			case CPUIDRegisterName::EBX:
				RegisterValue = SubleafArgumentsAndResult.Result.EBX;
				break;
			case CPUIDRegisterName::ECX:
				RegisterValue = SubleafArgumentsAndResult.Result.ECX;
				break;
			case CPUIDRegisterName::EDX:
				RegisterValue = SubleafArgumentsAndResult.Result.EDX;
				break;
			}


			// Check if the requested bit is set
			return ( RegisterValue & ( 1u << BitNumber ) ) != 0;
		}


		void Split32BitsInto8Bits( const uint32_t             Input,
		                           std::array< uint8_t, 4 > & Bytes ) noexcept;

		std::vector< std::unique_ptr< max::CPU::CacheInfo > > GetCacheInfoForByte( const uint8_t  Byte,
		                                                                           const uint32_t Family,
		                                                                           const uint32_t Model ) noexcept;

		std::vector< std::unique_ptr< max::CPU::CacheInfo > > GetCacheInfoForRegister( const uint32_t RegisterValue, const bool IsRegisterEAX, const uint32_t Family, const uint32_t Model ) noexcept
		{
			std::vector< std::unique_ptr< max::CPU::CacheInfo > > Returning = {};

			// If the high bit is set this register contains valid information
			if( ( RegisterValue & (1u << 31) ) == 0 )
			{
				// This register contains valid information
				// Break this register into bytes
				std::array< uint8_t, 4 > Bytes = {};
				Split32BitsInto8Bits( RegisterValue, Bytes );

				size_t BytesToProcess = 4; //-V112
				// Unlike the other registers, we ignore the last byte of EAX
				if( IsRegisterEAX )
				{
					BytesToProcess = 3;
				}
				for( ; BytesToProcess > 0; BytesToProcess-- )
				{
					auto CacheInfoForByte = GetCacheInfoForByte( Bytes[ BytesToProcess - 1 ], Family, Model );
					std::move( std::begin( CacheInfoForByte ), std::end( CacheInfoForByte ), std::back_inserter( Returning ) );
				}
			}

			return Returning;
		}

		void Split32BitsInto8Bits( const uint32_t Input, std::array< uint8_t, 4 > & Bytes ) noexcept
		{
			Bytes[ 0 ] = static_cast< uint8_t >( ( Input & ( 0b1111'1111u << 24 ) ) >> 24 );
			Bytes[ 1 ] = static_cast< uint8_t >( ( Input & ( 0b1111'1111u << 16 ) ) >> 16 );
			Bytes[ 2 ] = static_cast< uint8_t >( ( Input & ( 0b1111'1111u << 8  ) ) >>  8 );
			Bytes[ 3 ] = static_cast< uint8_t >( ( Input & ( 0b1111'1111u << 0  ) ) >>  0 );
		}

		std::vector< std::unique_ptr< max::CPU::CacheInfo > > GetCacheInfoForByte( const uint8_t Byte, const uint32_t Family, const uint32_t Model ) noexcept
		{
			std::vector< std::unique_ptr< max::CPU::CacheInfo > > Returning;

			using max::CPU::CacheInfo;

			switch( Byte )
			{
			case 0x01: // Instruction TLB: 4 KByte pages, 4-way set associative, 32 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ 4 }, 32 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Instruction, std::move( Configurations ) ) ) );
				}
				break;
			case 0x02: // Instruction TLB: 4 MByte pages, fully associative, 2 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 * 1024 }, Associativity{ Associativity::FullyAssociative{} }, 2 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Instruction, std::move( Configurations ) ) ) );
				}
				break;
			case 0x03: // Data TLB: 4 KByte pages, 4-way set associative, 64 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ 4 }, 64 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0x04: // Data TLB: 4 MByte pages, 4-way set associative, 8 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 * 1024 }, Associativity{ 4 }, 8 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0x05: // Data TLB: 4 MByte pages, 4-way set associative, 32 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 * 1024 }, Associativity{ 4 }, 64 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0x06: // 1st-level instruction cache: 8 KBytes, 4-way set associative, 32 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 1, CacheInfo::CacheContentType::Instruction, 8 * 1024, Associativity{ 4 }, 32, 1 ) ) ); //-V112
				break;
			case 0x08: // 1st-level instruction cache: 16 KBytes, 4-way set associative, 32 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 1, CacheInfo::CacheContentType::Instruction, 16 * 1024, Associativity{ 4 }, 32, 1 ) ) ); //-V112
				break;
			case 0x09: // 1st-level instruction cache: 32 KBytes, 4-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 1, CacheInfo::CacheContentType::Instruction, 32 * 1024, Associativity{ 4 }, 64, 1 ) ) ); //-V112
				break;
			case 0x0a: // 1st-level data cache: 8 KBytes, 2-way set associative, 32 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 1, CacheInfo::CacheContentType::Data, 8 * 1024, Associativity{ 2 }, 32, 1 ) ) ); //-V112
				break;
			case 0x0b: // Instruction TLB: 4 MByte pages, 4-way set associative, 4 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 * 1024 }, Associativity{ 4 }, 4 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Instruction, std::move( Configurations ) ) ) );
				}
				break;
			case 0x0c: // 1st-level data cache: 16 KBytes, 4-way set associative, 32 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 1, CacheInfo::CacheContentType::Data, 16 * 1024, Associativity{ 4 }, 32, 1 ) ) ); //-V112
				break;
			case 0x0d: // 1st-level data cache: 16 KBytes, 4-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 1, CacheInfo::CacheContentType::Data, 16 * 1024, Associativity{ 4 }, 64, 1 ) ) ); //-V112
				break;
			case 0x0e: // 1st-level data cache: 24 KBytes, 6-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 1, CacheInfo::CacheContentType::Data, 24 * 1024, Associativity{ 6 }, 64, 1 ) ) );
				break;
			case 0x1d: // 2nd-level cache: 128 KBytes, 2-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 128 * 1024, Associativity{ 2 }, 64, 1 ) ) );
				break;
			case 0x21: // 2nd-level cache: 256 KBytes, 8-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 256 * 1024, Associativity{ 8 }, 64, 1 ) ) );
				break;
			case 0x22: // 3rd-level cache: 512 KBytes, 4-way set associative, 64 byte line size, 2 lines per sector
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 512 * 1024, Associativity{ 4 }, 64, 2 ) ) ); //-V112
				break;
			case 0x23: // 3rd-level cache: 1 MBytes, 8-way set associative, 64 byte line size, 2 lines per sector
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 1 * 1024 * 1024, Associativity{ 8 }, 64, 2 ) ) );
				break;
			case 0x24: // 2nd-level cache: 1 MBytes, 16-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 1 * 1024 * 1024, Associativity{ 16 }, 64, 1 ) ) );
				break;
			case 0x25: // 3rd-level cache: 2 MBytes, 8-way set associative, 64 byte line size, 2 lines per sector
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 2 * 1024 * 1024, Associativity{ 8 }, 64, 2 ) ) );
				break;
			case 0x29: // 3rd-level cache: 4 MBytes, 8-way set associative, 64 byte line size, 2 lines per sector
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 4 * 1024 * 1024, Associativity{ 8 }, 64, 2 ) ) ); //-V112
				break;
			case 0x2c: // 1st-level data cache: 32 KBytes, 8-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 1, CacheInfo::CacheContentType::Data, 32 * 1024, Associativity{ 8 }, 64, 1 ) ) ); //-V112
				break;
			case 0x30: // 1st-level instruction cache: 32 KBytes, 8-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 1, CacheInfo::CacheContentType::Instruction, 32 * 1024, Associativity{ 8 }, 64, 1 ) ) ); //-V112
				break;
			case 0x41: // 2nd-level cache: 128 KBytes, 4-way set associative, 32 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 128 * 1024, Associativity{ 4 }, 32, 1 ) ) ); //-V112
				break;
			case 0x42: // 2nd-level cache: 256 KBytes, 4-way set associative, 32 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 256 * 1024, Associativity{ 4 }, 32, 1 ) ) ); //-V112
				break;
			case 0x43: // 2nd-level cache: 512 KBytes, 4-way set associative, 32 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 512 * 1024, Associativity{ 4 }, 32, 1 ) ) ); //-V112
				break;
			case 0x44: // 2nd-level cache: 1 MByte, 4-way set associative, 32 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 1 * 1024 * 1024, Associativity{ 4 }, 32, 1 ) ) ); //-V112
				break;
			case 0x45: // 2nd-level cache: 2 MByte, 4-way set associative, 32 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 2 * 1024 * 1024, Associativity{ 4 }, 32, 1 ) ) ); //-V112
				break;
			case 0x46: // 3rd-level cache: 4 MByte, 4-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 4 * 1024 * 1024, Associativity{ 4 }, 64, 1 ) ) ); //-V112
				break;
			case 0x47: // 3rd-level cache: 8 MByte, 8-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 8 * 1024 * 1024, Associativity{ 8 }, 64, 1 ) ) );
				break;
			case 0x48: // 2nd-level cache: 3 MByte, 12-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 3 * 1024 * 1024, Associativity{ 12 }, 64, 1 ) ) );
				break;
			case 0x49: // 3rd-level cache: 4 MByte, 16-way set associative, 64 byte line size (Intel Xeon processor MP,
					   // Family 0FH, Model 06H);
					   // 2nd-level cache: 4 MByte, 16-way set associative, 64 byte line size
				if( Family == 0x0f && Model == 0x06 ) {
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 4 * 1024 * 1024, Associativity{ 16 }, 64, 1 ) ) ); //-V112
				} else {
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 4 * 1024 * 1024, Associativity{ 16 }, 64, 1 ) ) ); //-V112
				}
				break;
			case 0x4a: // 3rd-level cache: 6 MByte, 12-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 6 * 1024 * 1024, Associativity{ 12 }, 64, 1 ) ) );
				break;
			case 0x4b: // 3rd-level cache: 8 MByte, 16-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 8 * 1024 * 1024, Associativity{ 16 }, 64, 1 ) ) );
				break;
			case 0x4c: // 3rd-level cache: 12 MByte, 12-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 12 * 1024 * 1024, Associativity{ 12 }, 64, 1 ) ) );
				break;
			case 0x4d: // 3rd-level cache: 16 MByte, 16-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 16 * 1024 * 1024, Associativity{ 16 }, 64, 1 ) ) );
				break;
			case 0x4e: // 2nd-level cache: 6 MByte, 24-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 6 * 1024 * 1024, Associativity{ 12 }, 64, 1 ) ) );
				break;
			case 0x4f: // Instruction TLB: 4 KByte pages, 32 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ Associativity::UnknownAssociativity{} }, 32 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Instruction, std::move( Configurations ) ) ) );
				}
				break;
			case 0x50: // Instruction TLB: 4 KByte and 2 MByte or 4 MByte pages, 64 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ Associativity::UnknownAssociativity{} }, 64 ); //-V112
					Configurations.emplace_back( std::vector< uint32_t >{ 2 * 1024 * 1024, 4 * 1024 * 1024 }, Associativity{ Associativity::UnknownAssociativity{} }, 64 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Instruction, std::move( Configurations ) ) ) );
				}
				break;
			case 0x51: // Instruction TLB: 4 KByte and 2 MByte or 4 MByte pages, 128 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ Associativity::UnknownAssociativity{} }, 128 ); //-V112
					Configurations.emplace_back( std::vector< uint32_t >{ 2 * 1024 * 1024, 4 * 1024 * 1024 }, Associativity{ Associativity::UnknownAssociativity{} }, 128 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Instruction, std::move( Configurations ) ) ) );
				}
				break;
			case 0x52: // Instruction TLB: 4 KByte and 2 MByte or 4 MByte pages, 256 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ Associativity::UnknownAssociativity{} }, 256 ); //-V112
					Configurations.emplace_back( std::vector< uint32_t >{ 2 * 1024 * 1024, 4 * 1024 * 1024 }, Associativity{ Associativity::UnknownAssociativity{} }, 256 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Instruction, std::move( Configurations ) ) ) );
				}
				break;
			case 0x55: // Instruction TLB: 2 MByte or 4 MByte pages, fully associative, 7 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 2 * 1024 * 1024, 4 * 1024 * 1024 }, Associativity{ Associativity::FullyAssociative{} }, 7 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Instruction, std::move( Configurations ) ) ) );
				}
				break;
			case 0x56: // Data TLB: 4 MByte pages, 4-way set associative, 16 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 * 1024 }, Associativity{ 4 }, 16 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0x57: // Data TLB: 4 KByte pages, 4-way associative, 16 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ 4 }, 16 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0x59: // Data TLB: 4 KByte pages, fully associative, 16 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ Associativity::FullyAssociative{} }, 16 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0x5a: // Data TLB: 2 MByte or 4 MByte pages, 4-way set associative, 32 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 2 * 1024 * 1024, 4 * 1024 * 1024 }, Associativity{ 4 }, 32 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0x5b: // Data TLB: 4 KByte and 4 MByte pages, 64 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ Associativity::UnknownAssociativity{} }, 64 ); //-V112
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 * 1024 }, Associativity{ Associativity::UnknownAssociativity{} }, 64 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >(  std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0x5c: // Data TLB: 4 KByte and 4 MByte pages, 128 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ Associativity::UnknownAssociativity{} }, 128 ); //-V112
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 * 1024 }, Associativity{ Associativity::UnknownAssociativity{} }, 128 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0x5d: // Data TLB: 4 KByte and 4 MByte pages, 256 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ Associativity::UnknownAssociativity{} }, 256 ); //-V112
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 * 1024 }, Associativity{ Associativity::UnknownAssociativity{} }, 256 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0x60: // 1st-level data cache: 16 KByte, 8-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 1, CacheInfo::CacheContentType::Data, 16 * 1024, Associativity{ 8 }, 64, 1 ) ) );
				break;
			case 0x61: // Instruction TLB: 4 KByte pages, fully associative, 48 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ 4 }, 48 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Instruction, std::move( Configurations ) ) ) );
				}
				break;
			case 0x63: // Data TLB: 2 MByte or 4 MByte pages, 4-way set associative, 32 entries and a separate array with 1 GByte
					   // pages, 4-way set associative, 4 entries
				{				
					std::vector< max::CPU::TLBConfiguration > Configurations1 = {};
					Configurations1.emplace_back( std::vector< uint32_t >{ 2 * 1024 * 1024, 4 * 1024 * 1024 }, Associativity{ 4 }, 32 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations1 ) ) ) );
				
					std::vector< max::CPU::TLBConfiguration > Configurations2 = {};
					Configurations2.emplace_back( std::vector< uint32_t >{ 1 * 1024 * 1024 * 1024 }, Associativity{ 4 }, 4 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations2 ) ) ) );
				}
				break;
			case 0x64: // Data TLB: 4 KByte pages, 4-way set associative, 512 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ 4 }, 512 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0x66: // 1st-level data cache: 8 KByte, 4-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 1, CacheInfo::CacheContentType::Data, 8 * 1024, Associativity{ 4 }, 64, 1 ) ) ); //-V112
				break;
			case 0x67: // 1st-level data cache: 16 KByte, 4-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 1, CacheInfo::CacheContentType::Data, 16 * 1024, Associativity{ 4 }, 64, 1 ) ) ); //-V112
				break;
			case 0x68: // 1st-level data cache: 32 KByte, 4-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 1, CacheInfo::CacheContentType::Data, 32 * 1024, Associativity{ 4 }, 64, 1 ) ) ); //-V112
				break;
			case 0x6a: // uTLB: 4 KByte pages, 8-way set associative, 64 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ 8 }, 64 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Unified, std::move( Configurations ) ) ) );
				}
				break;
			case 0x6b: // DTLB: 4 KByte pages, 8-way set associative, 256 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ 8 }, 256 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0x6c: // DTLB: 2M / 4M pages, 8-way set associative, 128 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 2 * 1024 * 1024, 4 * 1024 * 1024 }, Associativity{ 8 }, 128 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Unified, std::move( Configurations ) ) ) );
				}
				break;
			case 0x6d: // DTLB: 1 GByte pages, fully associative, 16 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 1 * 1024 * 1024 * 1024 }, Associativity{ Associativity::FullyAssociative{} }, 16 );
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0x70: // Trace cache : 12 K-μop, 8-way set associative
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TraceCache >( 12 * 1024, Associativity{ 8 } ) ) );
				break;
			case 0x71: // Trace cache : 16 K-μop, 8-way set associative
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TraceCache >( 16 * 1024, Associativity{ 8 } ) ) );
				break;
			case 0x72: // Trace cache : 32 K-μop, 8-way set associative
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TraceCache >( 32 * 1024, Associativity{ 8 } ) ) ); //-V112
				break;
			case 0x76: // Instruction TLB: 2 MiB / 4 MiB pages, fully associative, 8 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 2 * 1024 * 1024, 4 * 1024 * 1024 }, Associativity{ Associativity::FullyAssociative{} }, 8 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Unified, std::move( Configurations ) ) ) );
				}
				break;
			case 0x78: // 2nd-level cache: 1 MByte, 4-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 1 * 1024 * 1024, Associativity{ 4 }, 64, 1 ) ) ); //-V112
				break;
			case 0x79: // 2nd-level cache: 128 KByte, 8-way set associative, 64 byte line size, 2 lines per sector
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 128 * 1024, Associativity{ 8 }, 64, 2 ) ) );
				break;
			case 0x7a: // 2nd-level cache: 256 KByte, 8-way set associative, 64 byte line size, 2 lines per sector
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 256 * 1024, Associativity{ 8 }, 64, 2 ) ) );
				break;
			case 0x7b: // 2nd-level cache: 512 KByte, 8-way set associative, 64 byte line size, 2 lines per sector
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 512 * 1024, Associativity{ 8 }, 64, 2 ) ) );
				break;
			case 0x7c: // 2nd-level cache: 1 MByte, 8-way set associative, 64 byte line size, 2 lines per sector
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 1 * 1024 * 1024, Associativity{ 8 }, 64, 2 ) ) );
				break;
			case 0x7d: // 2nd-level cache: 2 MByte, 8-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 2 * 1024 * 1024, Associativity{ 8 }, 64, 1 ) ) );
				break;
			case 0x7f: // 2nd-level cache: 512 KByte, 2-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 512 * 1024, Associativity{ 2 }, 64, 1 ) ) );
				break;
			case 0x80: // 2nd-level cache: 512 KByte, 8-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 512 * 1024, Associativity{ 8 }, 64, 1 ) ) );
				break;
			case 0x82: // 2nd-level cache: 256 KByte, 8-way set associative, 32 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 256 * 1024, Associativity{ 8 }, 32, 1 ) ) ); //-V112
				break;
			case 0x83: // 2nd-level cache: 512 KByte, 8-way set associative, 32 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 512 * 1024, Associativity{ 8 }, 32, 1 ) ) ); //-V112
				break;
			case 0x84: // 2nd-level cache: 1 MByte, 8-way set associative, 32 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 1 * 1024 * 1024, Associativity{ 8 }, 32, 1 ) ) ); //-V112
				break;
			case 0x85: // 2nd-level cache: 2 MByte, 8-way set associative, 32 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 2 * 1024 * 1024, Associativity{ 8 }, 32, 1 ) ) ); //-V112
				break;
			case 0x86: // 2nd-level cache: 512 KByte, 4-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 512 * 1024, Associativity{ 4 }, 64, 1 ) ) ); //-V112
				break;
			case 0x87: // 2nd-level cache: 1 MByte, 8-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 2, CacheInfo::CacheContentType::Unified, 1 * 1024 * 1024, Associativity{ 8 }, 64, 1 ) ) );
				break;
			case 0xa0: // DTLB: 4k pages, fully associative, 32 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ Associativity::FullyAssociative{} }, 32 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0xb0: // Instruction TLB: 4 KByte pages, 4-way set associative, 128 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ 4 }, 128 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Instruction, std::move( Configurations ) ) ) );
				}
				break;
			case 0xb1: // Instruction TLB: 2 MByte pages, 4-way, 8 entries or 4 MByte pages, 4-way, 4 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 2 * 1024 * 1024 }, Associativity{ 4 }, 8 ); //-V112
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 * 1024 }, Associativity{ 4 }, 4 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Instruction, std::move( Configurations ) ) ) );
				}
				break;
			case 0xb2: // Instruction TLB: 4 KByte pages, 4-way set associative, 64 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ 4 }, 64 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Instruction, std::move( Configurations ) ) ) );
				}
				break;
			case 0xb3: // Data TLB: 4 KByte pages, 4-way set associative, 128 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ 4 }, 128 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0xb4: // Data TLB1: 4 KByte pages, 4-way associative, 256 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ 4 }, 256 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0xb5: // Instruction TLB: 4 KByte pages, 8-way set associative, 64 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ 8 }, 64 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Instruction, std::move( Configurations ) ) ) );
				}
				break;
			case 0xb6: // Instruction TLB: 4 KByte pages, 8-way set associative, 128 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ 8 }, 128 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Instruction, std::move( Configurations ) ) ) );
				}
				break;
			case 0xba: // Data TLB1: 4 KByte pages, 4-way associative, 64 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ 4 }, 64 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0xc0: // Data TLB: 4 KByte and 4 MByte pages, 4-way associative, 8 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024, 4 * 1024 * 1024 }, Associativity{ 4 }, 8 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0xc1: // Shared 2nd-Level TLB: 4 KByte / 2 MByte pages, 8-way associative, 1024 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024, 2 * 1024 * 1024 }, Associativity{ 8 }, 1024 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Unified, std::move( Configurations ) ) ) );
				}
				break;
			case 0xc2: // DTLB: 4 KByte / 2 MByte pages, 4-way associative, 16 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024, 2 * 1024 * 1024 }, Associativity{ 4 }, 16 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0xc3: // Shared 2nd-Level TLB: 4 KByte / 2 MByte pages, 6-way associative, 1536 entries.
					   // Also 1GBbyte pages, 4-way, 16 entries.
				{	
					std::vector< max::CPU::TLBConfiguration > Configurations1 = {};
					Configurations1.emplace_back( std::vector< uint32_t >{ 4 * 1024, 2 * 1024 * 1024 }, Associativity{ 6 }, 1536 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Unified, std::move( Configurations1 ) ) ) );
				
					std::vector< max::CPU::TLBConfiguration > Configurations2 = {};
					Configurations2.emplace_back( std::vector< uint32_t >{ 1 * 1024 * 1024 * 1024 }, Associativity{ 4 }, 16 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Unified, std::move( Configurations2 ) ) ) );
				}
				break;
			case 0xc4: // DTLB: 2M / 4M Byte pages, 4-way associative, 32 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 2 * 1024 * 1024, 2 * 1024 * 1024 }, Associativity{ 4 }, 32 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Data, std::move( Configurations ) ) ) );
				}
				break;
			case 0xca: // Shared 2nd-Level TLB: 4 KByte pages, 4-way associative, 512 entries
				{
					std::vector< max::CPU::TLBConfiguration > Configurations = {};
					Configurations.emplace_back( std::vector< uint32_t >{ 4 * 1024 }, Associativity{ 4 }, 512 ); //-V112
					Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::TLB >( CacheInfo::CacheContentType::Unified, std::move( Configurations ) ) ) );
				}
				break;
			case 0xd0: // 3rd-level cache: 512 KByte, 4-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 512 * 1024, Associativity{ 4 }, 64, 1 ) ) ); //-V112
				break;
			case 0xd1: // 3rd-level cache: 1 MByte, 4-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 1 * 1024 * 1024, Associativity{ 4 }, 64, 1 ) ) ); //-V112
				break;
			case 0xd2: // 3rd-level cache: 2 MByte, 4-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 2 * 1024 * 1024, Associativity{ 4 }, 64, 1 ) ) ); //-V112
				break;
			case 0xd6: // 3rd-level cache: 1 MByte, 8-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 1 * 1024 * 1024, Associativity{ 8 }, 64, 1 ) ) );
				break;
			case 0xd7: // 3rd-level cache: 2 MByte, 8-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 2 * 1024 * 1024, Associativity{ 8 }, 64, 1 ) ) );
				break;
			case 0xd8: // 3rd-level cache: 4 MByte, 8-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 4 * 1024 * 1024, Associativity{ 8 }, 64, 1 ) ) ); //-V112
				break;
			case 0xdc: // 3rd-level cache: 1.5 MByte, 12-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, ( 1024 + 512 ) * 1024, Associativity{ 12 }, 64, 1 ) ) );
				break;
			case 0xdd: // 3rd-level cache: 3 MByte, 12-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 3 * 1024 * 1024, Associativity{ 12 }, 64, 1 ) ) );
				break;
			case 0xde: // 3rd-level cache: 6 MByte, 12-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 6 * 1024 * 1024, Associativity{ 12 }, 64, 1 ) ) );
				break;
			case 0xe2: // 3rd-level cache: 2 MByte, 16-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 2 * 1024 * 1024, Associativity{ 16 }, 64, 1 ) ) );
				break;
			case 0xe3: // 3rd-level cache: 4 MByte, 16-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 4 * 1024 * 1024, Associativity{ 16 }, 64, 1 ) ) ); //-V112
				break;
			case 0xe4: // 3rd-level cache: 8 MByte, 16-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 8 * 1024 * 1024, Associativity{ 16 }, 64, 1 ) ) );
				break;
			case 0xea: // 3rd-level cache: 12 MByte, 24-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 12 * 1024 * 1024, Associativity{ 24 }, 64, 1 ) ) );
				break;
			case 0xeb: // 3rd-level cache: 18 MByte, 24-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 18 * 1024 * 1024, Associativity{ 24 }, 64, 1 ) ) );
				break;
			case 0xec: // 3rd-level cache: 24 MByte, 24-way set associative, 64 byte line size
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::CacheLevel >( 3, CacheInfo::CacheContentType::Unified, 24 * 1024 * 1024, Associativity{ 24 }, 64, 1 ) ) );
				break;
			case 0xf0: // 64-Byte prefetching
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::Prefetch >( 64 ) ) );
				break;
			case 0xf1: // 128-Byte prefetching
				Returning.push_back( std::unique_ptr< max::CPU::CacheInfo >( std::make_unique< max::CPU::Prefetch >( 128 ) ) );
				break;
			}

			return Returning;
		}

		template< typename CPUIDPolicy >
		std::vector< max::CPU::CPUIDSubleafArgumentsAndResult > GetCPUIDSubleafResults() noexcept
		{
			std::vector< max::CPU::CPUIDSubleafArgumentsAndResult > SubleafResults;



			// cpuid function 0 returns the highest valid function number in EAX
			max::CPU::CPUIDSubleafResult Result = {};
			CPUIDPolicy::CPUID( Result, 0 );
			const auto LeafCount = Result.EAX;


			// Populate CPUID results
			// We already ran function 0.
			SubleafResults.emplace_back( 0, 0, std::move( Result ) );
			// So we will loop through 1-x
			for( uint32_t Leaf = 1; Leaf <= LeafCount; Leaf++ )
			{
				if( Leaf == 4 ) //-V112 Dangerous magic number 4 used -- in this case, it isn't a sizeof(int)
				{
					for( uint32_t Subleaf = 0; ; Subleaf++ )
					{
						CPUIDPolicy::CPUIDExtended( Result, Leaf, Subleaf );
						if( Result.EAX == 0 && Result.EBX == 0 && Result.ECX == 0 && Result.EDX == 0 )
						{
							break;
						}

						SubleafResults.emplace_back( Leaf, Subleaf, std::move( Result ) );
					}
				} else {
					CPUIDPolicy::CPUID( Result, Leaf );
					SubleafResults.emplace_back( Leaf, 0, std::move( Result ) );
				}
			}



			// cpuid function 0x8000'0000 returns the highest valid extended function number in EAX
			CPUIDPolicy::CPUID( Result, 0x8000'0000 ); // -V112 Dangerous magic number 0x8000'0000 -- in this case
			const auto ExtendedLeafCount = Result.EAX - 0x8000'0000; // -V112


			// Populate CPUID results
			// We already ran extended function 0.
			SubleafResults.emplace_back( 0x8000'0000, 0, std::move( Result ) ); // -V112
			// So we will loop through 1-x
			for( uint32_t i = 1; i <= ExtendedLeafCount; i++ )
			{
				CPUIDPolicy::CPUID( Result, i + 0x8000'0000 ); // -V112
				SubleafResults.emplace_back( i + 0x8000'0000, 0, std::move( Result ) ); // -V112
			}


			return SubleafResults;
		}

	} // anonymous namespace

	CPUID MakeCPUID() noexcept
	{
#if defined( MAX_COMPILER_VC )
	#if defined( MAX_X86_64 )
		typedef X64AssemblyIsCPUIDAvailablePolicy   IsCPUIDAvailablePolicy;
	#elif defined( MAX_X86 )
		typedef X86AssemblyIsCPUIDAvailablePolicy   IsCPUIDAvailablePolicy;
	#else
		static_assert( false, "Unsupported platform" );
	#endif
	typedef VCIntrinsicCPUIDPolicy                  CPUIDPolicy;
#elif defined( MAX_COMPILER_GCC ) || defined( MAX_COMPILER_CLANG )
	#if defined( MAX_X86_64 )
		typedef X64GCCAssemblyIsCPUIDAvailablePolicy   IsCPUIDAvailablePolicy;
		typedef X64GCCAssemblyCPUIDPolicy              CPUIDPolicy;
	#elif defined( MAX_X86 )
		typedef X86GCCAssemblyIsCPUIDAvailablePolicy   IsCPUIDAvailablePolicy;
		typedef X86GCCAssemblyCPUIDPolicy              CPUIDPolicy;
	#elif defined( MAX_AARCH64 ) || defined( MAX_ARM ) || defined( MAX_THUMB )
		typedef ArmIsCPUIDAvailablePolicy              IsCPUIDAvailablePolicy;
		typedef AArch64CPUIDPolicy                     CPUIDPolicy;
	#else
		static_assert( false, "Unsupported platform" );
	#endif
#else
		static_assert( false, "Unsupported compiler" );
#endif

		if( ! IsCPUIDAvailablePolicy::IsCPUIDAvailable() )
		{
			return CPUID{ std::vector< CPUIDSubleafArgumentsAndResult >{} };
		}

		return CPUID{ GetCPUIDSubleafResults< CPUIDPolicy >() };
	}

} // namespace CPU
} // namespace max
