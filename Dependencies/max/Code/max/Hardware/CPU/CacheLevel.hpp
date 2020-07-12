// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_CPU_CACHELEVEL_HPP
#define MAX_CPU_CACHELEVEL_HPP

#include "CacheInfo.hpp"
#include <cstdint>
#include "Associativity.hpp"

namespace max
{
namespace CPU
{

	class CacheLevel : public CacheInfo
	{
	public:

		CacheLevel( const uint32_t           Level,
		            const CacheContentType   ContentType,
		            const uint32_t           SizeInBytes,
		            const Associativity &    AssociativityInfo,
		            const uint32_t           CacheLineSizeInBytes,
		            const uint32_t           CacheLinesPerSector   ) noexcept;
		CacheLevel()                                      noexcept = delete;
		CacheLevel( const CacheLevel & rhs )              noexcept = default;
		CacheLevel( CacheLevel && rhs )                   noexcept = default;
		~CacheLevel()                                     noexcept = default;

		CacheLevel & operator =( const CacheLevel & rhs ) noexcept = default;
		CacheLevel & operator =( CacheLevel && rhs )      noexcept = default;

		CacheContentType   ContentType;
		uint32_t           Level;
		uint32_t           SizeInBytes;
		Associativity      AssociativityInfo;
		uint32_t           CacheLineSizeInBytes;
		uint32_t           CacheLinesPerSector;

	};

} // namespace CPU
} // namespace max

#endif // #ifndef MAX_CPU_CACHELEVEL_HPP
