#include "ball.h"
#include <iostream>
#include "player.h"

Ball::Ball(Player& playerRef) : player(playerRef) {
    yvel = 200.0f;
    xvel = 200.0f;

    player = playerRef;

    // Init rectangle object, 20 width, 150 height
    ball = sf::CircleShape(15);

    // Initial position for ball
    ball.setPosition(800.0f/2.0f - 7.5f, 600.0f/2.0f - 7.5f);

    // Set player (rectangle) color to green
    ball.setFillColor(sf::Color::Red);

    font.loadFromFile("assets/Basic-Regular.ttf");
    text = sf::Text("", font, 24);
    text.setPosition(sf::Vector2f(200, 200));
}

void Ball::render(sf::RenderWindow& window, float dt) {
    window.draw(ball);
    window.draw(text);
    update(dt);
}

void Ball::update(float dt) {
    float xpos = ball.getPosition().x;
    float ypos = ball.getPosition().y;

    collisionDetection(xpos, ypos);

    text.setString("Ball xpos: " + std::to_string(static_cast<int>(xpos)) + "\nBall ypos: " + std::to_string(static_cast<int>(xpos)));
    ball.setPosition(xpos + xvel * dt, ypos + yvel * dt);
}

void Ball::setVelocity() {

}

void Ball::collisionDetection(float xpos, float ypos) {
    if (xpos >= 800.0f - 30.0f)
         xvel = -200.0f;
    if (ypos >= 600.0f - 30.0f)
        yvel = -200.0f;
    if (ypos <= 0.0f)
        yvel = 200.0f;
    if (xpos <= 0.0f)
        xvel = 200.0f;
}

void Ball::resetBall() {
    ball.setPosition(800.0f / 2.0f - 7.5f, 600.0f / 2.0f - 7.5f);
}