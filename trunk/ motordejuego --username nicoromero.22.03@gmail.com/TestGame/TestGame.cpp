#include "TestGame.h"

TestGame::TestGame(HINSTANCE hInstance) : Game(hInstance)
{
}
bool TestGame::OnStart()
{
	return true;
}
bool TestGame::OnLoop()
{
	return true;
}
bool TestGame::OnShutDown()
{
	return true;
}