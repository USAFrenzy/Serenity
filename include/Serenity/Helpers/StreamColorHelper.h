#pragma once

#include <Serenity/SharedData.h>
#include <Serenity/Helpers/Utilities.h>
#include <Serenity/Helpers/StreamHelper.h>

#include <ostream>

namespace serenity {
	namespace helper_stream_color {

		inline std::ostream& black(std::ostream& stream)
		{
			if(helper_stream::isColored(stream)) {
				switch(operatingSystem) {
					case OpSystem::Windows:
						{
							helper_stream::windowAttributes(stream, 0);
							return stream;
						}
						break;
					case OpSystem::Mac:
						{
							stream << serenity::utilities::LogColorToColorCode(
							  details::MsgDetails::LogColor::black);
							return stream;
						}
						break;
					case OpSystem::Linux:
						{
							stream << serenity::utilities::LogColorToColorCode(
							  details::MsgDetails::LogColor::black);
							return stream;
						}
						break;
					default:
						{
							return stream;
						}
						break;
				}
			}
		}

		inline std::ostream& red(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								helper_stream::windowAttributes(stream,
												FOREGROUND_RED);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::red);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::red);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}

		inline std::ostream& green(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								helper_stream::windowAttributes(stream,
												FOREGROUND_GREEN);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::green);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::green);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}

		inline std::ostream& yellow(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								helper_stream::windowAttributes(stream,
												FOREGROUND_GREEN |
												  FOREGROUND_RED);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::yellow);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::yellow);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}

		inline std::ostream& blue(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								helper_stream::windowAttributes(stream,
												FOREGROUND_BLUE);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::blue);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::blue);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}

		inline std::ostream& magenta(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								helper_stream::windowAttributes(stream,
												FOREGROUND_BLUE |
												  FOREGROUND_RED);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::magenta);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::magenta);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}

		inline std::ostream& cyan(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								helper_stream::windowAttributes(
								  stream,
								  FOREGROUND_BLUE | FOREGROUND_GREEN);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::cyan);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::cyan);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}

		inline std::ostream& white(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								helper_stream::windowAttributes(
								  stream,
								  FOREGROUND_BLUE | FOREGROUND_GREEN |
								    FOREGROUND_RED);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::white);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::white);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}

		inline std::ostream& bgBlack(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								helper_stream::windowAttributes(stream, -1, 0);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgBlack);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgBlack);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}
		inline std::ostream& bgRed(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								helper_stream::windowAttributes(stream,
												-1,
												BACKGROUND_RED);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgRed);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgRed);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}

		inline std::ostream& bgGreen(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								helper_stream::windowAttributes(stream,
												-1,
												BACKGROUND_GREEN);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgGreen);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgGreen);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}

		inline std::ostream& bgYellow(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								helper_stream::windowAttributes(stream,
												-1,
												BACKGROUND_GREEN |
												  BACKGROUND_RED);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgYellow);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgYellow);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}

		inline std::ostream& bgBlue(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								helper_stream::windowAttributes(stream,
												-1,
												BACKGROUND_BLUE);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgBlue);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgBlue);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}

		inline std::ostream& bgMagenta(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								helper_stream::windowAttributes(stream,
												-1,
												BACKGROUND_BLUE |
												  BACKGROUND_RED);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgMagenta);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgMagenta);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}

		inline std::ostream& bgCyan(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								helper_stream::windowAttributes(stream,
												-1,
												BACKGROUND_GREEN |
												  BACKGROUND_BLUE);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgCyan);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgCyan);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}

		inline std::ostream& bgWhite(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								helper_stream::windowAttributes(stream,
												-1,
												BACKGROUND_GREEN |
												  BACKGROUND_BLUE |
												  BACKGROUND_RED);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgWhite);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::bgWhite);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}

		inline std::ostream& boldYellow(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								// Just Plain Ol' Yellow For Windows
								helper_stream::windowAttributes(stream,
												FOREGROUND_GREEN |
												  FOREGROUND_RED);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::boldYellow);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::boldYellow);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}

		inline std::ostream& boldRed(std::ostream& stream)
		{
			{
				if(helper_stream::isColored(stream)) {
					switch(operatingSystem) {
						case OpSystem::Windows:
							{
								// Just Plain Ol' Red For Windows
								helper_stream::windowAttributes(stream,
												FOREGROUND_RED);
								return stream;
							}
							break;
						case OpSystem::Mac:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::boldRed);
								return stream;
							}
							break;
						case OpSystem::Linux:
							{
								stream << serenity::utilities::LogColorToColorCode(
								  details::MsgDetails::LogColor::boldRed);
								return stream;
							}
							break;
						default:
							{
								return stream;
							}
							break;
					}
				}
			}
		}
	} // namespace helper_stream_color

} // namespace serenity