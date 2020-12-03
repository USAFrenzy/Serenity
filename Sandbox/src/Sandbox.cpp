#include <Windows.h> // For Resetting The Console Color For Now
#include <iostream>
#include <Serenity/Logger.h>
#include <thread>

//! Note: Take This .clang-format File And Upload For Use In Projects...Ironed
//! Out The Kinks
// This I What I'd Like To Eventually Accomplish Here...
/*
        Logger log; OR Logger("LoggerName");    
        log.setlevel(LogLevel::lvl); OR [as a global setting] SetLevel(LogLevel::lvl)
        log.setpattern("Formatting String"); OR [as a global setting] SetPattern("Formatting String")    
        log.LogOutput(LogOutput::o/p) OR [as a global setting] LogOutput(LogOutput::o/p);
        log.SetStyle(LoggerStyle::style); OR [as a global setting] SetStyle(LoggerStyle::style); // JSON, YAML, etc...
                           Now I'd Also Like To Bind Different Sink Types Together 
       i.e. Being Whether It's Solely A File/Console O/P Or Both, Colored Text Or Not, Rotating Files Or Not, File Size, etc

    */


#define Testing 1

int main( )
{
#if Testing
	std::cout << "Testing Library Header Into Sandbox... \n";
	std::cout << "Creating TestLog.txt\n\n";

	serenity::Logger log("Test Logger");
	log.Init("TestLog.txt", serenity::details::logger::LogOutput::all);
	log.Open( ); /*****************************************************************************/

	using serenity::details::logger::LogLevel;
	log.Log("Printing All Log Levels:");
	for(int i = SERENITY_TRACE; i <= SERENITY_DISABLED; i++) {
		log.SetLogLevel(( LogLevel ) i);
		log.Log(log.GetLogLevel( ));
	}
	log.Log("**********************************************************************************");


	// ToDo: Fix The Flags And Swap The Mappings For Background vs. Foreground - Fix The Reset Flag In Particular
	//?                   Possibly Implement Operator Overloading Here For Inc/Dec?

	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
	log.Log("Testing Message Flag Switches:");
	log.Log("**********************************************************************************");
	using serenity::details::MsgDetails;
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(handle, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	for(int color = 1; color < 27; color++) {
		MsgDetails::LogColor temp = static_cast<MsgDetails::LogColor>(color);
		log.SetLogColor(temp);
		log.Log(log.UseMsgColor( ) + "Console Message Flags: " + log.PrintMsgColor( ));
		SetConsoleTextAttribute(handle, wOldColorAttrs);
		//log.SetLogColor( MsgDetails::LogColor::reset);
	}
	log.Log("**********************************************************************************");
	log.Close( ); /*****************************************************************************/


	std::cout << "\nSwitching To MessageLog.txt\n";
	serenity::Logger msgLog("Message Logger");
	msgLog.Init("MessageLog.txt", serenity::details::logger::LogOutput::file);
	msgLog.Open( ); /*****************************************************************************/
	msgLog.Log("**********************************************************************************");
	float simulatedWork = 1;
	float simulatedEnd  = 225;
	ProgressBar logProgress;
	logProgress.SetStatus("Writing To MessageLog.txt");

	for(simulatedWork; simulatedWork <= simulatedEnd; ++simulatedWork) {
		logProgress.UpdateProgress(simulatedWork, simulatedEnd);
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		msgLog.Log("Simulated Work Message " + std::to_string(static_cast<int>(simulatedWork)));
	}
	ProgressBarManager logManager;
	std::cout << "**********************************************************************************\n";
	std::cout << logManager.Size( ) << std::endl;

	msgLog.Log("**********************************************************************************");

	msgLog.Close( ); /****************************************************************************/

	// This Next One, I Would Like For Debugging Purposes: Print Out That Logger's Info In Full
	// std::cout << log << std::endl;

	std::cout << "\nFinished Testing Library Header... \n\n";
	system("Pause");
#endif // Testing
}
