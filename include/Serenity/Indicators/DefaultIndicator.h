#pragma once

#include <Serenity/Indicators/IndicatorInterfaces/IProgress.h>
#include <Serenity/Indicators/IndicatorManager.h>

namespace serenity {

	// removed IProgress Inheritance: Manager implicitly Inherits from this class
	class DefaultBar : public manager::Manager
	{
	      public:
		DefaultBar( );

		DefaultBar(DefaultBar& instance);

		~DefaultBar( );

		void UpdateProgress(float updateValue, float totalWork, std::ostream& os = std::cout);

		void OutputProgress(std::ostream& os = std::cout) override;

		void FillBar(const std::string& symbol) override;

		void FillRemainder(const std::string& symbol) override;

	      private:
		std::string m_barFill;
		std::string m_barRemainder;
	};


} // namespace serenity