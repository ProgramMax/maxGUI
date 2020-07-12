// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <algorithm>

namespace max
{
namespace v0
{
namespace Containers
{

	// Documentation: Range_ctor.md
	template< typename T >
	MAX_SEMI_PURE_DEFINITION( constexpr Range< T >::Range( const T Minimum, const T Maximum ) MAX_DOES_NOT_THROW )
		: Minimum( Minimum )
		, Maximum( Maximum )
	{
	}

	// Documentation: MakeRange.md
	template< typename T >
	MAX_PURE_DEFINITION( Range< T > MakeRange( const T Value1, const T Value2 ) MAX_DOES_NOT_THROW )
	{
		const T Minimum = std::min( Value1, Value2 );
		const T Maximum = std::max( Value1, Value2 );

		return Range< T >{ Minimum, Maximum };
	}

} // namespaxe Containers
} // namespace v0
} // namespace max
