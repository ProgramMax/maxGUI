// Copyright 2016, The max Contibutors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_CPU_X64GCCASSEMBLYCPUIDPOLICY_HPP
#define MAX_CPU_X64GCCASSEMBLYCPUIDPOLICY_HPP

#include <array>
#include <cstdint>
#include "../CPUIDSubleafResult.hpp"

namespace max
{
namespace CPU
{

	class X64GCCAssemblyCPUIDPolicy
	{
	public:

		static void CPUID(         CPUIDSubleafResult & Registers, uint32_t Leaf )                   noexcept;
		static void CPUIDExtended( CPUIDSubleafResult & Registers, uint32_t Leaf, uint32_t Subleaf ) noexcept;

	};

} // namespace CPU
} // namespace max

#endif // #ifndef MAX_CPU_X64GCCASSEMBLYCPUIDPOLICY_HPP
