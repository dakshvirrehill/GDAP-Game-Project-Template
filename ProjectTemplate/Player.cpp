#include "GameCore.h"
#include "Player.h"
#include "ProjectEngine.h"
#include "ICollidable.h"
#include "Animator.h"

IMPLEMENT_DYNAMIC_CLASS(Player)

void Player::initialize()
{
	if (!isEnabled())
	{
		return;
	}
	Component::initialize();
	ProjectEngine::instance().setPlayer(this);
}

Player::~Player()
{
	ProjectEngine::instance().setPlayer(nullptr);
}

void Player::update(float deltaTime)
{
	if (!getGameObject()->isEnabled() || !enabled)
	{
		return;
	}
	if (win)
	{
		return;
	}
	sf::Vector2f moveOffset(0, 0);
	bool isMoving = false;
	
	//getGameObject()->
	Animator* anim = ((Animator*)getGameObject()->getComponent("Animator"));
	if (InputManager::instance().getKeyState(sf::Keyboard::Down) == InputManager::PushState::Held)
	{
		if(anim->getCurrentAnimationName() != "DWalk")
		{
			anim->setCurrentAnimation("DWalk");
			anim->playCurrentAnimation();
		}

		moveOffset.y += moveSpeed * deltaTime;
		isMoving = true;
	}
	if (InputManager::instance().getKeyState(sf::Keyboard::Up) == InputManager::PushState::Held)
	{
		if (anim->getCurrentAnimationName() != "UWalk")
		{
			anim->setCurrentAnimation("UWalk");
			anim->playCurrentAnimation();
		}
		moveOffset.y -= moveSpeed * deltaTime;
		isMoving = true;
	}
	if (InputManager::instance().getKeyState(sf::Keyboard::Left) == InputManager::PushState::Held)
	{
		if (anim->getCurrentAnimationName() != "LWalk")
		{
			anim->setCurrentAnimation("LWalk");
			anim->playCurrentAnimation();
		}
		moveOffset.x -= moveSpeed * deltaTime;
		isMoving = true;
	}
	if (InputManager::instance().getKeyState(sf::Keyboard::Right) == InputManager::PushState::Held)
	{
		if (anim->getCurrentAnimationName() != "RWalk")
		{
			anim->setCurrentAnimation("RWalk");
			anim->playCurrentAnimation();
		}
		moveOffset.x += moveSpeed * deltaTime;
		isMoving = true;
	}

	if(!isMoving)
	{
		if (anim->getCurrentAnimationName() != "Idle")
		{
			anim->setCurrentAnimation("Idle");
			anim->playCurrentAnimation();
		}
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

	collisionData->colliders[otherColliderIx]->getGameObject()->getComponent("Text")->setEnabled(true);
	win = true;
}
