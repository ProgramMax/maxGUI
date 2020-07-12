// Copyright 2019, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ConfigurationTest.hpp"
#include <max/Compiling/Configuration.hpp>
#include <max/Compiling/Macros.hpp>

namespace maxManualTests
{
	namespace Compiling
	{

		void RunConfigurationTestSuite()
		{
			MAX_COMPILER_MESSAGE("MAX_MESSAGE works");
			MAX_COMPILER_MESSAGE("And you can include other defines like __LINE__: " MAX_EXPAND_AND_STRINGIFY(__LINE__));
		}

	} // namespace Compiling
} // namespace maxManualTests
