#include <Serenity/Indicators/DefaultIndicator.h>


namespace serenity {

	DefaultBar::DefaultBar( ) : m_barFill("#"), m_barRemainder("-") { }

	DefaultBar::DefaultBar(DefaultBar& instance)
	  : m_barFill(instance.m_barFill), m_barRemainder(instance.m_barRemainder)
	{
	}

	DefaultBar::~DefaultBar( ) { }

	void DefaultBar::UpdateProgress(float updateValue, float totalWork, std::ostream& os)
	{
		if(managerSubscribers.size( ) != 0) {
			NotifySubscriber( );
		}
		SetWorkload(totalWork);
		Progress(updateValue);
		OutputProgress(os);
	}

	void DefaultBar::OutputProgress(std::ostream& os)
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

	void DefaultBar::FillBar(const std::string& symbol)
	{
		std::unique_lock threadLock {m_mutex};
		m_barFill = symbol;
	}

	void DefaultBar::FillRemainder(const std::string& symbol)
	{
		std::unique_lock threadLock {m_mutex};
		m_barRemainder = symbol;
	}
} // namespace serenity