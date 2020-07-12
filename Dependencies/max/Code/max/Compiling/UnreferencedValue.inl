// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

namespace max
{
namespace Compiling
{

	template< typename T >
	void UnreferencedValue( const T & Value ) MAX_DOES_NOT_THROW
	{
		(void)Value; // This should get optimized out
	}

} // namespace Compiling
} // namespace max
