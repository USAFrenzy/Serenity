#pragma once

#include <map>
#include <string>
#include <sstream>


namespace serenity {

	struct utilities
	{
		// Probably Don't Need These As Static Functions

		inline static std::string LogStyleToString(serenity::details::MsgDetails::LogStyle style)
		{
			std::map<serenity::details::MsgDetails::LogStyle, std::string> styleString = {
			  {serenity::details::MsgDetails::LogStyle::reset, "Reset"},
			  {serenity::details::MsgDetails::LogStyle::bold, "Bold"},
			  {serenity::details::MsgDetails::LogStyle::dark, "Dark"},
			  {serenity::details::MsgDetails::LogStyle::underline, "Underline"},
			  {serenity::details::MsgDetails::LogStyle::blink, "Blink"},
			  {serenity::details::MsgDetails::LogStyle::reverse, "Reverse"},
			  {serenity::details::MsgDetails::LogStyle::concealed, "Concealed"},
			  {serenity::details::MsgDetails::LogStyle::clearline, "Clear-line"},
			};
			std::string resultString = "DEFAULT";
			auto iterator            = styleString.find(style);
			if(iterator != styleString.end( )) {
				resultString = iterator->second;
			}
			return resultString;
		}

		inline static std::string LogStyleToCode(serenity::details::MsgDetails::LogStyle style)
		{
			std::map<serenity::details::MsgDetails::LogStyle, std::string> logStyleMap = {
			  {serenity::details::MsgDetails::LogStyle::reset, "\033[m"},
			  {serenity::details::MsgDetails::LogStyle::bold, "\033[1m"},
			  {serenity::details::MsgDetails::LogStyle::dark, "\033[2m"},
			  {serenity::details::MsgDetails::LogStyle::underline, "\033[4m"},
			  {serenity::details::MsgDetails::LogStyle::blink, "\033[5m"},
			  {serenity::details::MsgDetails::LogStyle::reverse, "\033[7m"},
			  {serenity::details::MsgDetails::LogStyle::concealed, "\033[8m"},
			  {serenity::details::MsgDetails::LogStyle::clearline, "\033[K"},
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
			std::map<std::string, serenity::details::MsgDetails::LogStyle> logStyleString = {
			  {"\033[m", serenity::details::MsgDetails::LogStyle::reset},
			  {"\033[1m", serenity::details::MsgDetails::LogStyle::bold},
			  {"\033[2m", serenity::details::MsgDetails::LogStyle::dark},
			  {"\033[4m", serenity::details::MsgDetails::LogStyle::underline},
			  {"\033[5m", serenity::details::MsgDetails::LogStyle::blink},
			  {"\033[7m", serenity::details::MsgDetails::LogStyle::reverse},
			  {"\033[8m", serenity::details::MsgDetails::LogStyle::concealed},
			  {"\033[K", serenity::details::MsgDetails::LogStyle::clearline},
			};
			serenity::details::MsgDetails::LogStyle resultString =
			  serenity::details::MsgDetails::LogStyle::reset;
			auto iterator = logStyleString.find(styleStr);
			if(iterator != logStyleString.end( )) {
				resultString = iterator->second;
			}
			return resultString;
		}

		inline std::string LogColorToColorCode(serenity::details::MsgDetails::LogColor color)
		{
			std::map<serenity::details::MsgDetails::LogColor, std::string> logColorMap = {

			  {serenity::details::MsgDetails::LogColor::black, "\033[30m"},
			  {serenity::details::MsgDetails::LogColor::red, "\033[31m"},
			  {serenity::details::MsgDetails::LogColor::green, "\033[32m"},
			  {serenity::details::MsgDetails::LogColor::yellow, "\033[33m"},
			  {serenity::details::MsgDetails::LogColor::blue, "\033[34m"},
			  {serenity::details::MsgDetails::LogColor::magenta, "\033[35m"},
			  {serenity::details::MsgDetails::LogColor::cyan, "\033[36m"},
			  {serenity::details::MsgDetails::LogColor::white, "\033[37m"},
			  {serenity::details::MsgDetails::LogColor::bgBlack, "\033[40m"},
			  {serenity::details::MsgDetails::LogColor::bgRed, "\033[41m"},
			  {serenity::details::MsgDetails::LogColor::bgGreen, "\033[42m"},
			  {serenity::details::MsgDetails::LogColor::bgYellow, "\033[43m"},
			  {serenity::details::MsgDetails::LogColor::bgBlue, "\033[44m"},
			  {serenity::details::MsgDetails::LogColor::bgMagenta, "\033[45m"},
			  {serenity::details::MsgDetails::LogColor::bgCyan, "\033[46m"},
			  {serenity::details::MsgDetails::LogColor::bgWhite, "\033[47m"},
			  {serenity::details::MsgDetails::LogColor::boldYellow, "\033[33m\033[1m"},
			  {serenity::details::MsgDetails::LogColor::boldRed, "\033[31m\033[1m"}

			};
			std::string resultString = "DEFAULT";
			auto iterator            = logColorMap.find(color);
			if(iterator != logColorMap.end( )) {
				resultString = iterator->second;
			}
			return resultString;
		}
		inline serenity::details::MsgDetails::LogColor LogColorFromColorCode(std::string colorStr)
		{
			std::map<std::string, serenity::details::MsgDetails::LogColor> logColorString =

			  {
			    {"\033[30m", serenity::details::MsgDetails::LogColor::black},
			    {"\033[31m", serenity::details::MsgDetails::LogColor::red},
			    {"\033[32m", serenity::details::MsgDetails::LogColor::green},
			    {"\033[33m", serenity::details::MsgDetails::LogColor::yellow},
			    {"\033[34m", serenity::details::MsgDetails::LogColor::blue},
			    {"\033[35m", serenity::details::MsgDetails::LogColor::magenta},
			    {"\033[36m", serenity::details::MsgDetails::LogColor::cyan},
			    {"\033[37m", serenity::details::MsgDetails::LogColor::white},
			    {"\033[40m", serenity::details::MsgDetails::LogColor::bgBlack},
			    {"\033[41m", serenity::details::MsgDetails::LogColor::bgRed},
			    {"\033[42m", serenity::details::MsgDetails::LogColor::bgGreen},
			    {"\033[43m", serenity::details::MsgDetails::LogColor::bgYellow},
			    {"\033[44m", serenity::details::MsgDetails::LogColor::bgBlue},
			    {"\033[45m", serenity::details::MsgDetails::LogColor::bgMagenta},
			    {"\033[46m", serenity::details::MsgDetails::LogColor::bgCyan},
			    {"\033[47m", serenity::details::MsgDetails::LogColor::bgWhite},
			    {"\033[33m\033[1m", serenity::details::MsgDetails::LogColor::boldYellow},
			    {"\033[31m\033[1m", serenity::details::MsgDetails::LogColor::boldRed},
			  };
			serenity::details::MsgDetails::LogColor resultString =
			  static_cast<serenity::details::MsgDetails::LogColor>(
			    serenity::details::MsgDetails::LogStyle::reset);
			auto iterator = logColorString.find(colorStr);
			if(iterator != logColorString.end( )) {
				resultString = iterator->second;
			}
			return resultString;
		}

		inline std::string LogColorToStr(serenity::details::MsgDetails::LogColor color)
		{
			std::map<serenity::details::MsgDetails::LogColor, std::string> colorStr = {
			  {serenity::details::MsgDetails::LogColor::black, "Black"},
			  {serenity::details::MsgDetails::LogColor::red, "Red"},
			  {serenity::details::MsgDetails::LogColor::green, "Green"},
			  {serenity::details::MsgDetails::LogColor::yellow, "Yellow"},
			  {serenity::details::MsgDetails::LogColor::blue, "Blue"},
			  {serenity::details::MsgDetails::LogColor::magenta, "Magenta"},
			  {serenity::details::MsgDetails::LogColor::cyan, "Cyan"},
			  {serenity::details::MsgDetails::LogColor::white, "White"},
			  {serenity::details::MsgDetails::LogColor::bgBlack, "Black Background"},
			  {serenity::details::MsgDetails::LogColor::bgRed, "Red Background"},
			  {serenity::details::MsgDetails::LogColor::bgGreen, "Green Background"},
			  {serenity::details::MsgDetails::LogColor::bgYellow, "Yellow Background"},
			  {serenity::details::MsgDetails::LogColor::bgBlue, "Blue Background"},
			  {serenity::details::MsgDetails::LogColor::bgMagenta, "Magenta Background"},
			  {serenity::details::MsgDetails::LogColor::bgCyan, "Cyan Background"},
			  {serenity::details::MsgDetails::LogColor::bgWhite, "White Background"},
			  {serenity::details::MsgDetails::LogColor::boldYellow, "Bold Yellow"},
			  {serenity::details::MsgDetails::LogColor::boldRed, "Bold Red"}};
			std::string resultString = "DEFAULT";
			auto iterator            = colorStr.find(color);
			if(iterator != colorStr.end( )) {
				resultString = iterator->second;
			}
			return resultString;
		}

		inline serenity::details::MsgDetails::LogColor GetColor( )
		{
			return LogColorFromColorCode(serenity::details::MsgDetails::GetMsgColor( ));
		}

		inline static serenity::details::MsgDetails::LogStyle GetStyle( )
		{
			return LogStyleFromCode(serenity::details::MsgDetails::GetMsgStyle( ));
		}

		inline std::string PrintColorAsText( )
		{
			return utilities::LogColorToStr(GetColor( ));
		}

		void SetLogColor(serenity::details::MsgDetails::LogColor color)
		{
			serenity::details::MsgDetails::SetMsgColor(LogColorToStr(color));
		}

		void SetLogStyle(details::MsgDetails::LogStyle style)
		{
			serenity::details::MsgDetails::SetMsgStyle(LogStyleToString(style));
		}
	}; // struct utilities

