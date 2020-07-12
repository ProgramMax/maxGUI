// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_CPU_PREFETCH_HPP
#define MAX_CPU_PREFETCH_HPP

#include "CacheInfo.hpp"
#include <cstdint>

namespace max
{
namespace CPU
{

	class Prefetch : public CacheInfo
	{
	public:

		explicit Prefetch( const uint32_t SizeInBytes ) noexcept;
		Prefetch()                                      noexcept = delete;
		Prefetch( const Prefetch & rhs )                noexcept = default;
		Prefetch( Prefetch && rhs )                     noexcept = default;
		~Prefetch()                                     noexcept = default;

		Prefetch & operator =( const Prefetch & rhs )   noexcept = default;
		Prefetch & operator =( Prefetch && rhs )        noexcept = default;

		uint32_t SizeInBytes;

	};

} // namespace CPU
} // namespace max

#endif // #ifndef MAX_CPU_PREFETCH_HPP
