#pragma once

#include <Serenity/Indicators/IndicatorInterfaces/ObserverInterface.h>

#include <mutex>  // For Thread-Safety In ProgressBar Class
#include <vector> // Strictly For Indicator Handle Storage (May Just Create A Streamlined Vector Class For This)
#include <iostream>

namespace serenity {

	//!? FIXME!!!
	class ProgressBar : public INotifier
	{
	      public:
		ProgressBar( );

		ProgressBar(ProgressBar& copy);

		virtual ~ProgressBar( ) { };

		void Progress(float progressValue);

		// ToDo: Once This Is FLushed Out, Get Rid Of totalWork Param As It's Only Used For Simulating
		// ToDo: Workload ORRRRR Template This Function So That The updateValue And totalWork Params Can Be
		// ToDo: Substituted In For Whatever Use Case And Keep The Parameters As Is
		virtual void UpdateProgress(float updateValue, float totalWork, std::ostream& os = std::cout);

		void RegisterIndicator( ) override;
		void UnregisterIndicator( ) override;
		void NotifySubscriber( ) override;

		virtual void OutputProgress(std::ostream& os = std::cout);

		void SetWorkload(float totalWorkload);

		void SetBarWidth(float width);

		virtual void FillBar(const std::string& symbol);

		virtual void FillRemainder(const std::string& symbol);

		void SetStatus(const std::string& statusMessage);

		static int ManagerRefCount( );

		std::vector<ProgressBar*> GetManagerHandle( );

		void UpdateManagerHandle( );

		inline static std::vector<ProgressBar*> managedIndicators;

	      protected:
		std::mutex m_mutex;
		std::string m_barFill;
		std::string m_barRemainder;
		std::string m_status;
		float m_barWidth;
		float m_progress;
		float m_totalWork;
	};

	namespace indicator_handle {
		using ManagerHandle = std::vector<ProgressBar*>;

		static ManagerHandle m_managerHandle {ProgressBar::managedIndicators};
		static int m_refCounter;
	} // namespace indicator_handle

} // namespace serenity