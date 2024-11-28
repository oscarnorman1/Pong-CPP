// MyClass.h
#ifndef BALL_H   // If MYCLASS_H is not defined
#define BALL_H   // Define MYCLASS_H

#include <SFML/Graphics.hpp>
#include "player.h"
#include <iostream>

class Ball {
public:
    sf::CircleShape ball;
    float xvel;
    float yvel;

    sf::Text text;
    sf::Font font;

    Player& player;

    Ball(Player& player);

    void render(sf::RenderWindow& window, float dt); // Method declaration
    void update(float dt);
    void setVelocity();
    void collisionDetection(float xpos, float ypos);
    void resetBall();
};

#endif // End of include guard
