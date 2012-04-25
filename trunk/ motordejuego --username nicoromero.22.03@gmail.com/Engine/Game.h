#ifndef GAME_H
#define GAME_H
//------------------------------------------------------------------------
#include "Defines.h"
#include "Window.h"
#include "Renderer.h"
#include "Structs.h"

//------------------------------------------------------------------------
class ENGINE_API Game
{
public:
	Game(HINSTANCE hInstance);
	virtual ~Game();
	
	// engine functions
	bool StartUp();
	bool Loop();
	bool ShutDown();
	
protected:
	// virtual functions
	virtual bool OnStart() =0;
	virtual bool OnLoop() = 0;
	virtual bool OnShutDown() = 0;
	

private:
	Renderer* m_pkRender;
	Window* m_pkWindow;
	HINSTANCE m_hInstance;
	ColorVertex Colors[3];
	
};
//QueryPerformanceCounter
#endif GAME_H