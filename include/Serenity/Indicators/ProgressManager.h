#pragma once

#include <iostream>
#include <vector>

#include <Serenity/Indicators/ProgressBar.h>

// This Is A WIP For Progress Indicator
namespace serenity {
	// #########################################################################################################

	//? Might be Worth Looking Into Templating Class Named As "ProgressManager" That Will Create And Manage A
	//? Vector Of Type T And Reference That Vector Through Indices To The Instance Being Observed?
	class ProgressBarManager : public ProgressBar
	{

	      public:
		ProgressBarManager( );

		~ProgressBarManager( );

		virtual void RegisterObserver( );		

		void UpdateProgress(float updateValue, float totalWork, std::ostream& os = std::cout) override;

	      private:
	};
	// #########################################################################################################
} // namespace serenity
