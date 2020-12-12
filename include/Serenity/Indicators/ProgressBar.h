#pragma once

#include <iostream>
#include <mutex>  // For Thread-Safety In ProgressBar Class
#include <vector> // Strictly For Indicator Handle Storage (May Just Create A Streamlined Vector Class For This)

#include <Serenity/Indicators/ObserverInterface.h>

// ToDo:  Look At ProgressManager.h Note

namespace serenity {
	using ManagerHandle = std::vector<Subscriber*>;

	//!? FIXME!!!
	class ProgressBar : public Notifier
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

		void RegisterIndicator(Subscriber* managerListener) override;
		void UnregisterIndicator(Subscriber* managerListener) override;
		void NotifySubscriber( ) override;

		virtual void OutputProgress(std::ostream& os = std::cout);

		void SetWorkload(float totalWorkload);

		void SetBarWidth(float width);

		virtual void FillBar(const std::string& symbol);

		virtual void FillRemainder(const std::string& symbol);

		void SetStatus(const std::string& statusMessage);
		ManagerHandle GetHandle( );

		void UpdateHandle( );

		static int HandleRef( );

	      protected:
		std::mutex m_mutex;
		std::string m_barFill;
		std::string m_barRemainder;
		std::string m_status;
		float m_barWidth;
		float m_progress;
		float m_totalWork;
		std::vector<Subscriber*> managerSubscribers;
	};

	namespace indicator_handle {
		static ManagerHandle m_managerHandle;
		static int m_refCounter;
	} // namespace indicator_handle

} // namespace serenity