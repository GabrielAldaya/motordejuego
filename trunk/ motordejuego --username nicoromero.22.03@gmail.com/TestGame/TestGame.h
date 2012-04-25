#include "Game.h"

class TestGame : public Game
{
public:
	TestGame(HINSTANCE hInstance);
	bool OnStart();
	bool OnLoop();
	bool OnShutDown();
};;