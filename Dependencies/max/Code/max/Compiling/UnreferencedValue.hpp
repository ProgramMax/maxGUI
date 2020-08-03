// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_COMPILING_UNREFERENCEDVALUE_HPP
#define MAX_COMPILING_UNREFERENCEDVALUE_HPP

namespace max
{
namespace Compiling
{

	template< typename T >
	void UnreferencedValue( const T & Value ) noexcept;

} // namespace Compiling
} // namespace max

#include <max/Compiling/UnreferencedValue.inl>

#endif // #ifndef MAX_COMPILING_UNREFERENCEDVALUE_HPP
