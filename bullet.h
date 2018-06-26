#pragma once

#ifndef _BULLET_H_
#define _BULLET_H_

#define BULLET_HEIGHT (40)
#define BULLET_WIDTH (40)
#define MAX_BULLET (256)

void InitBullet(void);
void UninitBullet(void);
void UpdateBullet(void);
void DrawBullet(void);

void CreateBullet(float x, float y);
bool IsBullet(int index);
void DestoryBullet(int index);
const D3DXVECTOR2 GetBulletPos(int index);
#endif