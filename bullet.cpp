#include "main.h"
#include "Polygon.h"
#include "player.h"
#include "bullet.h"

#define BULLET_SPEED (5.0f)



typedef struct {
	D3DXVECTOR2 vPos;
	bool bBullet;
}BULLET;

static BULLET g_Bullet[MAX_BULLET];

void InitBullet(void)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		//g_Bullet[i].vPos = D3DXVECTOR2(0.0f, 0.0f);
		g_Bullet[i].bBullet = false;
	}

}
void UninitBullet(void) 
{

}
void UpdateBullet(void)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (g_Bullet[i].bBullet)
		{
			g_Bullet[i].vPos.x += BULLET_SPEED;
			if (g_Bullet[i].vPos.x + BULLET_WIDTH > WINDOW_WIDTH)
			{
				g_Bullet[i].bBullet = false;
			}
		}
	}
}
void DrawBullet(void)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (g_Bullet[i].bBullet)
		{
			SetTexture(TEX_2);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			//SetPolygonRotation(192.5f, 108.0f, g_ftestangle);
			DrawPolygon(g_Bullet[i].vPos.x, g_Bullet[i].vPos.y, 40.f, 40.f, 0, 0, 320, 320);
		}
	}
}

void CreateBullet(float x, float y)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (!g_Bullet[i].bBullet)
		{
			g_Bullet[i].bBullet = true;
			g_Bullet[i].vPos = D3DXVECTOR2(x, y);
			break;
		}
	}
}

bool IsBullet(int index)
{
	return g_Bullet[index].bBullet;
}
void DestoryBullet(int index)
{
	g_Bullet[index].bBullet = false;
}

const D3DXVECTOR2 GetBulletPos(int index)
{
	return g_Bullet[index].vPos;
}