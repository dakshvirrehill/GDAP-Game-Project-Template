#include "GameCore.h"
#include "GameEngine.h"
#include "ProjectEngine.h"
#include "Player.h"

void registerGameClasses()
{
	REGISTER_DYNAMIC_CLASS(Player);
}

int main(int argc, char* argv[])
{
    registerGameClasses();

    //GameEngine::instance().initialize();
    GameEngine::instance().initialize(&ProjectEngine::instance());

	GameObject* playerGameObject = GameObjectManager::instance().createGameObject();
	playerGameObject->createComponent(Player::getClassName());

	GameEngine::instance().gameLoop();


	//GameObject* go = GameObjectManager::instance().createGameObject();
	//go->getTransform()->setPosition(sf::Vector2f(5, 10));
	//go->getTransform()->translate(sf::Vector2f(2, 2));
	//Transform* tr = (Transform*)go->getComponent(Transform::getClassName());
	//go->getTransform()->setRotation(45);
	//std::cout << go->getTransform()->getPosition().x << std::endl;
	//std::cout << go->getTransform()->getForward().x << std::endl;
	return -1;
}