// this header file contains the implementation of the ConcreteFileOutput class

#include "LoggingConcreteMonitorOutput.h"
#include <iostream>

namespace loggingSystem{

ConcreteMonitorOutput::ConcreteMonitorOutput(const std::initializer_list<LoggingCategories> categs, const std::string& monitorName) : categories{categs}{
    std::cout << "ConcreteMonitorOutput ctor called "
              << "with name: " << monitorName << std::endl; 
}
    
void ConcreteMonitorOutput::Update(LoggingCategories cat, const std::string& message){
    std::cout << " the received monitor output is: " << std::endl;
    std::cout << LoggingCategories2String(cat) << message << std::endl;
}

std::set<LoggingCategories> ConcreteMonitorOutput::GetLoggingCategories() const{
    return categories;
}

} // end of loggingSystem namespace