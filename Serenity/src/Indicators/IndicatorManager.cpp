#include <Serenity/Indicators/IndicatorInterfaces/IProgress.h>
#include <Serenity/Indicators/IndicatorManager.h>

namespace serenity {
	namespace manager {
		Manager::Manager( ) { }

		Manager::~Manager( ) { }

		void Manager::Update(float updateValue, float totalWork, std::ostream &os = std::cout) { }

		void Manager::RegisterIndicator( )
		{
			serenity::IProgress::managedIndicators.emplace_back(this);
			reference_counter::m_referenceCount++;
		}

		void Manager::UnregisterIndicator( )
		{
			std::vector<serenity::IProgress *>::iterator iteratorIndex =
			  std::find(serenity::IProgress::managedIndicators.begin( ),
				    serenity::IProgress::managedIndicators.end( ),
				    this);
			if(iteratorIndex != serenity::IProgress::managedIndicators.end( )) {
				serenity::IProgress::managedIndicators.erase(iteratorIndex);
			}
			reference_counter::m_referenceCount--;
		}

		std::vector<serenity::IProgress *> Manager::GetHandle( )
		{
			return serenity::IProgress::managedIndicators;
		}

		size_t Manager::GetSize( )
		{
			return serenity::IProgress::managedIndicators.size( );
		}

		int Manager::GetRefCount( )
		{
			return reference_counter::m_referenceCount;
		}
	} // namespace manager
} // namespace serenity
