//--------------------------------------------------------------------------------------------------
//
// É|ÉäÉSÉìÇÃï`âÊ
//																				    2017.06.05 RYU
//--------------------------------------------------------------------------------------------------

#ifndef POLYGON_H
#define POLYGON_H

// ç\ë¢ëÃíËã`
typedef struct {
	D3DXVECTOR4 pos;
	D3DCOLOR color;
	D3DXVECTOR2 texcoord;
}VERTEX_2D;

typedef struct {
	char filename[256];
	int width;
	int height;
}TEXTURE;

typedef enum TEXTURE_NUM
{
	TEX_BG,
	TEX_CAR_1,
	TEX_CAR_2,
	TEX_GROUNDEXP,
	TEX_CAREXP,
	TEX_PLANE,
	TEX_HANYI,
	TEX_0,
	TEX_1,
	TEX_2,
	TEX_3,
	TEX_4,
	TEX_5,
	TEX_6,
	TEX_7,
	TEX_8,
	TEX_9,
	TEX_01,
	TEX_02,
	TEX_03,
	TEX_G,
	TEX_O,
	TEX_TITLE,
	TEX_STORY,
	TEX_WIN,
	TEX_LOSE,
	TEX_A1,
	TEX_A2,
	TEX_A3,
	TEX_A4,
	TEX_A5,
	TEX_B1,
	TEX_B2,
	TEX_B3,
	TEX_B4,
	TEX_B5,
	TEX_C1,
	TEX_C2,
	TEX_C3,
	TEX_C4,
	TEX_C5,
	TEX_PAUSE_01,
	TEX_PAUSE_02,
	TEX_FILED,
	TEX_SKILL,
	TEX_MAX
};

const TEXTURE TextureMessage[TEX_MAX] =
{
	{ "Texture/map.png", 1066, 800 },
	{ "Texture/car1.png", 152, 96 },
	{ "Texture/car2.png", 142, 92 },
	{ "Texture/groundexp.png", 476, 485 },
	{ "Texture/carexp.png", 583, 536 },
	{ "Texture/plane.png", 512, 512 },
	{ "Texture/hanyi.png", 100, 100 },
	{ "Texture/0.png", 29, 32 },
	{ "Texture/1.png", 29, 32 },
	{ "Texture/2.png", 29, 32 },
	{ "Texture/3.png", 29, 32 },
	{ "Texture/4.png", 29, 32 },
	{ "Texture/5.png", 29, 32 },
	{ "Texture/6.png", 29, 32 },
	{ "Texture/7.png", 29, 32 },
	{ "Texture/8.png", 29, 32 },
	{ "Texture/9.png", 29, 32 },
	{ "Texture/01.png", 200, 200 },
	{ "Texture/02.png", 200, 200 },
	{ "Texture/03.png", 200, 200 },
	{ "Texture/g.png", 100, 100 },
	{ "Texture/o.png", 100, 100 },
	{ "Texture/title.png", 1066, 800 },
	{ "Texture/story.png", 1066, 800 },
	{ "Texture/win.png", 1066, 800 },
	{ "Texture/lose.png", 1066, 800 },
	{ "Texture/A1.png", 100, 100 },
	{ "Texture/A2.png", 100, 100 },
	{ "Texture/A3.png", 100, 100 },
	{ "Texture/A4.png", 100, 100 },
	{ "Texture/A5.png", 100, 100 },
	{ "Texture/B1.png", 100, 100 },
	{ "Texture/B2.png", 100, 100 },
	{ "Texture/B3.png", 100, 100 },
	{ "Texture/B4.png", 100, 100 },
	{ "Texture/B5.png", 100, 100 },
	{ "Texture/C1.png", 100, 100 },
	{ "Texture/C2.png", 100, 100 },
	{ "Texture/C3.png", 100, 100 },
	{ "Texture/C4.png", 100, 100 },
	{ "Texture/C5.png", 100, 100 },
	{ "Texture/pause_01.png", 1066, 800 },
	{ "Texture/pause_02.png", 1066, 800 },
	{ "Texture/filed.png", 650, 500 },
	{ "Texture/skill.png", 200, 200 },
};


bool InitPolygon();
void UninitPolygon();
void UpdatePolygon();


void SetPolygonColor(D3DCOLOR nColor);
void SetTexture(int nNumTex);
void SetPolygonRotation(float cx, float cy, float angle);
void SetPolygonScale(float cx, float cy, float sx, float sy);
void DrawPolygon(float dx, float dy, float dw, float dh, int tcx, int tcy, int tcw, int tch,bool bAffine = false);

#endif
