#include <Serenity/Logger.h>
#include <Serenity/Helpers/MessageHelper.h>
#include <Serenity/Helpers/OstreamHelper.h>
#include <iostream>

namespace serenity {

	Logger::Logger(std::string loggerName)
	  : m_loggerName(std::move(loggerName)),
	    m_ostream(serenity::helper_ostream::InterfaceType::cout),
	    m_logLevel(details::logger::LogLevel::trace),
	    m_output(details::logger::LogOutput::all)
	{
		serenity::helper_ostream::global_ostream =
		  serenity::helper_ostream::InterfaceTypeToStr(this->m_ostream);
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

	// Would Be Used For Either Setting ostream to cout, cerr, or clog
	void Logger::SetLoggerOstream(serenity::helper_ostream::InterfaceType osInterface)
	{
		serenity::helper_ostream::SetOstreamType(osInterface);
	}

	std::ostream *const Logger::GetLoggerOstream( )
	{
		return serenity::helper_ostream::GetOstreamType( );
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

	// auto MapLogLevelToOstreamType(serenity::details::logger::LogLevel logLevel)
	//{
	//	std::map<serenity::details::logger::LogLevel, serenity::helper_ostream::InterfaceType> ostreamMap =
	//{

	//	  {details::logger::LogLevel::trace},
	//	  {details::logger::LogLevel::info},
	//	  {details::logger::LogLevel::warning},
	//	  {details::logger::LogLevel::debug},
	//	};
	//}
	//! Note: This Can Be Thrown In A log message standalone file; that way
	//! formatting can take place in a standalone file for the logged messages
	void Logger::Log(const std::string &message)
	{
		switch(m_output) {
			case details::logger::LogOutput::file:
				{
					//!? ###################################################
					//!? #          This Is Currently A Bug                #
					//!? ###################################################
					//!? auto *temp = GetLoggerOstream( );
					//!? serenity::helper_message::UseMsgColor(*temp)
					//? Possible Causes May Be From The Indirection To helper_ostream Functions
					// ToDo: Look Into helper_ostream namespace functions

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