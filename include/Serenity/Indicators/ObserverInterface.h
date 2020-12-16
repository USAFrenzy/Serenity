#pragma once

#include <iostream>

// Interface Classes That Will Hold Base Functions That The Manager & Indicators Will Inherit From
class ISubscriber
{
      public:
	virtual ~ISubscriber( ) { };
	virtual void Update(float updateValue, float totalWork, std::ostream &os) = 0;
};
class INotifier
{
      public:
	virtual ~INotifier( ) { };
	virtual void RegisterIndicator( )   = 0;
	virtual void UnregisterIndicator( ) = 0;
	virtual void NotifySubscriber( )    = 0;
};