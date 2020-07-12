// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_ALGORITHMS_MATH_HPP
#define MAX_ALGORITHMS_MATH_HPP


#include <max/Compiling/CurrentVersionNamespace.hpp>
#include <max/Compiling/AliasingOptimizations.hpp>
#include <max/Containers/Range.hpp>
#include <max/Compiling/ThrowSpecification.hpp>

namespace max
{	
MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
{
namespace Algorithms
{

	template< typename T >
	MAX_PURE_DECLARATION( constexpr T TwoToThePowerOf( const T Exponent ) MAX_DOES_NOT_THROW );

} // namespace Algorithms
} // MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
MAX_CURRENT_VERSION_NAMESPACE_END( v0 )
} // namespace max

#include <max/Algorithms/Math.inl>

#endif // #ifndef MAX_ALGORITHMS_MATH_HPP
