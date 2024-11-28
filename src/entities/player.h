#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Player {
public:
    sf::RectangleShape player;
    float yvel;
    float xvel;

    sf::Text text;
    sf::Font font;

    Player(); // Constructor declaration

    void render(sf::RenderWindow& window, float dt); // Method declaration
    void update(float dt);
    void setDirection(sf::Event eventType);
    bool collisionDetectionTop(float ypos);
    bool collisionDetectionBottom(float ypos);
    sf::Vector2f getPosition();
};

#endif // MYCLASS_H
