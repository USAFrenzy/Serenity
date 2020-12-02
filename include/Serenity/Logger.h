#pragma once

#include <Serenity/SharedData.h>
#include <fstream>
#include <iomanip>

namespace serenity {
	class Logger : public details::MsgDetails, public serenity::utilities
	{

	      private:
		using LogLevel  = serenity::details::logger::LogLevel;
		using LogOutput = serenity::details::logger::LogOutput;

	      public:
		Logger(std::string loggerName);
		void Init(const std::string &fileName, const LogOutput output);
		void Flush( );
		void Open( );
		void Close( );
		std::string LogLevelToString(serenity::details::logger::LogLevel s_level);
		virtual ~Logger( ) = default;

		//! Note: This Can Be Thrown In A log message standalone file; that way
		//! formatting can take place in a standalone file for the logged messages
		//!                               Planned:
		//! Log(const std::string &message, const LogOutput, std::string
		//! formatString);

		void Log(const std::string &message);
		void SetLogLevel(serenity::details::logger::LogLevel logLevel);
		std::string GetLogLevel( );

	      private:
		std::string m_loggerName;
		LogLevel m_logLevel;
		std::string m_fileName;
		std::fstream m_file;
		LogOutput m_output;
		bool m_isFileOpen {false};
	};

} // namespace serenity

