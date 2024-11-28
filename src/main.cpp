#include <SFML/Graphics.hpp>
#include <iostream>
#include "entities/player.h"
#include "entities/ball.h"

int main()
{
    Player player;
    Ball ball(player);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong", sf::Style::Default, settings);

    window.setFramerateLimit(60);

    sf::Clock deltaClock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                    std::exit(0);
                else if (event.key.code == sf::Keyboard::K)
                    ball.resetBall();
                else
                    player.setDirection(event);
            else
                player.yvel = 0;

        }

        float dt = deltaClock.restart().asSeconds(); 
        
        window.clear();
        player.render(window, dt);
        ball.render(window, dt);
        window.display();
       
        float fps = 1.0f / dt;
        //std::cout << "FPS: " << floor(fps) << std::endl;
    }

    return 0;
}