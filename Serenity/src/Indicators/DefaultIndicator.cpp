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
		if(IProgress::managedIndicators.size( ) != 0) {
			IProgress::NotifySubscriber( );
		}
		IProgress::SetWorkload(totalWork);
		IProgress::Progress(updateValue);
		OutputProgress(os);
	}

	void DefaultBar::OutputProgress(std::ostream& os)
	{
		std::unique_lock threadLock {serenity::IProgress::m_mutex};
		// Check The Progress Status And Output The Updated Visual Progress Indicator As Well As
		// The Updated Percentage Completed And The Status Message Corresponding To The Process

		float i                     = 0.0f;
		float completedRatio        = ((IProgress::m_progress / IProgress::m_totalWork));
		const float finshedProgress = (completedRatio * IProgress::m_barWidth);
		int percentage              = static_cast<int>(completedRatio * 100.0f);

		if(IProgress::m_progress > IProgress::m_totalWork) {
			return;
		}
		os << "\r" << std::flush;
		os << percentage << "%";
		os << " [";
		for(i; i < IProgress::m_barWidth; ++i) {
			(i <= finshedProgress) ? (os << m_barFill) : (os << m_barRemainder);
		}
		os << "]";
		os << " [" << IProgress::m_progress << "/" << IProgress::m_totalWork << "] ";
		os << " " << IProgress::m_status;
	}

	void DefaultBar::FillBar(const std::string& symbol)
	{
		std::unique_lock threadLock {IProgress::m_mutex};
		m_barFill = symbol;
	}

	void DefaultBar::FillRemainder(const std::string& symbol)
	{
		std::unique_lock threadLock {IProgress::m_mutex};
		m_barRemainder = symbol;
	}
} // namespace serenity