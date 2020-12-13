# Serenity Logger #

This Is More Practice Than Anything Else As Well As A Learning Project As A Home-brewed Logging Library.

The Intended Use For This Eventual Library Is To Substitute spdlog In Redemption And For Use In Future Projects. (Albeit, This Will Probably Never Match That Lib's Speed) 


****************************************************************************
## Links
### [ToDo List](https://github.com/USAFrenzy/Serenity/wiki/ToDo-List) 
### [Change Log](https://github.com/USAFrenzy/Serenity/wiki/Change-Log)
### [Future Site](https://usafrenzy.github.io/Serenity/)
****************************************************************************

## Current Goals                                                   
- [ ] Get From Current Usage Syntax To Expected Usage Syntax 
- [X] Have The Registration Of A Logger Grab The Manager Handle And Insert Itself Into The Manager Via A Handle
- [ ]
- [ ]
- [ ]
- [ ]
- [ ]

### Example:
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

## Logger Class
Expected Usage | Current Usage
------------ | -------------
````Logger.Register();```` |````Logger.Register(Subscriber& manager)````
````Logger log(“LoggerName”);```` OR ````Logger("LoggerName");```` | ````Logger log(“LoggerName”)````
````log.SetLevel(LogLevel::lvl);```` OR ````SetLevel(LogLevel::lvl)```` | ````log.SetLevel(LogLevel::lvl);````  
````log.SetPattern("fmtStr"); OR SetPattern("fmtStr")````  | ------------------N/A---------------
````log.LogOutput(LogOutput::op)```` OR  ````LogOutput(LogOutput::op);```` | ````log.Init(fileName, LogOutput::op);````
 |  To Be Fair I Still Like Having A Default Init Function... | Since It Would Allow For Easy Usage Setup
````log.SetFormat(LoggerFormat::format);```` OR ````SetFormat(LoggerFormat::format);```` | ------------------N/A---------------

###############################################
## [Future Class Tables Placeholder]
###############################################

