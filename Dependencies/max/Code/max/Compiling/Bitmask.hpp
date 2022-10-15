// Copyright 2020, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_COMPILING_BITMASK_HPP
#define MAX_COMPILING_BITMASK_HPP

#include <type_traits>

namespace max
{
	namespace Compiling
	{
		template< typename EnumClassType >
		struct BitmaskableEnumClass
		{
			static const bool Bitmaskable = false;
		};

		template< typename EnumClassType >
		constexpr bool bitmaskable_enum_class_v = BitmaskableEnumClass< EnumClassType >::Bitmaskable;

#define MAX_BITMASKABLE_ENUM_CLASS( EnumClassType )          \
	template<>                                                   \
	struct max::Compiling::BitmaskableEnumClass< EnumClassType > \
	{                                                            \
		static const bool Bitmaskable = true;                      \
	}

	} // namespace Compiling
} // namespace max

template< typename EnumClassType >
typename std::enable_if< max::Compiling::BitmaskableEnumClass< EnumClassType >::Bitmaskable, EnumClassType >::type
operator |( EnumClassType lhs, EnumClassType rhs )
{
	using UnderlyingType = typename std::underlying_type< EnumClassType >::type;

	return static_cast< EnumClassType > (
		static_cast< UnderlyingType >( lhs ) |
		static_cast< UnderlyingType >( rhs )
		);
}

template< typename EnumClassType >
typename std::enable_if< max::Compiling::BitmaskableEnumClass< EnumClassType >::Bitmaskable, EnumClassType >::type
operator &( EnumClassType lhs, EnumClassType rhs )
{
	using UnderlyingType = typename std::underlying_type< EnumClassType >::type;

	return static_cast< EnumClassType > (
		static_cast< UnderlyingType >( lhs ) &
		static_cast< UnderlyingType >( rhs )
		);
}

template< typename EnumClassType >
typename std::enable_if< max::Compiling::BitmaskableEnumClass< EnumClassType >::Bitmaskable, EnumClassType >::type
operator ^( EnumClassType lhs, EnumClassType rhs )
{
	using UnderlyingType = typename std::underlying_type< EnumClassType >::type;

	return static_cast< EnumClassType > (
		static_cast< UnderlyingType >( lhs ) ^
		static_cast< UnderlyingType >( rhs )
		);
}

template< typename EnumClassType >
typename std::enable_if< max::Compiling::BitmaskableEnumClass< EnumClassType >::Bitmaskable, EnumClassType >::type
operator ~( EnumClassType Value )
{
	using UnderlyingType = typename std::underlying_type< EnumClassType >::type;

	return static_cast< EnumClassType > ( ~static_cast< UnderlyingType >( Value ) );
}

template< typename EnumClassType >
typename std::enable_if< max::Compiling::BitmaskableEnumClass< EnumClassType >::Bitmaskable, EnumClassType & >::type
operator |=( EnumClassType & lhs, EnumClassType rhs )
{
	using UnderlyingType = typename std::underlying_type< EnumClassType >::type;

	lhs = static_cast< EnumClassType > (
		static_cast< UnderlyingType >( lhs ) |
		static_cast< UnderlyingType >( rhs )
		);

	return lhs;
}

template< typename EnumClassType >
typename std::enable_if< max::Compiling::BitmaskableEnumClass< EnumClassType & >::Bitmaskable, EnumClassType & >::type
operator &=( EnumClassType & lhs, EnumClassType rhs )
{
	using UnderlyingType = typename std::underlying_type< EnumClassType >::type;

	lhs = static_cast< EnumClassType > (
		static_cast< UnderlyingType >( lhs ) &
		static_cast< UnderlyingType >( rhs )
		);

	return lhs;
}

template< typename EnumClassType >
typename std::enable_if< max::Compiling::BitmaskableEnumClass< EnumClassType >::Bitmaskable, EnumClassType & >::type
operator ^=( EnumClassType & lhs, EnumClassType rhs )
{
	using UnderlyingType = typename std::underlying_type< EnumClassType >::type;

	lhs = static_cast< EnumClassType > (
		static_cast< UnderlyingType >( lhs ) ^
		static_cast< UnderlyingType >( rhs )
		);

	return lhs;
}

#endif // #ifndef MAX_COMPILING_BITMASK_HPP