#pragma once

#include <iostream>
#include <mutex>  // For Thread-Safety In ProgressBar Class
#include <vector> // Strictly For Indicator Handle Storage (May Just Create A Streamlined Vector Class For This)

//! Note: Right Now, This Is Suuuppperrr Messy And Unorganized
// ToDo:  Look A ProgressManager.h Note

namespace serenity {

	//!? FIXME!!!
	class ProgressBar
	{
	      public:
		ProgressBar( );

		ProgressBar(ProgressBar& copy);

		virtual ~ProgressBar( ) { };

		void Progress(float progressValue);

		// Todo: Once This Is FLushed Out, Get Rid Of totalWork Param As It's Only Used For Simulating
		// Workload
		virtual void UpdateProgress(float updateValue, float totalWork, std::ostream& os = std::cout);

		void RegisterObserver( );
		void UnregisterObserver( );

		virtual void OutputProgress(std::ostream& os = std::cout);

		void SetWorkload(float totalWorkload);

		void SetBarWidth(float width);

		virtual void FillBar(const std::string& symbol);

		virtual void FillRemainder(const std::string& symbol);

		void SetStatus(const std::string& statusMessage);

		static std::vector<ProgressBar*> GetHandle( );

	      protected:
		std::mutex m_mutex;
		std::string m_barFill;
		std::string m_barRemainder;
		std::string m_status;
		float m_barWidth;
		float m_progress;
		float m_totalWork;
		int m_index;
	};

	namespace indicator_handle {
		static std::vector<ProgressBar*> m_managerHandle;
		static int m_handleIndex {0};
	} // namespace indicator_handle

} // namespace serenity