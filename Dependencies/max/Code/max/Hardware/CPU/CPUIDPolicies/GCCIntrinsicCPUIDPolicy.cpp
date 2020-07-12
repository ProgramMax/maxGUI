// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Hardware/CPU/CPUIDPolicies/GCCIntrinsicCPUIDPolicy.hpp>
#include <cpuid.h>

namespace max
{
namespace CPU
{

	void GCCIntrinsicCPUIDPolicy::CPUID( CPUIDSubleafResult & Registers, uint32_t Leaf ) noexcept
	{
		static_assert( sizeof( uint32_t ) == sizeof( unsigned int ), "GCC's intrinsic requires an unsigned int for the registers" );
		__get_cpuid( Leaf, & Registers.EAX, & Registers.EBX, & Registers.ECX, & Registers.EDX );
	}

	void GCCIntrinsicCPUIDPolicy::CPUIDExtended( CPUIDSubleafResult & Registers, uint32_t Leaf, uint32_t Subleaf ) noexcept
	{
		static_assert( sizeof( uint32_t ) == sizeof( unsigned int ), "VC's intrinsic requires an unsigned int for the registers" );
		__get_cpuid_count( Leaf, Subleaf, & Registers.EAX, & Registers.EBX, & Registers.ECX, & Registers.EDX );
	}

} // namespace CPU
} // namespace max
