// Copyright 2018, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_CONTAINERS_VECTOR_HPP
#define MAX_CONTAINERS_VECTOR_HPP

#include <max/Compiling/CurrentVersionNamespace.hpp>
#include <max/Compiling/AliasingOptimizations.hpp>
#include <initializer_list>
#include <array>

namespace max
{
MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
{
namespace Containers
{

	template< typename T, size_t Dimensions >
	class Vector
	{
	public:

		Vector() noexcept = default;
		Vector( const std::initializer_list< T > & rhs ) noexcept;
		Vector( const Vector< T, Dimensions > & rhs ) noexcept = default;
		Vector( Vector< T, Dimensions > && rhs ) noexcept = default;
		~Vector() noexcept = default;

		Vector< T, Dimensions > & operator =( const Vector< T, Dimensions > & rhs ) noexcept = default;
		Vector< T, Dimensions > & operator =( Vector< T, Dimensions > && rhs ) noexcept = default;

		Vector< T, Dimensions > operator +( const Vector< T, Dimensions > & rhs ) const noexcept;
		Vector< T, Dimensions > operator -( const Vector< T, Dimensions > & rhs ) const noexcept;
		Vector< T, Dimensions > Cross     ( const Vector< T, Dimensions > & rhs ) const noexcept;
		T                       Dot       ( const Vector< T, Dimensions > & rhs ) const noexcept;
		Vector< T, Dimensions > operator *( const T rhs ) const noexcept;
		Vector< T, Dimensions > operator /( const T rhs ) const noexcept;

		T                       Length()    const noexcept;
		Vector< T, Dimensions > Normalize() const noexcept;

		T &       operator []( const size_t Index ) noexcept;
		const T & operator []( const size_t Index ) const noexcept;

		const T *  data() const noexcept;

	private:

		std::array< T, Dimensions > Elements;

	};

} // namespace Containers
} // MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
MAX_CURRENT_VERSION_NAMESPACE_END( v0 )
} // namespace max

#include "Vector.inl"

#endif // #ifndef MAX_CONTAINERS_VECTOR_HPP
