#include "GameCore.h"
#include "ProjectEngine.h"
#include "Player.h"

void ProjectEngine::initialize()
{
	GameObject* playerGameObject = GameObjectManager::instance().createGameObject();
	playerGameObject->createComponent(Player::getClassName());
}

void ProjectEngine::update(float deltaTime)
{
}
