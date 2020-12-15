#pragma once

#include <Serenity/Indicators/ObserverInterface.h>
#include <Serenity/Indicators/ProgressBar.h>

/*
    Might be worth looking into doing something along the lines of having the current
    ProgressBar class be a base class that all styles of progress bars inherit from and then have them
    be registered in the base class by some function that determines that if that style's vector isn't empty,
    create a vector of pointers which can then be referenced by some function here that sorts through them?
    This Way, A progress object can call RegisterIndicator and this will create a pointer to that progress object
    and push this pointer into a vector of pointers for that style which is then referenced here. This would
    allow control on whether a single progress object should be updated or whether we want to update all progress
    objects at once i.e. :

    ProgressBarManager manager;      ***** -> where the initialization process for this object references the
					      individual progress bar vectors, possibly by setting member variable
					      vectors = to individual progress bar vectors of each style
    DerivedbarClass foo("foobar");   ***** -> Minimal Change To Code For The Current ProgressBar Class
    foo.Register();                  ***** -> SetIndex(); bar.push_back(this_object);
    ProgressBarBase::Register();     ***** -> if(!DerivedBarVector.empty()) {baz.push_back(*this_object);}
	where 'DerivedBarVector' is the vector of that progress object's style

    This Way, one could either call foo.Update(); OR manager.Update(); depending on singular or multiple progress
    bars. The Hierarchy would look something like :
	ProgressBarManager->ProgressBar->DerivedBar_1, ...DerivedBar_n
*/


// This Is A WIP For Progress Indicator
namespace serenity {
	class IndicatorManager : public Subscriber
	{
	      public:
		IndicatorManager( );

		~IndicatorManager( );

		void Update(float updateValue, float totalWork, std::ostream &os = std::cout) override;

	      private:
		indicator_handle::ManagerHandle m_progressBars;
	};
} // namespace serenity
