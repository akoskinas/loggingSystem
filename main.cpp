// this file illustrates the use of the logging system

// includes
#include "LoggingConcreteLoggingManager.h"
#include "LoggingConcreteFileOutput.h"
#include "LoggingConcreteMonitorOutput.h"

#include <iostream>
using namespace loggingSystem;

int main(){

    // define new manager
    ConcreteLoggingManager myManager;

    // define a new file output
    ConcreteFileOutput myFileOutput("new_file.log");

    // register the new file output
    myManager.Register({LoggingCategories::Info, LoggingCategories::Error},&myFileOutput);

    // define a new monitor output
    ConcreteMonitorOutput myMonitorOutput("new monitor");

    // register the new monitor output
    myManager.Register({LoggingCategories::Info, LoggingCategories::Warning},&myMonitorOutput);

    // test Notify functionality
    myManager.Notify(LoggingCategories::Info, std::string{__FILE__} + ": " + std::to_string(__LINE__) + " : " + "testMsg1");
    myManager.Notify(LoggingCategories::Error, std::string{__FILE__} + ": " + std::to_string(__LINE__) + " : " + "testMsg2");

    myManager.Deregister({LoggingCategories::Error},&myFileOutput);
    myManager.Notify(LoggingCategories::Info, std::string{__FILE__} + ": " + std::to_string(__LINE__) + " : " + "testMsg3");
    myManager.Notify(LoggingCategories::Error, std::string{__FILE__} + ": " + std::to_string(__LINE__) + " : " + "testMsg4");

}

template <typename... Args> // variadic parameter pack 
void notify(ConcreteLoggingManager& manager, LoggingCategories category, const Args&... args)
{
    std::ostringstream oss;
    (oss << ... << args);  // C++17 fold expression
    manager.Notify(category, oss.str());
}

// call as `notify(myManager, LoggingCategories::Info, 10, "hello", someStreamableThing);`

// In C++20, you can use `std::source_location` instead of __FILE__ and __LINE__ macros:
// https://en.cppreference.com/w/cpp/utility/source_location

// Before, you have to use a macro that passes those __FILE__ and __LINE__ macros to some
// other function call:
/* 
#define LOG_NOTIFY(category, message) \
    myManager.Notify(category, __FILE__, 
*/

// to-do:
// 3. implement unit testing using the framework
// add a timestamp