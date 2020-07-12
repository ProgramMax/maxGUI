// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_LOGGING_DONOTHINGLOGGER_HPP
#define MAX_LOGGING_DONOTHINGLOGGER_HPP

#include <max/Compiling/ThrowSpecification.hpp>

namespace max
{
namespace Logging
{

	class DoNothingLogger
	{
	public:

		void LogInfo(    const wchar_t * Info    ) MAX_DOES_NOT_THROW;
		void LogDebug(   const wchar_t * Debug   ) MAX_DOES_NOT_THROW;
		void LogWarning( const wchar_t * Warning ) MAX_DOES_NOT_THROW;
		void LogError(   const wchar_t * Error   ) MAX_DOES_NOT_THROW;

	};

} // namespace Logging
} // namespace max

#endif
