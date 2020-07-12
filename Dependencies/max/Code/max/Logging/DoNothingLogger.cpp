// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "max/Logging/DoNothingLogger.hpp"

namespace max
{
namespace Logging
{

	void DoNothingLogger::LogInfo( const wchar_t * /* Info */ ) MAX_DOES_NOT_THROW
	{
	}

	void DoNothingLogger::LogDebug( const wchar_t * /* Debug */ ) MAX_DOES_NOT_THROW
	{
	}

	void DoNothingLogger::LogWarning( const wchar_t * /* Warning */ ) MAX_DOES_NOT_THROW
	{
	}

	void DoNothingLogger::LogError( const wchar_t * /* Error */ ) MAX_DOES_NOT_THROW
	{
	}

} // namespace Logging
} // namespace max
