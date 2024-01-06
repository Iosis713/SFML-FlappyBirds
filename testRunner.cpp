#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include "Headers/Sprite.hpp"
#include "Headers/Moveable.hpp"

/*_____________________________________ SPRITE class _________________________________*/

class SpriteFixture : public testing::TestWithParam<sf::Vector2f>
{
public:
protected:
    Sprite mSprite{sf::Vector2f(50.f, 100.f), 20.f, 100.f, sf::Color::Red};
};

TEST_P(SpriteFixture, TestSetPosition)
{
    sf::Vector2f param = GetParam();

    mSprite.setPosition(param);

    ASSERT_EQ(mSprite.getPosition(), param);
}

TEST(Sprite, getHeightTest)
{
    Sprite mSprite{sf::Vector2f(50.f, 100.f), 20.f, 70.f, sf::Color::Red}; 

    ASSERT_EQ(70.f, mSprite.getHeight());
}

TEST(Sprite, getWidthTest)
{
    Sprite mSprite{sf::Vector2f(50.f, 100.f), 60.f, 70.f, sf::Color::Red};
    
    ASSERT_EQ(60.f, mSprite.getWidth());
}


INSTANTIATE_TEST_CASE_P(TestingSetPosition, SpriteFixture, testing::Values(sf::Vector2f(20, 30),
                                                        sf::Vector2f(60, -10),
                                                        sf::Vector2f(-20, -30)));

/*________________________ MOVEABLE class ________________________________________*/

class MoveableFixture : public testing::TestWithParam<sf::Vector2f>
{
public:
protected:
    Moveable mMoveable{sf::Vector2f(600.f, 300.f), 30.f, 70.f};
};

TEST_P(MoveableFixture, setVelocityTest)
{
    sf::Vector2f param = GetParam();
    
    mMoveable.setVelocity(param);

    ASSERT_EQ(mMoveable.getVelocity(), param);
    TearDown();
}

INSTANTIATE_TEST_CASE_P(TestingSetVelocity, MoveableFixture, testing::Values(sf::Vector2f(10, 40),
                                                                             sf::Vector2f(0, 30),
                                                                             sf::Vector2f(0, -20),
                                                                             sf::Vector2f(10, 0),
                                                                             sf::Vector2f(-17.6, 0),
                                                                             sf::Vector2f(-11.2, -23.2)));

TEST_P(MoveableFixture, updatePositionTest)
{
    sf::Vector2f param = GetParam();//velocity vector
    sf::Vector2f initialPosition = mMoveable.getPosition();

    mMoveable.setVelocity(param);
    mMoveable.updatePosition();

    ASSERT_EQ(mMoveable.getPosition(), initialPosition + param);
    TearDown();
}

INSTANTIATE_TEST_CASE_P(TestingUpdatePosition, MoveableFixture,
        testing::Values(sf::Vector2f(17.6, 41),
                        sf::Vector2f(0.0, 37.1),
                        sf::Vector2f(0.0, -27.16),
                        sf::Vector2f(12.9, 0.0),
                        sf::Vector2f(-27.62, 0.0),
                        sf::Vector2f(-51.2, -43.2)));

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

