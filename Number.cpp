#include "Number.h"
#include "main.h"
#include "Polygon.h"

#define TEXNUMBER_WIDTH (29)
#define TEXNUMBER_HEIGTH (32)

void DrawNumber(int n, float x, float y)
{
	if (n < 0 || n>9)
	{
		return;
	}

	switch (n)
	{
	case 1:SetTexture(TEX_1);	SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255)); DrawPolygon(x, y, NUMBER_WIDTH*2, NUMBER_HEIGHT*2, 0, 0, TEXNUMBER_WIDTH, TEXNUMBER_HEIGTH); break;
	case 2:SetTexture(TEX_2);	SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255)); DrawPolygon(x, y, NUMBER_WIDTH * 2, NUMBER_HEIGHT * 2, 0, 0, TEXNUMBER_WIDTH, TEXNUMBER_HEIGTH); break;
	case 3:SetTexture(TEX_3);	SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255)); DrawPolygon(x, y, NUMBER_WIDTH * 2, NUMBER_HEIGHT * 2, 0, 0, TEXNUMBER_WIDTH, TEXNUMBER_HEIGTH); break;
	case 4:SetTexture(TEX_4);	SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255)); DrawPolygon(x, y, NUMBER_WIDTH * 2, NUMBER_HEIGHT * 2, 0, 0, TEXNUMBER_WIDTH, TEXNUMBER_HEIGTH); break;
	case 5:SetTexture(TEX_5);	SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255)); DrawPolygon(x, y, NUMBER_WIDTH * 2, NUMBER_HEIGHT * 2, 0, 0, TEXNUMBER_WIDTH, TEXNUMBER_HEIGTH); break;
	case 6:SetTexture(TEX_6);	SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255)); DrawPolygon(x, y, NUMBER_WIDTH * 2, NUMBER_HEIGHT * 2, 0, 0, TEXNUMBER_WIDTH, TEXNUMBER_HEIGTH); break;
	case 7:SetTexture(TEX_7);	SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255)); DrawPolygon(x, y, NUMBER_WIDTH * 2, NUMBER_HEIGHT * 2, 0, 0, TEXNUMBER_WIDTH, TEXNUMBER_HEIGTH); break;
	case 8:SetTexture(TEX_8);	SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255)); DrawPolygon(x, y, NUMBER_WIDTH * 2, NUMBER_HEIGHT * 2, 0, 0, TEXNUMBER_WIDTH, TEXNUMBER_HEIGTH); break;
	case 9:SetTexture(TEX_9);	SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255)); DrawPolygon(x, y, NUMBER_WIDTH * 2, NUMBER_HEIGHT * 2, 0, 0, TEXNUMBER_WIDTH, TEXNUMBER_HEIGTH); break;
	case 0:SetTexture(TEX_0);	SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255)); DrawPolygon(x, y, NUMBER_WIDTH * 2, NUMBER_HEIGHT * 2, 0, 0, TEXNUMBER_WIDTH, TEXNUMBER_HEIGTH); break;
	default:
		break;
	}
}
