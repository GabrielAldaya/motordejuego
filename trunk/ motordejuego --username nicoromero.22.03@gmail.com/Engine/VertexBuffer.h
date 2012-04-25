#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H
//--------------------------------------------------------------------------------
#include <D3D9.h>
#include "Defines.h"
//--------------------------------------------------------------------------------
#pragma comment (lib, "d3d9.lib")
//--------------------------------------------------------------------------------
template <class PixelFormatClass, unsigned int FVF>
class VertexBuffer
{
private:
	unsigned int m_uiVbSize;//Indica el tamaño del vertex buffer. Fijado a un valor constante
	unsigned int m_uiFlush;//uiFlush: Indica la cantidad de vértices cada cuanto se realizará un DrawPrimitive de los ya vértices almacenados.
	unsigned int m_uiBase; //Indica el índice en el cual se deja el vertex buffer
	unsigned int m_uiVtxToLock;//Indica la cantidad de vértices a trabar en Draw
	D3DPRIMITIVETYPE m_PrimitiveType; //Indica la primitiva pasada como parámetro a Draw
	IDirect3DVertexBuffer9* m_pVertexBuffer; //El Vértex Buffer creado queda encapsulado dentro de la clase
	IDirect3DDevice9* m_pDev; //Almaceno temporalmente el dispositivo pasado como parámetro en Draw.


//--------------------------------------------------------------------------------
public:
	
	VertexBuffer();	
	~VertexBuffer();
	//Crea el vertex buffer, al cual se le pasará como parámetro el dispositivo de DirectX
	//que se inicializó en la clase Renderer. Un segundo parámetro, opcional, índicará si el mismo es o no dinámico.
	bool Create(IDirect3DDevice9 * pDev, bool bDynamic);
	//Libera al vertex buffer. Usualmente este método se invocará en el apagado del juego.
	void Release();
	//Este método le indicará cual es el vb activo a DirectX.
	void Bind(void);
	//Será el método utilizado cada vez que se desee transferir vértices al vb. Se le pasa como parámetro el array de vértices, 
	//la primitiva a dibujar y la cantidad de vértices en el array.
	void Draw(PixelFormatClass * pVtxCollection, D3DPRIMITIVETYPE primitiveType, unsigned int uiVtxCount);
	//Este método invocará a DrawPrimitive (método de DirectX que procesa los vértices insertos en el vb).
	//Será invocado al menos una vez en el dibujado de cada objeto (y más si la cantidad de vértices del objeto es mayor a m_uiFlush).
	void Flush();
};
//--------------------------------------------------------------------------------
#include "VertexBuffer.inl"
#endif //VERTEXBUFFER_H