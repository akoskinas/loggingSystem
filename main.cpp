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
    ConcreteFileOutput myFileOutput({LoggingCategories::Info, LoggingCategories::Error},"new file");

    // register the new file output
    myManager.Register(&myFileOutput);

    // define a new monitor output
    ConcreteMonitorOutput myMonitorOutput({LoggingCategories::Info, LoggingCategories::Warning},"new monitor");

    // register the new monitor output
    myManager.Register(&myMonitorOutput);

    // test Notify functionality
    myManager.Notify(LoggingCategories::Info, std::string{__FILE__} + ": " + std::to_string(__LINE__) + " : " + "testMsg1");

    myManager.Notify(LoggingCategories::Error,"testMsg2");
}

// General questions
// 1. why can't I have a container (e.g a vector or a set) of references??
// 

// to-do:
// 1. disable copy semantics to ensure that no duplicate output can be registered
// 2. implement deregister
//  - default: remove output from all categories
//  - provide also option for removal of only some categories
// 3. implement unit testing using the framework
// 4. update register - remove the LoggingCategories from the LoggingOutput
//  - reason: the same folder could be used by different programs 
//  - the categories refer to the registration - not to the output itself!
// 5. add a name data member to the Output classes
// 6. add a parameter to the notify, so that the outputs know from whom they have been notified!
// - e.g name