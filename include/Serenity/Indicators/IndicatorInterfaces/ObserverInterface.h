#pragma once

#include <iostream>

// Interface Classes That Will Hold Base Functions That The Manager & Indicators Will Inherit From
class ISubscriber
{
      public:
	virtual void Update(float updateValue, float totalWork, std::ostream &os) = 0;
};

class INotifier
{
      public:
	virtual void RegisterIndicator( )   = 0;
	virtual void UnregisterIndicator( ) = 0;
	virtual void NotifySubscriber( )    = 0;
};


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