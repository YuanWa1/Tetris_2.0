//
// Created by Pawan on 1/6/26.
//

#ifndef TETRIS_2_0_RENDER_H
#define TETRIS_2_0_RENDER_H


#include <glad/glad.h>
#include <string>
#include "vector"

class Render {
public:
    Render(const std::string& vert, const std::string& frag);
    void draw() const;
    void use() const;
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setVertices(const std::vector<float>  &vertices) {
        m_vertices = vertices;
    }

private:
    GLuint programID;
    unsigned VAO;
    unsigned VBO;
    //Shaders
    std::vector<float> m_vertices;
    void checkCompileErrors(unsigned int shader, std::string type);
};



#endif //TETRIS_2_0_RENDER_H