#include <Serenity/Common/SharedData.h>
#include <Serenity/Helpers/Utilities.h>

#include <Serenity/Logger/Logger.h>

#include <Serenity/Indicators/IndicatorManager.h>
#include <Serenity/Indicators/DefaultIndicator.h>

#include <string>

#define Testing 1

int main( )
{
#if Testing
	/*  
                            ###########################################################################################################
                            #                                 Logger Initialization Section                                           #
                            ###########################################################################################################
    */
	std::cout << "Testing Library Header Into Sandbox... \n";
	std::cout << "Creating TestLog.txt\n\n";
	serenity::Logger log("Test Logger");
	log.Init("TestLog.txt", serenity::details::logger::LogOutput::all);

	/*
                            ############################################# End Of Section ##############################################
    */
	/*  
                            ###########################################################################################################
                            #                                    Logger Log Level Testing Section                                     #
                            ###########################################################################################################
    */
	log.Open( );
	using serenity::details::logger::LogLevel;
	log.Log("Printing All Log Levels:");
	for(int i = SERENITY_TRACE; i <= SERENITY_DISABLED; i++) {
		log.SetLogLevel(( LogLevel ) i);
		log.Log(log.GetLogLevel( ));
	}
	log.Log("**********************************************************************************");
	log.Close( );
	/*
                            ############################################# End Of Section ###############################################

   */
	/*  
                            ###########################################################################################################
                            #                                    Logger Log Color Testing Section                                     #
                            ###########################################################################################################
    */
	//!? ####################################################################################################################
	//!? #                                                     BUG                                                          #
	//!? ####################################################################################################################
	//!? # Removed UseMsgColor() -> Currently Bugged Usage Where It Only Returns Black Foreground And Black Background Text #
	//!? ####################################################################################################################

	//! ##########################################################################################################################################
	//! #                                             Intended Usage Of The Basic Log Function:                                                  #
	//! ##########################################################################################################################################
	//! Message To Buffer->Format Message Based On Args[like fmt](Color, Placement, etc...)->Color Stream->Formatted Message ->Reset Color Stream

	//!  ##########################################################################################################################################
	//!  #                                                               NOTE:                                                                    #
	//!  #     Currently Hacked The Utility Functions In The Form Of 'logHelp' Variable For Color Functions Until Wrapped Into Log() Function     #
	//!  ##########################################################################################################################################

	log.Open( );
	log.Log("Testing Message Flag Switches:");
	log.Log("**********************************************************************************");
	using serenity::details::MsgDetails;

	serenity::utilities logHelp;
	for(int color = 1; color < 19; ++color) {
		MsgDetails::LogColor temp = static_cast<MsgDetails::LogColor>(color);
		logHelp.SetLogColor(temp);
		log.Log("Console Message Flags: " + logHelp.LogColorToStr(temp));
		logHelp.SetLogStyle(MsgDetails::LogStyle::reset);
	}

	log.Log("**********************************************************************************");
	log.Close( );
	/*
                            ############################################# End Of Section ##############################################
    */
	/*  
                            ###########################################################################################################
                            #                       Logger Logging And Progress Indication Testing Section                            #
                            ###########################################################################################################
    */

	std::cout << "\nSwitching To MessageLog.txt\n";
	serenity::Logger msgLog("Message Logger");
	msgLog.Init("MessageLog.txt", serenity::details::logger::LogOutput::file);
	msgLog.Open( );
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
	msgLog.Close( );
	/*
                            ############################################# End Of Section ##############################################
    */

	/*  
                            ###########################################################################################################
                            #                           Logger Registration And Management Testing Section                            #
                            ###########################################################################################################
    */

	serenity::indicator_handle::ManagerHandle indicatorHandle = logProgress.GetManagerHandle( );
	std::cout << "\n\nSwitching Back To Testlog.txt\n\n";
	log.Open( );
	log.Log("Testing The Register Observer Func -> Initial Handle Reference Count: " +
		std::to_string(logProgress.ManagerRefCount( )));
	logProgress.RegisterIndicator( );
	log.Log("Registered One Indicator -> Handle Reference Count: " +
		std::to_string(logProgress.ManagerRefCount( )));

	// This Is Kind Of A Hacked Way Of Updating The Handle After Assignment
	indicatorHandle = logProgress.GetManagerHandle( );

	log.Log("Passed Handle Size For Comparison: " + std::to_string(indicatorHandle.size( )));
	log.Log("Testing The Unregister Observer Func -> Initial Handle Reference Count: " +
		std::to_string(logProgress.ManagerRefCount( )));
	logProgress.UnregisterIndicator( );
	log.Log("Unregistered One Indicator -> Handle Reference Count: " +
		std::to_string(logProgress.ManagerRefCount( )));

	// This Is Kind Of A Hacked Way Of Updating The Handle After Assignment
	indicatorHandle = logProgress.GetManagerHandle( );

	log.Log("Passed Handle Size For Comparison: " + std::to_string(indicatorHandle.size( )));
	log.Close( );

	std::cout << "\n\n**********************************************************************************\n";
	/*
                            ############################################# End Of Section ##############################################
    */


	/*  
                            ###########################################################################################################
                            #                        Misc Sandbox For Testing And Wrapping Up The Testing Section                     #
                            ###########################################################################################################
    */


	// This Next One, I Would Like For Debugging Purposes: Print Out That Logger's Info In Full
	// std::cout << log << std::endl;
	std::cout << "\n\t\t\tFinished Testing Library Header...\n\n";
	std::cout << "\n**********************************************************************************\n";
	system("Pause");

	/*
                            ############################################# End Of Section ##############################################
    */
#endif // Testing

	/*  
                            ###########################################################################################################
                            #                             Misc Sandbox And Everything Else Section                                  #
                            ###########################################################################################################
    */
}
