// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_CPU_TRACECACHE_HPP
#define MAX_CPU_TRACECACHE_HPP

#include "CacheInfo.hpp"
#include <cstdint>
#include "Associativity.hpp"

namespace max
{
namespace CPU
{

	class TraceCache : public CacheInfo
	{
	public:

		TraceCache( const uint32_t        SizeInMicroOperations,
		            const Associativity & AssociativityInfo    ) noexcept;
		TraceCache()                                             noexcept = delete;
		TraceCache( const TraceCache & rhs )                     noexcept = default;
		TraceCache( TraceCache && rhs )                          noexcept = default;
		~TraceCache()                                            noexcept = default;

		TraceCache & operator =( const TraceCache & rhs )        noexcept = default;
		TraceCache & operator =( TraceCache && rhs )             noexcept = default;

		uint32_t      SizeInMicroOperations;
		Associativity AssociativityInfo;

	};

} // namespace CPU
} // namespace max

#endif // #ifndef MAX_CPU_TRACECACHE_HPP
