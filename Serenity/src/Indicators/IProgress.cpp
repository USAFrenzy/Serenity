#include <Serenity/Indicators/IndicatorInterfaces/IProgress.h>

namespace serenity {

	IProgress::IProgress( )
	  : m_barFill(""), m_barRemainder(""), m_barWidth(50.0f), m_progress(0.0f), m_status(""), m_totalWork(0.0f)
	{
		// RegisterIndicator( );
	}

	IProgress::IProgress(IProgress& copy)
	  : m_barFill(copy.m_barFill),
	    m_barRemainder(copy.m_barRemainder),
	    m_barWidth(copy.m_barWidth),
	    m_progress(copy.m_progress),
	    m_status(copy.m_status),
	    m_totalWork(copy.m_totalWork)
	{
	}

	IProgress::~IProgress( )
	{
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
	void IProgress::RegisterIndicator( ) { }

	// Searches Through The Subscriber Vector For The Listener Object And If The Listener Object Has Been
	// Found, Removes It From The Subscriber Vector
	void IProgress::UnregisterIndicator( ) { }

	void IProgress::NotifySubscriber( )
	{
		// Was Initially thinking Of having the subscriber's update() method called here
	}

	void IProgress::Progress(float progressValue)
	{
		std::unique_lock threadLock {m_mutex};
		m_progress = progressValue;
	}

	void IProgress::UpdateProgress(float updateValue, float totalWork, std::ostream& os) { }

	void IProgress::OutputProgress(std::ostream& os) { }

	void IProgress::SetWorkload(float totalWorkload)
	{
		std::unique_lock threadLock {m_mutex};
		m_totalWork = totalWorkload;
	}

	void IProgress::SetBarWidth(float width)
	{
		std::unique_lock threadLock {m_mutex};
		m_barWidth = width;
	}

	void IProgress::FillBar(const std::string& symbol) { }

	void IProgress::FillRemainder(const std::string& symbol) { }

	void IProgress::SetStatus(const std::string& statusMessage)
	{
		std::unique_lock threadLock {m_mutex};
		m_status = statusMessage;
	}
} // namespace serenity
