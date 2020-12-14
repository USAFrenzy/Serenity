#include <Serenity/Logger.h>
#include <iostream>

namespace serenity {

	Logger::Logger(std::string loggerName)
	  : m_loggerName(std::move(loggerName)),

	    m_logLevel(details::logger::LogLevel::trace),
	    m_output(details::logger::LogOutput::all)
	{
	}

	void Logger::Init(const std::string &fileName, const details::logger::LogOutput output)
	{
		m_fileName = fileName;
		m_output   = output;
	}

	void Logger::Open( )
	{
		if(m_isFileOpen) {
			return;
		}
		if(m_output == details::logger::LogOutput::all || m_output == details::logger::LogOutput::file) {
			m_file.open(m_fileName, std::ios::out);
			m_isFileOpen = m_file.is_open( );
			if(!m_isFileOpen) {
				// TODO: Either Do A Try, Throw, Catch Here Or Maybe Just Wrap An Assertion Here
				throw std::runtime_error("Log File Not Able To Be Opened.");
			}
		} else {
			m_isFileOpen = true;
		}
	}

	void Logger::Close( )
	{
		Flush( );
		if(m_output == details::logger::LogOutput::all || m_output == details::logger::LogOutput::file) {
			m_file.close( );
		}
	}

	void Logger::Flush( )
	{
		if(m_output == details::logger::LogOutput::all || m_output == details::logger::LogOutput::file) {
			m_file.flush( );
		}
	}
	std::string Logger::LogLevelToString(details::logger::LogLevel s_level)
	{
		std::map<details::logger::LogLevel, std::string> logLevelMap = {
		  {details::logger::LogLevel::trace, "TRACE"},
		  {details::logger::LogLevel::info, "INFO"},
		  {details::logger::LogLevel::warning, "WARNING"},
		  {details::logger::LogLevel::debug, "DEBUG"},
		  {details::logger::LogLevel::error, "ERROR"},
		  {details::logger::LogLevel::fatal, "FATAL"},
		  {details::logger::LogLevel::off, "DISABLED"}};

		std::string resultString = "NONE";
		auto iterator            = logLevelMap.find(s_level);
		if(iterator != logLevelMap.end( )) {
			resultString = iterator->second;
		}
		return resultString;
	}

	//! Note: This Can Be Thrown In A log message standalone file; that way
	//! formatting can take place in a standalone file for the logged messages
	void Logger::Log(const std::string &message)
	{
		switch(m_output) {
			case details::logger::LogOutput::file:
				{
					std::ofstream log(m_fileName, std::ios_base::out | std::ios_base::app);
					log << m_loggerName << ": " << message << '\n';
					log.close( );
				}
				break;
			case details::logger::LogOutput::console:
				{
					std::cout << m_loggerName << ": " << message << "\n";
				}
				break;
			case details::logger::LogOutput::all:
				{
					std::cout << m_loggerName << ": " << message << "\n";

					std::ofstream log(m_fileName, std::ios_base::out | std::ios_base::app);
					log << m_loggerName << ": " << message << '\n';
					log.close( );
				}
				break;
			case details::logger::LogOutput::none:
				{
				}
				break;
			default: std::cout << "Unable To Log Messages" << std::endl; break;
		}
	}

	// Independently Sets The Logger's Log Level
	void Logger::SetLogLevel(details::logger::LogLevel logLevel)
	{
		m_logLevel = logLevel;
	}
	std::string Logger::GetLogLevel( )
	{
		std::string lvlStr = LogLevelToString(m_logLevel);
		return lvlStr;
	}


} // namespace serenity