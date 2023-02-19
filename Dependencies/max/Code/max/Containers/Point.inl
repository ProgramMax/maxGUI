// Copyright 2021, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <algorithm>

namespace max
{
namespace v0
{
namespace Containers
{

	namespace impl
	{

		template< typename T, size_t Dimensions >
		CartesianPointBase< T, Dimensions >::CartesianPointBase( const std::initializer_list< T > & rhs ) noexcept
			: Elements()
		{
			// TODO: Check bounds
			std::copy( rhs.begin(), rhs.end(), Elements.begin() );
		}

		template< typename T, size_t Dimensions >
		T & CartesianPointBase< T, Dimensions >::operator []( const size_t Index ) noexcept
		{
			return Elements[ Index ];
		}

		template< typename T, size_t Dimensions >
		const T & CartesianPointBase< T, Dimensions >::operator []( const size_t Index ) const noexcept
		{
			return Elements[ Index ];
		}

		template< typename T, size_t Dimensions >
		const T * CartesianPointBase< T, Dimensions >::data() const noexcept
		{
			return Elements.data();
		}

		template< typename T, size_t Dimensions >
		CartesianPoint1DImpl< T, Dimensions >::CartesianPoint1DImpl( const std::initializer_list< T > & rhs ) noexcept
			: CartesianPointBase< T, Dimensions >( rhs )
		{}

		template< typename T, size_t Dimensions >
		CartesianPoint2DImpl< T, Dimensions >::CartesianPoint2DImpl( const std::initializer_list< T > & rhs ) noexcept
			: CartesianPoint1DImpl< T, Dimensions >( rhs )
		{}

		template< typename T, size_t Dimensions >
		CartesianPoint3DImpl< T, Dimensions >::CartesianPoint3DImpl( const std::initializer_list< T > & rhs ) noexcept
			: CartesianPoint2DImpl< T, Dimensions >( rhs )
		{}

	} // namespace impl

	template< typename T >
	CartesianPoint< T, 1 >::CartesianPoint( const std::initializer_list< T > & rhs ) noexcept
		: impl::CartesianPoint1DImpl< T, 1 >( rhs )
	{}

	template< typename T >
	CartesianPoint< T, 2 >::CartesianPoint( const std::initializer_list< T > & rhs ) noexcept
		: impl::CartesianPoint2DImpl< T, 2 >{ rhs }
	{}

	template< typename T >
	CartesianPoint< T, 3 >::CartesianPoint( const std::initializer_list< T > & rhs ) noexcept
		: impl::CartesianPoint3DImpl< T, 3 >( rhs )
	{}

	template< typename T, size_t Dimensions >
	CartesianPoint< T, Dimensions >::CartesianPoint( const std::initializer_list< T > & rhs ) noexcept
		: impl::CartesianPoint3DImpl< T, Dimensions >( rhs )
	{}

} // namespace Containers
} // namespace v0
} // namespace max
