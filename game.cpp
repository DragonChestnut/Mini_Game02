#include "main.h"
#include "game.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "judgement.h"
#include "Explosion.h"
#include "Number.h"
#include "score.h"
#include "Polygon.h"
#include "input.h"
#include "plane.h"
#include "tittle.h"
#include "result.h"
#include "effect.h"


static int Gametime = 3600;
static int wallhit = 0;
static int gamestart = 5;
static int gamestartconter = 60;
static double pi = 3.14159;
static int titleconter = 0;
static int animateconter = 0;
static int fumikaAconter = 0;
static int result = 0;
static int pauseconter = 0;
static int effectconter = 0;
static int airconter = 1;

void InitGame(void)
{
	gamestart = 5;
	titleconter = 0;
	animateconter = 0;
	gamestartconter = 60;
	fumikaAconter = 0;
	Gametime = 3600;
	wallhit = 0;
	result = 0;
	pauseconter = 0;
	effectconter = 0;
	airconter = 1;
	InitPlayer();
	InitEffect();
	//InitBullet();
	//InitEnemy();
	InitExplosion();
	InitPlane();
	InitTittle();
	InitResult();
}
void UninitGame(void)
{
	UninitPolygon();
	UninitPlayer();
	UninitEffect();
	//UninitEnemy();
	//UninitBullet();
	UninitPlane();
	UninitExplosion();
	UninitTittle();
	

}
void UpdateGame(void)
{
	if (Gametime>3000)
	{
		SetMaxPlane(3);
	}
	else if(Gametime>2400)
	{
		SetMaxPlane(4);
	}
	else if (Gametime>1800)
	{
		SetMaxPlane(5);
	}
	else if (Gametime>1200)
	{
		SetMaxPlane(6);
	}
	else if (Gametime>600)
	{
		SetMaxPlane(7);
	}
	else
	{
		SetMaxPlane(8);
	}
	{

	}
	if (UpdateTittle())
	{
		titleconter = 1;
	}
	if (titleconter == 1)
	{
		if (gamestartconter <= 0)
		{
			gamestart--;
			gamestartconter = 60;
		}
		if (gamestart == 1)
		{
			if (pauseconter == 0)
			{
				if (GetKeyboardPress(DIK_P))
				{
					pauseconter = 1;
				}
				if (Gametime > 0)
				{
					Gametime--;
				}
				if (effectconter >= 10)
				{
					CreateEffect(GetPlayerPos()->x, GetPlayerPos()->y, 60);
					effectconter = 0;
				}
				else
				{
					effectconter++;
				}
				UpdatePlayer();
				UpdateEffect();
				//UpdateBullet();
				//UpdateEnemy();
				UpdatePlane();
				UpdateExplosion();
				if (IsPlayer)
				{
					if ((FELD_WIDTH + FELD_X - GetPlayerPosmid()->x) <= -16)
					{
						wallhit = 1;
					}
					if ((FELD_HEIGHT + FELD_Y - GetPlayerPosmid()->y) <= -16)
					{
						wallhit = 1;
					}
					if (GetPlayerPosmid()->x - FELD_X <= -16)
					{
						wallhit = 1;
					}
					if (GetPlayerPosmid()->y - FELD_Y <= -16)
					{
						wallhit = 1;
					}
					if (wallhit == 1)
					{
						//DestoryPlayer();
						//CreatePlayer();
						wallhit = 0;
						gamestart = 0;
						SetResult(2);
					}
				}
				for (int i = 0; i < MAX_PLANE; i++)
				{
					if (IsPlane(i))
					{
						if (Gametime < 3400)
						{
							if (Gametime % 300 == 15)
							{
								CreateExplosion(GetPlanePos(i).x, GetPlanePos(i).y, i);
								DestoryPlane(i);
							}
						}
					}
				}
				if (Gametime < 3400)
				{
					if (Gametime % 300 == 15)
					{
						for (int i = 0; i < MAX_PLANE; i++)
						{
							if (HitCircle(GetPlanePos(i).x + 100, GetPlanePos(i).y + 100, 100, GetPlayerPosmid()->x - 20 * cosf(GetPlayerRotation()*pi / 180) + 5 * sinf(GetPlayerRotation()*pi / 180), GetPlayerPosmid()->y - 20 * sinf(GetPlayerRotation()*pi / 180) - 5 * cosf(GetPlayerRotation()*pi / 180), 12))
							{
								//DestoryPlayer();
								//CreatePlayer();
								gamestart = 0;
								SetResult(2);
								break;
							}
						}
					}
				}
			}
			if (pauseconter == 1)
			{
				if (GetKeyboardPress(DIK_RETURN))
				{
					pauseconter = 0;
				}
				if (GetKeyboardPress(DIK_DOWN))
				{
					pauseconter = 2;
				}
			}
			if (pauseconter == 2)
			{
				if (GetKeyboardPress(DIK_RETURN))
				{
					InitGame();
				}
				if (GetKeyboardPress(DIK_UP))
				{
					pauseconter = 1;
				}
			}
		}
		UpdatePolygon();
		if (Gametime<=0)
		{
			gamestart = 0;
			SetResult(1);
		}
		UpdateResult();
	}
	//UpdatePolygon();
}
void DrawGame(void)
{
	if (titleconter==0)
	{
		DrawTittle();
	}
	if (titleconter == 1)
	{
		SetTexture(TEX_BG);
		SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
		DrawPolygon(0.f, 0.f, 1066.f, 800.f, 0, 0, 1066, 800);
		if (gamestart == 5)
		{
			SetTexture(TEX_03);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon((WINDOW_WIDTH - 200) / 2, (WINDOW_HEIGHT - 200) / 2, 200, 200, 0, 0, 200, 200);
			DrawScore(Gametime / 60, 2, true, (WINDOW_WIDTH - 4 * NUMBER_WIDTH) * 0.5, 20);
			gamestartconter--;
		}
		if (gamestart == 4)
		{
			SetTexture(TEX_02);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon((WINDOW_WIDTH - 200) / 2, (WINDOW_HEIGHT - 200) / 2, 200, 200, 0, 0, 200, 200);
			DrawScore(Gametime / 60, 2, true, (WINDOW_WIDTH - 4 * NUMBER_WIDTH) * 0.5, 20);
			gamestartconter--;
		}
		if (gamestart == 3)
		{
			SetTexture(TEX_01);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon((WINDOW_WIDTH - 200) / 2, (WINDOW_HEIGHT - 200) / 2, 200, 200, 0, 0, 200, 200);
			DrawScore(Gametime / 60, 2, true, (WINDOW_WIDTH - 4 * NUMBER_WIDTH) * 0.5, 20);
			gamestartconter--;
		}
		if (gamestart == 2)
		{
			SetTexture(TEX_G);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 128));
			DrawPolygon((WINDOW_WIDTH - 400) / 2, (WINDOW_HEIGHT - 200) / 2, 200, 200, 0, 0, 100, 100);
			SetTexture(TEX_O);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 128));
			DrawPolygon(WINDOW_WIDTH / 2, (WINDOW_HEIGHT - 200) / 2, 200, 200, 0, 0, 100, 100);
			DrawScore(Gametime / 60, 2, true, (WINDOW_WIDTH - 4 * NUMBER_WIDTH) * 0.5, 20);
			gamestartconter--;
		}
		if (gamestart == 1)
		{
			DrawScore(Gametime / 60 + 1, 2, true, (WINDOW_WIDTH - 4 * NUMBER_WIDTH) * 0.5, 20);
		}
		if (Gametime < 3600 && Gametime>1)
		{
			if (Gametime % 300 == 60)
			{
				airconter = 90;
			}
			if (airconter>1)
			{
				airconter--;
				SetTexture(TEX_PLANE);
				SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
				DrawPolygon(-512 + (WINDOW_WIDTH + 512)*(89 - airconter % 300) / (airconter % 300), FELD_Y, 512, 512, 0, 0, 512, 512);
			}
		}
		switch (fumikaAconter)
		{
		case 0:SetTexture(TEX_B1);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon(900, 0, 100, 100, 0, 0, 100, 100); animateconter++; break;
		case 1:SetTexture(TEX_B2);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon(900, 0, 100, 100, 0, 0, 100, 100); animateconter++; break;
		case 2:SetTexture(TEX_B3);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon(900, 0, 100, 100, 0, 0, 100, 100); animateconter++; break;
		case 3:SetTexture(TEX_B4);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon(900, 0, 100, 100, 0, 0, 100, 100); animateconter++; break;
		case 4:SetTexture(TEX_B5);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon(900, 0, 100, 100, 0, 0, 100, 100); animateconter++; break;
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
		DrawPlane();
		DrawEffect();
		DrawPlayer();
		//	DrawBullet();
		//	DrawEnemy();
		DrawExplosion();
		DrawResult();
		if (pauseconter==1)
		{
			SetTexture(TEX_PAUSE_01);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon(0.f, 0.f, 1066.f, 800.f, 0, 0, 1066, 800);
		}
		if (pauseconter == 2)
		{
			SetTexture(TEX_PAUSE_02);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon(0.f, 0.f, 1066.f, 800.f, 0, 0, 1066, 800);
		}
	}
}

//int bgamestart(void)
//{
//	return Gametime;
//}