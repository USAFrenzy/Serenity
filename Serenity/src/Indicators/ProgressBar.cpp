#include <Serenity/Indicators/ProgressBar.h>


// ToDo:  Look A ProgressManager.h Note


namespace serenity {

	ProgressBar::ProgressBar( )
	  : m_barFill(""),
	    m_barRemainder(""),
	    m_barWidth(50.0f),
	    m_progress(0.0f),
	    m_status(""),
	    m_totalWork(0.0f),
	    m_index(0)
	{
		// RegisterIndicator( );
	}

	ProgressBar::ProgressBar(ProgressBar& copy)
	  : m_barFill(copy.m_barFill),
	    m_barRemainder(copy.m_barRemainder),
	    m_barWidth(copy.m_barWidth),
	    m_progress(copy.m_progress),
	    m_status(copy.m_status),
	    m_totalWork(copy.m_totalWork),
	    m_index(copy.m_index)
	{
		// RegisterIndicator( );
	}

	// ToDo: #################################################################################################
	// ToDo: #                 Figure This Register/Unregister Business Out...                               #
	// ToDo: #################################################################################################
	//?                      Possible solution for Register/Unregister Functions:
	//? Have a member variable int index that is assigned from an increment of a local static index total in
	//? RegisterIndicator(). In UnregisterIndicator(), If The index that was unregistered isn't the highest index
	//? number, then iterate through all indices and decrement them by one in a way that keeps the position
	//? order in tact via an iterator that takes the member index value as an argument? Should do some more
	//? container research to see if there's a better and more efficient way of doing this

	// May Add To Ctor For Automatic Registration, Otherwise, Registration To The Manager "Observer" Would Have
	// To Be Manual. Need To Think On Whether I Want Automatically Or Manually Added "Listeners"
	//? -> One Pro To Automatic Registration Would Be That There Would Be Less Copying => Could Just Use Move
	//?    Semantics To Move This Base Class Vector Handle To The Manager Vector Reference When Manager Object
	//?    Is Instantiated?
	void ProgressBar::RegisterIndicator( )
	{
		// This Works To Register An Indicator Object
		indicator_handle::m_managerHandle.emplace_back(this);
		//? Some Sort Of static index total Is Incremented here and the instance member index = the
		//? incremented static variable
		this->m_index = indicator_handle::m_handleIndex++;
	}

	void ProgressBar::UnregisterIndicator( )
	{
		int index = this->m_index;
		indicator_handle::m_managerHandle.erase(indicator_handle::m_managerHandle.begin( ) + index);
		indicator_handle::m_handleIndex--; // After Deletion, Decrement The Total Index Reference
		// Still Need A Way To Iterate Through The Handle Vector And Decrement The Index Values
		//? Might Work As Something Like This:
		for(auto element : indicator_handle::m_managerHandle) {
			element->m_index--;
		}
	}
	// ToDo: #################################################################################################

	void ProgressBar::Progress(float progressValue)
	{
		std::unique_lock threadLock {m_mutex};
		m_progress = progressValue;
	}

	void ProgressBar::UpdateProgress(float updateValue, float totalWork, std::ostream& os) { }

	void ProgressBar::OutputProgress(std::ostream& os) { }

	void ProgressBar::SetWorkload(float totalWorkload)
	{
		std::unique_lock threadLock {m_mutex};
		m_totalWork = totalWorkload;
	}

	void ProgressBar::SetBarWidth(float width)
	{
		std::unique_lock threadLock {m_mutex};
		m_barWidth = width;
	}

	void ProgressBar::FillBar(const std::string& symbol) { }

	void ProgressBar::FillRemainder(const std::string& symbol) { }

	void ProgressBar::SetStatus(const std::string& statusMessage)
	{
		std::unique_lock threadLock {m_mutex};
		m_status = statusMessage;
	}

	std::vector<ProgressBar*> ProgressBar::GetHandle( )
	{
		return indicator_handle::m_managerHandle;
	}

} // namespace serenity
