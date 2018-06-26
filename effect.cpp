#include "effect.h"
#include <d3dx9.h>
#include "main.h"
#include "polygon.h"
#include "player.h"

static EFFECT g_Effects[MAX_EFFECT];
static int g_nFrameCount = 0;
static double pi = 3.14159;

void InitEffect(void)
{
	for (int i = 0; i < MAX_EFFECT; i++)
	{
		g_Effects[i].bEffect = false;
	}
	g_nFrameCount = 0;
}
void UninitEffect(void)
{

}
void UpdateEffect(void)
{
	//�����̃`�F�b�N
	for (int i = 0; i < MAX_EFFECT; i++)
	{
		if (g_Effects[i].bEffect)
		{
			int nAge = g_nFrameCount - g_Effects[i].nBirth;
			if (nAge >= g_Effects[i].nLimit) {
				g_Effects[i].bEffect = false;
			}
		}
	}
	g_nFrameCount++;
}
void DrawEffect(void)
{
	//���Z�����̐ݒ�
	LPDIRECT3DDEVICE9 pDevice = GetD3DDevice();

	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_BLENDFACTOR);

	for (int i = 0; i < MAX_EFFECT; i++)
	{
		if (g_Effects[i].bEffect)
		{


			//�G�t�F�N�g�̊ۂ�`��

			//�N��ɂ���ă��l��ύX����
			//�O�΂͍ŏ��ɐݒ肳�ꂽ���l
			//�������}����N��l == �O
			float fAge_arufa = g_nFrameCount - g_Effects[i].nBirth;
			float fScale = 1.f - fAge_arufa / g_Effects[i].nLimit;
			//	float Scale = nAge_arufa/255;

			SetPolygonScale( fScale, fScale,1, 1);
			SetPolygonRotation(PLAYER_WIDTH / 6, PLAYER_HEIGHT / 9, g_Effects[i].rotation*pi / 180);

			SetTexture(TEX_CAR_1);
			SetPolygonColor(D3DXCOLOR(1, 1, 1, fScale));
			
			DrawPolygon(g_Effects[i].vPos.x, g_Effects[i].vPos.y, PLAYER_WIDTH / 3, PLAYER_HEIGHT / 3, 0, 0, PLAYER_WIDTH, PLAYER_HEIGHT, true);
			//SetPolygonScale(fScale, fScale, 1, 1);
		}
	}

	pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	//�ʏ�̔����������ɖ߂�
}
void CreateEffect(float x, float y, int nLimit)
{
	for (int i = 0; i < MAX_EFFECT; i++)
	{
		if (!g_Effects[i].bEffect)
		{

			g_Effects[i].bEffect = true;
			g_Effects[i].nBirth = g_nFrameCount;
			g_Effects[i].nLimit = nLimit;
			g_Effects[i].vPos = D3DXVECTOR2(x, y);
			g_Effects[i].rotation = GetPlayerRotation();
			break;
		}
	}
}