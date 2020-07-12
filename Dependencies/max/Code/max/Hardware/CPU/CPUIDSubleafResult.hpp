// Copyright 2016, The max Contibutors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_CPU_CPUIDSUBLEAFRESULT_HPP
#define MAX_CPU_CPUIDSUBLEAFRESULT_HPP


#include <cstdint>

namespace max
{
namespace CPU
{

	struct CPUIDSubleafResult
	{

		uint32_t EAX;
		uint32_t EBX;
		uint32_t ECX;
		uint32_t EDX;

	};

} // namespace CPU
} // namespace max

#endif // #ifndef MAX_CPU_CPUIDSUBLEAFRESULT_HPP
