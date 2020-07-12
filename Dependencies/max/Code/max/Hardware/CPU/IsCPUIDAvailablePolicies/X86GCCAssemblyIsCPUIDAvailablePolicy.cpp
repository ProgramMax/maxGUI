// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Hardware/CPU/IsCPUIDAvailablePolicies/X86GCCAssemblyIsCPUIDAvailablePolicy.hpp>
#include <cstdint>

namespace max
{
namespace CPU
{

	bool X86GCCAssemblyIsCPUIDAvailablePolicy::IsCPUIDAvailable() noexcept
	{
		uint32_t AlteredEFLAGS = UINT32_C( 0 );

		__asm__( R"(
			# Get the current EFLAGS register and set the ID bit

			pushfl                                       # Save the current EFLAGS register onto the stack
			pop    %[AlteredEFLAGS]                      # Put the EFLAGS value in EAX
			mov    %[AlteredEFLAGS],  %%ebx              # Save the value so we can later restore it
			xor    $0x200000,         %[AlteredEFLAGS]   # Set the ID bit
			push   %[AlteredEFLAGS]                      # Put the altered EFLAGS value back onto the stack
			popfl                                        # Restore the altered EFLAGS register


			# Check if the altered EFLAGS register stuck

			pushfl                    # Save the new (possibly altered) EFLAGS register onto the stack
			pop    %[AlteredEFLAGS]   # Put the new EFLAGS value in EAX
			push   %%ebx              # Put the original, unaltered EFLAGS back on the stack
			popfl                     # Put the original, unaltered EFLAGS back into the EFLAGS register
		)"
			: [AlteredEFLAGS] "=r" (AlteredEFLAGS)
			:
			: "%ebx" );

		return ( AlteredEFLAGS & 0x200000 ) == 0x200000;
	}

} // namespace CPUID
} // namespace max
