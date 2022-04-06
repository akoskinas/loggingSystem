// this header file contains the IOutout abstract class 

#ifndef LOGGINGIOUTPUT_H
#define LOGGINGIOUTPUT_H

// includes
#include "LoggingCategories.h"
#include <string>
#include <set>

namespace loggingSystem {

class IOutput{
public:
    virtual void Update(const std::string& message) = 0;
    virtual std::set<LoggingCategories> GetLoggingCategories() const = 0;
};

} // namespace loggingSystem

#endif

// Questions:
// 1. could I avoid declaring already the container with the logging categories?