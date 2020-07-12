// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Hardware/CPU/CacheLevel.hpp>

namespace max
{
namespace CPU
{

	CacheLevel::CacheLevel( const uint32_t           Level,
	                        const CacheContentType   ContentType,
	                        const uint32_t           SizeInBytes,
	                        const Associativity &    AssociativityInfo,
	                        const uint32_t           CacheLineSizeInBytes,
	                        const uint32_t           CacheLinesPerSector   ) noexcept
		: CacheInfo(            CacheInfoType::CacheLevel )
		, ContentType(          ContentType               )
		, Level(                Level                     )
		, SizeInBytes(          SizeInBytes               )
		, AssociativityInfo(    AssociativityInfo         )
		, CacheLineSizeInBytes( CacheLineSizeInBytes      )
		, CacheLinesPerSector(  CacheLinesPerSector       )
	{
	}

} // namespace CPU
} // namespace max
