#pragma once

#include <Serenity/Indicators/IndicatorInterfaces/ObserverInterface.h>
#include <Serenity/Indicators/ProgressBar.h>

// This Is A WIP For Progress Indicator
namespace serenity {
	class IndicatorManager : public ISubscriber
	{
	      public:
		IndicatorManager( );

		~IndicatorManager( );

		void Update(float updateValue, float totalWork, std::ostream &os = std::cout) override;

	      private:
		ProgressBar m_updater { }; // ToDo: REMOVE ME!!!! THIS ISN'T WORTH 224 BYTES
		indicator_handle::ManagerHandle m_progressBars;
	};

} // namespace serenity

namespace untested {

	namespace manager_handler {
		// Thinking Of Having This Be A Way That The Indicators And The Manager
		// Talk To One Another Through Passing A Handle For Data Sharing
		/*
		######################################################################
		#          IndicatorManger->ManagerHandle->INotifier                 #
		#          IndicatorManger->ManagerHandle->ISubscriber               #
		######################################################################
		Therefore I could have this class literally pass the data through the
		two classes and update and register them without having either the
		ProgressBar or the IndicatorManager classes know anything about one
		another
		*/
		// Obviously Change Return Types When Implemented....
		// UPDATE: Rolled Back A few steps to here... First way didn't work as planned
		class ManagerHandler : public INotifier
		{
		      public:
			virtual void RegisterIndicator( ) override { }
			virtual void UnregisterIndicator( ) override { }
			virtual void NotifySubscriber( ) override { }
			virtual void GetHandle( )
			{ /* Technically Should Return A ProgressBar Handle */
			}
			virtual void UpdateHandle( ) { }
			virtual void GetRefCount( ) { }
		};

	} // namespace manager_handler

	namespace manager {
		// Alright So In Practice The ManagerHandle Interface Would Be Like So:
		// Current Thoughts:
		//  -> Inherit directly from the ProgressBar Class Here to have direct access to the vector of
		//  stored indicators, that way, when a manager instance is created, only then should there be
		//  access to the vector. This in turn would possibly allow me to move the ProgressBar vector out
		//  of the global scope and allow the manager to not have to rely on instantiating both a vector to
		//  reference the indicator vector as well as possibly allow the manager class to update the list
		//  without having a class instanced ProgressBar variable
		// -> Inherit From the ManagerHandler class in order to abstract away any manager specific
		// functions and aid in loosely coupling the manager to the indicators
		// -> Inherit from the ISubscriber Interface in order to for this to be an observer/observable
		// pattern
		// Will Come up with the possible Pros and Cons tomorrow before I start flushing this idea out
		class Manager :
		  public manager_handler::ManagerHandler,
		  public ISubscriber,
		  public serenity::ProgressBar
		{
		      public:
			Manager( ) { }

			~Manager( ) { }

			void Update(float updateValue, float totalWork, std::ostream &os = std::cout) override { }

		      protected:
			// same function as the current m_progressBars variable above
			unsigned int m_referenceCount { };
		};
	} // namespace manager

} // namespace untested