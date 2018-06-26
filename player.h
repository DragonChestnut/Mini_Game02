#pragma once


#ifndef _PLAYER_H_
#define _PLAYER_H_

#define PLAYER_WIDTH (152)
#define PLAYER_HEIGHT (96)
#define PLAYER_SPEED (5)

void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

bool IsPlayer(void);
void CreatePlayer(void);
void DestoryPlayer(void);
const D3DXVECTOR2* GetPlayerPos(void);
const D3DXVECTOR2* GetPlayerPosmid(void);
int GetPlayerRotation(void);
int GetPlayerFiled(void);


#endif // !_PLAYER_H_