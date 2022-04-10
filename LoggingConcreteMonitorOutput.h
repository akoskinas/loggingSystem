// this header file contains the concrete class ConcreteFileOutput

#ifndef LOGGINGCONCRETEMONITOROUTPUT_H
#define LOGGINGCONCRETEMONITOROUTPUT_H

#include "LoggingIOutput.h"
#include "LoggingCategories.h"

namespace loggingSystem{

class ConcreteMonitorOutput : public IOutput{
public:
    ConcreteMonitorOutput(const std::string& monitorName);
    void Update(const std::string& message) override;
    std::string GetName() const override;
private:
    std::string mName;
};

} // end of loggingSystem namespace

#endif
