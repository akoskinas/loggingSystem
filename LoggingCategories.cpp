// this file contains the implementation of helper functions

#include "LoggingCategories.h"

namespace loggingSystem {

std::string LoggingCategories2String(LoggingCategories cat)
{
    std::string convertedString{};
    switch (cat)
    {
    case LoggingCategories::Info:
        convertedString = "Info:";
        break;

    case LoggingCategories::Debug:
        convertedString = "Debug:";
        break;

    case LoggingCategories::Warning:
        convertedString = "Warning:";
        break;

    case LoggingCategories::Error:
        convertedString = "Error:";
        break;

    default:
        break;
    }
    return convertedString;
}

} // namespace loggingSystem