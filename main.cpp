#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

//using Point2 = sf::Vector2f;

const int BLOCK_WIDTH = 100;
const int BLOCK_HEIGHT = 25;
const double PI = acos(-1);
const float FOV = PI / 3;
const float DIST_DEPTH = 160;
const int MAP_WIDTH = 1024;
const int MAP_HEIGHT = 1024;
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 1024;


class Player {
private:
    float x;
    float y;
    float direction;
    sf::CircleShape point;
    sf::RectangleShape dirLine;
    sf::CircleShape circleFOV;


public:
    Player();
    Player(float posX, float posY, float dir);
    std::pair<float, float> getPosition() const;
    float getDirection() const;
    int setPosition(const float posX, const float posY);
    int setDirection(const float dir);
    int movePosition(const float posX, const float posY);
    int moveDirection(const float dir);
    sf::CircleShape getPoint()const;
    int update();
    sf::RectangleShape getDirLine() const;
//    sf::CircleShape getFOVCircle() const;

};

Player::Player() {
    x = 0;
    y = 0;
    direction = 90;
    point.setRadius(12);
    point.setFillColor(sf::Color::Magenta);
    point.setPosition(x, y);
    dirLine.setSize(sf::Vector2f(55, 2));
    dirLine.setFillColor(sf::Color::Black);
    dirLine.setOrigin(dirLine.getPosition() + sf::Vector2f(0, dirLine.getSize().y / 2));
//    circleFOV.setRadius(55);
//    circleFOV.setOrigin(point.getOrigin());
//    circleFOV.setFillColor(sf::Color(255, 0, 0, 64));
}

Player::Player(float posX, float posY, float dir) {
    x = posX;
    y = posY;
    direction = dir;
    point.setRadius(12);
    point.setFillColor(sf::Color::Magenta);
    point.setPosition(x, y);
    dirLine.setSize(sf::Vector2f(55, 2));
    dirLine.setFillColor(sf::Color::Black);
    dirLine.setOrigin(dirLine.getPosition() + sf::Vector2f(0, dirLine.getSize().y / 2));
//    circleFOV.setRadius(55);
//    circleFOV.setOrigin(point.getPosition() + sf::Vector2f(12, 12));
//    circleFOV.setFillColor(sf::Color(255, 0, 0, 64));
}

std::pair<float, float> Player::getPosition() const {
    return std::make_pair(x, y);
}

float Player::getDirection() const {
    return direction;
}

int Player::setPosition(const float posX, const float posY) {
    try {
        x = posX;
        y = posY;
        update();
    } catch(...) {
        return -1;
    }

    return 0;
}

int Player::setDirection(const float dir) {
    try {
        direction = dir;
    } catch(...) {
        return -1;
    }

    return 0;
}

int Player::movePosition(const float posX, const float posY) {
    try {
        x += posX;
        y += posY;
        update();
    } catch(...) {
        return -1;
    }

    return 0;
}

int Player::moveDirection(const float dir) {
    try {
        direction += dir;
        dirLine.rotate(-dir);
    } catch(...) {
        return -1;
    }

    return 0;
}

sf::CircleShape Player::getPoint() const {
    return point;
}

int Player::update() {
    point.setPosition(x, y);
    dirLine.setPosition(point.getRadius() + x, point.getRadius() + y);
    circleFOV.setPosition(x, y);

    return 0;
}

sf::RectangleShape Player::getDirLine() const {
    return dirLine;
}

//sf::CircleShape Player::getFOVCircle() const {
//    return circleFOV;
//}


//int generateBounds(std::vector<sf::RectangleShape> &walls) {
//    for(int i = 0; i < 10; ++i) {
//        walls.emplace_back(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT));
//        walls.back().setPosition(i * BLOCK_WIDTH, 0);
//        walls.back().setFillColor(sf::Color::Red);
//    }
//    for(int i = 0; i < 10; ++i) {
//        walls.emplace_back(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT));
//        walls.back().setPosition(i * BLOCK_WIDTH + BLOCK_HEIGHT, BLOCK_WIDTH * 10);
//        walls.back().setFillColor(sf::Color::Yellow);
//    }
//    for(int i = 0; i < 10; ++i) {
//        walls.emplace_back(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT));
//        walls.back().rotate(90);
//        walls.back().setPosition(BLOCK_HEIGHT, i * BLOCK_WIDTH + BLOCK_HEIGHT);
//        walls.back().setFillColor(sf::Color::Green);
//    }
//    for(int i = 0; i < 10; ++i) {
//        walls.emplace_back(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT));
//        walls.back().rotate(90);
//        walls.back().setPosition(BLOCK_WIDTH * 10 + BLOCK_HEIGHT, i * BLOCK_WIDTH);
//        walls.back().setFillColor(sf::Color::Magenta);
//    }
//
//    return 0;
//}

