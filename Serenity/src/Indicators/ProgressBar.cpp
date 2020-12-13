#include <Serenity/Indicators/ProgressBar.h>


// ToDo:  Look A ProgressManager.h Note


namespace serenity {

	ProgressBar::ProgressBar( )
	  : m_barFill(""), m_barRemainder(""), m_barWidth(50.0f), m_progress(0.0f), m_status(""), m_totalWork(0.0f)
	{
		// RegisterIndicator( );
	}

	ProgressBar::ProgressBar(ProgressBar& copy)
	  : m_barFill(copy.m_barFill),
	    m_barRemainder(copy.m_barRemainder),
	    m_barWidth(copy.m_barWidth),
	    m_progress(copy.m_progress),
	    m_status(copy.m_status),
	    m_totalWork(copy.m_totalWork)
	{
	}

	// May Add To Ctor For Automatic Registration, Otherwise, Registration To The Manager "Observer" Would Have
	// To Be Manual. Need To Think On Whether I Want Automatically Or Manually Added "Listeners"
	//? -> One Pro To Automatic Registration Would Be That There Would Be Less Copying => Could Just Use Move
	//?    Semantics To Move This Base Class Vector Handle To The Manager Vector Reference When Manager Object
	//?    Is Instantiated?
	void ProgressBar::RegisterIndicator( )
	{
		managedIndicators.emplace_back(this);
		indicator_handle::m_refCounter++;
		UpdateManagerHandle( );
	}

	// Searches Through The Subscriber Vector For The Listener Object And If The Listener Object Has Been
	// Found, Removes It From The Subscriber Vector
	void ProgressBar::UnregisterIndicator( )
	{
		indicator_handle::ManagerHandle::iterator iteratorIndex =
		  std::find(managedIndicators.begin( ), managedIndicators.end( ), this);
		if(iteratorIndex != managedIndicators.end( )) {
			managedIndicators.erase(iteratorIndex);
		}
		indicator_handle::m_refCounter--;
		UpdateManagerHandle( );
	}

	void ProgressBar::NotifySubscriber( )
	{
		// UpdateManagerHandle() May Possibly Be Unnecessary Here -> Don't Have A Test Laid Out For It Yet
		UpdateManagerHandle( );
		// Was Initially thinking Of having the subscriber's update() method called here
	}

	void ProgressBar::Progress(float progressValue)
	{
		std::unique_lock threadLock {m_mutex};
		m_progress = progressValue;
	}

	void ProgressBar::UpdateProgress(float updateValue, float totalWork, std::ostream& os) { }

	void ProgressBar::OutputProgress(std::ostream& os) { }

	void ProgressBar::SetWorkload(float totalWorkload)
	{
		std::unique_lock threadLock {m_mutex};
		m_totalWork = totalWorkload;
	}

	void ProgressBar::SetBarWidth(float width)
	{
		std::unique_lock threadLock {m_mutex};
		m_barWidth = width;
	}

	void ProgressBar::FillBar(const std::string& symbol) { }

	void ProgressBar::FillRemainder(const std::string& symbol) { }

	void ProgressBar::SetStatus(const std::string& statusMessage)
	{
		std::unique_lock threadLock {m_mutex};
		m_status = statusMessage;
	}

	std::vector<ProgressBar*> ProgressBar::GetManagerHandle( )
	{
		return indicator_handle::m_managerHandle;
	}

	void ProgressBar::UpdateManagerHandle( )
	{
		indicator_handle::m_managerHandle = managedIndicators;
	}

	int ProgressBar::ManagerRefCount( )
	{
		return indicator_handle::m_refCounter;
	}

} // namespace serenity
