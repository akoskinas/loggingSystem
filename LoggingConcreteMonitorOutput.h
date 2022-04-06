// this header file contains the concrete class ConcreteFileOutput

#ifndef LOGGINGCONCRETEMONITOROUTPUT_H
#define LOGGINGCONCRETEMONITOROUTPUT_H

#include "LoggingIOutput.h"
#include "LoggingCategories.h"
#include <string>
#include <initializer_list>
#include <set>

namespace loggingSystem{

class ConcreteMonitorOutput : public IOutput{
public:
    ConcreteMonitorOutput(const std::initializer_list<LoggingCategories> categs, const std::string& monitorName);
    void Update(LoggingCategories cat, const std::string& message) override;
    std::set<LoggingCategories> GetLoggingCategories() const override;
private:
    std::set<LoggingCategories> categories;
};

} // end of loggingSystem namespace

#endif
