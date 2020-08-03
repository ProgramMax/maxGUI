// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_LOGGING_DONOTHINGLOGGER_HPP
#define MAX_LOGGING_DONOTHINGLOGGER_HPP

namespace max
{
namespace Logging
{

	class DoNothingLogger
	{
	public:

		void LogInfo(    const wchar_t * Info    ) noexcept;
		void LogDebug(   const wchar_t * Debug   ) noexcept;
		void LogWarning( const wchar_t * Warning ) noexcept;
		void LogError(   const wchar_t * Error   ) noexcept;

	};

} // namespace Logging
} // namespace max

#endif
