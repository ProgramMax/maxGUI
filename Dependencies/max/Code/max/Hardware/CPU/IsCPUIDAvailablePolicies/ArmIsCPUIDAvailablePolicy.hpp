// Copyright 2019, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_CPUID_ARMISCPUIDAVAILABLEPOLICY_HPP
#define MAX_CPUID_ARMISCPUIDAVAILABLEPOLICY_HPP

namespace max
{
namespace CPU
{

	class ArmIsCPUIDAvailablePolicy
	{
	public:

		static bool IsCPUIDAvailable() noexcept { return true; }

	};

} // namespace CPU
} // namespace max

#endif // #ifndef MAX_CPUID_ARMISCPUIDAVAILABLEPOLICY_HPP
