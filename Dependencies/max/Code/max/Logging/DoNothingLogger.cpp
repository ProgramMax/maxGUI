// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "max/Logging/DoNothingLogger.hpp"

namespace max
{
namespace Logging
{

	void DoNothingLogger::LogInfo( const wchar_t * /* Info */ ) noexcept
	{
	}

	void DoNothingLogger::LogDebug( const wchar_t * /* Debug */ ) noexcept
	{
	}

	void DoNothingLogger::LogWarning( const wchar_t * /* Warning */ ) noexcept
	{
	}

	void DoNothingLogger::LogError( const wchar_t * /* Error */ ) noexcept
	{
	}

} // namespace Logging
} // namespace max
