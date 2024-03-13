#pragma once

#include "KronaCore.h"
#include <string>

namespace Krona {

    struct Matrix4;

    class KRAPI Shader {
        public:
            virtual ~Shader() = default;

            static Ref<Shader> Create(const std::string& name, const std::string& vertexSource, const std::string& fragmentSource);

            virtual void Bind() = 0;
            virtual void Unbind() = 0;

            virtual void SetUniformFloat4(const std::string& name, float x, float y, float z, float w) = 0;
            virtual void SetUniformMatrix4(const std::string& name, const Matrix4& value) = 0;
    };

}