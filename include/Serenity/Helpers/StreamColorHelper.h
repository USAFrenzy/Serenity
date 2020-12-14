#pragma once

#include <Serenity/Helpers/StreamHelper.h>
#include <Serenity/SharedData.h>

#include <ostream>

namespace serenity {
	namespace helper_stream_color {

		inline std::ostream& black(std::ostream& stream)
		{
			if(stream_helper::colored(stream)) {
				switch(operatingSystem) {
					case OpSystem::Windows:
						{
							stream_helper::windowAttributes(stream, 0);
						}
						break;
					case OpSystem::Mac:
						{
							stream << LogColorToColorCode(
							  details::MsgDetails::LogColor::black);
						}
						break;
					case OpSystem::Linux:
						{
							stream << LogColorToColorCode(
							  details::MsgDetails::LogColor::black);
						}
						break;
				}
				return stream;
			}
		}

		inline std::ostream& red(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								stream_helper::windowAttributes(stream,
												FOREGROUND_RED);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::red);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::red);
							}
							break;
					}
					return stream;
				}
			}
		}

		inline std::ostream& green(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								stream_helper::windowAttributes(stream,
												FOREGROUND_GREEN);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::green);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::green);
							}
							break;
					}
					return stream;
				}
			}
		}

		inline std::ostream& yellow(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								stream_helper::windowAttributes(stream,
												FOREGROUND_GREEN |
												  FOREGROUND_RED);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::yellow);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::yellow);
							}
							break;
					}
					return stream;
				}
			}
		}

		inline std::ostream& blue(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								stream_helper::windowAttributes(stream,
												FOREGROUND_BLUE);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::blue);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::blue);
							}
							break;
					}
					return stream;
				}
			}
		}

		inline std::ostream& magenta(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								stream_helper::windowAttributes(stream,
												FOREGROUND_BLUE |
												  FOREGROUND_RED);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::magenta);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::magenta);
							}
							break;
					}
					return stream;
				}
			}
		}

		inline std::ostream& cyan(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								stream_helper::windowAttributes(
								  stream,
								  FOREGROUND_BLUE | FOREGROUND_GREEN);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::cyan);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::cyan);
							}
							break;
					}
					return stream;
				}
			}
		}

		inline std::ostream& white(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								stream_helper::windowAttributes(
								  stream,
								  FOREGROUND_BLUE | FOREGROUND_GREEN |
								    FOREGROUND_RED);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::white);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::white);
							}
							break;
					}
					return stream;
				}
			}
		}

		inline std::ostream& bgBlack(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								stream_helper::windowAttributes(stream, -1, 0);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgBlack);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgBlack);
							}
							break;
					}
					return stream;
				}
			}
		}
		inline std::ostream& bgRed(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								stream_helper::windowAttributes(stream,
												-1,
												BACKGROUND_RED);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgRed);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgRed);
							}
							break;
					}
					return stream;
				}
			}
		}

		inline std::ostream& bgGreen(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								stream_helper::windowAttributes(stream,
												-1,
												BACKGROUND_GREEN);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgGreen);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgGreen);
							}
							break;
					}
					return stream;
				}
			}
		}

		inline std::ostream& bgYellow(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								stream_helper::windowAttributes(stream,
												-1,
												BACKGROUND_GREEN |
												  BACKGROUND_RED);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgYellow);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgYellow);
							}
							break;
					}
					return stream;
				}
			}
		}

		inline std::ostream& bgBlue(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								stream_helper::windowAttributes(stream,
												-1,
												BACKGROUND_BLUE);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgBlue);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgBlue);
							}
							break;
					}
					return stream;
				}
			}
		}

		inline std::ostream& bgMagenta(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								stream_helper::windowAttributes(stream,
												-1,
												BACKGROUND_BLUE |
												  BACKGROUND_RED);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgMagenta);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgMagenta);
							}
							break;
					}
					return stream;
				}
			}
		}

		inline std::ostream& bgCyan(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								stream_helper::windowAttributes(stream,
												-1,
												BACKGROUND_GREEN |
												  BACKGROUND_BLUE);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgCyan);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgCyan);
							}
							break;
					}
					return stream;
				}
			}
		}

		inline std::ostream& bgWhite(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								stream_helper::windowAttributes(stream,
												-1,
												BACKGROUND_GREEN |
												  BACKGROUND_BLUE |
												  BACKGROUND_RED);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgWhite);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::bgWhite);
							}
							break;
					}
					return stream;
				}
			}
		}

		inline std::ostream& boldYellow(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								// Just Plain Ol' Yellow For Windows
								stream_helper::windowAttributes(stream,
												FOREGROUND_GREEN |
												  FOREGROUND_RED);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::boldYellow);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::boldYellow);
							}
							break;
					}
					return stream;
				}
			}
		}

		inline std::ostream& boldRed(std::ostream& stream)
		{
			{
				if(stream_helper::colored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								// Just Plain Ol' Red For Windows
								stream_helper::windowAttributes(stream,
												FOREGROUND_RED);
							}
							break;
						case OpSystem::Mac:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::boldRed);
							}
							break;
						case OpSystem::Linux:
							{
								stream << LogColorToColorCode(
								  details::MsgDetails::LogColor::boldRed);
							}
							break;
					}
					return stream;
				}
			}
		}
	} // namespace helper_stream_color

} // namespace serenity