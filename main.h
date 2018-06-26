#pragma once
//===================================
//
//ÉÅÉCÉìÉwÉbÉ_
//
//                    2017.06.05 Zhao
//===================================

#ifndef _MAIN_H_
#define _MAIN_H_

#include<d3d9.h>
#include <Windows.h>
#include <d3dx9.h>
#include <stdio.h>

#define WINDOW_WIDTH    (1066)
#define WINDOW_HEIGHT   (800)
#define FELD_WIDTH    (900)
#define FELD_HEIGHT    (520)
#define FELD_X    (85)
#define FELD_Y    (139)


LPDIRECT3DDEVICE9 GetD3DDevice(void);



#endif // _MAIN_H_