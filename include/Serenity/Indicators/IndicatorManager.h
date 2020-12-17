#pragma once

#include <Serenity/Indicators/IndicatorInterfaces/ObserverInterface.h>
#include <Serenity/Indicators/ProgressBar.h>

// This Is A WIP For Progress Indicator
namespace serenity {
	class IndicatorManager : public ISubscriber
	{
	      public:
		IndicatorManager( );

		~IndicatorManager( );

		void Update(float updateValue, float totalWork, std::ostream &os = std::cout) override;

	      private:
		ProgressBar m_updater { }; // ToDo: REMOVE ME!!!! THIS ISN'T WORTH 224 BYTES
		indicator_handle::ManagerHandle m_progressBars;
	};

	// Alright So In Practice The ManagerHandle Interface Would Be Like So:
	class Manager : public ManagerHandler, public ISubscriber, public ProgressBar
	{
	      public:
		Manager( ) { }

		~Manager( ) { }

		void Update(float updateValue, float totalWork, std::ostream &os = std::cout) override { }
	};

} // namespace serenity
