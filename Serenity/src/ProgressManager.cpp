#include <Serenity/Indicators/ProgressManager.h>

namespace serenity {


	ProgressBarManager::ProgressBarManager( ) { }
	ProgressBarManager::~ProgressBarManager( ) { }

	//? No Way To Search For And Unregister An Instance Either ->
	//?  Maybe Look Into Templating/Reference Wrapping?
	void ProgressBarManager::RegisterObserver( ) { }

	void ProgressBarManager::UpdateProgress(float updateValue, float totalWork, std::ostream& os)
	{
		// for(auto element : m_managerHandle) {
		SetWorkload(totalWork);
		Progress(updateValue);
		OutputProgress(os);
		//}
	}

} // namespace serenity