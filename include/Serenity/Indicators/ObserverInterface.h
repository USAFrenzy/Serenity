#pragma once

// Interface Classes That Will Hold Base Functions That The Manager & Indicators Will Inherit From
class Subscriber
{
      public:
	virtual ~Subscriber( ) { };
	virtual void Update(float updateValue, float totalWork, std::ostream &os) = 0;
};

class Notifier
{
      public:
	virtual ~Notifier( ) { };
	virtual void RegisterIndicator(Subscriber *managerListener)   = 0;
	virtual void UnregisterIndicator(Subscriber *managerListener) = 0;
	virtual void NotifySubscriber( )                             = 0;
};