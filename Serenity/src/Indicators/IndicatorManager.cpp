#include <Serenity/Indicators/IndicatorManager.h>

namespace serenity {

	IndicatorManager::IndicatorManager( ) : m_progressBars(std::move(indicator_handle::m_managerHandle)) { }

	IndicatorManager::~IndicatorManager( )
	{
		// This May Be Unnecessary
		for(auto element : m_progressBars) {
			delete element;
		}
	}

	// Pretty Easy To Read: When The Manager Is Notified Of A Change, Update
	// The References And Then Perform The Update Function For Each Indicator In That Handle
	void IndicatorManager::Update(float updateValue, float totalWork, std::ostream& os)
	{
		m_progressBars = m_updater.GetManagerHandle( ); // ToDo: REMOVE ME!!!! THIS ISN'T WORTH 224 BYTES

		for(auto indicator : m_progressBars) {
			indicator->UpdateProgress(updateValue, totalWork, os);
		}
	}
} // namespace serenity