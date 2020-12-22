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
	//
	//


	/*
                            ############################################# End Of Section ##############################################
    */
	/*  
                            ###########################################################################################################
                            #                                    Logger Log Level Testing Section                                     #
                            ###########################################################################################################
    */
	log.Open( );
	log.Log("##################################");
	log.Log("#  Iterating Through Log Levels  #");
	log.Log("##################################");
	using serenity::details::logger::LogLevel;
	log.Log("Printing All Log Levels:");
	for(int i = SERENITY_TRACE; i <= SERENITY_DISABLED; i++) {
		log.SetLogLevel(( LogLevel ) i);
		log.Log(log.GetLogLevel( ));
	}
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
	log.Log("############################################");
	log.Log("# Iterating Through Message Flag Switches: #");
	log.Log("############################################");
	using serenity::details::MsgDetails;

	serenity::utilities logHelp;
	for(int color = 1; color < 19; ++color) {
		MsgDetails::LogColor temp = static_cast<MsgDetails::LogColor>(color);
		logHelp.SetLogColor(temp);
		log.Log("Console Message Flags: " + logHelp.LogColorToStr(temp));
		logHelp.SetLogStyle(MsgDetails::LogStyle::reset);
	}

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
	float simulatedEnd  = 100;
	serenity::DefaultBar logProgress;
	logProgress.serenity::IProgress::SetStatus("Writing For Loop To MessageLog.txt");

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
	std::cout << "\n\nSwitching Back To Testlog.txt\n\n";
	log.Open( );
	
	log.Log("########################################################################################");
	log.Log("#    Now Current manager's GetHandle(), Register/Unregister, GetRefCount() Functions   #");
	log.Log("########################################################################################");
	serenity::manager::Manager newHandle;
	newHandle.GetHandle( );
	log.Log("Initial Handle Size: " + std::to_string(newHandle.GetSize( )));
	logProgress.RegisterIndicator( );
	log.Log("Initial Handle Reference Count: " + std::to_string(newHandle.GetRefCount( )));
	log.Log("Handle Size After Registering One Indicator: " + std::to_string(newHandle.GetSize( )));
	log.Log("Handle Reference Count After Registration: " + std::to_string(newHandle.GetRefCount( )));
	logProgress.UnregisterIndicator( );
	log.Log("Handle Size After Unregistering One Indicator: " + std::to_string(newHandle.GetSize( )));
	log.Log("Handle Reference Count After Unregistration: " + std::to_string(newHandle.GetRefCount( )));
	std::cout << std::endl; // Just For Visual Clarity In Console O/P Nothing More And Nothing Less

	// #############################################################################################################

	log.Log("########################################################################################");
	log.Log("#     Bulk Creation Of Indicators And Registering/Unregistering Them In A For Loop     #");
	log.Log("########################################################################################");
	std::vector<serenity::DefaultBar*> tempIndicators;
	tempIndicators.reserve(25);

	log.Log("");
	log.Log("Initial Handle Size: " + std::to_string(newHandle.GetSize( )));
	log.Log("Initial Handle Reference Count: " + std::to_string(newHandle.GetRefCount( )));
	log.Log("");


	log.Log("###########################################");
	log.Log("#    Creating Indicators In A For Loop:   #");
	log.Log("###########################################");
	for(int i = 1; i <= 10; i++) {
		tempIndicators.emplace_back(new serenity::DefaultBar( ));
		log.Log("Indicator Number (" + std::to_string(i) + ") Created");
	}
	log.Log("");

	log.Log("###########################################");
	log.Log("#  Registering Indicators In A For Loop:  #");
	log.Log("###########################################");
	for(int i = 0; i < tempIndicators.size( ); i++) {
		tempIndicators [i]->RegisterIndicator( );
		log.Log("Handle Size After Registering Indicator: " + std::to_string(newHandle.GetSize( )));
		log.Log("Handle Reference Count After Registration: " + std::to_string(newHandle.GetRefCount( )));
	}
	log.Log("");

	log.Log("###########################################");
	log.Log("# Unregistering Indicators In A For Loop: #");
	log.Log("###########################################");
	for(int i = 0; i < tempIndicators.size( ); i++) {
		tempIndicators [i]->UnregisterIndicator( );
		log.Log("Handle Size After Unregistering Indicator: " + std::to_string(newHandle.GetSize( )));
		log.Log("Handle Ref Count After Unregistration: " + std::to_string(newHandle.GetRefCount( )));
	}

	tempIndicators.clear( );
	std::cout << std::endl; // Just For Visual Clarity In Console O/P Nothing More And Nothing Less

	log.Close( );
	// This Next One, I Would Like For Debugging Purposes: Print Out That Logger's Info In Full
	// std::cout << log << std::endl;

	/*
                            ############################################# End Of Section ##############################################
    */


	/*  
                            ###########################################################################################################
                            #                        Misc Sandbox For Testing And Wrapping Up The Testing Section                     #
                            ###########################################################################################################
    */
	log.Open( );
	log.Log("############################################################");
	log.Log("# Information On The Size Of The Current Classes In Bytes: #");
	log.Log("############################################################");
	log.Log("Size of Progress Bar Class: " + std::to_string(sizeof(serenity::IProgress)) + " Bytes");
	log.Log("Size of Default Bar Class: " + std::to_string(sizeof(serenity::DefaultBar)) + " Bytes");
	log.Log("Size of the Now Current Manager Class: " + std::to_string(sizeof(serenity::manager::Manager)) + " Bytes");
	log.Log("############################################################");
	log.Close( );

	std::cout << "\n**********************************************************************************";
	std::cout << "\n\n\t\t\tFinished Testing Library Header...\n\n";
	std::cout << "**********************************************************************************\n";

	// Just Pausing Agnostically and getting rid of the 'return type ignored' - nothing useful and will be discarded anyways
	#if _DEBUG
	char val = std::getchar( );
	#endif
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