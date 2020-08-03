// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Compiling/Configuration.hpp>

#if defined( MAX_COMPILER_VC )
#include <stdlib.h>
#endif

namespace max
{
namespace v0
{
namespace Algorithms
{

#if defined( MAX_COMPILER_CLANG ) || \
	( defined( MAX_COMPILER_GCC ) && MAX_COMPILER_VERSION_AT_LEAST( 4, 3, 0 )  )
	MAX_PURE_DEFINITION( inline uint64_t SwapEndian( const uint64_t Value ) noexcept )
	{
		return __builtin_bswap64( Value );
	}

	MAX_PURE_DEFINITION( inline uint32_t SwapEndian( const uint32_t Value ) noexcept )
	{
		return __builtin_bswap32( Value );
	}

	MAX_PURE_DEFINITION( inline uint16_t SwapEndian( const uint16_t Value ) noexcept )
	{
		return __builtin_bswap16( Value );
	}
#elif defined( MAX_COMPILER_VC )
	MAX_PURE_DEFINITION( inline uint64_t SwapEndian( const uint64_t Value ) noexcept )
	{
		return _byteswap_uint64( Value );
	}

	MAX_PURE_DEFINITION( inline uint32_t SwapEndian( const uint32_t Value ) noexcept )
	{
		return _byteswap_ulong( Value );
	}

