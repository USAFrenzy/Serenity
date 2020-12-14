#pragma once

#include <Serenity/SharedData.h>
#include <Serenity/Helpers/Utilities.h>
#include <Serenity/Helpers/StreamHelper.h>


namespace serenity {

	namespace helper_stream_style {

		inline std::ostream& reset(std::ostream& stream)
		{
			if(helper_stream::isColored(stream)) {
				switch(operatingSystem) {
					case OpSystem::Windows:
						{
							helper_stream::windowAttributes(stream, -1, -1);
						}
						break;
					case OpSystem::Mac:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::reset);
						}
						break;
					case OpSystem::Linux:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::reset);
						}
						break;
				}
				return stream;
			}
		}

		inline std::ostream& bold(std::ostream& stream)
		{
			if(helper_stream::isColored(stream)) {
				switch(operatingSystem) {
					case OpSystem::Windows:
						{
							helper_stream::windowAttributes(stream, -1, -1);
						}
						break;
					case OpSystem::Mac:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::bold);
						}
						break;
					case OpSystem::Linux:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::bold);
						}
						break;
				}
				return stream;
			}
		}

		inline std::ostream& dark(std::ostream& stream)
		{
			if(helper_stream::isColored(stream)) {
				switch(operatingSystem) {
					case OpSystem::Windows:
						{
							helper_stream::windowAttributes(stream, -1, -1);
						}
						break;
					case OpSystem::Mac:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::dark);
						}
						break;
					case OpSystem::Linux:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::dark);
						}
						break;
				}
				return stream;
			}
		}

		inline std::ostream& underline(std::ostream& stream)
		{
			if(helper_stream::isColored(stream)) {
				switch(operatingSystem) {
					case OpSystem::Windows:
						{
							helper_stream::windowAttributes(stream, -1, -1);
						}
						break;
					case OpSystem::Mac:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::underline);
						}
						break;
					case OpSystem::Linux:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::underline);
						}
						break;
				}
				return stream;
			}
		}

		inline std::ostream& blink(std::ostream& stream)
		{
			if(helper_stream::isColored(stream)) {
				switch(operatingSystem) {
					case OpSystem::Windows:
						{
							helper_stream::windowAttributes(stream, -1, -1);
						}
						break;
					case OpSystem::Mac:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::blink);
						}
						break;
					case OpSystem::Linux:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::blink);
						}
						break;
				}
				return stream;
			}
		}

		inline std::ostream& reverse(std::ostream& stream)
		{
			if(helper_stream::isColored(stream)) {
				switch(operatingSystem) {
					case OpSystem::Windows:
						{
							helper_stream::windowAttributes(stream, -1, -1);
						}
						break;
					case OpSystem::Mac:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::reverse);
						}
						break;
					case OpSystem::Linux:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::reverse);
						}
						break;
				}
				return stream;
			}
		}

		inline std::ostream& concealed(std::ostream& stream)
		{
			if(helper_stream::isColored(stream)) {
				switch(operatingSystem) {
					case OpSystem::Windows:
						{
							helper_stream::windowAttributes(stream, -1, -1);
						}
						break;
					case OpSystem::Mac:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::concealed);
						}
						break;
					case OpSystem::Linux:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::concealed);
						}
						break;
				}
				return stream;
			}
		}

		inline std::ostream& clearline(std::ostream& stream)
		{
			if(helper_stream::isColored(stream)) {
				switch(operatingSystem) {
					case OpSystem::Windows:
						{
							helper_stream::windowAttributes(stream, -1, -1);
						}
						break;
					case OpSystem::Mac:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::clearline);
						}
						break;
					case OpSystem::Linux:
						{
							stream << serenity::utilities::LogStyleToCode(
							  details::MsgDetails::LogStyle::clearline);
						}
						break;
				}
				return stream;
			}
		}


	} // namespace helper_stream_style


} // namespace serenity