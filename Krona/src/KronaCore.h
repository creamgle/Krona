#pragma once

#include "Krona/Core/PlatformDetection.h"

#ifdef KR_PLATFORM_MAC
    #ifdef KR_EXPORT
        #define KRAPI __attribute__((visibility("default")))
    #else
        #define KRAPI
    #endif
#else
    #define KRAPI
#endif

#include <memory>

namespace Krona {

    template<typename T>
    using Scope = std::unique_ptr<T>;

    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args) {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

	template<typename T>
	using Ref = std::shared_ptr<T>;
	
    template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args) {
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Krona/Core/Log.h"