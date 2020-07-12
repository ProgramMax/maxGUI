; Copyright 2016, The max Contributors. All rights reserved.
; Use of this source code is governed by a BSD-style license that can be
; found in the LICENSE file.

.code

max_Hardware_CPU_X64AssemblyIsCPUIDAvailablePolicies_IsCPUIDAvailable PROC

	; Get the current rflags register and set the id bit

	pushfq                   ; Save the current rflags register onto the stack
	pop    rax               ; Put the rflags value in rax
	mov    rcx, rax          ; Save the value so we can later restore it
	xor    rax, 0200000h     ; Set the id bit
	push   rax               ; Put the altered rflags value back onto the stack
	popfq                    ; Restore the altered rflags register


	; Check if the altered rflags register stuck

	pushfq                   ; Save the new (possibly altered) rflags register onto the stack
	pop    rax               ; Put the new rflags value in rax
	mov    rdx, rax          ; Store the rflags value
	push   rcx               ; Put the original, unaltered rflags back on the stack
	popfq                    ; Put the original, unaltered rflags back into the rflags register


	; rdx now contains the altered rflags
	; If the alteration stayed, cpuid is supported.
	and   rdx,  0200000h
	cmp   rdx,  0200000h
	je    equal
	xor   rax,  rax
	ret
equal:
	mov   rax,  1
	ret

max_Hardware_CPU_X64AssemblyIsCPUIDAvailablePolicies_IsCPUIDAvailable ENDP

END
