#include <Serenity/Indicators/ProgressBar.h>


// ToDo:  Look A ProgressManager.h Note


namespace serenity {

	ProgressBar::ProgressBar( )
	  : m_barFill(""),
	    m_barRemainder(""),
	    m_barWidth(50.0f),
	    m_progress(0.0f),
	    m_status(""),
	    m_totalWork(0.0f)
	{
		// RegisterObserver( );
	}

	ProgressBar::ProgressBar(ProgressBar& copy)
	  : m_barFill(copy.m_barFill),
	    m_barRemainder(copy.m_barRemainder),
	    m_barWidth(copy.m_barWidth),
	    m_progress(copy.m_progress),
	    m_status(copy.m_status),
	    m_totalWork(copy.m_totalWork)
	{
		// RegisterObserver( );
	}

	// void ProgressBar::RegisterObserver( ) override
	//{
	//	ProgressBar* object = new ProgressBar( );
	//	auto m_managerHandle     = & GetManagerHandle( );
	//	m_instance          = object;
	//	m_managerHandle->emplace_back(&object);
	//}

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

	std::vector<ProgressBar> ProgressBar::GetHandle( )
	{
		return indicator_handle::m_managerHandle;
	}

} // namespace serenity
