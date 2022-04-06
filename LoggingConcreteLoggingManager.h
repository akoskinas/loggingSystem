// this header file contains the definition of the ConcreteLoggingManager

#ifndef LOGGINGCONRETELOGGINGMANAGER_H
#define LOGGINGCONRETELOGGINGMANAGER_H

// includes
#include <string>
#include <unordered_map>
#include "LoggingIOutput.h"
#include "LoggingILoggingManager.h"

namespace loggingSystem {

class ConcreteLoggingManager : public ILoggingManager{
public:
    void Register(IOutput* output) override;
    void Deregister(IOutput* output) override;
    void Notify(LoggingCategories categ, const std::string& message) const override;

private:
    std::unordered_map<LoggingCategories, IOutput*> observers;
};

} // end of loggingSystem namespace

#endif

// Questions:
// 1. to make sure that an output was registered successfully?
//     I was thinking something like:
//     [[nodiscard]] bool Register(IOutout& output) override;
//     Does it make sense? and how?
//
// 2. in order to avoid double entries?
//      do I need an additional unique component?
//      can i base the uniqueness on the pointer?
//      - in that case, do I need to disable COPY and MOVE semantics?