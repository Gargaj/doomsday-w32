
#include <assert.h>

#define ASSERT(x) assert(x)

#ifdef WIN32

#include <stdio.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"d3d9.lib")
#ifdef _DEBUG
    #pragma comment(lib, "d3dx9d.lib")
#else
    #pragma comment(lib, "d3dx9.lib")
#endif

#endif


#ifdef _XBOX
#include <xtl.h>
#include <xgraphics.h>
#include <tchar.h> 
#include <cstdio>
#include <cassert>
#include "XBUtil.h"
#endif

#include "zlib/zlib.h"

void demo_init();
void demo_deinit();
void demo_render(float t);

void mosaic_init();
void mosaic_deinit();
void mosaic_render(float t);
void zoomer_init();
void zoomer_deinit();
void zoomer_render(float t);
void slides_init();
void slides_deinit();
void slides_render(float t);
void ifs_init();
void ifs_deinit();
void ifs_render(float t);
void meta_init();
void meta_render(float t);

extern float angles[256];


extern LPDIRECT3DDEVICE9       g_pd3dDevice;

extern HRESULT CreateSecondaryRenderTarget( unsigned int dwWidth, unsigned int dwHeight);
extern HRESULT DestroySecondaryRenderTarget();

extern void SetSecondaryRenderTarget();
extern void RenderSecondary(LPDIRECT3DSURFACE9 m_pBackBuffer, LPDIRECT3DSURFACE9 m_pDepthBuffer, int blend=0);

#define WRAP(x) {\
	HRESULT hresult=x; \
	ASSERT(SUCCEEDED(hresult)); \
}

extern	LPDIRECT3DSURFACE9 main_back;
extern	LPDIRECT3DSURFACE9 main_depth;

inline DWORD FtoDW( FLOAT f ) { return *((DWORD*)&f); }

#define CLAMP(x) (max(min(1,x),0))

extern void zoomer_none();
extern void zoomer_set(int layer, float speed, float rotate, float hue, float pos=0.0, float posrot=0.0);
struct ANIMSET
{
	int flags;
	int frameCount;
	LPDIRECT3DTEXTURE9 *frames;
	double rott;
	double zoomt;
	double speed;
	double rotate;
	double hue;
	double huet;
	double scale;
	int colorop;
};

extern ANIMSET animSet[32];
extern float motionblur;
extern float radialblur;
extern float fade;
