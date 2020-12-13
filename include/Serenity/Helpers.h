#pragma once

#include <SharedData.h>

enum class OpSystem { Windows = 1, Linux, Mac };

#if defined(_WIN32) || defined(_WIN64)
	#define SERENITY_WINDOWS
constexpr operatingSystem = OpSystem::Windows;
#elif defined(__APPLE__)
	#define SERENITY_MAC
constexpr operatingSystem = OpSystem::Mac;
#elif defined(__unix__) || defined(__unix)
	#define SERENITY_LINUX
constexpr operatingSystem = OpSystem::Linux;
#else
	#error unsupported platform
#endif

#if defined(SERENITY_WINDOWS)
	#if defined(_MSC_VER)
		#if !defined(NOMINMAX)
			#define NOMINMAX
		#endif
		#include <io.h>
		#include <windows.h>
	#endif
#elif defined(SERENITY_MAC) || defined(SERENITY_LINUX)
	#include <unistd.h>
#endif

namespace helper_color {

	// iword index allocation set to the colorIndex variable
	static int colorIndex = std::ios_base::xalloc( );

	inline FILE* GetStdStream(const std::ostream& stream);
	inline bool isColored(std::ostream& stream);
	inline bool is_atty(const std::ostream& stream);

#if defined(SERENITY_WINDOWS)
	//? background = -1?
	inline void windowAttributes(std::ostream& stream, int foreground, int background);
#endif
	// 'colored' And 'uncolored' Are Used As Flags Here For The isColored() Function To Take Advantage Of
	// Boolean Return Types Rather Than Converting The Index To A Boolean Type And Testing Against That

	// Sets The Stream To Be Colored By Setting The Streams iword Index Flag To A Long 0
	inline std::ostream& colored(std::ostream& stream)
	{
		stream.iword(colorIndex) = 0L;
	}
	// Sets The Stream To Be UnColored By Setting The Streams iword Index Flag To A Long 1 (Default Behavior)
	inline std::ostream& uncolored(std::ostream& stream)
	{
		stream.iword(colorIndex) = 1L;
	}

	// For Sanity's Sake Here
	using MsgColor = serenity::details::MsgDetails::LogColor;

	inline std::ostream& reset(std::ostream stream)
	{
		switch(operatingSystem) {
			case OpSystem::Windows:
				{
					windowAttributes(stream, -1, -1);
				}
				break;
			case OpSystem::Mac || OpSystem::Linux:
				{
					stream << MsgColor::reset;
				}
				break;
		}
	}
	// ToDo: Flush The Rest Of The Choices Out For LogColor And LogStyle

} // namespace helper_color