//
// Created by jxmwa on 1/6/2026.
//

#include "GameObject.h"


void GameObject::setVertices(std::vector<float> &vertices) {
    this->vertices = vertices;
}

std::vector<float> GameObject::getVertices() {
    return this->vertices;
}
