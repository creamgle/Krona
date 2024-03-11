#pragma once

#if defined(__APPLE__)
    #include <TargetConditionals.h>

    #if TARGET_OS_MAC == 1
        #define KR_PLATFORM_MAC
    #else
        #error "macOS is the only currently supported Apple platform!"
    #endif 
#else
    #error "Current platform not yet support!"
#endif