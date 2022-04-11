// this header file contains the concrete class ConcreteFileOutput

#ifndef LOGGINGCONCRETEFILEOUTPUT_H
#define LOGGINGCONCRETEFILEOUTPUT_H

#include "LoggingIOutput.h"
#include <memory>
#include <fstream>

namespace loggingSystem{

class ConcreteFileOutput : public IOutput{
public:
    ConcreteFileOutput(const std::string& fileName);
    void Update(const std::string& message) override;
    std::string GetName() const override;
private:
    std::string mName;
    std::unique_ptr<std::ofstream> fileHandler{nullptr};
};

} // end of loggingSystem namespace

#endif

// Questions:
// 1.   how to approach the file generation?
// should I have a private function that tries to create the file 
// and returns accordingly an error message if the attempt fails?
// OR should I have this check in the constructor??

// 2.   how to approach the SetCategories?
// should I have a virtual method on the Interface?
// should I have the categories inside the output objects? or completely separated?
// and initialize them using the ctor?

// 3. how to return the LoggingCategories? which container to use?
