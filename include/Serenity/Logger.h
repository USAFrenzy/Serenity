#pragma once

#include <Serenity/SharedData.h>
#include <fstream>

namespace serenity {
	class Logger
	{
	      public:
		Logger(std::string loggerName);
		void Init(const std::string &fileName, const details::logger::LogOutput output);
		void Flush( );
		void Open( );
		void Close( );
		std::string LogLevelToString(details::logger::LogLevel s_level);
		virtual ~Logger( ) = default;

		//! Note: This Can Be Thrown In A log message standalone file; that way
		//! formatting can take place in a standalone file for the logged messages
		//!                               Planned:
		//! Log(const std::string &message, const LogOutput, std::string
		//! formatString);

		void Log(const std::string &message);
		void SetLogLevel(details::logger::LogLevel logLevel);
		std::string GetLogLevel( );

	      protected:
		std::string m_loggerName;
		details::logger::LogLevel m_logLevel;
		std::string m_fileName;
		std::fstream m_file;
		details::logger::LogOutput m_output;
		bool m_isFileOpen {false};
	};

} // namespace serenity