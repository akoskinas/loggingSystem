// this header file contains the different available logging categories

#ifndef LOGGINGCATEGORIES_H
#define LOGGINGCATEGORIES_H

#include <string>

namespace loggingSystem {

enum class LoggingCategories
{
    Info, Debug, Warning, Error
};

constexpr const char* LoggingCategories2String(LoggingCategories cat);
// returning `std::string_view` would also be a good idea

} // namespace loggingSystem

#endif 