	namespace helper_ostream {
		struct OstreamInterface
		{
			std::string interfaceOstream;

			enum class InterfaceType { cout = 0, clog = 1, cerr = 2 };

			static std::string InterfaceTypeToStr(InterfaceType ostream)
			{
				std::map<InterfaceType, std::string> ostreamMap = {

				  {InterfaceType::cout, "std::cout"},
				  {InterfaceType::cerr, "std::cerr"},
				  {InterfaceType::clog, "std::clog"}

				};
				std::string resultString = "UNKNOWN";
				auto iterator            = ostreamMap.find(ostream);
				if(iterator != ostreamMap.end( )) {
					resultString = iterator->second;
				}
				return resultString;
			}

			void SetOstreamType(InterfaceType ostream)
			{
				interfaceOstream = InterfaceTypeToStr(ostream);
			}

			std::ostream* GetOstreamType( )
			{
				if(interfaceOstream == "std::cout") {
					std::ostream& os = std::cout;
					return &os;
				} else if(interfaceOstream == "std::cerr") {
					std::ostream& os = std::cerr;
					return &os;
				} else {
					std::ostream& os = std::cout;
					return &os;
				}
			}

			std::string OstreamToString(std::ostream& os)
			{
				std::stringstream osStr;
				osStr << os.rdbuf( );
				return osStr.str( );
			}
		};
	} // namespace helper_ostream

} // namespace serenity