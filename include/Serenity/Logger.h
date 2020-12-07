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

/*
    Might be worth looking into doing something along the lines of having the current
    ProgressBar class be a base class that all styles of progress bars inherit from and then have them
    be registered in the base class by some function that determines that if that style's vector isn't empty,
    create a vector of pointers which can then be referenced by some function here that sorts through them?
    This Way, A progress object can call RegisterObserver and this will create a pointer to that progress object
    and push this pointer into a vector of pointers for that style which is then referenced here. This would
    allow control on whether a single progress object should be updated or whether we want to update all progress
    objects at once i.e. :

    ProgressBarManager manager;      ***** -> where the initialization process for this object references the
					      individual progress bar vectors, possibly by setting member variable
					      vectors = to individual progress bar vectors of each style
    DerivedbarClass foo("foobar");   ***** -> Minimal Change To Code For The Current ProgressBar Class
    foo.Register();                  ***** -> SetIndex(); bar.push_back(this_object);
    ProgressBarBase::Register();     ***** -> if(!DerivedBarVector.empty()) {baz.push_back(*this_object);}
	where 'DerivedBarVector' is the vector of that progress object's style

    This Way, one could either call foo.Update(); OR manager.Update(); depending on singular or multiple progress
    bars. The Hierarchy would look something like :
	ProgressBarManager->ProgressBar->DerivedBar_1, ...DerivedBar_n
*/