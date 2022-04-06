// this header file contains the implementation of the ConcreteLoggingManager

// includes
#include "LoggingConcreteLoggingManager.h"

// remove the following after making sure it works!
#include <iostream>

#include <set>

namespace loggingSystem {

void ConcreteLoggingManager::Register(IOutput* output){

    for(auto i : output->GetLoggingCategories()){
        std::cout << i << std::endl;
    }
    //observers.insert(output);
    (void) output;
    std::cout << "registering..." << std::endl;
}

void ConcreteLoggingManager::Deregister(IOutput* output){
    //observers.erase(observers.find(output));
    (void) output;
}

void ConcreteLoggingManager::Notify(LoggingCategories cat, const std::string& message) const {
    std::cout << "Notify called with message: " << message << std::endl;
    (void) cat;
    (void) message;    
}

} // end of loggingSystem namespace

// Question:
// what is a better design, when it comes to assigning the different IOutput to the unordered_map 
// with respect to their LoggingCategories that have assigned?