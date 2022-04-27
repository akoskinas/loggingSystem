// this header file contains the definition of the ConcreteLoggingManager

#ifndef LOGGINGCONRETELOGGINGMANAGER_H
#define LOGGINGCONRETELOGGINGMANAGER_H

// includes
#include <string>
#include <map>
#include <initializer_list>
#include "LoggingIOutput.h"
#include "LoggingILoggingManager.h"
#include "LoggingCategories.h"

namespace loggingSystem {

class ConcreteLoggingManager : public ILoggingManager{
public:
    void Register(const std::initializer_list<LoggingCategories> categs, IOutput* output) override;
    void Deregister(const std::initializer_list<LoggingCategories> categs, IOutput* output) override;
    void Notify(LoggingCategories categ, const std::string& message) const override;
private:
    std::multimap<LoggingCategories, IOutput*> observers;
        // consider `std::map<LoggingCategories, std::set<IOutput*>>`
        // to avoid accidental double output for the same category
};

} // end of loggingSystem namespace

#endif
