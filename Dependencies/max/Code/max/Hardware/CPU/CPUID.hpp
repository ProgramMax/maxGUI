// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_CPU_CPUID_HPP
#define MAX_CPU_CPUID_HPP

#include <string>
#include <vector>
#include <memory>
#include "CPUIDSubleafArgumentsAndResult.hpp"
#include "CacheInfo.hpp"

namespace max
{
namespace CPU
{

	class CPUID
	{
	public:

		CPUID()                                  noexcept = delete;
		CPUID( const CPUID &  rhs )                       = default;
		CPUID(       CPUID && rhs )              noexcept = default;

		CPUID & operator =( const CPUID &  rhs )          = default;
		CPUID & operator =(       CPUID && rhs ) noexcept = default;

		// Function 0
		std::string Vendor()              const noexcept;

		// Function 1
		uint32_t Stepping()               const noexcept;
		uint32_t Model()                  const noexcept;
		uint32_t Family()                 const noexcept;
		uint32_t ProcessorType()          const noexcept;

		uint32_t BrandIndex()             const noexcept;
		uint32_t CLFLUSHLineSizeInBytes() const noexcept;
		uint32_t MaximumAddressableIDs()  const noexcept;
		uint32_t InitialAPICID()          const noexcept;

		bool SupportsSSE3()               const noexcept;
		bool SupportsPCLMULQDQ()          const noexcept;
		bool SupportsDTES64()             const noexcept;
		bool SupportsMONITOR()            const noexcept;
		bool SupportsDSCPL()              const noexcept;
		bool SupportsVMX()                const noexcept;
		bool SupportsSMX()                const noexcept;
		bool SupportsEST()                const noexcept;
		bool SupportsTM2()                const noexcept;
		bool SupportsSSSE3()              const noexcept;
		bool SupportsCNXTID()             const noexcept;
		bool SupportsSDBG()               const noexcept;
		bool SupportsFMA()                const noexcept;
		bool SupportsCX16()               const noexcept;
		bool SupportsXTPR()               const noexcept;
		bool SupportsPDCM()               const noexcept;
		bool SupportsPCID()               const noexcept;
		bool SupportsDCA()                const noexcept;
		bool SupportsSSE41()              const noexcept;
		bool SupportsSSE42()              const noexcept;
		bool SupportsX2APIC()             const noexcept;
		bool SupportsMOVBE()              const noexcept;
		bool SupportsPOPCNT()             const noexcept;
		bool SupportsTSCDeadline()        const noexcept;
		bool SupportsAES()                const noexcept;
		bool SupportsXSAVE()              const noexcept;
		bool SupportsOSXSAVE()            const noexcept;
		bool SupportsAVX()                const noexcept;
		bool SupportsF16C()               const noexcept;
		bool SupportsRDRAND()             const noexcept;
		bool SupportsHypervisor()         const noexcept;

		bool SupportsFPU()                const noexcept;
		bool SupportsVME()                const noexcept;
		bool SupportsDE()                 const noexcept;
		bool SupportsPSE()                const noexcept;
		bool SupportsTSC()                const noexcept;
		bool SupportsMSR()                const noexcept;
		bool SupportsPAE()                const noexcept;
		bool SupportsMCE()                const noexcept;
		bool SupportsCX8()                const noexcept;
		bool SupportsAPIC()               const noexcept;
		bool SupportsSEP()                const noexcept;
		bool SupportsMTRR()               const noexcept;
		bool SupportsPGE()                const noexcept;
		bool SupportsMCA()                const noexcept;
		bool SupportsCMOV()               const noexcept;
		bool SupportsPAT()                const noexcept;
		bool SupportsPSE36()              const noexcept;
		bool SupportsPSN()                const noexcept;
		bool SupportsCLFSH()              const noexcept;
		bool SupportsDS()                 const noexcept;
		bool SupportsACPI()               const noexcept;
		bool SupportsMMX()                const noexcept;
		bool SupportsFXSR()               const noexcept;
		bool SupportsSSE()                const noexcept;
		bool SupportsSSE2()               const noexcept;
		bool SupportsSS()                 const noexcept;
		bool SupportsHTT()                const noexcept;
		bool SupportsTM()                 const noexcept;
		bool SupportsIA64()               const noexcept;
		bool SupportsPBE()                const noexcept;

		std::vector< std::unique_ptr< max::CPU::CacheInfo > > CacheDetails() const noexcept;

		// There is a collection of leaves.
		// Each leaf can have a collection of subleaves.
		std::vector< CPUIDSubleafArgumentsAndResult > SubleafResults;

	private:

		friend CPUID MakeCPUID() noexcept;

		CPUID( std::vector< CPUIDSubleafArgumentsAndResult > && SubleafResults ) noexcept;

	};

	CPUID MakeCPUID() noexcept;

} // namespace CPU
} // namespace max

#endif // #ifndef MAX_CPU_CPUID_HPP
