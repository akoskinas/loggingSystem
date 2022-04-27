// this file contains the implementation of helper functions

#include "LoggingCategories.h"

namespace loggingSystem {

constexpr const char* LoggingCategories2String(LoggingCategories cat)
{
    switch (cat)
    {
        case LoggingCategories::Info:    return "Info";
        case LoggingCategories::Debug:   return "Debug";
        case LoggingCategories::Warning: return "Warning";
        case LoggingCategories::Error:   return "Error";
    }

    return "UNKNOWN CATEGORY";
}

} // namespace loggingSystem