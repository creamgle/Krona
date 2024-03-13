#include "GLMesh.h"

#include "Krona/Renderer/Mesh.h"
#include "glad/glad.h"
#include <vector>

namespace Krona {

    GLMesh::GLMesh(std::vector<Vertex> vertices, std::vector<uint32_t> triangles) : 
        mVertices(vertices), mTriangles(triangles) {
        Generate();
    }

    GLMesh::~GLMesh() {
        glDeleteVertexArrays(1, &mVao);
    }

    void GLMesh::Generate() {
        uint32_t vbo, ebo;

        glGenVertexArrays(1, &mVao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindVertexArray(mVao);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * mVertices.size(), &mVertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * mTriangles.size(), &mTriangles[0], GL_STATIC_DRAW);

        /* Position Attribute */
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

        glBindVertexArray(0);
    }

    void GLMesh::Draw() {
        glBindVertexArray(mVao);
        glDrawElements(GL_TRIANGLES, mTriangles.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

}