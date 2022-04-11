// this header file contains the implementation of the ConcreteLoggingManager

// includes
#include "LoggingConcreteLoggingManager.h"

// remove the following after making sure it works!
#include <iostream>

namespace loggingSystem {

void ConcreteLoggingManager::Register(const std::initializer_list<LoggingCategories> categs, IOutput* output){

    //std::cout << "registering..." << std::endl;
    for(const LoggingCategories categ : categs){
        observers.insert(std::pair<LoggingCategories,IOutput*>(categ,output));
    }
}

void ConcreteLoggingManager::Deregister(const std::initializer_list<LoggingCategories> categs, IOutput* output){
    typedef std::multimap<LoggingCategories, IOutput*>::iterator iterator;
    for (const LoggingCategories categ : categs){
        std::pair<iterator, iterator> iterpair = observers.equal_range(categ);

        iterator it = iterpair.first;
        for (; it != iterpair.second; ++it) {
            if (it->second == output) { 
                observers.erase(it);
                break;
            }
        }
    }
}

void ConcreteLoggingManager::Notify(LoggingCategories cat, const std::string& message) const {
    //std::cout << "Notify called with message: " << message << std::endl;
    for (auto itr = observers.begin(); itr != observers.end(); itr++){
        if (itr->first == cat) {
            itr->second->Update(LoggingCategories2String(itr->first)+ "\t" + message);
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
// 4. Deregister was basically a copy-paste --> how the fuck works?