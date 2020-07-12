// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Hardware/CPU/Prefetch.hpp>

namespace max
{
namespace CPU
{

	Prefetch::Prefetch( const uint32_t SizeInBytes ) noexcept
		: CacheInfo(   CacheInfoType::Prefetch )
		, SizeInBytes( SizeInBytes             )
	{
	}

} // namespace CPU
} // namespace max
