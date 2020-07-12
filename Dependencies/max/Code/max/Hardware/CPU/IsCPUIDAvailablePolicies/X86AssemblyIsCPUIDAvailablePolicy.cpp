// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Hardware/CPU/IsCPUIDAvailablePolicies/X86AssemblyIsCPUIDAvailablePolicy.hpp>
#include <cstdint>

namespace max
{
namespace CPU
{

	bool X86AssemblyIsCPUIDAvailablePolicy::IsCPUIDAvailable() noexcept
	{
		uint32_t AlteredEFLAGS = UINT32_C( 0 );

		__asm {
			; Get the current EFLAGS register and set the ID bit

			pushfd                   ; Save the current EFLAGS register onto the stack
			pop    eax               ; Put the EFLAGS value in EAX
			mov    ebx, eax          ; Save the value so we can later restore it
			xor    eax, 0x200000     ; Set the ID bit
			push   eax               ; Put the altered EFLAGS value back onto the stack
			popfd                    ; Restore the altered EFLAGS register

			; Check if the altered EFLAGS register stuck

			pushfd                    ; Save the new (possibly altered) EFLAGS register onto the stack
			pop    eax                ; Put the new EFLAGS value in EAX
			mov    AlteredEFLAGS, eax ; Store the EFLAGS value in our C++ variable
			push   ebx                ; Put the original, unaltered EFLAGS back on the stack
			popfd                     ; Put the original, unaltered EFLAGS back into the EFLAGS register
		}

		return ( AlteredEFLAGS & 0x200000 ) == 0x200000;
	}

} // namespace CPUID
} // namespace max
