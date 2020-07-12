// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Hardware/CPU/TraceCache.hpp>

namespace max
{
namespace CPU
{

	TraceCache::TraceCache( const uint32_t        SizeInMicroOperations,
	                        const Associativity & AssociativityInfo    ) noexcept
		: CacheInfo(             CacheInfoType::TraceCache )
		, SizeInMicroOperations( SizeInMicroOperations     )
		, AssociativityInfo(     AssociativityInfo         )
	{
	}

} // namespace CPU
} // namespace max
