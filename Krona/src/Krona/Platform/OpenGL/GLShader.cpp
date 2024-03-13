#include "GLShader.h"
#include "glad/glad.h"
#include <string>

namespace Krona {

    GLShader::GLShader(const std::string& name, const std::string& vertexSource, const std::string& fragmentSource) {
        if (!Generate(vertexSource, fragmentSource)) {
            Log::Error("Failed to create shader [ " + name + "]!");
            return;
        }

        Log::Info("Successfully created shader [ " + name + " ]");
    }

    GLShader::~GLShader() {
        glDeleteProgram(mProgram);
    }

    bool GLShader::Generate(const std::string& vertexSource, const std::string& fragmentSource) {
        mProgram = glCreateProgram();

        uint32_t vertex = AddShader(GL_VERTEX_SHADER, vertexSource);
        uint32_t fragment = AddShader(GL_FRAGMENT_SHADER, fragmentSource);

        glLinkProgram(mProgram);

        GLint isLinked = 0;
        glGetProgramiv(mProgram, GL_LINK_STATUS, &isLinked);
        if (isLinked == GL_FALSE) {
            GLint maxLength = 0;
			glGetProgramiv(mProgram, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(mProgram, maxLength, &maxLength, &infoLog[0]);

            glDeleteShader(vertex);
            glDeleteShader(fragment);
            glDeleteProgram(mProgram);

            Log::Error(infoLog.data()); 
            Log::Error("Failed to link shader program");
        }

        glDetachShader(mProgram, vertex);
        glDetachShader(mProgram, fragment);
        
        return true;
    }

    uint32_t GLShader::AddShader(uint32_t type, const std::string& source) {
        uint32_t shader = glCreateShader(type);

        const GLchar* sourceCStr = source.c_str();
        glShaderSource(shader, 1, &sourceCStr, 0);

        glCompileShader(shader);

        GLint isCompiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
        if (isCompiled == GL_FALSE) {
            GLint maxLength = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

            glDeleteShader(shader);

            std::string typeName = "UNKNOWN";
            if (type == GL_VERTEX_SHADER) typeName = "Vertex";
            else if (type == GL_FRAGMENT_SHADER) typeName = "Fragment";

            Log::Error(infoLog.data());
            Log::Error("Failed to compile " + typeName + " shader!");
        }

        glAttachShader(mProgram, shader);

        return shader;
    }

    void GLShader::Bind() {
        glUseProgram(mProgram);
    }

    void GLShader::Unbind() {
        glUseProgram(0);
    }

    void GLShader::SetUniformFloat4(const std::string& name, float x, float y, float z, float w) {
        glUniform4f(glGetUniformLocation(mProgram, name.c_str()), x, y, z, w);
    }

    void GLShader::SetUniformMatrix4(const std::string& name, const Matrix4& value) {
        glUniformMatrix4fv(glGetUniformLocation(mProgram, name.c_str()), 1, GL_FALSE, &value.m[0]);
    }

}