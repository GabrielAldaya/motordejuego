//Create
template <class PixelFormatClass, unsigned int FVF>
inline bool VertexBuffer<PixelFormatClass, FVF>::Create(IDirect3DDevice9 * pDev, bool bDynamic)
{
	// Creo el vertex buffer con los datos indicados
	HRESULT hr = pDev->CreateVertexBuffer(
						m_uiVbSize*sizeof(PixelFormatClass),
						(bDynamic ? D3DUSAGE_WRITEONLY | D3DUSAGE_DYNAMIC : 0),
						FVF,
						D3DPOOL_DEFAULT,
						&m_pVertexBuffer,
						NULL);
	// Indico que la base de vb a lockear es cero
	if (hr != D3D_OK)
		return false;

	return true;
}
//Bind
template <class PixelFormatClass, unsigned int FVF>
inline void VertexBuffer<PixelFormatClass, FVF>::Bind(void)
{
	HRESULT hr = m_pDev->SetVertexShader(NULL);
	hr = m_pDev->SetFVF(FVF);
	hr = m_pDev->SetStreamSource(0, m_pVertexBuffer, NULL, sizeof(PixelFormatClass));
}
//Draw
template <class PixelFormatClass, unsigned int FVF>
inline void VertexBuffer<PixelFormatClass, FVF>::Draw(PixelFormatClass * pVtxCollection, D3DPRIMITIVETYPE primitiveType, unsigned int uiVtxCount)
{
	m_kPrimitiveType = primitiveType;

	if (m_uiFlush < uiVtxCount)
		m_uiVtxToLock = m_uiFlush;
	else
		m_uiVtxToLock = uiVtxCount;

	if (m_uiBase + m_uiVtxToLock > m_uiVbSize)
		m_uiBase = 0;

	void* pvVertices = NULL;
	HRESULT hr = m_pVertexBuffer->Lock(m_uiBase * sizeof(PixelFormatClass), m_uiVtxToLock * sizeof(PixelFormatClass),(void **) &pvVertices,
								m_uiBase ? D3DLOCK_NOOVERWRITE : D3DLOCK_DISCARD);


	while(m_uiVtxToLock > 0)
	{
		memcpy(pvVertices, &pVtxCollection[uiVtxProcNow],sizeof(PixelFormatClass)*m_uiVtxToLock);
		uiVtxProcNow += m_uiVtxToLock;
		m_pVertexBuffer->Unlock();
		Flush();
		m_uiBase += m_uiVtxToLock;
		
		if (m_uiBase > m_uiVbSize - 1)
			m_uiBase = 0;

		if (m_uiFlush < (uiVtxCount-uiVtxProcNow))
			m_uiVtxToLock = m_uiFlush;
		else
			m_uiVtxToLock = uiVtxCount-uiVtxProcNow;

		if (m_uiBase + m_uiVtxToLock > m_uiVbSize)
			m_uiBase = 0;

		hr = m_pVertexBuffer->Lock(m_uiBase * sizeof(PixelFormatClass),	m_uiVtxToLock * sizeof(PixelFormatClass),(void **) &pvVertices,
									m_uiBase ? D3DLOCK_NOOVERWRITE : D3DLOCK_DISCARD);
	}

	hr = m_pVertexBuffer->Unlock();
}

//Flush
template <class PixelFormatClass, unsigned int FVF>
inline void VertexBuffer<PixelFormatClass, FVF>::Flush()
{
	int iPrimitiveCount;
	// Determino la cantidad de primitivas a realizar en función del tipo
	if (m_kPrimitiveType == D3DPT_POINTLIST)
		iPrimitiveCount = m_uiVtxToLock;
	else if (m_kPrimitiveType == D3DPT_LINELIST)
		iPrimitiveCount = m_uiVtxToLock/2;
	else if (m_kPrimitiveType == D3DPT_LINESTRIP)
		iPrimitiveCount = m_uiVtxToLock-1;
	else if (m_kPrimitiveType == D3DPT_TRIANGLELIST)
		iPrimitiveCount = m_uiVtxToLock/3;
	else if (m_kPrimitiveType == D3DPT_TRIANGLESTRIP)
		iPrimitiveCount = m_uiVtxToLock-2;
	else if (m_kPrimitiveType == D3DPT_TRIANGLEFAN)
		iPrimitiveCount = m_uiVtxToLock-2;
	else
		iPrimitiveCount = 0;
	
	HRESULT hr = m_pDev->DrawPrimitive(m_kPrimitiveType, m_uiBase, iPrimitiveCount);
}
//Constructor
template <class PixelFormatClass, unsigned int FVF>
inline VertexBuffer<PixelFormatClass, FVF>::VertexBuffer()
{
	m_uiVbSize=450;
	m_uiFlush=150;
	m_uiBase=0;
	m_uiVtxToLock=0;
	m_pVertexBuffer=NULL;
	m_pDev = pDev;
	m_pVertexBuffer=NULL;
	m_pDev=NULL;
}
//Destructor
template <class PixelFormatClass, unsigned int FVF>
inline VertexBuffer<PixelFormatClass, FVF>::~VertexBuffer(){
	free(m_pVertexBuffer);
	free(m_pDev)
}

//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
