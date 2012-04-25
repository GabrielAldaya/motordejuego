#ifndef WINDOWS_H
#define WINDOWS_H

#include "Defines.h"

class ENGINE_API Window
{
public:
	
	Window(HINSTANCE hInstance);
	~Window();
	bool createWindow(unsigned int uiWidthh, unsigned int uiHeight, HWND & hWnd);

private:
	HWND m_hWnd;
	HINSTANCE m_hInstance;

};

LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
#endif //WINDOW_H