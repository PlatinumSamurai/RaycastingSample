//
// Created by Alexander Nikolaev on 06.01.2023.
//

#ifndef RAYCASTING_FIELDOFVIEW_H
#define RAYCASTING_FIELDOFVIEW_H

#include <SFML/Graphics/Shape.hpp>

const float PI = 3.14159;

class FieldOfView : public sf::Shape {
private:
    float radius;
    float FOV = PI / 3;
    int pointCount;

public:
    explicit FieldOfView(float radius = 30, int pointCount = 512);
    void setRadius(float r);
    float getRadius() const;
    virtual size_t getPointCount() const;
    virtual sf::Vector2f getPoint(std::size_t index) const;

};


#endif //RAYCASTING_FIELDOFVIEW_H
