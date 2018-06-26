//=======================================================================================
//						
//						
//=======================================================================================

#ifndef _EFFECT_H_
#define _EFFECT_H_
#include <d3dx9.h>
#define MAX_EFFECT (1024)

typedef struct {
	D3DXVECTOR2 vPos;
	D3DCOLOR color;
	int nLimit;
	int nBirth;
	bool bEffect;
	int rotation;
}EFFECT;


void InitEffect(void);
void UninitEffect(void);
void UpdateEffect(void);
void DrawEffect(void);
void CreateEffect( float x, float y,int nLimit);

#endif //_EFFECT_H_

