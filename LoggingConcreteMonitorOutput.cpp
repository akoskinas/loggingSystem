// this header file contains the implementation of the ConcreteFileOutput class

#include "LoggingConcreteMonitorOutput.h"
#include <iostream>

namespace loggingSystem{

ConcreteMonitorOutput::ConcreteMonitorOutput(const std::string& monitorName): mName{monitorName}{
    //std::cout << "ConcreteMonitorOutput ctor called "
    //          << "with name: " << monitorName << std::endl;
}
    
void ConcreteMonitorOutput::Update(const std::string& message){
    //std::cout << " the received monitor output is: " << std::endl;
    std::cout << message << std::endl;
}

std::string ConcreteMonitorOutput::GetName() const {
    return mName;
}

} // end of loggingSystem namespace