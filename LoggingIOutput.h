// this header file contains the IOutout abstract class 

#ifndef LOGGINGIOUTPUT_H
#define LOGGINGIOUTPUT_H

// includes
#include <string>

namespace loggingSystem {

class IOutput{
public:
    virtual void Update(const std::string& message) = 0;
        // maybe string_view could be used here

    virtual std::string GetName() const = 0;
};

} // namespace loggingSystem

#endif