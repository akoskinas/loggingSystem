// this header file contains the implementation of the ConcreteFileOutput class

#include "LoggingConcreteFileOutput.h"
#include <iostream>
#include <cstring>

namespace loggingSystem{

ConcreteFileOutput::ConcreteFileOutput(const std::string& fileName) : mName{fileName} {
    fileHandler.open(mName, std::ios::out);
    if (!fileHandler){
        std::cerr << "Creation of file: " << GetName() << " failed!" << '\n';
    }    
}
    
void ConcreteFileOutput::Update(const std::string& message){
    if (!fileHandler) { return; }
    fileHandler << message << '\n';
    
    fileHandler.flush(); 
        // write immediately to the file (flush the in-memory buffer)
        // slower, but avoids data loss in case of crashing
        // maybe could be an option on ConcreteFileOutput constructor
}

std::string ConcreteFileOutput::GetName() const {
    return mName;
}

} // end of loggingSystem namespace
