//
// Created by Pawan on 1/6/26.
//

#include "Renderer.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include "vector"

Renderer::Renderer(const std::string& vert, const std::string& frag)
{
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    std::stringstream vStringStream;
    std::stringstream fStringStream;
    std::string vertStr;
    std::string fragStr;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        vShaderFile.open(vert);
        fShaderFile.open(frag);

        vStringStream << vShaderFile.rdbuf();
        fStringStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertStr = vStringStream.str();
        fragStr = fStringStream.str();
    }
    catch (const std::ifstream::failure&) {
        std::cerr << "ERROR::RENDER::SHADER_FILE_NOT_READ\n";
    }

    const char* vShaderCode = vertStr.c_str();
    const char* fShaderCode = fragStr.c_str();

    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");

    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    programID = glCreateProgram();
    glAttachShader(programID, vertex);
    glAttachShader(programID, fragment);
    glLinkProgram(programID);
    checkCompileErrors(programID, "PROGRAM");

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Renderer::draw(GameObject& game_object) const {
    unsigned int vao, vbo ,ebo;

    std::vector<int> indices = {
        0, 1, 3,
        1, 2, 3
    };

    use();
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    // Now we have our vertex Array object, which is the rule for the vertex drawing

    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    const auto& verts = game_object.getVertices();
    glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(float), verts.data(), GL_DYNAMIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
    // Now we have pointed which is our vertex data using the m_vbo

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    // GLsizei count = (GLsizei)(verts.size() / 3);
    //
    // glDrawArrays(GL_TRIANGLES, 0, count);

    // GLsizei count = (GLsizei)(verts.size() / 3);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
    // glDrawArrays(GL_TRIANGLES, 0, count);

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}


void Renderer::use() const
{
    glUseProgram(programID);
}

void Renderer::setBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(programID, name.c_str()),
                static_cast<int>(value));
}

void Renderer::setInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
}

void Renderer::setFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(programID, name.c_str()), value);
}

void Renderer::checkCompileErrors(unsigned int shader, std::string type)
{
    int success;
    char infoLog[1024];

    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: "
                      << type << "\n"
                      << infoLog << "\n";
        }
    }
    else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            std::cerr << "ERROR::PROGRAM_LINKING_ERROR of type: "
                      << type << "\n"
                      << infoLog << "\n";
        }
    }
}
