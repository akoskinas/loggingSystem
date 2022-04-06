// this header file contains the ILoggingManager abstract class 

#ifndef LOGGINGILOGGINGMANAGER_H
#define LOGGINGILOGGINGMANAGER_H

// includes
#include <string>
#include "LoggingIOutput.h"
#include "LoggingCategories.h"

namespace loggingSystem {

class ILoggingManager{
public:
    virtual void Register(IOutput* output) = 0;
    virtual void Deregister(IOutput* output) = 0;
    virtual void Notify(LoggingCategories cat, const std::string& message) const = 0;
};


} // namespace loggingSystem

#endif
