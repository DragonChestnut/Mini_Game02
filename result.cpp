#include "result.h"
#include "Polygon.h"
#include "input.h"
#include "player.h"
#include "game.h"

static int resultconter = 0;
static int fumikaAconter = 0;
static int animateconter = 0;
static int alfconter = 0;

void InitResult(void)
{
	resultconter = 0;
	fumikaAconter = 0;
	animateconter = 0;
	alfconter = 0;
}
void UninitResult(void)
{

}
void UpdateResult(void)
{
	if (resultconter!=0)
	{
		if (GetKeyboardTrigger(DIK_RETURN))
		{
			InitGame();
		}
	}

}
void DrawResult(void)
{
	if (resultconter == 1)
	{
		SetTexture(TEX_WIN);
		SetPolygonColor(D3DCOLOR_ARGB(alfconter, 255, 255, 255));
		DrawPolygon(0, 0, 1066, 800, 0, 0, 1066, 800);
		switch (fumikaAconter)
		{
		case 0:SetTexture(TEX_C1);
			SetPolygonColor(D3DCOLOR_ARGB(alfconter, 255, 255, 255));
			DrawPolygon(370, 230, 300, 300, 0, 0, 100, 100); animateconter++; break;
		case 1:SetTexture(TEX_C2);
			SetPolygonColor(D3DCOLOR_ARGB(alfconter, 255, 255, 255));
			DrawPolygon(370, 230, 300, 300, 0, 0, 100, 100); animateconter++; break;
		case 2:SetTexture(TEX_C3);
			SetPolygonColor(D3DCOLOR_ARGB(alfconter, 255, 255, 255));
			DrawPolygon(370, 230, 300, 300, 0, 0, 100, 100); animateconter++; break;
		case 3:SetTexture(TEX_C4);
			SetPolygonColor(D3DCOLOR_ARGB(alfconter, 255, 255, 255));
			DrawPolygon(370, 230, 300, 300, 0, 0, 100, 100); animateconter++; break;
		case 4:SetTexture(TEX_C5);
			SetPolygonColor(D3DCOLOR_ARGB(alfconter, 255, 255, 255));
			DrawPolygon(370, 230, 300, 300, 0, 0, 100, 100); animateconter++; break;
		default:
			break;
		}
		if (animateconter >= 10)
		{
			if (fumikaAconter >= 4)
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
		if (alfconter<255)
		{
			alfconter+=5;
		}
	}
	if (resultconter == 2)
	{
		SetTexture(TEX_LOSE);
		SetPolygonColor(D3DCOLOR_ARGB(alfconter, 255, 255, 255));
		DrawPolygon(0, 0, 1066, 800, 0, 0, 1066, 800);
		switch (fumikaAconter)
		{
		case 0:SetTexture(TEX_A1);
			SetPolygonColor(D3DCOLOR_ARGB(alfconter, 255, 255, 255));
			DrawPolygon(370, 230, 300, 300, 0, 0, 100, 100); animateconter++; break;
		case 1:SetTexture(TEX_A2);
			SetPolygonColor(D3DCOLOR_ARGB(alfconter, 255, 255, 255));
			DrawPolygon(370, 230, 300, 300, 0, 0, 100, 100); animateconter++; break;
		case 2:SetTexture(TEX_A3);
			SetPolygonColor(D3DCOLOR_ARGB(alfconter, 255, 255, 255));
			DrawPolygon(370, 230, 300, 300, 0, 0, 100, 100); animateconter++; break;
		case 3:SetTexture(TEX_A4);
			SetPolygonColor(D3DCOLOR_ARGB(alfconter, 255, 255, 255));
			DrawPolygon(370, 230, 300, 300, 0, 0, 100, 100); animateconter++; break;
		case 4:SetTexture(TEX_A5);
			SetPolygonColor(D3DCOLOR_ARGB(alfconter, 255, 255, 255));
			DrawPolygon(370, 230, 300, 300, 0, 0, 100, 100); animateconter++; break;
		default:
			break;
		}
		if (animateconter >= 10)
		{
			if (fumikaAconter >= 4)
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
		if (alfconter<255)
		{
			alfconter+=5;
		}
	}
}

void SetResult(int i)
{
	resultconter = i;
}