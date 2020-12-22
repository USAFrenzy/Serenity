#include <Serenity/Indicators/IndicatorManager.h>

namespace serenity {

	IndicatorManager::IndicatorManager( ) : m_progressBars(*indicator_handle::m_managerHandle) { }

	IndicatorManager::~IndicatorManager( )
	{
		// This May Be Unnecessary
		for(auto element : m_progressBars) {
			delete element;
		}
	}

	// Pretty Easy To Read: When The Manager Is Notified Of A Change, Update
	// The References And Then Perform The Update Function For Each Indicator In That Handle
	void IndicatorManager::Update(float updateValue, float totalWork, std::ostream &os)
	{
		// Sigh.. May actually keep this for the time being just to move forward with the program right now
		m_progressBars = m_updater.GetManagerHandle( ); // ToDo: REMOVE ME!!!! THIS ISN'T WORTH 224 BYTES

		for(auto indicator : m_progressBars) {
			indicator->UpdateProgress(updateValue, totalWork, os);
		}
	}


} // namespace serenity
namespace untested {
	namespace manager {
		Manager::Manager( ) { }

		Manager::~Manager( ) { }

		void Manager::Update(float updateValue, float totalWork, std::ostream &os = std::cout) { }

		void Manager::RegisterIndicator( )
		{
			serenity::ProgressBar::managedIndicators.emplace_back(this);
			reference_counter::m_referenceCount++;
		}

		void Manager::UnregisterIndicator( )
		{
			std::vector<serenity::ProgressBar *>::iterator iteratorIndex =
			  std::find(serenity::ProgressBar::managedIndicators.begin( ),
				    serenity::ProgressBar::managedIndicators.end( ),
				    this);
			if(iteratorIndex != serenity::ProgressBar::managedIndicators.end( )) {
				serenity::ProgressBar::managedIndicators.erase(iteratorIndex);
			}
			reference_counter::m_referenceCount--;
		}

		std::vector<serenity::ProgressBar *> Manager::GetHandle( )
		{
			return serenity::ProgressBar::managedIndicators;
		}

		size_t Manager::GetSize( )
		{
			return serenity::ProgressBar::managedIndicators.size( );
		}

		int Manager::GetRefCount( )
		{
			return reference_counter::m_referenceCount;
		}
	} // namespace manager
} // namespace untested
