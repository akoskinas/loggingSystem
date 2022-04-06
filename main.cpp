// this file illustrates the use of the logging system

// includes
#include "LoggingConcreteLoggingManager.h"
#include "LoggingConcreteFileOutput.h"

int main(){
    // define new manager
    loggingSystem::ConcreteLoggingManager myManager;

    // define new file output
    loggingSystem::ConcreteFileOutput myFileOutput({loggingSystem::LoggingCategories::Info},"new file");

    // register the file
    myManager.Register(&myFileOutput);

    myManager.Notify(loggingSystem::LoggingCategories::Info,"this");
}

// General questions
// 1. why can't I have a container (e.g a vector or a set) of references??