#pragma once
#include <Serenity/SharedData.h>

#include <Serenity/Helpers/StreamHelper.h>
#include <Serenity/Helpers/StreamColorHelper.h>
#include <Serenity/Helpers/StreamStyleHelper.h>

#include <ostream>

namespace serenity {
	namespace helper_message {
		inline void UseMsgColor(std::ostream& os)
		{
			// ToDo: FLush Out With Color Options, Create The TextColor Enum Which Will
			// ToDo: Handle Whether To Output The Formatted String With The Color Code For
			// ToDo: Mac/Lin Or Use Win's Color Defines

			switch(serenity::GetColor( )) {
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