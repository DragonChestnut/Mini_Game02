#include "tittle.h"
#include "Polygon.h"
#include "input.h"
#include "player.h"

static int titleconter = 0;
static int fumikaAconter = 0;
static int animateconter = 0;
static int tittlealfconter = 0;

void InitTittle(void)
{
	titleconter = 0;
	fumikaAconter = 0;
	animateconter = 0;
	tittlealfconter = 0;
}
void UninitTittle(void)
{

}
bool UpdateTittle(void)
{
	if (titleconter==0)
	{
		if (GetKeyboardTrigger(DIK_RETURN))
		{
			titleconter = 1;
		}
	}
	else
	{
		if (GetKeyboardTrigger(DIK_RETURN))
		{
			titleconter = 0;
			return true;
		}
	}
	return false;
}
void DrawTittle(void)
{
	if (titleconter == 0)
	{
		SetTexture(TEX_TITLE);
		SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
		DrawPolygon(0, 0, 1066, 800, 0, 0, 1066, 800);
		switch (fumikaAconter)
		{
		case 0:SetTexture(TEX_B1);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon(200, 550, 200, 200, 0, 0, 100, 100); animateconter ++; break;
		case 1:SetTexture(TEX_B2);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon(200, 550, 200, 200, 0, 0, 100, 100); animateconter++; break;
		case 2:SetTexture(TEX_B3);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon(200, 550, 200, 200, 0, 0, 100, 100); animateconter++; break;
		case 3:SetTexture(TEX_B4);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon(200, 550, 200, 200, 0, 0, 100, 100); animateconter++; break;
		case 4:SetTexture(TEX_B5);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon(200, 550, 200, 200, 0, 0, 100, 100); animateconter++; break;
		default:
			break;
		}
		if (animateconter >= 10)
		{
			if (fumikaAconter>=4)
			{
				fumikaAconter = 0;
				animateconter = 0;
			}
			else
			{
				fumikaAconter++;
				animateconter = 0;
			}
		}
	}
	if (titleconter == 1)
	{
		if (tittlealfconter<255)
		{
			tittlealfconter ++;
		}
		SetTexture(TEX_STORY);
		SetPolygonColor(D3DCOLOR_ARGB(tittlealfconter, 255, 255, 255));
		DrawPolygon(0, 0, 1066, 800, 0, 0, 1066, 800);
	}
}