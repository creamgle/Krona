#pragma once

#include "Krona/Renderer/Mesh.h"
#include "KronaCore.h"

namespace Krona::Primitives {

    KRAPI Ref<Mesh> CreateQuad(float left, float right, float bottom, float top);

}