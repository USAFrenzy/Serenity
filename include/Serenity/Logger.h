#pragma once

#include <Serenity/SharedData.h>

#include <fstream>


namespace serenity {
	// fwd declaration
	namespace helper_ostream {
		enum class InterfaceType : unsigned int;
	}


	class Logger
	{
	      public:
		Logger(std::string loggerName);
		void Init(const std::string &fileName, const details::logger::LogOutput output);
		void Flush( );
		void Open( );
		void Close( );
		std::string LogLevelToString(details::logger::LogLevel s_level);
		void SetLoggerOstream(serenity::helper_ostream::InterfaceType osInterface);
		std::ostream *const GetLoggerOstream( );
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
		serenity::helper_ostream::InterfaceType m_ostream;
	};

} // namespace serenity