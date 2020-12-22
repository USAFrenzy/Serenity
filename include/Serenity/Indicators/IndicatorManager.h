#pragma once

#include <Serenity/Indicators/IndicatorInterfaces/IManagerHandler.h>
#include <Serenity/Indicators/IndicatorInterfaces/IObserver.h>

namespace serenity {
	namespace manager {
		class Manager : public manager_handler::ManagerHandler, public ISubscriber
		// Inheritance:
		// ManagerHandler->ProgressBar->INotifier
		// & ISubscriber
		{
		      public:
			Manager( );

			~Manager( );

			void Update(float updateValue, float totalWork, std::ostream &os) override;

			void manager_handler::ManagerHandler::RegisterIndicator( );

			void manager_handler::ManagerHandler::UnregisterIndicator( );

			std::vector<serenity::ProgressBar *> manager_handler::ManagerHandler::GetHandle( );

			size_t GetSize( );

			int GetRefCount( );
		};
	} // namespace manager
} // namespace serenity
namespace reference_counter {
	static int m_referenceCount;
} // namespace reference_counter