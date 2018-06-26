#include "main.h"
#include "Polygon.h"
#include "input.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "debug.h"
#include <time.h>


#define ENEMY_SPEED (5.0f)

typedef struct {
	D3DXVECTOR2 vPos;
	bool bEnemy;
	bool lrconter;
	int lrnumconter;
	long long Animeconter;
}ENEMY;



static ENEMY g_Enemy[MAX_ENEMY];

void InitEnemy(void)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		g_Enemy[i].vPos= D3DXVECTOR2(WINDOW_WIDTH - ENEMY_WEITH, WINDOW_HEIGHT - ENEMY_HEIGHT);
		g_Enemy[i].bEnemy = false;
		g_Enemy[i].lrconter = true;
		g_Enemy[i].lrnumconter = 0;
		g_Enemy[i].Animeconter = 0;
	}
}
void UninitEnemy(void)
{
	
}
void UpdateEnemy(void)
{
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (g_Enemy[i].bEnemy)
		{
			g_Enemy[i].vPos.x -= rand()%3+2;
			if (g_Enemy[i].vPos.x <= 0)
			{
				DestoryEnemy(i);
			}
			if (g_Enemy[i].lrconter)
			{
				g_Enemy[i].vPos.y += rand()%15;
				g_Enemy[i].lrnumconter++;
				if (g_Enemy[i].lrnumconter==30)
				{
					g_Enemy[i].lrconter = false;
					g_Enemy[i].lrnumconter = 0;
				}
			}
			else
			{
				g_Enemy[i].vPos.y -= rand()%15;
				g_Enemy[i].lrnumconter++;
				if (g_Enemy[i].lrnumconter == 30)
				{
					g_Enemy[i].lrconter = true;
					g_Enemy[i].lrnumconter = 0;
				}
			}
			if (g_Enemy[i].vPos.y < 0)
			{
				g_Enemy[i].vPos.y = 0;
			}
			if (g_Enemy[i].vPos.y + ENEMY_HEIGHT > WINDOW_HEIGHT)
			{
				g_Enemy[i].vPos.y = WINDOW_HEIGHT - ENEMY_HEIGHT;
			}
		}
		g_Enemy[i].Animeconter++;
		if (!g_Enemy[i].bEnemy)
		{
			if ((g_Enemy[i].Animeconter % (12*(i+1))) == 0)
			{
				CreateEnemy(WINDOW_WIDTH - ENEMY_WEITH, rand() % (WINDOW_HEIGHT - ENEMY_HEIGHT )-i*10);
			}
		}
	}
}
void DrawEnemy(void)
{
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (g_Enemy[i].bEnemy)
		{
			SetTexture(TEX_1);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon(g_Enemy[i].vPos.x, g_Enemy[i].vPos.y, 160.f, 160.f, 0, 0, 320, 320);
			DebugPolygon(16, GetEnemyPos(i).x + 80, GetEnemyPos(i).y + 80, 50);
		}
	}
}


void CreateEnemy(float x, float y)
{
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (!g_Enemy[i].bEnemy)
		{
			g_Enemy[i].bEnemy = true;
			g_Enemy[i].vPos = D3DXVECTOR2(x, y);
		}
	}
}
bool IsEnemy(int index)
{
	return g_Enemy[index].bEnemy;
}
void DestoryEnemy(int index)
{
	g_Enemy[index].bEnemy = false;
}
const D3DXVECTOR2 GetEnemyPos(int index)
{
	return g_Enemy[index].vPos;
}

