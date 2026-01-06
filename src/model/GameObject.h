//
// Created by jxmwa on 1/6/2026.
//

#ifndef TETRIS_2_0_GAMEOBJECT_H
#define TETRIS_2_0_GAMEOBJECT_H
#include <vector>


class GameObject {
public:
    GameObject() = default;

    ~GameObject() = default;

    void setVertices(std::vector<float> &vertices);

    std::vector<float> getVertices();

private:
    std::vector<float> vertices;
};


#endif //TETRIS_2_0_GAMEOBJECT_H