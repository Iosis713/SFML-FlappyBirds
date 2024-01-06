#pragma once

#include "Sprite.hpp"

#include <SFML/Graphics.hpp>

class Moveable : public Sprite
{
protected:
    sf::Vector2f velocity_;

public:
    Moveable(sf::Vector2f position, float const width, float const height);
    Moveable(sf::Vector2f position, float const width, float const height, sf::Color color);
    void setVelocity(sf::Vector2f velocity);
    sf::Vector2f getVelocity() const;
};
