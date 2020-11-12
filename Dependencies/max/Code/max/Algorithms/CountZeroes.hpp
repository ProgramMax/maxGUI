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

			#if defined( MAX_CONSTEVAL_SUPPORTED )
				#define MAX_BITSCAN_CONSTEVAL consteval
			#else
				// consteval means the expression should only be evaluated at compile-time.
				// constexpr means it can either be compile-time or run-time.
				// constexpr is not what we actually want. But if consteval isn't supported, it is the only way to
				// evaluate something at compile-time.
				#define MAX_BITSCAN_CONSTEVAL constexpr
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

			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint64_t CountTrailingZeroesCompileTime( const uint64_t Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint32_t CountTrailingZeroesCompileTime( const uint32_t Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint16_t CountTrailingZeroesCompileTime( const uint16_t Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t  CountTrailingZeroesCompileTime( const uint8_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline int64_t  CountTrailingZeroesCompileTime( const int64_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline int32_t  CountTrailingZeroesCompileTime( const int32_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline int16_t  CountTrailingZeroesCompileTime( const int16_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline int8_t   CountTrailingZeroesCompileTime( const int8_t   Value ) noexcept );

			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint64_t CountLeadingZeroesCompileTime( const uint64_t Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint32_t CountLeadingZeroesCompileTime( const uint32_t Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint16_t CountLeadingZeroesCompileTime( const uint16_t Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t  CountLeadingZeroesCompileTime( const uint8_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline int64_t  CountLeadingZeroesCompileTime( const int64_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline int32_t  CountLeadingZeroesCompileTime( const int32_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline int16_t  CountLeadingZeroesCompileTime( const int16_t  Value ) noexcept );
			MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline int8_t   CountLeadingZeroesCompileTime( const int8_t   Value ) noexcept );

		} // namespace Algorithms
	} // MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
	MAX_CURRENT_VERSION_NAMESPACE_END(v0)
} // namespace max

#include <max/Algorithms/CountZeroes.inl>

#endif // #ifndef MAX_ALGORITHMS_COUNTZEROES_HPP
