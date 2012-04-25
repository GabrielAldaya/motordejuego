#ifndef STRUCTS_H
#define STRUCTS_H

///////////////////
#define COLOR_VERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)
struct ColorVertex
{
	float x,y,z;
	DWORD color;
};
///////////////////
#endif