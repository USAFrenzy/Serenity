#pragma once

#include <Serenity/Indicators/IndicatorInterfaces/IObserver.h>

#include <mutex>  // For Thread-Safety In IProgress Class
#include <vector> // Strictly For Indicator Handle Storage (May Just Create A Streamlined Vector Class For This)
#include <iostream>

namespace serenity {

	// Making This An Abstract Class That Inherits From The INotifier Interface
	// This Is For An Attempt To Make All Underlying Derived Classes Be Of This Class Type
	class IProgress : public INotifier
	{
	      public:
		IProgress( );

		IProgress(IProgress& copy);

		virtual ~IProgress( );

		void Progress(float progressValue);

		// ToDo: Once This Is FLushed Out, Get Rid Of totalWork Param As It's Only Used For Simulating
		// ToDo: Workload ORRRRR Template This Function So That The updateValue And totalWork Params Can Be
		// ToDo: Substituted In For Whatever Use Case And Keep The Parameters As Is
		void UpdateProgress(float updateValue, float totalWork, std::ostream& os = std::cout);

		virtual void RegisterIndicator( );
		virtual void UnregisterIndicator( );
		virtual void NotifySubscriber( );

		virtual void OutputProgress(std::ostream& os = std::cout);

		void SetWorkload(float totalWorkload);

		virtual void SetBarWidth(float width);

		virtual void FillBar(const std::string& symbol);

		virtual void FillRemainder(const std::string& symbol);

		void SetStatus(const std::string& statusMessage);

		inline static std::vector<IProgress*> managedIndicators;

	      protected:
		std::mutex m_mutex;
		std::string m_barFill;
		std::string m_barRemainder;
		std::string m_status;
		float m_barWidth;
		float m_progress;
		float m_totalWork;
	};
} // namespace serenity