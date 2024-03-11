#pragma once

#include "KronaCore.h"
#include <string>

namespace Krona::Log {

    enum LogLevel {
        LogLevel_Fatal = 0,
        LogLevel_Error = 1,
        LogLevel_Warn  = 2,
        LogLevel_Info  = 3,
        LogLevel_Debug = 4
    };


    KRAPI void Output(const LogLevel& level, const std::string& message);

    KRAPI void Fatal(const std::string& message);
    KRAPI void Error(const std::string& message);

    KRAPI void Warn(const std::string& message);
    KRAPI void Info(const std::string& message);
    
    KRAPI void Debug(const std::string& message);

}