#include "Explosion.h"
#include "main.h"
#include "Polygon.h"
#include "input.h"
#include "player.h"
#include "bullet.h"
#include "plane.h"


typedef struct {
	D3DXVECTOR2 vPos;
	bool bExplosion;
	int bExplosionA;
}EXPLOSION;

static EXPLOSION g_Explosion[MAX_PLANE];
static int max_plane = 6;

void InitExplosion(void)
{
	for (int i = 0; i < MAX_PLANE; i++)
	{
		g_Explosion[i].vPos = D3DXVECTOR2(0, 0);
		g_Explosion[i].bExplosion = false;
		g_Explosion[i].bExplosionA = 0;
	}
}

void UninitExplosion(void)
{

}

void UpdateExplosion(void)
{

}

void DrawExplosion()
{
	max_plane = GetMaxPlane();
	for (int i = 0; i < max_plane; i++)
	{
		if (g_Explosion[i].bExplosion)
		{
			SetTexture(TEX_GROUNDEXP);
			if (g_Explosion[i].bExplosionA <= 15)
			{
				SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
				DrawPolygon(g_Explosion[i].vPos.x, g_Explosion[i].vPos.y, 200, 200, 0, 0, 476, 485);
				g_Explosion[i].bExplosionA += 1;
			}
			else
			{
				g_Explosion[i].bExplosion = false;
				g_Explosion[i].bExplosionA = 0;
			}
		}
	}
}

void CreateExplosion(float x, float y,int i)
{
	if (!g_Explosion[i].bExplosion)
	{
		g_Explosion[i].bExplosion = true;
		g_Explosion[i].vPos.x = x;
		g_Explosion[i].vPos.y = y;
	}
}