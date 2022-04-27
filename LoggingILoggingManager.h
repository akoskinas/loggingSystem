// this header file contains the ILoggingManager abstract class 

#ifndef LOGGINGILOGGINGMANAGER_H
#define LOGGINGILOGGINGMANAGER_H

// includes
#include "LoggingIOutput.h"
#include "LoggingCategories.h"
#include <set>

namespace loggingSystem {

class ILoggingManager{
public:
    virtual void Register(const std::initializer_list<LoggingCategories> categs, IOutput* output) = 0;
    virtual void Deregister(const std::initializer_list<LoggingCategories> categs, IOutput* output) = 0;
    virtual void Notify(LoggingCategories cat, const std::string& message) const = 0;
};


} // namespace loggingSystem

#endif
