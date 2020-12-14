#pragma once

#include <Serenity/SharedData.h>
#include <Serenity/Helpers/Utilities.h>
#include <Serenity/Helpers/StreamHelper.h>
#include <Serenity/Helpers/StreamColorHelper.h>
#include <Serenity/Helpers/StreamStyleHelper.h>

#include <ostream>
#include <cassert>
#include <sstream>

namespace serenity {

	namespace ostream_string {
		std::string OstreamToString(std::ostream& os)
		{
			std::stringstream osStr;
			osStr << os.rdbuf( );
			return osStr.str( );
		}
	} // namespace ostream_string

	namespace helper_message {

		inline static std::string UseMsgColor(std::ostream& os)
		{
			// ToDo: FLush Out With Color Options, Create The TextColor Enum Which Will
			// ToDo: Handle Whether To Output The Formatted String With The Color Code For
			// ToDo: Mac/Lin Or Use Win's Color Defines

			switch(serenity::utilities::GetColor( )) {
				case details::MsgDetails::LogColor::black:
					{
						return serenity::ostream_string::OstreamToString(
						  os << helper_stream_color::black);
					}
					break;
				case details::MsgDetails::LogColor::red:
					{
						return serenity::ostream_string::OstreamToString(
						  os << helper_stream_color::red);
					}
					break;
				case details::MsgDetails::LogColor::green:
					{
						return serenity::ostream_string::OstreamToString(
						  os << helper_stream_color::green);
					}
					break;
				case details::MsgDetails::LogColor::yellow:
					{
						return serenity::ostream_string::OstreamToString(
						  os << helper_stream_color::yellow);
					}
					break;
				case details::MsgDetails::LogColor::blue:
					{
						return serenity::ostream_string::OstreamToString(
						  os << helper_stream_color::blue);
					}
					break;
				case details::MsgDetails::LogColor::magenta:
					{
						return serenity::ostream_string::OstreamToString(
						  os << helper_stream_color::magenta);
					}
					break;
				case details::MsgDetails::LogColor::cyan:
					{
						return serenity::ostream_string::OstreamToString(
						  os << helper_stream_color::cyan);
					}
					break;
				case details::MsgDetails::LogColor::white:
					{
						return serenity::ostream_string::OstreamToString(
						  os << helper_stream_color::white);
					}
					break;
				default:
					{
						return "Invalid Color Flag Used";
						assert(false);
					}
					break;
			}
		}

		inline auto UseFontStyle(std::ostream& os, details::MsgDetails::LogStyle style)
		{
			switch(style) {
				case details::MsgDetails::LogStyle::bold:
					{
						return serenity::ostream_string::OstreamToString(
						  os << serenity::helper_stream_style::bold);
					}
					break;
				case details::MsgDetails::LogStyle::dark:
					{
						return serenity::ostream_string::OstreamToString(
						  os << helper_stream_style::dark);
					}
					break;
				case details::MsgDetails::LogStyle::underline:
					{
						return serenity::ostream_string::OstreamToString(
						  os << helper_stream_style::underline);
					}
					break;
				case details::MsgDetails::LogStyle::blink:
					{
						return serenity::ostream_string::OstreamToString(
						  os << helper_stream_style::blink);
					}
					break;
				case details::MsgDetails::LogStyle::reverse:
					{
						return serenity::ostream_string::OstreamToString(
						  os << helper_stream_style::reverse);
					}
					break;
				case details::MsgDetails::LogStyle::concealed:
					{
						return serenity::ostream_string::OstreamToString(
						  os << helper_stream_style::concealed);
					}
					break;
				default: break;
			}
		}
	} // namespace helper_message
} // namespace serenity