#include "player.h"
#include <iostream>

Player::Player() {
    yvel = 0;
    xvel = 0;

    // Init rectangle object, 20 width, 150 height
    player = sf::RectangleShape(sf::Vector2f(20, 150));

    // Initial position for player, centered.
    player.setPosition(20.0f, 240.0f - 75.0f);

    // Set player (rectangle) color to green
    player.setFillColor(sf::Color::Green);

    font.loadFromFile("assets/Basic-Regular.ttf");
    text = sf::Text("aaaddddaaa", font, 24);
    text.setPosition(sf::Vector2f(25, 25));
}

void Player::render(sf::RenderWindow& window, float dt) {
    window.draw(player);
    window.draw(text);
    update(dt);
}

void Player::update(float dt)
{
    float ypos = player.getPosition().y;
    text.setString("ypos: " + std::to_string(static_cast<int>(ypos)));
    player.setPosition(20.0f, ypos + yvel * dt);
}   

void Player::setDirection(sf::Event eventType)
{
    float ypos = player.getPosition().y;
    if (eventType.key.code == sf::Keyboard::Down) {
        if (collisionDetectionBottom(ypos))
            yvel = 0;
        else
            yvel = 150.0f;
    }

    if (eventType.key.code == sf::Keyboard::Up) {
        if (collisionDetectionTop(ypos))
            yvel = 0;
        else
            yvel = -150.0f;
    }

}

bool Player::collisionDetectionTop(float ypos)
{
    if (ypos <= 0.0f) {
        std::cout << "Hit top\n";
        return true;
    }
    else {
        return false;
    }
}

bool Player::collisionDetectionBottom(float ypos)
{
    if (ypos >= 600.0f - 150.0f) {
        std::cout << "Hit bottom\n";
        return true;
    }
    else {
        return false;
    }
}

sf::Vector2f Player::getPosition() {
    return player.getPosition();
}