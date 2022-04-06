// this header file contains the different available logging categories

#ifndef LOGGINGCATEGORIES_H
#define LOGGINGCATEGORIES_H

#include <string>

namespace loggingSystem {

enum class LoggingCategories
{
    Info, Debug, Warning, Error
};

std::string LoggingCategories2String(LoggingCategories cat);

} // namespace loggingSystem

#endif 

// Questions:
// 1. should the LoggingCategories be placed in a container like a vector or sth?