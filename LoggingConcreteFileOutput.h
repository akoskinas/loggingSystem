// this header file contains the concrete class ConcreteFileOutput

#ifndef LOGGINGCONCRETEFILEOUTPUT_H
#define LOGGINGCONCRETEFILEOUTPUT_H

#include "LoggingIOutput.h"
#include <memory>
#include <fstream>

namespace loggingSystem{

/*
// idea: have rotating log system where the timestamp is added to
// the path of the desired output file
namespace impl
{ 
    std::string createFilenameWithTimestamp(const std::string& path);
}
*/

class ConcreteFileOutput : public IOutput{
public:
    ConcreteFileOutput(const std::string& fileName);
    void Update(const std::string& message) override;
    std::string GetName() const override;
private:
    std::string mName;
    std::ofstream fileHandler;
};

} // end of loggingSystem namespace

#endif
