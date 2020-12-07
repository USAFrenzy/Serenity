#pragma once

#include <iostream>
#include <vector>

#include <Serenity/Indicators/ProgressBar.h>

// This Is A WIP For Progress Indicator
namespace serenity {
	// #########################################################################################################

	//? Might be Worth Looking Into Templating Class Named As "ProgressManager" That Will Create And Manage A
	//? Vector Of Type T And Reference That Vector Through Indices To The Instance Being Observed?
	class ProgressBarManager : private ProgressBar
	{
	      public:
		ProgressBarManager( );

		~ProgressBarManager( );

		void RegisterObserver(ProgressBar& indicator);
		void UnregisterObserver( );

		int GetIndex( );

		void SetIndex( );

		//	void virtual UpdateProgress(float updateValue, float totalWork, std::ostream& os = std::cout);

	      private:
		std::vector<ProgressBar> &m_progressBars{indicator_handle::m_managerHandle};
		int m_index {0};
	};
	// #########################################################################################################
} // namespace serenity
