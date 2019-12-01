#include "GameCore.h"
#include "Player.h"
#include "ICollidable.h"

IMPLEMENT_DYNAMIC_CLASS(Player)

void Player::initialize()
{
	if (!isEnabled())
	{
		return;
	}
	Component::initialize();
}

void Player::update(float deltaTime)
{
	if (!getGameObject()->isEnabled() || !enabled)
	{
		return;
	}

	sf::Vector2f moveOffset(0, 0);

	if (InputManager::instance().getKeyState(sf::Keyboard::Down) == InputManager::PushState::Held)
	{
		moveOffset.y += moveSpeed * deltaTime;
	}
	if (InputManager::instance().getKeyState(sf::Keyboard::Up) == InputManager::PushState::Held)
	{
		moveOffset.y -= moveSpeed * deltaTime;
	}
	if (InputManager::instance().getKeyState(sf::Keyboard::Left) == InputManager::PushState::Held)
	{
		moveOffset.x -= moveSpeed * deltaTime;
	}
	if (InputManager::instance().getKeyState(sf::Keyboard::Right) == InputManager::PushState::Held)
	{
		moveOffset.x += moveSpeed * deltaTime;
	}

	getGameObject()->getTransform()->translate(moveOffset);
}

void Player::load(json::JSON& node)
{
	Component::load(node);
	if (node.hasKey("moveSpeed"))
	{
		moveSpeed = node["moveSpeed"].ToFloat();
	}
}

void Player::setEnabled(bool _enabled)
{
	enabled = _enabled;
	if (enabled && getGameObject()->isEnabled() && !initialized)
	{
		initialize();
	}
}


void Player::onTriggerEnter(const Collision* const collisionData)
{
	int otherColliderIx = 1;
	if (collisionData->colliders[otherColliderIx]->getGameObject() == getGameObject())
	{
		otherColliderIx = 0;
	}

	collisionData->colliders[otherColliderIx]->getGameObject()->setEnabled(true);
}
