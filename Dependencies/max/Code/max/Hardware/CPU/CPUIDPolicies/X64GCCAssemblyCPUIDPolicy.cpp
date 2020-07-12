// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Hardware/CPU/CPUIDPolicies/X64GCCAssemblyCPUIDPolicy.hpp>

namespace max
{
namespace CPU
{

	void X64GCCAssemblyCPUIDPolicy::CPUID( CPUIDSubleafResult & Registers, uint32_t Leaf ) noexcept
	{
		__asm__( R"(
			cpuid
		)"
			: "=a"( Registers.EAX ),
			  "=b"( Registers.EBX ),
			  "=c"( Registers.ECX ),
			  "=d"( Registers.EDX )
			: "a"( Leaf ),
			  "c"( 0 )
			: );
	}

	void X64GCCAssemblyCPUIDPolicy::CPUIDExtended( CPUIDSubleafResult & Registers, uint32_t Leaf, uint32_t Subleaf ) noexcept
	{
		__asm__( R"(
			cpuid
		)"
			: "=a"( Registers.EAX ),
			  "=b"( Registers.EBX ),
			  "=c"( Registers.ECX ),
			  "=d"( Registers.EDX )
			: "a"( Leaf ),
			  "c"( Subleaf )
			: );
	}

} // namespace CPU
} // namespace max
