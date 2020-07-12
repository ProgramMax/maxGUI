// Copyright 2019, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Hardware/CPU/CPUIDPolicies/AArch64CPUIDPolicy.hpp>

namespace max
{
namespace CPU
{

	void AArch64CPUIDPolicy::CPUID( CPUIDSubleafResult & /*Registers*/, uint32_t /*Leaf*/ ) noexcept
	{
	}

	void AArch64CPUIDPolicy::CPUIDExtended( CPUIDSubleafResult & /*Registers*/, uint32_t /*Leaf*/, uint32_t /*Subleaf*/ ) noexcept
	{
	}

} // namespace CPU
} // namespace max
