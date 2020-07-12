// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Hardware/CPU/IsCPUIDAvailablePolicies/X64GCCAssemblyIsCPUIDAvailablePolicy.hpp>
#include <cstdint>

namespace max
{
namespace CPU
{

	bool X64GCCAssemblyIsCPUIDAvailablePolicy::IsCPUIDAvailable() noexcept
	{
		uint64_t AlteredRFLAGS = UINT64_C( 0 );

		__asm__( R"(
			# Get the current RFLAGS register and set the ID bit

			pushfq                                       # Save the current RFLAGS register onto the stack
			pop    %[AlteredRFLAGS]                      # Put the RFLAGS value in RAX
			mov    %[AlteredRFLAGS],  %%rbx              # Save the value so we can later restore it
			xor    $0x200000,         %[AlteredRFLAGS]   # Set the ID bit
			push   %[AlteredRFLAGS]                      # Put the altered RFLAGS value back onto the stack
			popfq                                        # Restore the altered RFLAGS register


			# Check if the altered RFLAGS register stuck

			pushfq                    # Save the new (possibly altered) RFLAGS register onto the stack
			pop    %[AlteredRFLAGS]   # Put the new RFLAGS value in RAX
			push   %%rbx              # Put the original, unaltered RFLAGS back on the stack
			popfq                     # Put the original, unaltered RFLAGS back into the RFLAGS register
		)"
			: [AlteredRFLAGS] "=r" (AlteredRFLAGS)
			:
			: "rbx" );

		return ( AlteredRFLAGS & 0x200000 ) == 0x200000;
	}

} // namespace CPUID
} // namespace max
