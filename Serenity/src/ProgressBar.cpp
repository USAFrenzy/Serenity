#include <Serenity/Indicators/ProgressBar.h>

namespace serenity {
	ProgressBar::ProgressBar( )
	{
		// RegisterObserver( );
	}

	ProgressBar::ProgressBar(ProgressBar&)
	{
		// RegisterObserver( );
	}

	ProgressBar::~ProgressBar( ) { }

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

	void ProgressBar::SetStatus(const std::string& statusMessage)
	{
		std::unique_lock threadLock {m_mutex};
		m_status = statusMessage;
	}


	void ProgressBar::UpdateProgress(float updateValue, float totalWork, std::ostream& os)
	{
		SetWorkload(totalWork);
		Progress(updateValue);
		OutputProgress(os);
	}

	void ProgressBar::FillBar(const std::string& symbol)
	{
		std::unique_lock threadLock {m_mutex};
		m_barFill = symbol;
	}

	void ProgressBar::FillRemainder(const std::string& symbol)
	{
		std::unique_lock threadLock {m_mutex};
		m_barRemainder = symbol;
	}

	void ProgressBar::OutputProgress(std::ostream& os)
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
		os << percentage << "%";
		os << " [";
		for(i; i < m_barWidth; ++i) {
			(i <= finshedProgress) ? (os << m_barFill) : (os << m_barRemainder);
		}
		os << "]";
		os << " [" << m_progress << "/" << m_totalWork << "] ";
		os << " " << m_status;
	}


} // namespace serenity
