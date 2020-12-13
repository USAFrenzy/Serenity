#include <consoleapi2.h> // for GetConsoleScreenBufferInfo, SetConsoleTextAttribute, CONSOLE_SCREEN_BUFFER_INFO
#include <minwindef.h>   // for WORD
#include <process.h>     // for system
#include <processenv.h>  // for GetStdHandle
#include <WinBase.h>     // for STD_OUTPUT_HANDLE
#include <string>       // IWYU pragma: keep

#include <Serenity/Indicators/DefaultIndicator.h>
#include <Serenity/Indicators/IndicatorManager.h>
#include <Serenity/Logger.h>
#include <Serenity/SharedData.h> // for LogLevel, LogOutput, MsgDetails, MsgDetails::LogColor, LogOutput::all, LogOutput::file, SERENITY_DISABLED, SERENITY_TRACE

//! Note: Take This .clang-format File And Upload For Use In Projects...Ironed
//! Out The Kinks

// ToDo:  Look At ProgressManager.h Note

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


	// ToDo: Fix The Reset Flag
	// ToDo: Handle Color Output Text In Library Function Rather Than Explicitly Like Below
	//?      Possibly Implement Operator Overloading Here For Inc/Dec?

	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
	log.Log("Testing Message Flag Switches:");
	log.Log("**********************************************************************************");
	using serenity::details::MsgDetails;
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(handle, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	for(int color = 1; color <= 19; color++) {
		MsgDetails::LogColor temp = static_cast<MsgDetails::LogColor>(color);
		log.SetLogColor(temp);
		log.Log(log.UseMsgColor( ) + "Console Message Flags: " + log.PrintColorAsText( ));
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
	float simulatedEnd  = 500;
	serenity::DefaultBar logProgress;
	serenity::IndicatorManager manager;
	logProgress.SetStatus("Writing For Loop To MessageLog.txt");

	for(simulatedWork; simulatedWork <= simulatedEnd; ++simulatedWork) {
		logProgress.UpdateProgress(simulatedWork, simulatedEnd);
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		msgLog.Log("Simulated Work Message: " + std::to_string(static_cast<int>(simulatedWork)));
	}
	msgLog.Log("**********************************************************************************");
	msgLog.Close( ); /****************************************************************************/

	std::cout << "\n\nSwitching Back To Testlog.txt\n\n";
	log.Open( ); /****************************************************************************/
	log.Log("Testing The Register Observer Func");
	serenity::indicator_handle::ManagerHandle indicatorHandle = logProgress.GetManagerHandle( );
	log.Log("Handle Vector Size: " + std::to_string(logProgress.ManagerRefCount( )));
	logProgress.RegisterIndicator( );
	log.Log("Registered One Indicator");
	log.Log("Handle Vector Size: " + std::to_string(logProgress.ManagerRefCount( )));
	log.Log("Testing The Unregister Observer Func");
	log.Log("Handle Vector Size: " + std::to_string(logProgress.ManagerRefCount( )));
	logProgress.UnregisterIndicator( );
	log.Log("Unregistered One Indicator");
	log.Log("Handle Vector Size: " + std::to_string(logProgress.ManagerRefCount( )));
	log.Close( ); /****************************************************************************/

	std::cout << "\n\n**********************************************************************************\n";

	// This Next One, I Would Like For Debugging Purposes: Print Out That Logger's Info In Full
	// std::cout << log << std::endl;
	std::cout << "\n\t\t\tFinished Testing Library Header...\n\n";
	std::cout << "\n**********************************************************************************\n";
	system("Pause");
#endif // Testing
}
