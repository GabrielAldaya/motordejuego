#include "Game.h"

Game::Game(HINSTANCE hInstance)
:
m_pkRender(NULL),
m_pkWindow(NULL),
m_hInstance(hInstance)
{
	Colors[0].x=0.5;
	Colors[1].x=-0.5;
	Colors[2].x=-0.5;
	Colors[0].color = D3DCOLOR_XRGB(0,0,255);
	Colors[0].y=-0.5;
	Colors[1].y=0.5;
	Colors[2].y=-0.5;
	Colors[1].color = D3DCOLOR_XRGB(0,255,0);
	Colors[0].z=0.5;
	Colors[1].z=0.5;
	Colors[2].z=-0.5;
	Colors[2].color = D3DCOLOR_XRGB(255,0,0);
}
Game::~Game()
{}

bool Game::StartUp()
{
	HWND hWnd;	
	m_pkWindow = new Window(m_hInstance);
	m_pkWindow->createWindow(800 , 600, hWnd);
	m_pkRender = new Renderer();
	m_pkRender->InitDX(hWnd);
	if (!OnStart())
		return false;

	return true;
}

bool Game::Loop()
{
	
	m_pkRender->StartFrame();
	m_pkRender->Draw(&Colors[0],Renderer::TRIANGLE_LIST,3);
	m_pkRender->EndFrame();
	if(OnLoop())
		return true;
	

	return false;
}
bool Game::ShutDown()
{
	if (!OnShutDown())
		return false;

	if (m_pkWindow)
		delete m_pkWindow;

	m_pkWindow = NULL;

	return true;
}
