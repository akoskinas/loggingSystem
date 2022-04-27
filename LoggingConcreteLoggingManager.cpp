// this header file contains the implementation of the ConcreteLoggingManager

// includes
#include "LoggingConcreteLoggingManager.h"

// remove the following after making sure it works!
#include <iostream>

namespace loggingSystem {

void ConcreteLoggingManager::Register(const std::initializer_list<LoggingCategories> categs, IOutput* output){

    //std::cout << "registering..." << std::endl;
    for(const LoggingCategories categ : categs){
        observers.emplace(categ, output);
    }
}

void ConcreteLoggingManager::Deregister(const std::initializer_list<LoggingCategories> categs, IOutput* output){
    for (const LoggingCategories categ : categs){
        auto iterpair = observers.equal_range(categ);
        
        for (auto it = iterpair.first; it != iterpair.second; ++it) {
            if (it->second == output) { 
                observers.erase(it);
                break;
            }
        }
    }
}

void ConcreteLoggingManager::Notify(LoggingCategories cat, const std::string& message) const {
    //std::cout << "Notify called with message: " << message << std::endl;
    for (auto itr = observers.begin(); itr != observers.end(); ++itr){
        if (itr->first == cat) {
            itr->second->Update(LoggingCategories2String(itr->first)+ "\t" + message);
        }
    }
}

} // end of loggingSystem namespace
