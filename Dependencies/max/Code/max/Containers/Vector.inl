// Copyright 2018, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <cmath>

namespace max
{
namespace v0
{
namespace Containers
{

	template< typename T, size_t Dimensions >
	Vector< T, Dimensions >::Vector( const std::initializer_list< T > & rhs ) MAX_DOES_NOT_THROW
		: Elements()
	{
		std::copy( rhs.begin(), rhs.end(), Elements.begin() );
	}

	template< typename T, size_t Dimensions >
	Vector< T, Dimensions > Vector< T, Dimensions >::operator +( const Vector< T, Dimensions > & rhs ) const MAX_DOES_NOT_THROW
	{
		Vector< T, Dimensions > Returning;

		for( size_t i = 0; i < Dimensions; ++i )
		{
			Returning.Elements[ i ] = Elements[ i ] + rhs.Elements[ i ];
		}

		return Returning;
	}

	template< typename T, size_t Dimensions >
	Vector< T, Dimensions > Vector< T, Dimensions >::operator -( const Vector< T, Dimensions > & rhs ) const MAX_DOES_NOT_THROW
	{
		Vector< T, Dimensions > Returning;

		for( size_t i = 0; i < Dimensions; ++i )
		{
			Returning.Elements[ i ] = Elements[ i ] - rhs.Elements[ i ];
		}

		return Returning;
	}

	template< typename T, size_t Dimensions >
	Vector< T, Dimensions > Vector< T, Dimensions >::Cross( const Vector< T, Dimensions > & rhs ) const MAX_DOES_NOT_THROW
	{
		// TODO: This is currently implemented in 3D only
		Vector< T, Dimensions > Returning;

		Returning.Elements[ 0 ] = Elements[ 1 ] * rhs.Elements[ 2 ] - Elements[ 2 ] * rhs.Elements[ 1 ];
		Returning.Elements[ 1 ] = Elements[ 2 ] * rhs.Elements[ 0 ] - Elements[ 0 ] * rhs.Elements[ 2 ];
		Returning.Elements[ 2 ] = Elements[ 0 ] * rhs.Elements[ 1 ] - Elements[ 1 ] * rhs.Elements[ 0 ];

		return Returning;
	}

	template< typename T, size_t Dimensions >
	T Vector< T, Dimensions >::Dot( const Vector< T, Dimensions > & rhs ) const MAX_DOES_NOT_THROW
	{
		T Sum = 0;

		for( size_t i = 0; i < Dimensions; ++i )
		{
			Sum += Elements[ i ] * rhs.Elements[ i ];
		}

		return Sum;
	}

	template< typename T, size_t Dimensions >
	Vector< T, Dimensions > Vector< T, Dimensions >::operator *( const T rhs ) const MAX_DOES_NOT_THROW
	{
		Vector< T, Dimensions > Returning;

		for( size_t i = 0; i < Dimensions; ++i )
		{
			Returning.Elements[ i ] = Elements[ i ] * rhs;
		}

		return Returning;
	}

	template< typename T, size_t Dimensions >
	Vector< T, Dimensions > Vector< T, Dimensions >::operator /( const T rhs ) const MAX_DOES_NOT_THROW
	{
		Vector< T, Dimensions > Returning;

		for( size_t i = 0; i < Dimensions; ++i )
		{
			Returning.Elements[ i ] = Elements[ i ] / rhs;
		}

		return Returning;
	}

	template< typename T, size_t Dimensions >
	T Vector< T, Dimensions >::Length() const MAX_DOES_NOT_THROW
	{
		T Sum = 0;

		for( const T & Element : Elements )
		{
			Sum += Element * Element;
		}

		// TODO: This calls sqrt, which might not be implemented for T.
		return sqrt( Sum );
	}

	template< typename T, size_t Dimensions >
	Vector< T, Dimensions > Vector< T, Dimensions >::Normalize() const MAX_DOES_NOT_THROW
	{
		Vector< T, Dimensions > Returning;

		auto Magnitude = Length();
		auto InverseMagnitude = 1 / Magnitude;

		for( size_t i = 0; i < Dimensions; ++i )
		{
			Returning.Elements[ i ] = Elements[ i ] * InverseMagnitude;
		}

		return Returning;
	}

	template< typename T, size_t Dimensions >
	T & Vector< T, Dimensions >::operator []( const size_t Index ) MAX_DOES_NOT_THROW
	{
		return Elements[ Index ];
	}

	template< typename T, size_t Dimensions >
	const T & Vector< T, Dimensions >::operator []( const size_t Index ) const MAX_DOES_NOT_THROW
	{
		return Elements[ Index ];
	}

	template< typename T, size_t Dimensions >
	const T * Vector< T, Dimensions >::data() const MAX_DOES_NOT_THROW
	{
		return Elements.data();
	}

} // namespace Containers
} // namespace v0
} // namespace max
