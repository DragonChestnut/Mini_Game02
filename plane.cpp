#include "main.h"
#include "game.h"
#include "Polygon.h"
#include "plane.h"
#include "input.h"
#include <time.h>

#define MAX_SIZE (200)

typedef struct {
	D3DXVECTOR2 vPos;
	bool bPlane;
}PLANE;

static int max_plane=8;

static PLANE g_Plane[MAX_PLANE];

void InitPlane(void)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAX_PLANE; i++)
	{
		g_Plane[i].vPos = D3DXVECTOR2(0, 0);
		g_Plane[i].bPlane = false;
	}
}
void UninitPlane(void)
{

}
void UpdatePlane(void)
{
	for (int i = 0; i < max_plane; i++)
	{
		if (!g_Plane[i].bPlane)
		{
			CreatePlane((rand()%(780/max_plane))+ 85+ i*(780 / max_plane), (rand() % 400)+139);
		}
	}
}
void DrawPlane(void)
{
	for (int i = 0; i < max_plane; i++)
	{
		if (g_Plane[i].bPlane)
		{
			SetTexture(TEX_HANYI);
			SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			DrawPolygon(g_Plane[i].vPos.x, g_Plane[i].vPos.y, MAX_SIZE, MAX_SIZE, 0, 0, 100, 100);
		}
	}
}


void CreatePlane(float x, float y)
{
	for (int i = 0; i < max_plane; i++)
	{
		if (!g_Plane[i].bPlane)
		{
			g_Plane[i].bPlane = true;
			g_Plane[i].vPos = D3DXVECTOR2(x, y);
			break;
		}
	}
}

bool IsPlane(int index)
{
	return g_Plane[index].bPlane;
}

void DestoryPlane(int index)
{
	g_Plane[index].bPlane = false;
}
const D3DXVECTOR2 GetPlanePos(int index)
{
	return g_Plane[index].vPos;
}

int GetMaxPlane(void)
{
	return max_plane;
}

void SetMaxPlane(int i)
{
	max_plane = i;
}