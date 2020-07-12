// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Usage:
// struct T {};
// static_assert( max::Compiling::IsRegular< T >::value, "T should be a regular type." );

#ifndef MAX_COMPILING_ISREGULAR_HPP
#define MAX_COMPILING_ISREGULAR_HPP

namespace max
{
namespace Compiling
{

namespace Detail
{

	template< typename T >
	std::false_type CheckEqualityComparable( T const & t, long );

	template< typename T >
	auto CheckEqualityComparable( T const & t, int )
		-> typename std::is_convertible< decltype( t == t ), bool >::type;

} // namespace Detail

	template< typename T >
	struct IsEqualityComparable
		: decltype( Detail::CheckEqualityComparable( std::declval< T const & >(), 1 ) )
	{};

	template< typename T >
	struct IsRegular
		: std::integral_constant<
			bool,
			std::is_default_constructible< T >::value &&
			std::is_copy_constructible< T >::value &&
			std::is_move_constructible< T >::value &&
			std::is_copy_assignable< T >::value &&
			std::is_move_assignable< T >::value &&
			IsEqualityComparable< T >::value>
	{};

} // namespace Compiling
} // namespace max

#endif // #ifndef MAX_COMPILING_ISREGULAR_HPP
