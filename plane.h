#pragma once
#ifndef _PLANE_H_
#define _PLANE_H_

#define MAX_PLANE (8)

void InitPlane(void);
void UninitPlane(void);
void UpdatePlane(void);
void DrawPlane(void);

void CreatePlane(float x, float y);
bool IsPlane(int index);
void DestoryPlane(int index);
const D3DXVECTOR2 GetPlanePos(int index);

int GetMaxPlane(void);
void SetMaxPlane(int i);
#endif