#pragma once
#include <Serenity/SharedData.h>
#include <string>

namespace serenity {

	struct utilities
	{
		// Probably Don't Need These As Static Functions

		inline static std::string LogStyleToString(details::MsgDetails::LogStyle style)
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

		inline static std::string LogStyleToCode(details::MsgDetails::LogStyle style)
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

		inline static auto LogStyleFromCode(std::string styleStr)
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

		inline static std::string LogColorToColorCode(details::MsgDetails::LogColor color)
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
		inline static auto LogColorFromColorCode(std::string colorStr)
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

		inline static std::string LogColorToStr(details::MsgDetails::LogColor color)
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

		inline static auto GetColor( )
		{
			return LogColorFromColorCode(details::MsgDetails::GetMsgColor( ));
		}

		inline static details::MsgDetails::LogStyle GetStyle( )
		{
			return LogStyleFromCode(details::MsgDetails::GetMsgStyle( ));
		}

		inline static std::string PrintColorAsText( )
		{
			return utilities::LogColorToStr(GetColor( ));
		}

		void SetLogColor(details::MsgDetails::LogColor color)
		{
			details::MsgDetails::SetMsgColor(LogColorToStr(color));
		}

		void SetLogStyle(details::MsgDetails::LogStyle style)
		{
			details::MsgDetails::SetMsgStyle(LogStyleToString(style));
		}
	}; // struct utilities


} // namespace serenity