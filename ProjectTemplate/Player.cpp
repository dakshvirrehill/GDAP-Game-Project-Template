#include "GameCore.h"
#include "Player.h"

IMPLEMENT_DYNAMIC_CLASS(Player)

void Player::initialize()
{
	Component::initialize();
	spriteTexture.loadFromFile("../Assets/WitchIdle.png");
	playerSprite.setTexture(spriteTexture);
	playerSprite.setColor(sf::Color(255, 255, 255, 200));
}

void Player::update(float deltaTime)
{
	sf::Vector2f moveOffset(0, 0);

	if (InputManager::instance().getKeyState(sf::Keyboard::Down) == InputManager::PushState::Held)
	{
		moveOffset.y += 5;
	}
	if (InputManager::instance().getKeyState(sf::Keyboard::Up) == InputManager::PushState::Held)
	{
		moveOffset.y -= 5;
	}
	if (InputManager::instance().getKeyState(sf::Keyboard::Left) == InputManager::PushState::Held)
	{
		moveOffset.x -= 5;
	}
	if (InputManager::instance().getKeyState(sf::Keyboard::Right) == InputManager::PushState::Held)
	{
		moveOffset.x += 5;
	}

	getGameObject()->getTransform()->translate(moveOffset);
	playerSprite.setPosition(getGameObject()->getTransform()->getPosition());
	std::cout << playerSprite.getPosition().x << std::endl;

	auto window = RenderSystem::instance().getRenderWindow();
	if (window != nullptr)
	{
		window->clear();
		window->draw(playerSprite);
		window->display();
	}
}

void Player::load(json::JSON& node)
{
	Component::load(node);
}
