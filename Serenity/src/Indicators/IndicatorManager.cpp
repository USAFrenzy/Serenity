#include <Serenity/Indicators/IndicatorManager.h>

namespace serenity {
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
} // namespace serenity
