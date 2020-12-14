#pragma once

#include <iostream>
#include <map> // IWYU pragma: keep

#include <Serenity/Helpers/PlatformHelper.h>

constexpr int SERENITY_TRACE    = 0;
constexpr int SERENITY_INFO     = 1;
constexpr int SERENITY_WARNING  = 2;
constexpr int SERENITY_DEBUG    = 3;
constexpr int SERENITY_ERROR    = 4;
constexpr int SERENITY_FATAL    = 5;
constexpr int SERENITY_DISABLED = 6;

constexpr int LOG_TO_CONSOLE = 0;
constexpr int LOG_TO_FILE    = 1;
constexpr int LOG_TO_ALL     = 2;
constexpr int LOG_TO_NONE    = 3;

namespace serenity {

	namespace details {

		namespace logger {
			//? With All The Calls To Output Stream, Might Be Beneficial To Make Some Sort Of Filter
			//? Function That Sets The O/P Stream Handle Based On LogOutput

			enum class LogLevel {
				trace   = SERENITY_TRACE,
				info    = SERENITY_INFO,
				warning = SERENITY_WARNING,
				debug   = SERENITY_DEBUG,
				error   = SERENITY_ERROR,
				fatal   = SERENITY_FATAL,
				off     = SERENITY_DISABLED
			};

			enum class LogOutput {
				console = LOG_TO_CONSOLE,
				file    = LOG_TO_FILE,
				all     = LOG_TO_ALL,
				none    = LOG_TO_NONE
			};
		} // namespace logger

		// Todo: Create Some Ways For Dump Logs, Crash Logs - In General, Some Way To
		// Todo: Trace Logged Messages Before They Get To Log Texts
		namespace log_backtrace {
		}
		// ToDo: expand on LogTime to be more of a struct of sorts and retrieve the local time
		enum LogTime { local };

		// ToDo: Finish out the struct based on a time format, pattern format, message buffer,
		// ToDo: output source, current log level vs flush log level and swap formatted string from worker
		// ToDo: thread to current thread and output to log using Log() if multi-threading
		//?                         Maybe still use buffer if no MT?

		// ToDo: Rename Things To Make More Sense Here And Break Some Code Out Into Separate Files
		//? For Instance, Might Be Neater To Put All Enums In Their Own "Enums.h" Header File And Such

		static std::string m_msgColor;
		static std::string m_msgStyle;
		struct MsgDetails
		{
			enum class LogStyle {
				begin = 0,
				reset,
				bold,
				dark,
				underline,
				blink,
				reverse,
				concealed,
				clearline,
				end
			};

			enum class LogColor {
				begin = 0,
				black,
				red,
				green,
				yellow,
				blue,
				magenta,
				cyan,
				white,
				bgBlack,
				bgRed,
				bgGreen,
				bgYellow,
				bgBlue,
				bgMagenta,
				bgCyan,
				bgWhite,
				boldYellow,
				boldRed,
				end
			};
			static std::string GetMsgColor( )
			{
				return m_msgColor;
			}
			static std::string GetMsgStyle( )
			{
				return m_msgStyle;
			}
			static void SetMsgColor(std::string color)
			{
				m_msgColor = color;
			}
			static void SetMsgStyle(std::string style)
			{
				m_msgStyle = style;
			}
		};

	} // namespace details

} // namespace serenity
