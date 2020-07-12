// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Hardware/CPU/CPUIDSubleafArgumentsAndResult.hpp>
#include <utility>

namespace max
{
namespace CPU
{

	
	CPUIDSubleafArgumentsAndResult::CPUIDSubleafArgumentsAndResult( const uint32_t        Leaf,
	                                                                const uint32_t        Subleaf,
	                                                                CPUIDSubleafResult && Result ) noexcept
		: Leaf(    Leaf                )
		, Subleaf( Subleaf             )
		, Result(  std::move( Result ) )
	{
	}

} // namespace CPU
} // namespace max
