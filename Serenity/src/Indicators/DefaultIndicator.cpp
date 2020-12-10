#include <Serenity/Indicators/DefaultIndicator.h>


namespace serenity {


	DefaultBar::DefaultBar( ) { }

	DefaultBar::DefaultBar(DefaultBar& instance) { }

	DefaultBar::~DefaultBar( ) { }

	void DefaultBar::UpdateProgress(float updateValue, float totalWork, std::ostream& os) { }

	void DefaultBar::OutputProgress(std::ostream& os) { }

	void DefaultBar::FillBar(const std::string& symbol) { }

	void DefaultBar::FillRemainder(const std::string& symbol) { }


} // namespace serenity