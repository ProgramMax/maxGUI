// Copyright 2020, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_ALGORITHMS_COUNTZEROES_HPP
#define MAX_ALGORITHMS_COUNTZEROES_HPP

#include <max/Compiling/Configuration.hpp>
#include <max/Compiling/CurrentVersionNamespace.hpp>
#include <max/Compiling/AliasingOptimizations.hpp>
#include <cstdint>

namespace max
{
	MAX_CURRENT_VERSION_NAMESPACE_BEGIN(v0)
	{
		namespace Algorithms
		{

			#if defined( MAX_INTRINSICS_ALLOWED_INSIDE_CONSTEXPR )
				#define MAX_BITSCAN_CONSTEXPR constexpr
			#else
				#define MAX_BITSCAN_CONSTEXPR
			#endif

			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline uint64_t CountTrailingZeroes( const uint64_t Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline uint32_t CountTrailingZeroes( const uint32_t Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline uint16_t CountTrailingZeroes( const uint16_t Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline uint8_t  CountTrailingZeroes( const uint8_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline int64_t  CountTrailingZeroes( const int64_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline int32_t  CountTrailingZeroes( const int32_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline int16_t  CountTrailingZeroes( const int16_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline int8_t   CountTrailingZeroes( const int8_t   Value ) noexcept );

			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline uint64_t CountLeadingZeroes( const uint64_t Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline uint32_t CountLeadingZeroes( const uint32_t Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline uint16_t CountLeadingZeroes( const uint16_t Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline uint8_t  CountLeadingZeroes( const uint8_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline int64_t  CountLeadingZeroes( const int64_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline int32_t  CountLeadingZeroes( const int32_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline int16_t  CountLeadingZeroes( const int16_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEXPR inline int8_t   CountLeadingZeroes( const int8_t   Value ) noexcept );

			MAX_PURE_DECLARATION( constexpr inline uint64_t CountTrailingZeroesConstexpr( const uint64_t Value ) noexcept );
			MAX_PURE_DECLARATION( constexpr inline uint32_t CountTrailingZeroesConstexpr( const uint32_t Value ) noexcept );
			MAX_PURE_DECLARATION( constexpr inline uint16_t CountTrailingZeroesConstexpr( const uint16_t Value ) noexcept );
			MAX_PURE_DECLARATION( constexpr inline uint8_t  CountTrailingZeroesConstexpr( const uint8_t  Value ) noexcept );
			MAX_PURE_DECLARATION( constexpr inline int64_t  CountTrailingZeroesConstexpr( const int64_t  Value ) noexcept );
			MAX_PURE_DECLARATION( constexpr inline int32_t  CountTrailingZeroesConstexpr( const int32_t  Value ) noexcept );
			MAX_PURE_DECLARATION( constexpr inline int16_t  CountTrailingZeroesConstexpr( const int16_t  Value ) noexcept );
			MAX_PURE_DECLARATION( constexpr inline int8_t   CountTrailingZeroesConstexpr( const int8_t   Value ) noexcept );

			MAX_PURE_DECLARATION( constexpr inline uint64_t CountLeadingZeroesConstexpr( const uint64_t Value ) noexcept );
			MAX_PURE_DECLARATION( constexpr inline uint32_t CountLeadingZeroesConstexpr( const uint32_t Value ) noexcept );
			MAX_PURE_DECLARATION( constexpr inline uint16_t CountLeadingZeroesConstexpr( const uint16_t Value ) noexcept );
			MAX_PURE_DECLARATION( constexpr inline uint8_t  CountLeadingZeroesConstexpr( const uint8_t  Value ) noexcept );
			MAX_PURE_DECLARATION( constexpr inline int64_t  CountLeadingZeroesConstexpr( const int64_t  Value ) noexcept );
			MAX_PURE_DECLARATION( constexpr inline int32_t  CountLeadingZeroesConstexpr( const int32_t  Value ) noexcept );
			MAX_PURE_DECLARATION( constexpr inline int16_t  CountLeadingZeroesConstexpr( const int16_t  Value ) noexcept );
			MAX_PURE_DECLARATION( constexpr inline int8_t   CountLeadingZeroesConstexpr( const int8_t   Value ) noexcept );

		} // namespace Algorithms
	} // MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
	MAX_CURRENT_VERSION_NAMESPACE_END(v0)
} // namespace max

#include <max/Algorithms/CountZeroes.inl>

#endif // #ifndef MAX_ALGORITHMS_COUNTZEROES_HPP
