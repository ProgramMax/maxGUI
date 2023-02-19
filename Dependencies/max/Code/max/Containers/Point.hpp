// Copyright 2021, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_CONTAINERS_POINT_HPP
#define MAX_CONTAINERS_POINT_HPP

#include <max/Compiling/CurrentVersionNamespace.hpp>
#include <max/Compiling/AliasingOptimizations.hpp>
#include <initializer_list>
#include <array>
#include <cstddef>

namespace max
{
MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
{
namespace Containers
{

	namespace impl {

		template< typename T, size_t Dimensions >
		class CartesianPointBase {
		public:

			CartesianPointBase() noexcept = default;
			CartesianPointBase( const std::initializer_list< T > & rhs ) noexcept;

			T &       operator []( const size_t Index ) noexcept;
			const T & operator []( const size_t Index ) const noexcept;

			const T *  data() const noexcept;

		protected:

			std::array< T, Dimensions > Elements;

		};

		// Even though this is 1D, a Dimensions template param is used because 1D acts
		// as a base for 2D. When we tell CartesianPointBase what dimensionality to use,
		// it needs to be the final dimensionality, not 1D.
		template< typename T, size_t Dimensions >
		class CartesianPoint1DImpl : public CartesianPointBase< T, Dimensions > {
		public:

			CartesianPoint1DImpl() noexcept = default;
			CartesianPoint1DImpl( const std::initializer_list< T > & rhs ) noexcept;

			T &       X()       noexcept { return this->Elements[0]; }
			const T & X() const noexcept { return this->Elements[0]; }

		};

		template< typename T, size_t Dimensions >
		class CartesianPoint2DImpl : public CartesianPoint1DImpl< T, Dimensions > {
		public:

			CartesianPoint2DImpl() noexcept = default;
			CartesianPoint2DImpl( const std::initializer_list< T > & rhs ) noexcept;

			T &       Y()       noexcept { return this->Elements[1]; }
			const T & Y() const noexcept { return this->Elements[1]; }

		};

		template< typename T, size_t Dimensions >
		class CartesianPoint3DImpl : public CartesianPoint2DImpl< T, Dimensions >
		{
		public:

			CartesianPoint3DImpl() noexcept = default;
			CartesianPoint3DImpl( const std::initializer_list< T > & rhs ) noexcept;

			T &       Z()       noexcept { return this->Elements[2]; }
			const T & Z() const noexcept { return this->Elements[2]; }

		};

	} // namespace impl

	

	template< typename T, size_t Dimensions >
	class CartesianPoint;

	template< typename T >
	class CartesianPoint< T, 1 > : public impl::CartesianPoint1DImpl< T, 1 > {
	public:

		CartesianPoint() noexcept = default;
		CartesianPoint( const std::initializer_list< T > & rhs ) noexcept;

	};

	template< typename T >
	class CartesianPoint< T, 2 > : public impl::CartesianPoint2DImpl< T, 2 > {
	public:

		CartesianPoint() noexcept = default;
		CartesianPoint( const std::initializer_list< T > & rhs ) noexcept;

	};

	template< typename T >
	class CartesianPoint< T, 3 > : public impl::CartesianPoint3DImpl< T, 3 > {
	public:

		CartesianPoint() noexcept = default;
		CartesianPoint( const std::initializer_list< T > & rhs ) noexcept;

	};

	template< typename T, size_t Dimensions >
	class CartesianPoint : public impl::CartesianPoint3DImpl< T, Dimensions > {
	public:

		CartesianPoint() noexcept = default;
		CartesianPoint( const std::initializer_list< T > & rhs ) noexcept;

	};
	

	//template< typename T >
	//MAX_PURE_DECLARATION( CartesianPoint< T, Dimensions > MakeCartesianPoint( T Value, ... ) noexcept );

	template< typename RadiusType, size_t RadiusDimensions, typename AngleType, size_t AngleDimensions >
	class PolarPoint {
	public:

		//PolarPoint() noexcept = default;
		//PolarPoint( const std::initializer_list< T > & rhs ) noexcept;

		RadiusType &       Radius() noexcept;
		const RadiusType & Radius() const noexcept;
		AngleType &        Angle() noexcept;
		const AngleType &  Angle() const noexcept;

	private:

		std::array< RadiusType, RadiusDimensions > Radii;
		std::array< AngleType, AngleDimensions > Angles;

	};

} // namespace Containers
} // MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
MAX_CURRENT_VERSION_NAMESPACE_END( v0 )
} // namespace max

#include "Point.inl"

#endif // #ifndef MAX_CONTAINERS_POINT_HPP