	MAX_PURE_DEFINITION( inline uint16_t SwapEndian( const uint16_t Value ) noexcept )
	{
		return _byteswap_ushort( Value );
	}
#else
	MAX_PURE_DEFINITION( inline uint64_t SwapEndian( const uint64_t Value ) noexcept )
	{
		return static_cast< const uint64_t >(
			( ( Value & 0xff00'0000'0000'0000ull ) >> 56 ) |  // move byte 7 to byte 0
			( ( Value & 0x00ff'0000'0000'0000ull ) >> 40 ) |  // move byte 6 to byte 1
			( ( Value & 0x0000'ff00'0000'0000ull ) >> 24 ) |  // move byte 5 to byte 2
			( ( Value & 0x0000'00ff'0000'0000ull ) >> 8  ) |  // move byte 4 to byte 3
			( ( Value & 0x0000'0000'ff00'0000ull ) << 8  ) |  // move byte 3 to byte 4
			( ( Value & 0x0000'0000'00ff'0000ull ) << 24 ) |  // move byte 2 to byte 5
			( ( Value & 0x0000'0000'0000'ff00ull ) << 40 ) |  // move byte 1 to byte 6
			( ( Value & 0x0000'0000'0000'00ffull ) << 56 ) ); // move byte 0 to byte 7
	}

	MAX_PURE_DEFINITION( inline uint32_t SwapEndian( const uint32_t Value ) noexcept )
	{
		return static_cast< const uint32_t >(
			( ( Value & 0xff000000 ) >> 24 ) |  // move byte 3 to byte 0
			( ( Value & 0x00ff0000 ) >> 8  ) |  // move byte 2 to byte 1
			( ( Value & 0x0000ff00 ) << 8  ) |  // move byte 1 to byte 2
			( ( Value & 0x000000ff ) << 24 ) ); // move byte 0 to byte 3
	}

	MAX_PURE_DEFINITION( constexpr inline uint16_t SwapEndian( const uint16_t Value ) noexcept )
	{
		return static_cast< const uint16_t >(
			( ( Value & 0xff00 ) >> 8 ) |
			( ( Value & 0x00ff ) << 8 ) );
	}
#endif

	MAX_PURE_DEFINITION( inline int64_t SwapEndian( const int64_t Value ) noexcept )
	{
		return static_cast< int64_t >(
			SwapEndian( static_cast< uint64_t >( Value ) )
		);
	}

	MAX_PURE_DEFINITION( inline int32_t SwapEndian( const int32_t Value ) noexcept )
	{
		return static_cast< int32_t >(
			SwapEndian( static_cast< uint32_t >( Value ) )
		);
	}

	MAX_PURE_DEFINITION( inline int16_t SwapEndian( const int16_t Value ) noexcept )
	{
		return static_cast< int16_t >(
			SwapEndian( static_cast< uint16_t >( Value ) )
		);
	}

#if defined( MAX_COMPILER_CLANG ) || \
	( defined( MAX_COMPILER_GCC ) && MAX_COMPILER_VERSION_AT_LEAST( 4, 3, 0 )  )
	MAX_PURE_DEFINITION( constexpr inline uint64_t SwapEndianConstexpr( const uint64_t Value ) noexcept )
	{
		return __builtin_bswap64( Value );
	}

	MAX_PURE_DEFINITION( constexpr inline uint32_t SwapEndianConstexpr( const uint32_t Value ) noexcept )
	{
		return __builtin_bswap32( Value );
	}

	MAX_PURE_DEFINITION( constexpr inline uint16_t SwapEndianConstexpr( const uint16_t Value ) noexcept )
	{
		return __builtin_bswap16( Value );
	}
#else
	// MSVC does not allow intrinsics inside a constexpr. So use the normal functions.

	MAX_PURE_DEFINITION( constexpr inline uint64_t SwapEndianConstexpr( const uint64_t Value ) noexcept )
	{
		return static_cast<const uint64_t>(
			( ( Value & 0xff00'0000'0000'0000ull ) >> 56 ) |  // move byte 7 to byte 0
			( ( Value & 0x00ff'0000'0000'0000ull ) >> 40 ) |  // move byte 6 to byte 1
			( ( Value & 0x0000'ff00'0000'0000ull ) >> 24 ) |  // move byte 5 to byte 2
			( ( Value & 0x0000'00ff'0000'0000ull ) >> 8  ) |  // move byte 4 to byte 3
			( ( Value & 0x0000'0000'ff00'0000ull ) << 8  ) |  // move byte 3 to byte 4
			( ( Value & 0x0000'0000'00ff'0000ull ) << 24 ) |  // move byte 2 to byte 5
			( ( Value & 0x0000'0000'0000'ff00ull ) << 40 ) |  // move byte 1 to byte 6
			( ( Value & 0x0000'0000'0000'00ffull ) << 56 ) ); // move byte 0 to byte 7
	}

	MAX_PURE_DEFINITION( constexpr inline uint32_t SwapEndianConstexpr( const uint32_t Value ) noexcept )
	{
		return static_cast< const uint32_t >(
			( ( Value & 0xff000000 ) >> 24 ) |  // move byte 3 to byte 0
			( ( Value & 0x00ff0000 ) >> 8  ) |  // move byte 2 to byte 1
			( ( Value & 0x0000ff00 ) << 8  ) |  // move byte 1 to byte 2
			( ( Value & 0x000000ff ) << 24 ) ); // move byte 0 to byte 3
	}

	MAX_PURE_DEFINITION( constexpr inline uint16_t SwapEndianConstexpr( const uint16_t Value ) noexcept )
	{
		return static_cast< const uint16_t >(
			( ( Value & 0xff00 ) >> 8 ) |
			( ( Value & 0x00ff ) << 8 ) );
	}
#endif

	MAX_PURE_DEFINITION( constexpr inline int64_t SwapEndianConstexpr( const int64_t Value ) noexcept )
	{
		return static_cast< int64_t >(
			SwapEndianConstexpr( static_cast< uint64_t >( Value ) )
			);
	}

	MAX_PURE_DEFINITION( constexpr inline int32_t SwapEndianConstexpr( const int32_t Value ) noexcept )
	{
		return static_cast< int32_t >(
			SwapEndianConstexpr( static_cast< uint32_t >( Value ) )
			);
	}

	MAX_PURE_DEFINITION( constexpr inline int16_t SwapEndianConstexpr( const int16_t Value ) noexcept )
	{
		return static_cast< int16_t >(
			SwapEndianConstexpr( static_cast< uint16_t >( Value ) )
			);
	}

	MAX_PURE_DEFINITION( constexpr inline uint64_t LittleEndianToHost( const uint64_t Value ) noexcept )
	{
		#if defined( MAX_LITTLE_ENDIAN )
			return Value;
		#elif defined( MAX_BIG_ENDIAN )
			return SwapEndian( Value );
		#else
			static_assert( false, "Unknown endianness" );
		#endif
	}

	MAX_PURE_DEFINITION( constexpr inline uint32_t LittleEndianToHost( const uint32_t Value ) noexcept )
	{
		#if defined( MAX_LITTLE_ENDIAN )
			return Value;
		#elif defined( MAX_BIG_ENDIAN )
			return SwapEndian( Value );
		#else
			static_assert( false, "Unknown endianness" );
		#endif
	}

	MAX_PURE_DEFINITION( constexpr inline uint16_t LittleEndianToHost( const uint16_t Value ) noexcept )
	{
		#if defined( MAX_LITTLE_ENDIAN )
			return Value;
		#elif defined( MAX_BIG_ENDIAN )
			return SwapEndian( Value );
		#else
			static_assert( false, "Unknown endianness" );
		#endif
	}

	MAX_PURE_DEFINITION( constexpr inline int64_t LittleEndianToHost( const int64_t Value ) noexcept )
	{
		return static_cast< int64_t >(
			LittleEndianToHost( static_cast< uint64_t >( Value ) )
		);
	}

	MAX_PURE_DEFINITION( constexpr inline int32_t LittleEndianToHost( const int32_t Value ) noexcept )
	{
		return static_cast< int32_t >(
			LittleEndianToHost( static_cast< uint32_t >( Value ) )
		);
	}

	MAX_PURE_DEFINITION( constexpr inline int16_t LittleEndianToHost( const int16_t Value ) noexcept )
	{
		return static_cast< int16_t >(
			LittleEndianToHost( static_cast< uint16_t >( Value ) )
		);
	}

	MAX_PURE_DEFINITION( constexpr inline uint64_t BigEndianToHost( const uint64_t Value ) noexcept )
	{
		#if defined( MAX_BIG_ENDIAN )
			return Value;
		#elif defined( MAX_LITTLE_ENDIAN )
			return SwapEndianConstexpr( Value );
		#else
			static_assert( false, "Unknown endianness" );
		#endif
	}

	MAX_PURE_DEFINITION( constexpr inline uint32_t BigEndianToHost( const uint32_t Value ) noexcept )
	{
		#if defined( MAX_BIG_ENDIAN )
			return Value;
		#elif defined( MAX_LITTLE_ENDIAN )
			return SwapEndianConstexpr( Value );
		#else
			static_assert( false, "Unknown endianness" );
		#endif
	}

	MAX_PURE_DEFINITION( constexpr inline uint16_t BigEndianToHost( const uint16_t Value ) noexcept )
	{
		#if defined( MAX_BIG_ENDIAN )
			return Value;
		#elif defined( MAX_LITTLE_ENDIAN )
			return SwapEndianConstexpr( Value );
		#else
			static_assert( false, "Unknown endianness" );
		#endif
	}

	MAX_PURE_DEFINITION( constexpr inline int64_t BigEndianToHost( const int64_t Value ) noexcept )
	{
		return static_cast< int64_t >(
			BigEndianToHost( static_cast< uint64_t >( Value ) )
		);
	}

	MAX_PURE_DEFINITION( constexpr inline int32_t BigEndianToHost( const int32_t Value ) noexcept )
	{
		return static_cast< int32_t >(
			BigEndianToHost( static_cast< uint32_t >( Value ) )
		);
	}

	MAX_PURE_DEFINITION( constexpr inline int16_t BigEndianToHost( const int16_t Value ) noexcept )
	{
		return static_cast< int16_t >(
			BigEndianToHost( static_cast< uint16_t >( Value ) )
		);
	}

	MAX_PURE_DEFINITION( constexpr inline uint64_t HostToLittleEndian( const uint64_t Value ) noexcept )
	{
		#if defined( MAX_LITTLE_ENDIAN )
			return Value;
		#elif defined( MAX_BIG_ENDIAN )
			return SwapEndian( Value );
		#else
			static_assert( false, "Unknown endianness" );
		#endif
	}

	MAX_PURE_DEFINITION( constexpr inline uint32_t HostToLittleEndian( const uint32_t Value ) noexcept )
	{
		#if defined( MAX_LITTLE_ENDIAN )
			return Value;
		#elif defined( MAX_BIG_ENDIAN )
			return SwapEndian( Value );
		#else
			static_assert( false, "Unknown endianness" );
		#endif
	}

	MAX_PURE_DEFINITION( constexpr inline uint16_t HostToLittleEndian( const uint16_t Value ) noexcept )
	{
		#if defined( MAX_LITTLE_ENDIAN )
			return Value;
		#elif defined( MAX_BIG_ENDIAN )
			return SwapEndian( Value );
		#else
			static_assert( false, "Unknown endianness" );
		#endif
	}

	MAX_PURE_DEFINITION( constexpr inline int64_t HostToLittleEndian( const int64_t Value ) noexcept )
	{
		return static_cast< int64_t >(
			HostToLittleEndian( static_cast< uint64_t >( Value ) )
		);
	}

	MAX_PURE_DEFINITION( constexpr inline int32_t HostToLittleEndian( const int32_t Value ) noexcept )
	{
		return static_cast< int32_t >(
			HostToLittleEndian( static_cast< uint32_t >( Value ) )
		);
	}

	MAX_PURE_DEFINITION( constexpr inline int16_t HostToLittleEndian( const int16_t Value ) noexcept )
	{
		return static_cast< int16_t >(
			HostToLittleEndian( static_cast< uint16_t >( Value ) )
		);
	}

	MAX_PURE_DEFINITION( constexpr inline uint64_t HostToBigEndian( const uint64_t Value ) noexcept )
	{
		#if defined( MAX_BIG_ENDIAN )
			return Value;
		#elif defined( MAX_LITTLE_ENDIAN )
			return SwapEndianConstexpr( Value );
		#else
			static_assert( false, "Unknown endianness" );
		#endif
	}

	MAX_PURE_DEFINITION( constexpr inline uint32_t HostToBigEndian( const uint32_t Value ) noexcept )
	{
		#if defined( MAX_BIG_ENDIAN )
			return Value;
		#elif defined( MAX_LITTLE_ENDIAN )
			return SwapEndianConstexpr( Value );
		#else
			static_assert( false, "Unknown endianness" );
		#endif
	}

	MAX_PURE_DEFINITION( constexpr inline uint16_t HostToBigEndian( const uint16_t Value ) noexcept )
	{
		#if defined( MAX_BIG_ENDIAN )
			return Value;
		#elif defined( MAX_LITTLE_ENDIAN )
			return SwapEndianConstexpr( Value );
		#else
			static_assert( false, "Unknown endianness" );
		#endif
	}

	MAX_PURE_DEFINITION( constexpr inline int64_t HostToBigEndian( const int64_t Value ) noexcept )
	{
		return static_cast< int64_t >(
			HostToBigEndian( static_cast< uint64_t >( Value ) )
		);
	}

	MAX_PURE_DEFINITION( constexpr inline int32_t HostToBigEndian( const int32_t Value ) noexcept )
	{
		return static_cast< int32_t >(
			HostToBigEndian( static_cast< uint32_t >( Value ) )
		);
	}

	MAX_PURE_DEFINITION( constexpr inline int16_t HostToBigEndian( int16_t Value ) noexcept )
	{
		return static_cast< int16_t >(
			HostToBigEndian( static_cast< uint16_t >( Value ) )
		);
	}

	MAX_PURE_DEFINITION( constexpr inline uint64_t CombinePieces( const uint8_t First8Bits,
	                                                              const uint8_t Second8Bits,
	                                                              const uint8_t Third8Bits,
	                                                              const uint8_t Fourth8Bits,
	                                                              const uint8_t Fifth8Bits,
	                                                              const uint8_t Sixth8Bits,
	                                                              const uint8_t Seventh8Bits,
	                                                              const uint8_t Eighth8Bits ) noexcept )
	{
		auto ExpandedFirst8Bits  = static_cast< uint64_t >( First8Bits );
		auto ExpandedSecond8Bits = static_cast< uint64_t >( Second8Bits );
		auto ExpandedThird8Bits  = static_cast< uint64_t >( Third8Bits );
		auto ExpandedFourth8Bits = static_cast< uint64_t >( Fourth8Bits );
		auto ExpandedFifth8Bits  = static_cast< uint64_t >( Fifth8Bits );
		auto ExpandedSixth8Bits  = static_cast< uint64_t >( Sixth8Bits );
		auto ExpandedSeventh8Bits = static_cast< uint64_t >( Seventh8Bits );
		auto ExpandedEighth8Bits = static_cast< uint64_t >( Eighth8Bits );

		#if defined( MAX_LITTLE_ENDIAN )
			return static_cast< uint64_t >( ExpandedFirst8Bits | ExpandedSecond8Bits << 8 | ExpandedThird8Bits << 16 | ExpandedFourth8Bits << 24 | ExpandedFifth8Bits << 32 | ExpandedSixth8Bits << 40 | ExpandedSeventh8Bits << 48 | ExpandedEighth8Bits << 56 );
		#elif defined( MAX_BIG_ENDIAN )
			return static_cast< uint64_t >( ExpandedFirst8Bits << 56 | ExpandedSecond8Bits << 48 | ExpandedThird8Bits << 40 | ExpandedFourth8Bits << 32 | ExpandedFifth8Bits << 24 | ExpandedSixth8Bits << 16 | ExpandedSeventh8Bits << 8 | ExpandedEighth8Bits );
		#else
			static_assert( false, "Unknown endianness" );
		#endif
	}

	MAX_PURE_DEFINITION( constexpr inline uint32_t CombinePieces( const uint8_t First8Bits,
	                                                              const uint8_t Second8Bits,
	                                                              const uint8_t Third8Bits,
	                                                              const uint8_t Fourth8Bits ) noexcept )
	{
		auto ExpandedFirst8Bits  = static_cast< uint32_t >( First8Bits );
		auto ExpandedSecond8Bits = static_cast< uint32_t >( Second8Bits );
		auto ExpandedThird8Bits  = static_cast< uint32_t >( Third8Bits );
		auto ExpandedFourth8Bits = static_cast< uint32_t >( Fourth8Bits );

		#if defined( MAX_LITTLE_ENDIAN )
			return static_cast< uint32_t >( ExpandedFirst8Bits | ExpandedSecond8Bits << 8 | ExpandedThird8Bits <<  16 | ExpandedFourth8Bits << 24 );
		#elif defined( MAX_BIG_ENDIAN )
			return static_cast< uint32_t >( ExpandedFirst8Bits << 24 | ExpandedSecond8Bits << 16 | ExpandedThird8Bits << 8 | ExpandedFourth8bits );
		#else
			static_assert( false, "Unknown endianness" );
		#endif
	}

	MAX_PURE_DEFINITION( constexpr inline uint16_t CombinePieces( const uint8_t First8Bits,
	                                                              const uint8_t Second8Bits ) noexcept )
	{
		auto ExpandedFirst8Bits  = static_cast< uint16_t >( First8Bits );
		auto ExpandedSecond8Bits = static_cast< uint16_t >( Second8Bits );

		#if defined( MAX_LITTLE_ENDIAN )
			return static_cast< uint16_t >( ExpandedFirst8Bits | ExpandedSecond8Bits << 8 );
		#elif defined( MAX_BIG_ENDIAN )
			return static_cast< uint16_t >( ExpandedFirst8Bits << 8 | ExpandedSecond8Bits );
		#else
			static_assert( false, "Unknown endianness" );
		#endif
	}

	MAX_PURE_DEFINITION( constexpr inline int64_t CombinePieces( const int8_t First8Bits,
	                                                             const int8_t Second8Bits,
	                                                             const int8_t Third8Bits,
	                                                             const int8_t Fourth8Bits,
	                                                             const int8_t Fifth8Bits,
	                                                             const int8_t Sixth8Bits,
	                                                             const int8_t Seventh8Bits,
	                                                             const int8_t Eighth8Bits ) noexcept )
	{
		return static_cast< int64_t >(
			CombinePieces( static_cast< uint8_t >( First8Bits ), static_cast< uint8_t >( Second8Bits ), static_cast< uint8_t >( Third8Bits ), static_cast< uint8_t >( Fourth8Bits ), static_cast< uint8_t >( Fifth8Bits ), static_cast< uint8_t >( Sixth8Bits ), static_cast< uint8_t >( Seventh8Bits ), static_cast< uint8_t >( Eighth8Bits ) )
		);
	}

	MAX_PURE_DEFINITION( constexpr inline int32_t CombinePieces( const int8_t First8Bits,
	                                                             const int8_t Second8Bits,
	                                                             const int8_t Third8Bits,
	                                                             const int8_t Fourth8Bits) noexcept )
	{
		return static_cast< int32_t >(
			CombinePieces( static_cast< uint8_t >( First8Bits ), static_cast< uint8_t >( Second8Bits ), static_cast< uint8_t >( Third8Bits ), static_cast< uint8_t >( Fourth8Bits ) )
		);
	}

	MAX_PURE_DEFINITION( constexpr inline int16_t CombinePieces( const int8_t First8Bits,
	                                                             const int8_t Second8Bits ) noexcept )
	{
		return static_cast< int16_t >(
			CombinePieces( static_cast< uint8_t >( First8Bits ), static_cast< uint8_t >( Second8Bits ) )
		);
	}

} // namespace Algorithms
} // namespace v0
} // namespace max
