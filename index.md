# Serenity Logger #

This Is More Practice Than Anything Else As Well As A Learning Project As A Home-brewed Logging Library.

The Intended Use For This Eventual Library Is To Substitute spdlog In Redemption And For Use In Future Projects. (Albeit, This Will Probably Never Match That Lib's Speed) 


****************************************************************************
## Links
### [ToDo List](https://github.com/USAFrenzy/Serenity/wiki/ToDo-List) 
### [Change Log](https://github.com/USAFrenzy/Serenity/wiki/Change-Log)
****************************************************************************

### *Current* Logger Specific Example:
````c++
* Instance Oriented *                      * Global Oriented *                    * Default Init Oriented *
Logger foo("bar");                         SetLevel(LogLevel::baz);               Init();
foo.SetLevel(LogLevel::baz);               SetPattern("^[%H%M%S]^v");             Logger foo("bar");
foo.SetPattern("^[%H%M%S]^v");             LogOutput(LogOutput::bar);
foo.LogOutput(LogOutput::bar);             SetFormat(LoggerFormat::bar);
foo.SetFormat(LoggerFormat::bar);          Logger("foo");
foo.Register();                                                  
````

###############################################
### [Future Examples Placeholder]
###############################################

## Current Goals                                                   
- [ ] Get From Current Usage Syntax To Expected Usage Syntax 
- [X] Have The Registration Of A Logger Grab The Manager Handle And Insert Itself Into The Manager Via A Handle
- [ ]
- [ ]
- [ ]
- [ ]
- [ ]


## Logger Class
| Expected Usage | Current Usage | 
| ------------ | ------------- | 
| ````log.Register();```` | ------------------N/A--------------- |
| ````Logger log(“LoggerName”);```` OR ````Logger("LoggerName");```` | ````Logger log(“LoggerName”)```` |
| ````log.SetLevel(LogLevel::lvl);```` OR ````SetLevel(LogLevel::lvl)```` | ````log.SetLevel(LogLevel::lvl);```` |
| ````log.SetPattern("fmtStr");```` OR ````SetPattern("fmtStr")````  | ------------------N/A--------------- |
| ````log.LogOutput(LogOutput::op)```` OR  ````LogOutput(LogOutput::op);```` | ------------------N/A--------------- |
| ````log.SetFormat(LoggerFormat::format);```` OR ````SetFormat(LoggerFormat::format);```` | ------------------N/A--------------- |
| ````Logger::Init();```` OR ````log.Init();```` | ````log.Init(fileName, LogOutput::op);```` |
| ````Logger::GetLogLevel();```` OR ````log.GetLogLevel();```` | ````log.GetLogLevel();```` |
| ````Logger::LogLevelToString();```` OR ````log.LogLevelToString();```` | Currently A Mess With std::map |
| ````Logger::LogLevelFromString();```` OR ````log.LogLevelFromString();```` | ------------------N/A--------------- |
| ````Logger::LogMessage("Message To Log {}", msgArg);```` OR ````log.LogMessage("Message To Log {}", msgArg);````   | ````log.Log("Message To Log");```` |

## ProgressBar Class
##### This Class Is A Base Class With Virtual Functions Therefore It's Expected That It Should Have A Derived Indicator

| Expected Usage | Current Usage | 
| ------------ | ------------- | 
|_**VIRTUAL FUNCTIONS**_ | _**These Are The Functions That Require A Derived Class Implementation**_ |
| Virtual Destructor | Up To Derived Indicator (Although, Should Implement Freeing The Managed Indicators Vector From Memory If Empty) |
|````foo.UpdateProgress(); ```` | ````foo.UpdateProgress(float updateValue, float totalWork, std::ostream& os = std::cout); ````
|````foo.OutputProgress();```` | ````foo.OutputProgress(std::ostream &os = std::cout);```` |
|````foo.FillBar(const std::string &symbol);```` | ````foo.FillBar(const std::string &symbol```` |
|````foo.FillRemainder(const std::string &symbol);```` | ````foo.FillRemainder(const std::string &symbol);```` |
| _**OVERIDDEN FUNCTIONS**_ | _**These Currently Come From The ````Notifier```` Class**_ |
|````foo.RegisterIndicator();```` | ````foo.RegisterIndicator();```` |
|````foo.UnregisterIndicator();```` | ````foo.UnregisterIndicator();```` |
|````foo.NotifySubscriber(); ```` | ````foo.NotifySubscriber();```` However Is Currently Unimplemented |
|_**CLASS OWNED FUNCTIONS**_| _**Some Are Internal And Need To Be Moved To Protected Or Private Accessors**_ |
|````ProgressBar foo; ```` | ```` ProgressBar foo;```` |
|```` foo.ProgressCompleted(int progressValue);```` | ````foo.Progress(int progressValue);```` |
|````foo.SetWorkLoad(float totalWork);```` | ````foo.SetWorkLoad(float totalWork);```` |
|````foo.SetBarWdith(float width);```` | ````foo.SetBarWdith(float width);```` |
|````foo.SetStatus(const std::string &statusMessage);```` | ````foo.SetStatus(const std::string &statusMessage);```` |
|````foo.ManagerRefCount();```` | ````foo.ManagerRefCount();```` |
|````foo.UpdateManagerHandle();```` | ````foo.UpdateManagerHandle();```` |
|````foo.GetManagerHandle();```` | ````foo.GetManagerHandle();```` |

## DefaultIndicator Class
| Expected Usage | Current Usage | 
| ------------ | ------------- | 
### [DefaultIndicator PlaceHolder]

## IndicatorManager Class
| Expected Usage | Current Usage | 
| ------------ | ------------- |
### [IndicatorManager PlaceHolder]
 
## Sink Class
| Expected Usage | Current Usage | 
| ------------ | ------------- |
### [Sink PlaceHolder]

## DefaultSink Class
| Expected Usage | Current Usage | 
| ------------ | ------------- |
### [DefaultSink PlaceHolder]


###############################################
## [Future Class Tables Placeholder]
###############################################

