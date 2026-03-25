//
// Created by jxmwa on 1/6/2026.
//

#include "GameObject.h"

// Setters
void GameObject::setVertices(std::vector<float> &vertices) {
    this->vertices = vertices;
}

void GameObject::setIndices(std::vector<unsigned int> &indices) {
    this->indices = indices;
}


// Getters
std::vector<unsigned int>& GameObject::getIndices() {
    return this->indices;
}

std::vector<float>& GameObject::getVertices() {
    return this->vertices;
}



void GameObject::setRenderOrder(int render_Order) {
    this->renderOrder = render_Order;
}