int generateBounds(std::vector<sf::Vertex [2]> &walls) {
    for(int i = 0; i < 10; ++i) {
//        sf::Vertex line[2] = {
//                sf::Vertex(sf::Vector2f(i * BLOCK_WIDTH, 0)),
//                sf::Vertex(sf::Vector2f((i + 1) * BLOCK_WIDTH, 0))};
//        walls.push_back(line);
    }
//    for(int i = 0; i < 10; ++i) {
//        walls.emplace_back(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT));
//        walls.back().setPosition(i * BLOCK_WIDTH + BLOCK_HEIGHT, BLOCK_WIDTH * 10);
//        walls.back().setFillColor(sf::Color::Yellow);
//    }
//    for(int i = 0; i < 10; ++i) {
//        walls.emplace_back(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT));
//        walls.back().rotate(90);
//        walls.back().setPosition(BLOCK_HEIGHT, i * BLOCK_WIDTH + BLOCK_HEIGHT);
//        walls.back().setFillColor(sf::Color::Green);
//    }
//    for(int i = 0; i < 10; ++i) {
//        walls.emplace_back(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT));
//        walls.back().rotate(90);
//        walls.back().setPosition(BLOCK_WIDTH * 10 + BLOCK_HEIGHT, i * BLOCK_WIDTH);
//        walls.back().setFillColor(sf::Color::Magenta);
//    }

    return 0;
}

sf::Vector2f pointIntersection(const sf::Vector2f &a, const sf::Vector2f &b, const sf::Vector2f &c, const sf::Vector2f &d) {
    float s = ((a.x - c.x) * (d.y - c.y) - (d.x - c.x) * (a.y - c.y)) / ((d.x - c.x) * (b.y - a.y) - (b.x - a.x) * (d.y - c.y));
//    float r = ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / ((d.x - c.x) * (b.y - a.y) - (b.x - a.x) * (d.y - c.y));
    return s * (b - a) + a;
}

