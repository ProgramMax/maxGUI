// Copyright 2018, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_CONTAINERS_VECTOR_HPP
#define MAX_CONTAINERS_VECTOR_HPP

#include <max/Compiling/CurrentVersionNamespace.hpp>
#include <max/Compiling/AliasingOptimizations.hpp>
#include <max/Compiling/ThrowSpecification.hpp>
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

		Vector() MAX_DOES_NOT_THROW = default;
		Vector( const std::initializer_list< T > & rhs ) MAX_DOES_NOT_THROW;
		Vector( const Vector< T, Dimensions > & rhs ) MAX_DOES_NOT_THROW = default;
		Vector( Vector< T, Dimensions > && rhs ) MAX_DOES_NOT_THROW = default;
		~Vector() MAX_DOES_NOT_THROW = default;

		Vector< T, Dimensions > & operator =( const Vector< T, Dimensions > & rhs ) MAX_DOES_NOT_THROW = default;
		Vector< T, Dimensions > & operator =( Vector< T, Dimensions > && rhs ) MAX_DOES_NOT_THROW = default;

		Vector< T, Dimensions > operator +( const Vector< T, Dimensions > & rhs ) const MAX_DOES_NOT_THROW;
		Vector< T, Dimensions > operator -( const Vector< T, Dimensions > & rhs ) const MAX_DOES_NOT_THROW;
		Vector< T, Dimensions > Cross     ( const Vector< T, Dimensions > & rhs ) const MAX_DOES_NOT_THROW;
		T                       Dot       ( const Vector< T, Dimensions > & rhs ) const MAX_DOES_NOT_THROW;
		Vector< T, Dimensions > operator *( const T rhs ) const MAX_DOES_NOT_THROW;
		Vector< T, Dimensions > operator /( const T rhs ) const MAX_DOES_NOT_THROW;

		T                       Length()    const MAX_DOES_NOT_THROW;
		Vector< T, Dimensions > Normalize() const MAX_DOES_NOT_THROW;

		T &       operator []( const size_t Index ) MAX_DOES_NOT_THROW;
		const T & operator []( const size_t Index ) const MAX_DOES_NOT_THROW;

		const T *  data() const MAX_DOES_NOT_THROW;

	private:

		std::array< T, Dimensions > Elements;

	};

} // namespace Containers
} // MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
MAX_CURRENT_VERSION_NAMESPACE_END( v0 )
} // namespace max

#include "Vector.inl"

#endif // #ifndef MAX_CONTAINERS_VECTOR_HPP
