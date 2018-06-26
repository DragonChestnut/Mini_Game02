#pragma once

#ifndef _ENEMY_H_
#define _ENEMY_H_

#define ENEMY_HEIGHT (160)
#define ENEMY_WEITH (160)
#define MAX_ENEMY (3)

void InitEnemy(void);
void UninitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);

void CreateEnemy(float x, float y);
bool IsEnemy(int index);
void DestoryEnemy(int index);
const D3DXVECTOR2 GetEnemyPos(int index);


#endif