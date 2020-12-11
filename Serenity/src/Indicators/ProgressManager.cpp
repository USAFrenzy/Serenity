#include <Serenity/Indicators/ProgressManager.h>


// ToDo:  Look A ProgressManager.h Note


namespace serenity {


	ProgressBarManager::ProgressBarManager( ) { }
	ProgressBarManager::~ProgressBarManager( ) { }

	//? No Way To Search For And Unregister An Instance Either ->
	//?  Maybe Look Into Templating/Reference Wrapping?
	void ProgressBarManager::RegisterIndicator(ProgressBar& indicator)
	{
		// ToDo: Figure Out What The Whole "error C2558: class 'serenity::ProgressBar': no copy
		// ToDo: constructor available or copy constructor is declared 'explicit' " Is About

		// m_progressBars.emplace_back(indicator);
	}

	void ProgressBarManager::UnregisterIndicator( )
	{
		// ToDo: Figure Out What The Whole "error C2558: class 'serenity::ProgressBar': no copy
		// ToDo: constructor available or copy constructor is declared 'explicit' " Is About

		// m_progressBars.erase(m_progressBars.begin( ) + GetIndex());
	}
	int ProgressBarManager::GetIndex( )
	{
		return m_index;
	}
	void ProgressBarManager::SetIndex( )
	{
		m_index = static_cast<int>(m_progressBars.size( ));
	}
	// void ProgressBarManager::UpdateProgress(float updateValue, float totalWork, std::ostream& os)
	//{
	//	// for(auto element : m_managerHandle) {
	//	SetWorkload(totalWork);
	//	Progress(updateValue);
	//	OutputProgress(os);
	//	//}
	//}

} // namespace serenity