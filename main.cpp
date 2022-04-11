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

// General questions
// 1. why can't I have a container (e.g a vector or a set) of references??
// 2. how can i make it such that the __FILE__ and the __LINE__ are called implicitly,
//  without the need for the caller to specify them?
//  this allows for each output to display the file and the line that the message was sent from 

// to-do:
// 1. disable copy semantics to ensure that no duplicate output can be registered
// 2. implement deregister
//  - default: remove output from all categories
//  - provide also option for removal of only some categories
// 3. implement unit testing using the framework
// 5. add a name data member to the Output classes
// add a timestamp