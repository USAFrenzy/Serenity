#include <Serenity/Indicators/ProgressBar.h>

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

	ProgressBar::~ProgressBar( )
	{
		for(auto indicators : managedIndicators) {
			delete indicators;
		}
		managedIndicators.clear( );
		if(!managedIndicators.empty( )) {
			std::cout << "Pointer Vector Not Empty - Memory Leak Possible!\n";
		}
	}


	// May Add To Ctor For Automatic Registration, Otherwise, Registration To The Manager "Observer" Would Have
	// To Be Manual. Need To Think On Whether I Want Automatically Or Manually Added "Listeners"
	//? -> One Pro To Automatic Registration Would Be That There Would Be Less Copying => Could Just Use Move
	//?    Semantics To Move This Base Class Vector Handle To The Manager Vector Reference When Manager Object
	//?    Is Instantiated?
	void ProgressBar::RegisterIndicator( ) { }

	// Searches Through The Subscriber Vector For The Listener Object And If The Listener Object Has Been
	// Found, Removes It From The Subscriber Vector
	void ProgressBar::UnregisterIndicator( ) { }

	void ProgressBar::NotifySubscriber( )
	{
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
} // namespace serenity
