#include <Serenity/Indicators/IndicatorManager.h>


// ToDo:  Look At ProgressManager.h Note


namespace serenity {

	IndicatorManager::IndicatorManager( ) : m_progressBars(&indicator_handle::m_managerHandle) { }

	IndicatorManager::~IndicatorManager( )
	{
		// This May Be Unnecessary
		for(auto element : *m_progressBars) {
			delete element;
		}
	}

	void IndicatorManager::Update(float updateValue, float totalWork, std::ostream& os)
	{
		// Do Work?
	}
} // namespace serenity