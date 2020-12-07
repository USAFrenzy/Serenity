#pragma once

#include <iostream>
#include <mutex> // For ProgressBar Class
#include <vector>

namespace serenity {

	// ToDo:  Look A ProgressManager.h Note

	//!? FIXME!!!
	//! Note: Right Now, This Is Suuuppperrr Messy And Unorganized
	//!                              Current Issue:
	//! -> Instantiation Time Unknown Size For RegisterObserver() In m_managerHandle Size
	//? Might Be Able To Pass A Solid Reference To The Base Class Or Maybe Just Perform A Move Op?
	class ProgressBar
	{
	      public:
		ProgressBar( );

		ProgressBar(ProgressBar& copy);

		~ProgressBar( );

		void Progress(float progressValue);

		// Todo: Once This Is FLushed Out, Get Rid Of totalWork Param As It's Only Used For Simulating
		// Workload
		void virtual UpdateProgress(float updateValue, float totalWork, std::ostream& os = std::cout);

		// void RegisterObserver( ) override;

		void OutputProgress(std::ostream& os = std::cout);

		void SetWorkload(float totalWorkload);

		void SetBarWidth(float width);

		void FillBar(const std::string& symbol);

		void FillRemainder(const std::string& symbol);

		void SetStatus(const std::string& statusMessage);
		static std::vector<ProgressBar> GetHandle( );

	      private:
		std::mutex m_mutex;
		std::string m_barFill {"#"};
		std::string m_barRemainder {"-"};
		std::string m_status {""};
		float m_barWidth {50.0f};
		float m_progress {0.0f};
		float m_totalWork {0.0f};
		// ProgressBar* m_instance;
	};
namespace indicator_handle {
		static std::vector<ProgressBar> m_managerHandle;
	}
} // namespace serenity