#pragma once

#include "KronaCore.h"
#include "Krona/Core/Matrix4.h"
#include "Krona/Renderer/Shader.h"

namespace Krona {

    class GLShader : public Shader {
        public:
            GLShader(const std::string& name, const std::string& vertexSource, const std::string& fragmentSource);
            ~GLShader() override;

            void Bind() override;
            void Unbind() override;

            void SetUniformFloat4(const std::string& name, float x, float y, float z, float w) override;
            void SetUniformMatrix4(const std::string& name, const Matrix4& value) override;

        private:
            bool Generate(const std::string& vertexSource, const std::string& fragmentSource);
            uint32_t AddShader(uint32_t type, const std::string& source);

            uint32_t mProgram;
    };

}