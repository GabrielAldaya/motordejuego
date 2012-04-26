#include "Renderer.h"

Renderer::Renderer(){
}

Renderer::~Renderer(){}

bool Renderer::InitDX(HWND hWnd){
IDirect3D9 * _pD3D = NULL;

	// Intento crear el objeto DX9
	_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (!_pD3D)
		return false;

	//guardo la resolución actual del escritorio
	D3DDISPLAYMODE displayMode;
	HRESULT hr = _pD3D->GetAdapterDisplayMode (
					D3DADAPTER_DEFAULT,
			 		&displayMode
				);

	if (hr!=D3D_OK)
		return false;

	// Fijo los valores a la estructura D3DPRESENT_PARAMETERS
	D3DPRESENT_PARAMETERS d3dPresentParameters;
	ZeroMemory( &d3dPresentParameters, sizeof(d3dPresentParameters));
	d3dPresentParameters.BackBufferFormat = displayMode.Format;
	d3dPresentParameters.Windowed = true;
	d3dPresentParameters.BackBufferCount = 1; 
	d3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dPresentParameters.hDeviceWindow = 0; 
	d3dPresentParameters.Flags = 0;
	d3dPresentParameters.EnableAutoDepthStencil = TRUE;
	d3dPresentParameters.AutoDepthStencilFormat = D3DFMT_D24S8; 
	d3dPresentParameters.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dPresentParameters.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	//invocaremos al método CreateDevice
	hr = _pD3D->CreateDevice(
			D3DADAPTER_DEFAULT,
 			D3DDEVTYPE_HAL,
			hWnd,
			D3DCREATE_HARDWARE_VERTEXPROCESSING,
			&d3dPresentParameters,
			&m_pkDevice
		);

	if (hr!=D3D_OK)
		return false;

	return true;
}
void Renderer::StartFrame()
{
	// Limpio
	m_pkDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(80, 120, 150), 1.0f, 0);
	
	// Comienzo
	m_pkDevice->BeginScene();
}
void Renderer::EndFrame()
{
	// Termina 
	m_pkDevice->EndScene();
	m_pkDevice->Present(NULL, NULL, NULL, NULL);
	
}

void Renderer::Draw(ColorVertex * vertexColletion, 	PrimitiveType prim, unsigned int uiVertexCount)
{
	//m_vtxBufColor.Bind();
	//m_vtxBufColor.Draw(vertexColletion, m_primitiveVector[prim],uiVertexCount);
}