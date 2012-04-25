#ifndef RENDERER_H
#define RENDERER_H
#include<D3D9.h>
#include "VertexBuffer.h"
#include "Structs.h"
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
class Renderer
{
public:
	Renderer();
	~Renderer();
	bool InitDX(HWND hWnd);
	void StartFrame();
	void EndFrame();
	enum PrimitiveType
	{
		TRIANGLE_LIST = D3DPT_TRIANGLELIST,
		TRIANGLE_STRIP = D3DPT_TRIANGLESTRIP,
		TRIANGLE_FAN = D3DPT_TRIANGLEFAN,
		LINE_STRIP = D3DPT_LINESTRIP
	};
	void Draw(ColorVertex * vertexColletion, PrimitiveType prim, unsigned int uiVertexCount);
private:
	IDirect3DDevice9* m_pkDevice;

};
#endif