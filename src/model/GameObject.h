//
// Created by jxmwa on 1/6/2026.
//

#ifndef TETRIS_2_0_GAMEOBJECT_H
#define TETRIS_2_0_GAMEOBJECT_H
#include <vector>


class GameObject {
public:
    GameObject() = default;

    virtual ~GameObject() = default;

    void setVertices(std::vector<float> &vertices);

    void setIndices(std::vector<unsigned int> &indices);

    std::vector<float>& getVertices();

    std::vector<unsigned int>& getIndices();

    void setRenderOrder(int renderOrder);

    virtual void update() {};

protected:
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    int render0rder;
};


#endif //TETRIS_2_0_GAMEOBJECT_H