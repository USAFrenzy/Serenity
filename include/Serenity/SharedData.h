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

		// ToDo: Rename Things To Make More Sense Here And Break Some Code Out Into Separate Files
		//? For Instance, Might Be Neater To Put All Enums In Their Own "Enums.h" Header File And Such

		struct MsgDetails
		{
		      public:
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

		      protected:
			std::string LogStyleToCode(LogStyle style)
			{
				std::map<LogStyle, std::string> logStyleMap = {
				  {LogStyle::reset, "\033[m"},
				  {LogStyle::bold, "\033[1m"},
				  {LogStyle::dark, "\033[2m"},
				  {LogStyle::underline, "\033[4m"},
				  {LogStyle::blink, "\033[5m"},
				  {LogStyle::reverse, "\033[7m"},
				  {LogStyle::concealed, "\033[8m"},
				  {LogStyle::clearline, "\033[K"},
				};
				std::string resultString = "DEFAULT";
				auto iterator            = logStyleMap.find(style);
				if(iterator != logStyleMap.end( )) {
					resultString = iterator->second;
				}
				return resultString;
			}

			std::string LogColorToColorCode(LogColor color)
			{
				std::map<LogColor, std::string> logColorMap = {
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
			LogStyle LogStyleFromCode(std::string styleStr)
			{
				std::map<std::string, LogStyle> logStyleString = {
				  {"\033[m", LogStyle::reset},
				  {"\033[1m", LogStyle::bold},
				  {"\033[2m", LogStyle::dark},
				  {"\033[4m", LogStyle::underline},
				  {"\033[5m", LogStyle::blink},
				  {"\033[7m", LogStyle::reverse},
				  {"\033[8m", LogStyle::concealed},
				  {"\033[K", LogStyle::clearline},
				};
				LogStyle resultString = LogStyle::reset;
				auto iterator         = logStyleString.find(styleStr);
				if(iterator != logStyleString.end( )) {
					resultString = iterator->second;
				}
				return resultString;
			}

			LogColor LogColorFromColorCode(std::string colorStr)
			{
				std::map<std::string, LogColor> logColorString =

				  {
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
				LogColor resultString = static_cast<LogColor>(LogStyle::reset);
				auto iterator         = logColorString.find(colorStr);
				if(iterator != logColorString.end( )) {
					resultString = iterator->second;
				}
				return resultString;
			}

			std::string LogStyleToString(LogStyle style)
			{
				std::map<LogStyle, std::string> styleString = {
				  {LogStyle::reset, "Reset"},
				  {LogStyle::bold, "Bold"},
				  {LogStyle::dark, "Dark"},
				  {LogStyle::underline, "Underline"},
				  {LogStyle::blink, "Blink"},
				  {LogStyle::reverse, "Reverse"},
				  {LogStyle::concealed, "Concealed"},
				  {LogStyle::clearline, "Clear-line"},
				};
				std::string resultString = "DEFAULT";
				auto iterator            = styleString.find(style);
				if(iterator != styleString.end( )) {
					resultString = iterator->second;
				}
				return resultString;
			}

			std::string LogColorToStr(LogColor color)
			{
				std::map<LogColor, std::string> colorStr = {
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
			LogColor GetColor( )
			{
				return LogColorFromColorCode(m_msgColor);
			}
			std::string PrintColorAsText( )
			{
				return LogColorToStr(GetColor( ));
			}

			// ToDo: ################################################################################
			// ToDo: #                                   FixMe                                      #
			// ToDo: ################################################################################


			inline void SetLogColor(LogColor color)
			{
				m_msgColor = LogColorToColorCode(color);
			}

			std::string UseMsgColor( )
			{
				// ToDo: FLush Out With Color Options, Create The TextColor Enum Which Will
				// ToDo: Handle Whether To Output The Formatted String With The Color Code For
				// ToDo: Mac/Lin Or Use Win's Color Defines

				// std::ostream &os;
				/* switch(GetColor( )) {
					case LogColor::black:
						{
							os << TextColor::black;
						} break;
		*/
				std::string returnStr = "[This Is A PlaceHolder For Color Fmt]  ";
				return returnStr;
				//}
			}

			void LogResetColor( ) { }

		      private:
			std::string m_msgColor;
		};

		// ToDo: Look At UseMsgColor() Note Above ^^^
		enum class TextColor {


		}; // enum TextColor

		// ToDo: ################################################################################


	} // namespace details
	  // ****************************************************************************************
	struct utilities
	{
	}; // struct utilities
	   // ****************************************************************************************
} // namespace serenity
