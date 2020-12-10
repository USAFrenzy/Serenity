#pragma once

#include <Serenity/Indicators/ProgressBar.h>

namespace serenity {

	class DefaultBar : public ProgressBar
	{
	      public:
		DefaultBar( );

		DefaultBar(DefaultBar& instance);

		~DefaultBar( );

		void UpdateProgress(float updateValue, float totalWork, std::ostream& os = std::cout) override;

		void OutputProgress(std::ostream& os = std::cout) override;

		void FillBar(const std::string& symbol) override;

		void FillRemainder(const std::string& symbol) override;

	      private:
		std::mutex m_mutex;
		std::string m_barFill {"#"};
		std::string m_barRemainder {"-"};
		float m_barWidth {50.0f};
		// ProgressBar* m_instance;
	};


} // namespace serenity