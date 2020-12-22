#pragma once

#include <Serenity/Indicators/IndicatorInterfaces/IObserver.h>
#include <Serenity/Indicators/ProgressBar.h>
#include <vector>

// This Is A WIP For Progress Indicator
namespace serenity {

	namespace manager_handler {

		class ManagerHandler : public serenity::ProgressBar
		{
		      public:
			virtual void RegisterIndicator( )   = 0;
			virtual void UnregisterIndicator( ) = 0;
			virtual void NotifySubscriber( ) override { }
			virtual std::vector<serenity::ProgressBar *> GetHandle( ) = 0;
			// Leaving This Here For Now - Honestly Don't Think It's Needed Anymore
			virtual void UpdateHandle( ) { }
		};

	} // namespace manager_handler
} // namespace serenity