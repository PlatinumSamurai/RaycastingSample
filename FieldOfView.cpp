//
// Created by Alexander Nikolaev on 06.01.2023.
//

#include "FieldOfView.h"

FieldOfView::FieldOfView(const float radius, const int pointNumber) : radius(radius), pointCount(pointNumber + 1) {
    update();
}

void FieldOfView::setRadius(const float r) {
    radius = r;
    update();
}

float FieldOfView::getRadius() const {
    return radius;
}

size_t FieldOfView::getPointCount() const {
    return pointCount;
}

sf::Vector2f FieldOfView::getPoint(std::size_t index) const {
//    float angle =

    return sf::Vector2f();
}
