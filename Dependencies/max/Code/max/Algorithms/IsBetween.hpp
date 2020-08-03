// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_ALGORITHMS_ISBETWEEN_HPP
#define MAX_ALGORITHMS_ISBETWEEN_HPP


#include <max/Compiling/CurrentVersionNamespace.hpp>
#include <max/Compiling/AliasingOptimizations.hpp>
#include <max/Containers/Range.hpp>

namespace max
{	
MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
{
namespace Algorithms
{

	// Documentation: IsBetween.md
	template< typename T >
	MAX_PURE_DECLARATION( constexpr bool IsBetween( const T Value, const max::Containers::Range< T > & Range ) noexcept );

} // namespace Algorithms
} // MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
MAX_CURRENT_VERSION_NAMESPACE_END( v0 )
} // namespace max

#include <max/Algorithms/IsBetween.inl>

#endif // #ifndef MAX_ALGORITHMS_ISBETWEEN_HPP
