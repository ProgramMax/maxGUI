// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_CONTAINERS_RANGE_HPP
#define MAX_CONTAINERS_RANGE_HPP

// Documentaiton: Range.md

#include <max/Compiling/CurrentVersionNamespace.hpp>
#include <max/Compiling/AliasingOptimizations.hpp>
#include <max/Compiling/ThrowSpecification.hpp>

namespace max
{
MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
{
namespace Containers
{

	template< typename T >
	class Range
	{
	public:

		// Documentation: Range_ctor.md
		MAX_SEMI_PURE_DECLARATION( constexpr Range( const T Minimum, const T Maximum ) MAX_DOES_NOT_THROW );

		T Minimum;
		T Maximum;

	};

	// Documentation: MakeRange.md
	template< typename T >
	MAX_PURE_DECLARATION( Range< T > MakeRange( const T Value1, const T Value2 ) MAX_DOES_NOT_THROW );

} // namespace Containers
} // MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
MAX_CURRENT_VERSION_NAMESPACE_END( v0 )
} // namespace max

#include "Range.inl"

#endif // #ifndef MAX_CONTAINERS_RANGE_HPP
