#include "GameCore.h"
#include "Player.h"

IMPLEMENT_DYNAMIC_CLASS(Player)

void Player::initialize()
{
	Component::initialize();
	spriteTexture.loadFromFile("../Assets/WitchIdle.png");
	playerSprite.setTexture(spriteTexture);
	playerSprite.setColor(sf::Color(255, 255, 255, 200));
	playerSprite.setOrigin(getGameObject()->getTransform()->getPosition());
}

void Player::update(float deltaTime)
{
	sf::Vector2f moveOffset(0, 0);

	if (InputManager::instance().getKeyState(sf::Keyboard::Down) == InputManager::PushState::Held)
	{
		moveOffset.y += 50 * deltaTime;
	}
	if (InputManager::instance().getKeyState(sf::Keyboard::Up) == InputManager::PushState::Held)
	{
		moveOffset.y -= 50 * deltaTime;
	}
	if (InputManager::instance().getKeyState(sf::Keyboard::Left) == InputManager::PushState::Held)
	{
		moveOffset.x -= 50 * deltaTime;
	}
	if (InputManager::instance().getKeyState(sf::Keyboard::Right) == InputManager::PushState::Held)
	{
		moveOffset.x += 50 * deltaTime;
	}

	getGameObject()->getTransform()->translate(moveOffset);
	playerSprite.setPosition(getGameObject()->getTransform()->getPosition());
}

void Player::load(json::JSON& node)
{
	Component::load(node);
}

void Player::render(sf::RenderWindow* _window)
{
	_window->draw(playerSprite);
}
