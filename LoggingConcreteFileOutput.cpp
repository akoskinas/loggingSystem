// this header file contains the implementation of the ConcreteFileOutput class

#include "LoggingConcreteFileOutput.h"
#include <iostream>
#include <filesystem>

namespace loggingSystem{

ConcreteFileOutput::ConcreteFileOutput(const std::string& fileName) : mName{fileName} {
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
    fileHandler = std::make_unique<std::fstream>();
    fileHandler->open(mName, std::ios::out);
    if (!fileHandler){
        std::cerr << "Creation of file: " << GetName() << " failed!" << '\n';
    }    
}
    
void ConcreteFileOutput::Update(const std::string& message){
    //std::string temp_str = message;
    //fileHandler->operator<<(temp_str);
    fileHandler->operator<<("test");
}

std::string ConcreteFileOutput::GetName() const {
    return mName;
}

} // end of loggingSystem namespace

// Questions
// 1. how to handle better the file?