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
			static void SetMsgColor(std::string color ) {m_msgColor = color; }
			static void SetMsgStyle(std::string style) { m_msgStyle = style; }

		      protected:
			static std::string m_msgColor;
			static std::string m_msgStyle;
		};
	} // namespace details

	struct utilities
	{
	}; // struct utilities


	std::string LogStyleToString(details::MsgDetails::LogStyle style)
	{
		std::map<details::MsgDetails::LogStyle, std::string> styleString = {
		  {details::MsgDetails::LogStyle::reset, "Reset"},
		  {details::MsgDetails::LogStyle::bold, "Bold"},
		  {details::MsgDetails::LogStyle::dark, "Dark"},
		  {details::MsgDetails::LogStyle::underline, "Underline"},
		  {details::MsgDetails::LogStyle::blink, "Blink"},
		  {details::MsgDetails::LogStyle::reverse, "Reverse"},
		  {details::MsgDetails::LogStyle::concealed, "Concealed"},
		  {details::MsgDetails::LogStyle::clearline, "Clear-line"},
		};
		std::string resultString = "DEFAULT";
		auto iterator            = styleString.find(style);
		if(iterator != styleString.end( )) {
			resultString = iterator->second;
		}
		return resultString;
	}

	std::string LogStyleToCode(details::MsgDetails::LogStyle style)
	{
		std::map<details::MsgDetails::LogStyle, std::string> logStyleMap = {
		  {details::MsgDetails::LogStyle::reset, "\033[m"},
		  {details::MsgDetails::LogStyle::bold, "\033[1m"},
		  {details::MsgDetails::LogStyle::dark, "\033[2m"},
		  {details::MsgDetails::LogStyle::underline, "\033[4m"},
		  {details::MsgDetails::LogStyle::blink, "\033[5m"},
		  {details::MsgDetails::LogStyle::reverse, "\033[7m"},
		  {details::MsgDetails::LogStyle::concealed, "\033[8m"},
		  {details::MsgDetails::LogStyle::clearline, "\033[K"},
		};
		std::string resultString = "DEFAULT";
		auto iterator            = logStyleMap.find(style);
		if(iterator != logStyleMap.end( )) {
			resultString = iterator->second;
		}
		return resultString;
	}

	auto LogStyleFromCode(std::string styleStr)
	{
		std::map<std::string, details::MsgDetails::LogStyle> logStyleString = {
		  {"\033[m", details::MsgDetails::LogStyle::reset},
		  {"\033[1m", details::MsgDetails::LogStyle::bold},
		  {"\033[2m", details::MsgDetails::LogStyle::dark},
		  {"\033[4m", details::MsgDetails::LogStyle::underline},
		  {"\033[5m", details::MsgDetails::LogStyle::blink},
		  {"\033[7m", details::MsgDetails::LogStyle::reverse},
		  {"\033[8m", details::MsgDetails::LogStyle::concealed},
		  {"\033[K", details::MsgDetails::LogStyle::clearline},
		};
		details::MsgDetails::LogStyle resultString = details::MsgDetails::LogStyle::reset;
		auto iterator                              = logStyleString.find(styleStr);
		if(iterator != logStyleString.end( )) {
			resultString = iterator->second;
		}
		return resultString;
	}

	std::string LogColorToColorCode(details::MsgDetails::LogColor color)
	{
		std::map<details::MsgDetails::LogColor, std::string> logColorMap = {

		  {details::MsgDetails::LogColor::black, "\033[30m"},
		  {details::MsgDetails::LogColor::red, "\033[31m"},
		  {details::MsgDetails::LogColor::green, "\033[32m"},
		  {details::MsgDetails::LogColor::yellow, "\033[33m"},
		  {details::MsgDetails::LogColor::blue, "\033[34m"},
		  {details::MsgDetails::LogColor::magenta, "\033[35m"},
		  {details::MsgDetails::LogColor::cyan, "\033[36m"},
		  {details::MsgDetails::LogColor::white, "\033[37m"},
		  {details::MsgDetails::LogColor::bgBlack, "\033[40m"},
		  {details::MsgDetails::LogColor::bgRed, "\033[41m"},
		  {details::MsgDetails::LogColor::bgGreen, "\033[42m"},
		  {details::MsgDetails::LogColor::bgYellow, "\033[43m"},
		  {details::MsgDetails::LogColor::bgBlue, "\033[44m"},
		  {details::MsgDetails::LogColor::bgMagenta, "\033[45m"},
		  {details::MsgDetails::LogColor::bgCyan, "\033[46m"},
		  {details::MsgDetails::LogColor::bgWhite, "\033[47m"},
		  {details::MsgDetails::LogColor::boldYellow, "\033[33m\033[1m"},
		  {details::MsgDetails::LogColor::boldRed, "\033[31m\033[1m"}

		};
		std::string resultString = "DEFAULT";
		auto iterator            = logColorMap.find(color);
		if(iterator != logColorMap.end( )) {
			resultString = iterator->second;
		}
		return resultString;
	}
	auto LogColorFromColorCode(std::string colorStr)
	{
		std::map<std::string, details::MsgDetails::LogColor> logColorString =

		  {
		    {"\033[30m", details::MsgDetails::LogColor::black},
		    {"\033[31m", details::MsgDetails::LogColor::red},
		    {"\033[32m", details::MsgDetails::LogColor::green},
		    {"\033[33m", details::MsgDetails::LogColor::yellow},
		    {"\033[34m", details::MsgDetails::LogColor::blue},
		    {"\033[35m", details::MsgDetails::LogColor::magenta},
		    {"\033[36m", details::MsgDetails::LogColor::cyan},
		    {"\033[37m", details::MsgDetails::LogColor::white},
		    {"\033[40m", details::MsgDetails::LogColor::bgBlack},
		    {"\033[41m", details::MsgDetails::LogColor::bgRed},
		    {"\033[42m", details::MsgDetails::LogColor::bgGreen},
		    {"\033[43m", details::MsgDetails::LogColor::bgYellow},
		    {"\033[44m", details::MsgDetails::LogColor::bgBlue},
		    {"\033[45m", details::MsgDetails::LogColor::bgMagenta},
		    {"\033[46m", details::MsgDetails::LogColor::bgCyan},
		    {"\033[47m", details::MsgDetails::LogColor::bgWhite},
		    {"\033[33m\033[1m", details::MsgDetails::LogColor::boldYellow},
		    {"\033[31m\033[1m", details::MsgDetails::LogColor::boldRed},
		  };
		details::MsgDetails::LogColor resultString =
		  static_cast<details::MsgDetails::LogColor>(details::MsgDetails::LogStyle::reset);
		auto iterator = logColorString.find(colorStr);
		if(iterator != logColorString.end( )) {
			resultString = iterator->second;
		}
		return resultString;
	}

	std::string LogColorToStr(details::MsgDetails::LogColor color)
	{
		std::map<details::MsgDetails::LogColor, std::string> colorStr = {
		  {details::MsgDetails::LogColor::black, "Black"},
		  {details::MsgDetails::LogColor::red, "Red"},
		  {details::MsgDetails::LogColor::green, "Green"},
		  {details::MsgDetails::LogColor::yellow, "Yellow"},
		  {details::MsgDetails::LogColor::blue, "Blue"},
		  {details::MsgDetails::LogColor::magenta, "Magenta"},
		  {details::MsgDetails::LogColor::cyan, "Cyan"},
		  {details::MsgDetails::LogColor::white, "White"},
		  {details::MsgDetails::LogColor::bgBlack, "Black Background"},
		  {details::MsgDetails::LogColor::bgRed, "Red Background"},
		  {details::MsgDetails::LogColor::bgGreen, "Green Background"},
		  {details::MsgDetails::LogColor::bgYellow, "Yellow Background"},
		  {details::MsgDetails::LogColor::bgBlue, "Blue Background"},
		  {details::MsgDetails::LogColor::bgMagenta, "Magenta Background"},
		  {details::MsgDetails::LogColor::bgCyan, "Cyan Background"},
		  {details::MsgDetails::LogColor::bgWhite, "White Background"},
		  {details::MsgDetails::LogColor::boldYellow, "Bold Yellow"},
		  {details::MsgDetails::LogColor::boldRed, "Bold Red"}};
		std::string resultString = "DEFAULT";
		auto iterator            = colorStr.find(color);
		if(iterator != colorStr.end( )) {
			resultString = iterator->second;
		}
		return resultString;
	}

	auto GetColor( )
	{
		return LogColorFromColorCode(details::MsgDetails::GetMsgColor( ));
	}

	details::MsgDetails::LogStyle GetStyle( )
	{
		return LogStyleFromCode(details::MsgDetails::GetMsgStyle( ));
	}

	std::string PrintColorAsText( )
	{
		return LogColorToStr(GetColor( ));
	}

	inline void SetLogColor(details::MsgDetails::LogColor color)
	{

		details::MsgDetails::SetMsgColor(LogColorToStr(color));
	}

	inline void SetLogStyle(details::MsgDetails::LogStyle style)
	{
		details::MsgDetails::SetMsgStyle(LogStyleToString(style));
	}
} // namespace serenity
