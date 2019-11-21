#include "GameCore.h"
#include "GameEngine.h"
#include "ProjectEngine.h"

void registerGameClasses()
{
}

int main(int argc, char* argv[])
{
    registerGameClasses();

    GameEngine::instance().initialize();
    //GameEngine::instance().initialize(&ProjectEngine::instance());
	GameEngine::instance().gameLoop();

	return -1;
}