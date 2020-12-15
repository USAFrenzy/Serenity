#pragma once

#include <Serenity/Common/SharedData.h>
#include <Serenity/Helpers/Utilities.h>

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
		void SetLoggerOstream(serenity::helper_ostream::OstreamInterface::InterfaceType osInterface);
		std::ostream *const GetLoggerOstream( );
		void SetLogLevel(details::logger::LogLevel logLevel);
		std::string GetLogLevel( );
		virtual ~Logger( ) = default;

		//! Note: This Can Be Thrown In A log message standalone file; that way
		//! formatting can take place in a standalone file for the logged messages
		void Log(const std::string &message);

	      protected:
		std::string m_loggerName;
		details::logger::LogLevel m_logLevel;
		std::string m_fileName;
		std::fstream m_file;
		details::logger::LogOutput m_output;
		bool m_isFileOpen {false};
		serenity::helper_ostream::OstreamInterface::InterfaceType m_ostream;
	};

} // namespace serenity