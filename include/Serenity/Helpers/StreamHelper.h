#pragma once

#include <Serenity/Helpers/PlatformHelper.h>

#include <fstream>
#include <iostream>

namespace serenity {

	namespace helper_stream {

		// iword index allocation set to the colorIndex variable
		static int colorIndex = std::ios_base::xalloc( );

		inline FILE* GetStdStream(const std::ostream& stream)
		{
			if(&stream == &std::cout)
				return stdout;
			else if((&stream == &std::cerr) || (&stream == &std::clog))
				return stderr;

			return nullptr;
		};

		// Basically isatty posix function wrapper for validating output stream included from the <io.h>
		// header
		inline bool isCharDevice(const std::ostream& stream)
		{
			FILE* stdStream = GetStdStream(stream);

			if(!stdStream) {
				return false;
			}

#if defined(SERENITY_MAC) || defined(SERENITY_LINUX)
			return ::isatty(fileno(stdStream));
#elif defined(SERENITY_WINDOWS)
			return ::_isatty(_fileno(stdStream));
#endif
		}

#if defined(SERENITY_WINDOWS)
		inline void windowAttributes(std::ostream& stream, int foreground, int background = -1)
		{
			static WORD defAtr = 0;

			if(!isCharDevice(stream)) { // If Windows, Do Absolutely NADA In This Case
				return;
			}
			HANDLE handle = INVALID_HANDLE_VALUE;
			if(&stream == &std::cout) {
				handle = GetStdHandle(STD_OUTPUT_HANDLE);
			} else if(&stream == &std::cerr) {
				handle = GetStdHandle(STD_ERROR_HANDLE);
			}

			if(!defAtr) {
				CONSOLE_SCREEN_BUFFER_INFO info;
				if(!GetConsoleScreenBufferInfo(handle, &info)) {
					return;
				}
				defAtr = info.wAttributes;
			}

			// Reset Color Attributes
			if(foreground == -1 && background == -1) {
				SetConsoleTextAttribute(handle, defAtr);
				return;
			}

			CONSOLE_SCREEN_BUFFER_INFO info;
			if(!GetConsoleScreenBufferInfo(handle, &info)) {
				return;
			}

			if(foreground != -1) {
				info.wAttributes &= ~(info.wAttributes & 0x0F);
				info.wAttributes |= static_cast<WORD>(foreground);
			}

			if(background != -1) {
				info.wAttributes &= ~(info.wAttributes & 0xF0);
				info.wAttributes |= static_cast<WORD>(background);
			}
			SetConsoleTextAttribute(handle, info.wAttributes);
		};
#endif // Serenity_Windows

		inline bool isColored(std::ostream& stream)
		{
			return isCharDevice(stream) || static_cast<bool>(stream.iword(colorIndex));
		};

		// 'colored' And 'uncolored' Are Used As Flags Here For The isColored() Function To Take Advantage
		// Of Boolean Return Types Rather Than Converting The Index To A Boolean Type And Testing Against
		// That

		// Sets The Stream To Be Colored By Setting The Streams iword Index Flag To A Long 0
		inline void colored(std::ostream& stream)
		{
			stream.iword(colorIndex) = 0L;
		}
		// Sets The Stream To Be UnColored By Setting The Streams iword Index Flag To A Long 1 (Default
		// Behavior)
		inline void uncolored(std::ostream& stream)
		{
			stream.iword(colorIndex) = 1L;
		}

	} // namespace helper_stream

} // namespace serenity
