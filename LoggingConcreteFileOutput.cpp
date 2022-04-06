// this header file contains the implementation of the ConcreteFileOutput class

#include "LoggingConcreteFileOutput.h"
#include <iostream>

namespace loggingSystem{

ConcreteFileOutput::ConcreteFileOutput(const std::initializer_list<LoggingCategories> categs, const std::string& fileName) : categories{categs}{
    std::cout << "ConcreteFileOutput ctor called "
              << "with name: " << fileName << std::endl; 
}
    
void ConcreteFileOutput::Update(const std::string& message){
    // to-do
    std::cout << "output the message: " << message << std::endl;
}

std::set<LoggingCategories> ConcreteFileOutput::GetLoggingCategories() const{
    return categories;
}

} // end of loggingSystem namespace