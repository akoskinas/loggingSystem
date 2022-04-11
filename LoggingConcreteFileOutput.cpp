// this header file contains the implementation of the ConcreteFileOutput class

#include "LoggingConcreteFileOutput.h"
#include <iostream>
#include <cstring>

namespace loggingSystem{

ConcreteFileOutput::ConcreteFileOutput(const std::string& fileName) : mName{fileName} {
    fileHandler = std::make_unique<std::ofstream>();
    fileHandler->open(mName, std::ios::out);
    if (!fileHandler){
        std::cerr << "Creation of file: " << GetName() << " failed!" << '\n';
    }    
}
    
void ConcreteFileOutput::Update(const std::string& message){
    for (char c :message){
        fileHandler->put(c);
    }
    fileHandler->put('\n');

}

std::string ConcreteFileOutput::GetName() const {
    return mName;
}

} // end of loggingSystem namespace

// Questions
// 1. how to handle better the file?