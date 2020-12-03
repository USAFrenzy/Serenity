#pragma once

#include <iostream>
#include <mutex> // For ProgressBar Class
#include <vector>

// This Is A WIP For Progress Indicator

// #########################################################################################################

//? Might be Worth Looking Into Templating Class Named As "ProgressManager" That Will Create And Manage A
//? Vector Of Type T And Reference That Vector Through Indices To The Instance Being Observed?
class ProgressBarManager
{
	class ProgressBar;

      public:
	ProgressBarManager( ) { }
	~ProgressBarManager( ) { }
	//? This Is Currently A Quick Hack - No Viable Way To Search For And Reference Specific Instance Yet
	//? No Way To Search For And Unregister An Instance Either -> Maybe Look Into Templating/Reference
	// Wrapping?
	virtual void RegisterObserver( ) { }

	std::vector<ProgressBar>& GetManagerHandle( )
	{
		return this->listOfBars;
	}

	auto Size( )
	{
		return listOfBars.size( );
	}
	virtual void UpdateProgress(float updateValue, float totalWork, std::ostream& os = std::cout)
	{
		/*for(auto progressBarInstance : listOfBars.begin( )) {
		}*/
	}

      private:
	std::vector<ProgressBar> listOfBars;
};
// #########################################################################################################

//!? FIXME!!!
//! Note: Right Now, This Is Suuuppperrr Messy And Unorganized                    
//!                              Current Issue:                                   
//! -> Instantiation Time Unknown Size For RegisterObserver() In m_managerHandle Size
//? Might Be Able To Pass A Solid Reference To The Base Class Or Maybe Just Perform A Move Op?
class ProgressBar : public ProgressBarManager 
{
      public:
	ProgressBar( )
	{
		RegisterObserver( );
	}

	ProgressBar(ProgressBar&)
	{
		// RegisterObserver( );
	}
	~ProgressBar( )
	{
		delete this->m_instance;
		m_managerHandle.shrink_to_fit( );
	}

	void Progress(float progressValue)
	{
		std::unique_lock threadLock {m_mutex};
		m_progress = progressValue;
	}

	// Todo: Once This Is FLushed Out, Get Rid Of totalWork Param As It's Only Used For Simulating Workload
	void UpdateProgress(float updateValue, float totalWork, std::ostream& os = std::cout) override
	{
		for(auto element : m_managerHandle) {
			SetWorkload(totalWork);
			Progress(updateValue);
			OutputProgress(os);
		}
	}

	void RegisterObserver( ) override
	{
		ProgressBar* object = new ProgressBar( );
		auto m_managerHandle     = & GetManagerHandle( );
		m_instance          = object;
		m_managerHandle->emplace_back(&object);
	}
	void OutputProgress(std::ostream& os = std::cout)
	{
		std::unique_lock threadLock {m_mutex};
		// Check The Progress Status And Output The Updated Visual Progress Indicator As Well As
		// The Updated Percentage Completed And The Status Message Corresponding To The Process

		float i                     = 0.0f;
		float completedRatio        = ((m_progress / m_totalWork));
		const float finshedProgress = (completedRatio * m_barWidth);
		int percentage              = static_cast<int>(completedRatio * 100.0f);

		if(m_progress > m_totalWork) {
			return;
		}
		os << "\r" << std::flush;
		os << "[";
		for(i; i < m_barWidth; ++i) {
			(i <= finshedProgress) ? (os << m_barFill) : (os << m_barRemainder);
		}
		os << "]";
		os << " " << percentage << "%";
		os << " " << m_status;
	}
	void SetWorkload(float totalWorkload)
	{
		std::unique_lock threadLock {m_mutex};
		m_totalWork = totalWorkload;
	}

	void SetBarWidth(float width)
	{
		std::unique_lock threadLock {m_mutex};
		m_barWidth = width;
	}

	void FillBar(const std::string& symbol)
	{
		std::unique_lock threadLock {m_mutex};
		m_barFill = symbol;
	}

	void FillRemainder(const std::string& symbol)
	{
		std::unique_lock threadLock {m_mutex};
		m_barRemainder = symbol;
	}

	void SetStatus(const std::string& statusMessage)
	{
		std::unique_lock threadLock {m_mutex};
		m_status = statusMessage;
	}


      private:
	std::mutex m_mutex;
	std::string m_barFill {"#"};
	std::string m_barRemainder {"-"};
	std::string m_status {""};
	float m_barWidth {50.0f};
	float m_progress {0.0f};
	float m_totalWork {0.0f};
	ProgressBar* m_instance;
	std::vector<ProgressBar> m_managerHandle;
};
// #########################################################################################################