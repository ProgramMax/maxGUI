// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

namespace max
{
namespace v0
{
namespace Algorithms
{

	template< typename T >
	MAX_PURE_DEFINITION( constexpr inline T TwoToThePowerOf( const T Exponent ) MAX_DOES_NOT_THROW )
	{
		return 1u << Exponent;
	}

} // namespace Algorithms
} // namespace v0
} // namespace max