float crossProduct(const sf::Vector2f p1, const sf::Vector2f p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

float lineDirection(const sf::Vector2f p1, const sf::Vector2f p2, const sf::Vector2f p3) {
    return crossProduct(p3 - p1, p2 - p1);
}

bool onSegment(const sf::Vector2f p1, const sf::Vector2f p2, const sf::Vector2f p3) {
    return fmin(p1.x, p2.x) <= p3.x and p3.x <= fmax(p1.x, p2.x) and fmin(p1.y, p2.y) <= p3.y and
           p3.y <= fmax(p1.y, p2.y);
}

bool segmentsInetersect(const sf::Vector2f p1, const sf::Vector2f p2, const sf::Vector2f p3, const sf::Vector2f p4, sf::Vector2f &interPoint) {
    float d1 = lineDirection(p3, p4, p1);
    float d2 = lineDirection(p3, p4, p2);
    float d3 = lineDirection(p1, p2, p3);
    float d4 = lineDirection(p1, p2, p4);
    bool areIntersect = false;

    if(((d1 > 0 and d2 < 0) or (d1 < 0 and d2 > 0)) and ((d3 > 0 and d4 < 0) or (d3 < 0 and d4 > 0))) {
        areIntersect = true;
    } else if(d1 == 0 and onSegment(p3, p4, p1)) {
        areIntersect = true;
    } else if(d2 == 0 and onSegment(p3, p4, p2)) {
        areIntersect = true;
    } else if(d3 == 0 and onSegment(p1, p2, p3)) {
        areIntersect = true;
    } else if(d4 == 0 and onSegment(p1, p2, p4)) {
        areIntersect = true;
    }

    if(areIntersect) {
        interPoint = pointIntersection(p1, p2, p3, p4);
        return true;
    }

    return false;
}


float lineLength(const sf::Vector2f &p1, const sf::Vector2f &p2) {
    return sqrtf((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}



int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game Of Life");
    window.setFramerateLimit(60);
    Player player(500, 500, 90);
    player.update();
    std::vector<sf::Vertex [2]> walls;
//    std::vector<sf::RectangleShape> blocks;
//    std::vector<sf::RectangleShape> toDraw;
    sf::Clock timePoint1;
    sf::ConvexShape convex;
    sf::Vertex line[2] = {
            sf::Vertex(sf::Vector2f(3 * BLOCK_WIDTH, 5 * BLOCK_HEIGHT)),
            sf::Vertex(sf::Vector2f((4) * BLOCK_WIDTH, 5 * BLOCK_HEIGHT))};
//    walls.push_back(line);


    convex.move(sf::Vector2f(12, 12));
    convex.setFillColor(sf::Color(255, 255, 255, 128));
    convex.setOutlineThickness(1);
    convex.setOutlineColor(sf::Color::Red);
//    std::cout << convex.getPosition().x << " " << convex.getPosition().y << std::endl;
    convex.setPointCount(SCREEN_WIDTH / 32 + 1);
    convex.setPoint(0, player.getPoint().getPosition());
    for(int i = 1; i <= convex.getPointCount() - 1; ++i) {
        float rayAngle = (player.getDirection() * PI / 180 - FOV / 2.0f) + (float(i - 1) / float(convex.getPointCount() - 1)) * FOV;
//        rayAngle = rayAngle * PI / 180;
        float rayX = sinf(rayAngle);
        float rayY = cosf(rayAngle);

//        std::cout << "RayX: " << rayX << "  RayY: " << rayY << std::endl;
        convex.setPoint(i, sf::Vector2f(player.getPosition().first + rayX * DIST_DEPTH,
                                        player.getPosition().second + rayY * DIST_DEPTH));
    }

//    generateBounds(walls);
//
//    blocks.emplace_back(sf::RectangleShape(sf::Vector2f(BLOCK_WIDTH, BLOCK_WIDTH)));
//    blocks.back().setPosition(400, 400);
//    blocks.back().setFillColor(sf::Color::Magenta);

    sf::CircleShape circle;
    circle.setRadius(100);
    circle.setPosition(650, 650);
    circle.setFillColor(sf::Color::Yellow);

    while(window.isOpen()) {
        sf::Time timeElapsed = timePoint1.restart();
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();

                    break;

                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::E:
                            std::cout << "I go home by button E" << std::endl;
                            window.close();

                            break;

                        case sf::Keyboard::Escape:
                            std::cout << "I go home by button Esc" << std::endl;
                            window.close();

                            break;

                        case sf::Keyboard::Space:
                            std::cout << "Space button has been pressed!" << std::endl;

                            break;

                        default:
                            break;
                    }

                    break;

                case sf::Event::MouseButtonPressed:
                    switch (event.mouseButton.button) {
                        case sf::Mouse::Left:
                            std::cout << "Left mouse" << std::endl;

                            break;

                        case sf::Mouse::Right:
                            std::cout << "Right mouse" << std::endl;

                            break;

                        default:
                            break;
                    }

                    break;

                default:
                    break;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            std::cout << "W button has been pressed!" << std::endl;
            player.movePosition(sinf(player.getDirection() * PI / 180) * 0.25f * timeElapsed.asMilliseconds(),
                                cosf(player.getDirection() * PI / 180) * 0.25f * timeElapsed.asMilliseconds());
//            for(const auto &item : blocks) {
//                if(item.getGlobalBounds().intersects(player.getPoint().getGlobalBounds())) {
//                    player.movePosition(-sinf(player.getDirection() * PI / 180) * 0.25f * timeElapsed.asMilliseconds(),
//                                        -cosf(player.getDirection() * PI / 180) * 0.25f * timeElapsed.asMilliseconds());
//                }
//            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            std::cout << "S button has been pressed!" << std::endl;
            player.movePosition(-sinf(player.getDirection() * PI / 180) * 0.25f * timeElapsed.asMilliseconds(),
                                -cosf(player.getDirection() * PI / 180) * 0.25f * timeElapsed.asMilliseconds());
//            for(const auto &item : blocks) {
//                if(item.getGlobalBounds().intersects(player.getPoint().getGlobalBounds())) {
//                    player.movePosition(sinf(player.getDirection() * PI / 180) * 0.25f * timeElapsed.asMilliseconds(),
//                                        cosf(player.getDirection() * PI / 180) * 0.25f * timeElapsed.asMilliseconds());
//                }
//            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            std::cout << "A button has been pressed!" << std::endl;
            player.moveDirection(1.5);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            std::cout << "D button has been pressed!" << std::endl;
            player.moveDirection(-1.5);
        }

        convex.setPoint(0, player.getPoint().getPosition());
        for(int i = 1; i <= convex.getPointCount() - 1; ++i) {
            float rayAngle = float(player.getDirection() * PI / 180 - FOV / 2.0f) + (float(i - 1) / float(convex.getPointCount() - 1) * FOV);
            float rayLength = 0;
            bool isHitted = false;
            float rayX = sinf(rayAngle);
            float rayY = cosf(rayAngle);



            while(!isHitted and rayLength < DIST_DEPTH) {
                rayLength += 0.75;
                sf::Vector2f interPoint;

                float testX = player.getPosition().first + rayX * rayLength;
                float testY = player.getPosition().second + rayY * rayLength;

                if(testX < 0 or testX > MAP_WIDTH or testY < 0 or testY > MAP_HEIGHT) {
                    isHitted = true;
                    rayLength = DIST_DEPTH;
                } else {
                    if(segmentsInetersect(convex.getPoint(0), sf::Vector2f(testX, testY),
                                          line[0].position, line[1].position, interPoint)) {
                        rayLength = lineLength(convex.getPoint(0), interPoint);
						isHitted = true;
                    }
//                    for(const auto &item : blocks) {
//                        if(item.getGlobalBounds().contains(testX, testY)) {
//                            isHitted = true;
//                            break;
//                        }
//                    }
//                    if(circle.getGlobalBounds().contains(testX, testY)) {
//                        isHitted = true;
//                    }
                }

                convex.setPoint(i, sf::Vector2f(player.getPosition().first + rayX * rayLength - 11,
                                                player.getPosition().second + rayY * rayLength - 11));
            }

        }

//        toDraw.clear();
//        for(int x = 0; x < SCREEN_WIDTH; ++x) {
//            float rayAngle = float(player.getDirection() - FOV / 2.0f) + (float(x) / SCREEN_WIDTH * FOV);
//            float rayLength = 0;
//            bool isHitted = false;
//            float rayX = sinf(rayAngle);
//            float rayY = cosf(rayAngle);
//
//
//            while(!isHitted and rayLength < DIST_DEPTH) {
//                rayLength += 0.25;
//
//                float testX = player.getPosition().first + rayX * rayLength;
//                float testY = player.getPosition().second + rayY * rayLength;
//
//                if(testX < 0 or testX > MAP_WIDTH or testY < 0 or testY > MAP_HEIGHT) {
//                    isHitted = true;
//                    rayLength = DIST_DEPTH;
//                } else {
//                    for(const auto &item : blocks) {
//                        if(item.getGlobalBounds().contains(testX, testY)) {
//                            isHitted = true;
//                            break;
//                        }
//                    }
//                }
//            }
//
//            int ceil = SCREEN_HEIGHT / 2 - SCREEN_HEIGHT / rayLength;
//            int floor = SCREEN_HEIGHT - ceil;
//            sf::RectangleShape rect(sf::Vector2f(20, floor - ceil));
//
//            sf::Color color = sf::Color::Magenta;
//            sf::Color shade = sf::Color(15, 15, 15);
//
//
//            if(rayLength < DIST_DEPTH / 3.0f) {
//                rect.setFillColor(color);
//            } else if(rayLength < DIST_DEPTH / 2.0f) {
//                rect.setFillColor(color - shade);
//            } else if(rayLength < DIST_DEPTH / 1.5f) {
//                rect.setFillColor(color - shade - shade);
//            } else if(rayLength < DIST_DEPTH) {
//                rect.setFillColor(color - shade - shade - shade);
//            } else {
//                rect.setFillColor(shade);
//            }
//
//            for(int y = 0; y < SCREEN_HEIGHT; ++y) {
//                if(y == ceil) {
//                    rect.setPosition(x, y);
////                    window.draw(rect);
//                    toDraw.push_back(rect);
////                    break;
//                }
//            }
//        }

        window.clear(sf::Color::Black);
//        for(auto &item : walls) {
//            window.draw(item, 2, sf::Lines);
//        }
        window.draw(line, 2, sf::Lines);
        window.draw(circle);
        window.draw(convex);
        window.draw(player.getPoint());
        window.draw(player.getDirLine());
//        window.draw(player.getFOVCircle());
//        drawFOV(window, blocks, player);
//        for(const auto &item : toDraw) {
//            window.draw(item);
//        }
        window.display();
    }

    return 0;
}
