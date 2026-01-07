//
// Created by Pawan on 1/6/26.
//

#ifndef TETRIS_2_0_RENDER_H
#define TETRIS_2_0_RENDER_H

#include "model/GameObject.h"
#include <glad/glad.h>
#include <string>
#include "vector"

class Render {
public:
    Render(const std::string& vert, const std::string& frag);
    void draw(GameObject& game_object, unsigned int &vao, unsigned int &vbo ) const;
    void use() const;
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;

private:
    GLuint programID;
    unsigned VAO;
    unsigned VBO;
    //Shaders
    void checkCompileErrors(unsigned int shader, std::string type);
};



#endif //TETRIS_2_0_RENDER_H