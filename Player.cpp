
#include "main.h"
#include "Polygon.h"
#include "input.h"
#include "player.h"
#include "bullet.h"
#include "debug.h"
#include "effect.h"


static D3DXVECTOR2 g_vPos(0.0f, 0.0f);
static D3DXVECTOR2 g_vPosmid(0.0f, 0.0f);

static bool g_bPlayer = false;
static float alice_x = 300;
static float alice_y = 300;
static float tran = 0;
static double pi = 3.14159;
static int p_filed = 3;
static bool filedconter=false;
static int skillanime=0;
static int bulletconter = 0;


void InitPlayer(void)
{
	g_bPlayer = true;
	g_vPos.x = FELD_X+ PLAYER_WIDTH/3;
	g_vPos.y = FELD_Y+ (WINDOW_HEIGHT - PLAYER_HEIGHT/3)*0.5;
	tran = 0;
	p_filed = 3;
	skillanime = 0;
	filedconter = false;
	//g_vPos.x = (WINDOW_WIDTH - PLAYER_WIDTH)*0.5;
	//g_vPos.y = WINDOW_HEIGHT - PLAYER_HEIGHT*2.0;
}
void UninitPlayer(void)
{

}
void UpdatePlayer(void)
{
	g_vPos.x = PLAYER_SPEED*cosf(tran*pi / 180) + g_vPos.x;
	g_vPos.y = PLAYER_SPEED*sinf(tran*pi / 180) + g_vPos.y;
	g_vPosmid.x = g_vPos.x + PLAYER_WIDTH / 6;
	g_vPosmid.y = g_vPos.y + PLAYER_HEIGHT / 9;
	if (g_bPlayer)
	{
		if (GetKeyboardPress(DIK_A))
		{
			if (tran <= 0)
			{
				tran = 360;
			}
			if (tran >0)
			{
				tran -= 3;
			}
		}
		if (GetKeyboardPress(DIK_D))
		{
			if (tran >=360)
			{
				tran = 0;
			}
			if (tran < 360)
			{
				tran += 3;
			}
		}
		//if (GetKeyboardPress(DIK_SPACE))
		//{
		//	if (p_filed>0)
		//	{
		//		filedconter = true;
		//		p_filed--;
		//	}
		//}
	}
}
void DrawPlayer(void)
{
	if (g_bPlayer)
	{
		//aDebugText(10, 10, "プレイヤー座標 x=%.2f,y=%.2f", g_vPos.x, g_vPos.y);
		SetTexture(TEX_CAR_1);
		SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
		SetPolygonRotation(PLAYER_WIDTH / 6, PLAYER_HEIGHT /9, tran*pi / 180);
		DrawPolygon(g_vPos.x, g_vPos.y, PLAYER_WIDTH/3, PLAYER_HEIGHT/3, 0, 0, PLAYER_WIDTH, PLAYER_HEIGHT,true);
		DebugPolygon(16, g_vPosmid.x-20*cosf(tran*pi / 180)+5* sinf(tran*pi / 180), g_vPosmid.y-20*sinf(tran*pi / 180)-5 * cosf(tran*pi / 180), 12);
	}
	//if (filedconter)
	//{
	//	SetTexture(TEX_FILED);
	//	SetPolygonColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	//	SetPolygonRotation(PLAYER_WIDTH / 6, PLAYER_HEIGHT / 9, tran*pi / 180);
	//	DrawPolygon(g_vPosmid.x - 20 * cosf(tran*pi / 180) + 5 * sinf(tran*pi / 180)-50, g_vPosmid.y - 20 * sinf(tran*pi / 180) - 5 * cosf(tran*pi / 180)-50
	//		, 100, 100, 0, 0, 200, 200, true);
	//}
}

void CreatePlayer(void)
{
	g_bPlayer = true;
	g_vPos = D3DXVECTOR2(FELD_X + PLAYER_WIDTH/3, FELD_Y + (WINDOW_HEIGHT - PLAYER_HEIGHT/3)*0.5);
}

bool IsPlayer(void)
{
	return g_bPlayer;
}

void DestoryPlayer(void)
{
	g_bPlayer = false;
}

const D3DXVECTOR2* GetPlayerPos(void)
{
	return &g_vPos;
}

const D3DXVECTOR2* GetPlayerPosmid(void)
{
	return &g_vPosmid;
}

int GetPlayerRotation(void)
{
	return tran;
}

int GetPlayerFiled(void)
{
	return p_filed;
}

