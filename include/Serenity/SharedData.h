#pragma once

#include <iostream>
#include <map>
#include <string>

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
		  // ########################################################################################

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

		struct MsgDetails
		{
		      public:
			enum class LogColor {
				begin = 0,
				reset,
				bold,
				dark,
				underline,
				blink,
				reverse,
				concealed,
				clearline,
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

		      protected:
			std::string LogColorToColorCode(LogColor color)
			{
				std::map<LogColor, std::string> logColorMap = {

				  {LogColor::reset, "\033[m"},
				  {LogColor::bold, "\033[1m"},
				  {LogColor::dark, "\033[2m"},
				  {LogColor::underline, "\033[4m"},
				  {LogColor::blink, "\033[5m"},
				  {LogColor::reverse, "\033[7m"},
				  {LogColor::concealed, "\033[8m"},
				  {LogColor::clearline, "\033[K"},
				  {LogColor::black, "\033[30m"},
				  {LogColor::red, "\033[31m"},
				  {LogColor::green, "\033[32m"},
				  {LogColor::yellow, "\033[33m"},
				  {LogColor::blue, "\033[34m"},
				  {LogColor::magenta, "\033[35m"},
				  {LogColor::cyan, "\033[36m"},
				  {LogColor::white, "\033[37m"},
				  {LogColor::bgBlack, "\033[40m"},
				  {LogColor::bgRed, "\033[41m"},
				  {LogColor::bgGreen, "\033[42m"},
				  {LogColor::bgYellow, "\033[43m"},
				  {LogColor::bgBlue, "\033[44m"},
				  {LogColor::bgMagenta, "\033[45m"},
				  {LogColor::bgCyan, "\033[46m"},
				  {LogColor::bgWhite, "\033[47m"},
				  {LogColor::boldYellow, "\033[33m\033[1m"},
				  {LogColor::boldRed, "\033[31m\033[1m"}};
				std::string resultString = "DEFAULT";
				auto iterator            = logColorMap.find(color);
				if(iterator != logColorMap.end( )) {
					resultString = iterator->second;
				}
				return resultString;
			}

			LogColor LogColorFromColorCode(std::string colorStr)
			{
				std::map<std::string, LogColor> logColorString =

				  {
				    {"\033[m", LogColor::reset},
				    {"\033[1m", LogColor::bold},
				    {"\033[2m", LogColor::dark},
				    {"\033[4m", LogColor::underline},
				    {"\033[5m", LogColor::blink},
				    {"\033[7m", LogColor::reverse},
				    {"\033[8m", LogColor::concealed},
				    {"\033[K", LogColor::clearline},
				    {"\033[30m", LogColor::black},
				    {"\033[31m", LogColor::red},
				    {"\033[32m", LogColor::green},
				    {"\033[33m", LogColor::yellow},
				    {"\033[34m", LogColor::blue},
				    {"\033[35m", LogColor::magenta},
				    {"\033[36m", LogColor::cyan},
				    {"\033[37m", LogColor::white},
				    {"\033[40m", LogColor::bgBlack},
				    {"\033[41m", LogColor::bgRed},
				    {"\033[42m", LogColor::bgGreen},
				    {"\033[43m", LogColor::bgYellow},
				    {"\033[44m", LogColor::bgBlue},
				    {"\033[45m", LogColor::bgMagenta},
				    {"\033[46m", LogColor::bgCyan},
				    {"\033[47m", LogColor::bgWhite},
				    {"\033[33m\033[1m", LogColor::boldYellow},
				    {"\033[31m\033[1m", LogColor::boldRed},
				  };
				LogColor resultString = LogColor::reset;
				auto iterator         = logColorString.find(colorStr);
				if(iterator != logColorString.end( )) {
					resultString = iterator->second;
				}
				return resultString;
			}

			std::string LogColorToStr(LogColor color)
			{
				std::map<LogColor, std::string> colorStr = {

				  {LogColor::reset, "Reset"},
				  {LogColor::bold, "Bold"},
				  {LogColor::dark, "Dark"},
				  {LogColor::underline, "Underline"},
				  {LogColor::blink, "Blink"},
				  {LogColor::reverse, "Reverse"},
				  {LogColor::concealed, "Concealed"},
				  {LogColor::clearline, "Clear-line"},
				  {LogColor::black, "Black"},
				  {LogColor::red, "Red"},
				  {LogColor::green, "Green"},
				  {LogColor::yellow, "Yellow"},
				  {LogColor::blue, "Blue"},
				  {LogColor::magenta, "Magenta"},
				  {LogColor::cyan, "Cyan"},
				  {LogColor::white, "White"},
				  {LogColor::bgBlack, "Black Background"},
				  {LogColor::bgRed, "Red Background"},
				  {LogColor::bgGreen, "Green Background"},
				  {LogColor::bgYellow, "Yellow Background"},
				  {LogColor::bgBlue, "Blue Background"},
				  {LogColor::bgMagenta, "Magenta Background"},
				  {LogColor::bgCyan, "Cyan Background"},
				  {LogColor::bgWhite, "White Background"},
				  {LogColor::boldYellow, "Bold Yellow"},
				  {LogColor::boldRed, "Bold Red"}};
				std::string resultString = "DEFAULT";
				auto iterator            = colorStr.find(color);
				if(iterator != colorStr.end( )) {
					resultString = iterator->second;
				}
				return resultString;
			}

		      public:
			void SetLogColor(LogColor color)
			{
				m_msgColor = LogColorToColorCode(color);
			}
			LogColor GetLogColor( )
			{
				return LogColorFromColorCode(m_msgColor);
			}
			std::string PrintMsgColor( )
			{
				return LogColorToStr(GetLogColor( ));
			}
			std::string UseMsgColor( )
			{
				return m_msgColor;
			}
			//! This Is A Quick Hack
			// ToDo: FixMe
			void LogResetColor( ) { }

		      private:
			std::string m_msgColor;
		};


	} // namespace details
	  // ****************************************************************************************
	struct utilities
	{
	}; // struct utilities
	   // ****************************************************************************************
} // namespace serenity
