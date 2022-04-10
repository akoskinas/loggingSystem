// this header file contains the implementation of the ConcreteLoggingManager

// includes
#include "LoggingConcreteLoggingManager.h"

// remove the following after making sure it works!
#include <iostream>

namespace loggingSystem {

void ConcreteLoggingManager::Register(IOutput* output){

    std::cout << "registering..." << std::endl;

    for(const LoggingCategories categ : output->GetLoggingCategories()){
        observers.insert(std::pair<LoggingCategories,IOutput*>(categ,output));
    }
}

void ConcreteLoggingManager::Deregister(IOutput* output){
    // TO-DO: implement this!
    //observers.erase(observers.find(output));
    (void) output;
}

void ConcreteLoggingManager::Notify(LoggingCategories cat, const std::string& message) const {
    std::cout << "Notify called with message: " << message << std::endl;
    for (auto itr = observers.begin(); itr != observers.end(); itr++){
        if (itr->first == cat) {
            itr->second->Update(itr->first,message);
        }
    }
}

} // end of loggingSystem namespace

// Question:
// 1. what is a better design, when it comes to assigning the different IOutput to the unordered_map 
// with respect to their LoggingCategories that have assigned?
//
// 2. @Register: does it make sense to have the iteration of all the elements of the set 
// taken by reference: i.e 
// for(const LoggingCategories& categ : output->GetLoggingCategories()){
//
// 3. is there any benefit in incluing a uniqueID that the LoggingManager will assign to
// each registered output?
//