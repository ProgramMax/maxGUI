// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Compiling/AliasingOptimizationsTest.hpp>
#include <max/Compiling/ConfigurationTest.hpp>

int main()
{

	maxManualTests::Compiling::RunAliasingOptimizationsTestSuite();
	maxManualTests::Compiling::RunConfigurationTestSuite();

	return 0;
}
