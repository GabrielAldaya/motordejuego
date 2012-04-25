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
	unsigned int m_uiVbSize;//Indica el tama�o del vertex buffer. Fijado a un valor constante
	unsigned int m_uiFlush;//uiFlush: Indica la cantidad de v�rtices cada cuanto se realizar� un DrawPrimitive de los ya v�rtices almacenados.
	unsigned int m_uiBase; //Indica el �ndice en el cual se deja el vertex buffer
	unsigned int m_uiVtxToLock;//Indica la cantidad de v�rtices a trabar en Draw
	D3DPRIMITIVETYPE m_PrimitiveType; //Indica la primitiva pasada como par�metro a Draw
	IDirect3DVertexBuffer9* m_pVertexBuffer; //El V�rtex Buffer creado queda encapsulado dentro de la clase
	IDirect3DDevice9* m_pDev; //Almaceno temporalmente el dispositivo pasado como par�metro en Draw.


//--------------------------------------------------------------------------------
public:
	
	VertexBuffer();	
	~VertexBuffer();
	//Crea el vertex buffer, al cual se le pasar� como par�metro el dispositivo de DirectX
	//que se inicializ� en la clase Renderer. Un segundo par�metro, opcional, �ndicar� si el mismo es o no din�mico.
	bool Create(IDirect3DDevice9 * pDev, bool bDynamic);
	//Libera al vertex buffer. Usualmente este m�todo se invocar� en el apagado del juego.
	void Release();
	//Este m�todo le indicar� cual es el vb activo a DirectX.
	void Bind(void);
	//Ser� el m�todo utilizado cada vez que se desee transferir v�rtices al vb. Se le pasa como par�metro el array de v�rtices, 
	//la primitiva a dibujar y la cantidad de v�rtices en el array.
	void Draw(PixelFormatClass * pVtxCollection, D3DPRIMITIVETYPE primitiveType, unsigned int uiVtxCount);
	//Este m�todo invocar� a DrawPrimitive (m�todo de DirectX que procesa los v�rtices insertos en el vb).
	//Ser� invocado al menos una vez en el dibujado de cada objeto (y m�s si la cantidad de v�rtices del objeto es mayor a m_uiFlush).
	void Flush();
};
//--------------------------------------------------------------------------------
#include "VertexBuffer.inl"
#endif //VERTEXBUFFER_H