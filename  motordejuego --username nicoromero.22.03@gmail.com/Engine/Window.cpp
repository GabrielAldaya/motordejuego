#include "Window.h"

Window::Window(HINSTANCE hInstance)
:
m_hWnd(NULL),
m_hInstance(hInstance){}
Window::~Window()
{}

bool Window::createWindow(unsigned int uiWidth, unsigned int uiHeight, HWND & hWnd)
{
	//registracion a windows
	WNDCLASS kWC;
	memset(static_cast<void *> (&kWC), 0, sizeof(WNDCLASS));
	kWC.style = CS_HREDRAW | CS_VREDRAW;
	kWC.lpfnWndProc = (WNDPROC) WndProc;
	kWC.hInstance = m_hInstance;
	kWC.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
	kWC.lpszClassName = "Engine";

	if (!RegisterClass(&kWC))
		return false;


	m_hWnd = CreateWindow("Engine", "Engine v0.1", WS_OVERLAPPEDWINDOW , CW_USEDEFAULT,
							CW_USEDEFAULT, uiWidth +8 , uiHeight + 30, NULL, NULL , m_hInstance,
							NULL);

	if (!m_hWnd)
		return false;

	




	hWnd = m_hWnd;
	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	return true;
}


LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{	
	switch(message)
	{	
		case WM_DESTROY:
		
			PostQuitMessage(0);
			break;
		
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}