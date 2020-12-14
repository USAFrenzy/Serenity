#pragma once
#include <Serenity/SharedData.h>

#include <Serenity/Helpers/StreamHelper.h>
#include <Serenity/Helpers/StreamColorHelper.h>
#include <Serenity/Helpers/StreamStyleHelper.h>

#include <ostream>

namespace serenity {


	namespace utilities {
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
			return utilities::LogColorToStr(GetColor( ));
		}

		inline void SetLogColor(details::MsgDetails::LogColor color)
		{
			details::MsgDetails::SetMsgColor(LogColorToStr(color));
		}

		inline void SetLogStyle(details::MsgDetails::LogStyle style)
		{
			details::MsgDetails::SetMsgStyle(LogStyleToString(style));
		}
	}; // namespace utilities


	namespace helper_message {
		inline void UseMsgColor(std::ostream& os)
		{
			// ToDo: FLush Out With Color Options, Create The TextColor Enum Which Will
			// ToDo: Handle Whether To Output The Formatted String With The Color Code For
			// ToDo: Mac/Lin Or Use Win's Color Defines

			switch(serenity::utilities::GetColor( )) {
				case details::MsgDetails::LogColor::black:
					{
						os << helper_stream_color::black;
					}
					break;
				case details::MsgDetails::LogColor::red:
					{
						os << helper_stream_color::red;
					}
					break;
				case details::MsgDetails::LogColor::green:
					{
						os << helper_stream_color::green;
					}
					break;
				case details::MsgDetails::LogColor::yellow:
					{
						os << helper_stream_color::yellow;
					}
					break;
				case details::MsgDetails::LogColor::blue:
					{
						os << helper_stream_color::blue;
					}
					break;
				case details::MsgDetails::LogColor::magenta:
					{
						os << helper_stream_color::magenta;
					}
					break;
				case details::MsgDetails::LogColor::cyan:
					{
						os << helper_stream_color::cyan;
					}
					break;
				case details::MsgDetails::LogColor::white:
					{
						os << helper_stream_color::white;
					}
					break;
				default: break;
			}
		}

		inline void UseFontStyle(std::ostream& os, details::MsgDetails::LogStyle style)
		{
			switch(style) {
				case details::MsgDetails::LogStyle::bold:
					{
						os << helper_stream_style::bold;
					}
					break;
				case details::MsgDetails::LogStyle::dark:
					{
						os << helper_stream_style::dark;
					}
					break;
				case details::MsgDetails::LogStyle::underline:
					{
						os << helper_stream_style::underline;
					}
					break;
				case details::MsgDetails::LogStyle::blink:
					{
						os << helper_stream_style::blink;
					}
					break;
				case details::MsgDetails::LogStyle::reverse:
					{
						os << helper_stream_style::reverse;
					}
					break;
				case details::MsgDetails::LogStyle::concealed:
					{
						os << helper_stream_style::concealed;
					}
					break;
				default: break;
			}
		}
	} // namespace helper_message
} // namespace serenity