#include "Log.h"

#include <iostream>
#include <string>

namespace Krona::Log {

    void Output(const LogLevel& level, const std::string& message) {
        static const std::string tags[5] = {
            "\e[41m[FATAL] ",
            "\e[0;31m[ERROR] ",
            "\e[0;33m[WARN]  ",
            "\e[0;32m[INFO]  ",
            "\e[0;35m[DEBUG] "
        };

        std::cout << tags[level] << message << "\e[0m\n";
    }

    void Fatal(const std::string& message) {
        Output(LogLevel_Fatal, message);
    }

    void Error(const std::string& message) {
        Output(LogLevel_Error, message);
    }

    void Warn(const std::string& message) {
        Output(LogLevel_Warn, message);
    }

    void Info(const std::string& message) {
        Output(LogLevel_Info, message);
    }

    void Debug(const std::string& message) {
        Output(LogLevel_Debug, message);
    }

}