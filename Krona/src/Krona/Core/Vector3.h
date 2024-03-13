#pragma once

#include "Krona/Core/Vector2.h"
#include "KronaCore.h"

namespace Krona {

    struct KRAPI Vector3 {
        float x;
        float y;
        float z;

        Vector3() = default;
        Vector3(const Vector3& copy) = default;

        Vector3(float scalar) : x(scalar), y(scalar), z(scalar) { }
        Vector3(float x, float y, float z) : x(x), y(y), z(z) { }
        
        Vector3(const Vector2& other, float z) : x(other.x), y(other.y), z(z) { }
    };

}