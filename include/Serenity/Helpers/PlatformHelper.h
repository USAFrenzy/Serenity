#pragma once

enum class OpSystem { Windows = 1, Linux, Mac };

#if defined(_WIN32) || defined(_WIN64)
	#define SERENITY_WINDOWS
constexpr OpSystem operatingSystem = OpSystem::Windows;
#elif defined(__APPLE__)
	#define SERENITY_MAC
constexpr OpSystem operatingSystem = OpSystem::Mac;
#elif defined(__unix__) || defined(__unix)
	#define SERENITY_LINUX
constexpr OpSystem operatingSystem = OpSystem::Linux;
#else
	#error unsupported platform
#endif


#if defined(SERENITY_WINDOWS)
	#include <io.h>
	#include <Windows.h>
#elif defined(SERENITY_MAC) || defined(SERENITY_LINUX)
	#include <unistd.h>
	#include <minwindef.h> // for HFILE
#endif