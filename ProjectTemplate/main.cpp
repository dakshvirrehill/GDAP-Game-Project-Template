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

    GameEngine::instance().initialize(&ProjectEngine::instance());
	GameEngine::instance().gameLoop();

	return -1;
}