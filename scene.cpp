#include "scene.h"
#include "tittle.h"
#include "game.h"
#include "result.h"

//void(*pFunc)() = InitTittle;
//void(*pFunc)(int) = 
//void(*pFunc)(int,int) = 
//int(*pFunc)(int,int) = 


typedef void(*SceneFunc)(void);
static const SceneFunc g_pInit[]=
{
	InitTittle,
	InitGame,
	InitResult,
};
static const SceneFunc g_pUninit[] =
{
	UninitTittle,
	UninitGame,
	UninitResult,
};
static const SceneFunc g_pUpdate[] =
{
	UpdateTittle,
	UpdateGame,
	UpdateResult,
};
static const SceneFunc g_pDraw[] =
{
	DrawTittle,
	DrawGame,
	DrawResult,
};


#define START_SCENE (SCENE_TITTLE)

static SCENE_ID g_nID= START_SCENE;
static SCENE_ID g_nNextID= START_SCENE;

void InitScene(void)
{
	g_pInit[g_nID]();
	/*switch (g_nID)
	{
	case 	SCENE_TITTLE:
		InitTittle();
		break;
	case	SCENE_GAME:
		InitGame();
		break;
	case	SCENE_RESULT:
		InitResult();
		break;
	default:
		break;
	}*/
}
void UninitScene(void)
{
	g_pUninit[g_nID]();
	//switch (g_nID)
	//{
	//case 	SCENE_TITTLE:
	//	UninitTittle();
	//	break;
	//case	SCENE_GAME:
	//	UninitGame();
	//	break;
	//case	SCENE_RESULT:
	//	UninitResult();
	//	break;
	//default:
	//	break;
	//}
}
void UpdateScene(void)
{
	g_pUpdate[g_nID]();
	/*switch (g_nID)
	{
	case 	SCENE_TITTLE:
		UpdateTittle();
		break;
	case	SCENE_GAME:
		UpdateGame();
		break;
	case	SCENE_RESULT:
		UpdateResult();
		break;
	default:
		break;
	}*/
}
void DrawScene(void)
{
	g_pDraw[g_nID]();
	//switch (g_nID)
	//{
	//case 	SCENE_TITTLE:
	//	DrawTittle();
	//	break;
	//case	SCENE_GAME:
	//	DrawGame();
	//	break;
	//case	SCENE_RESULT:
	//	DrawResult();
	//	break;
	//default:
	//	break;
	//}
	if (g_nNextID != g_nID)
	{
		UninitScene();
		g_nID = g_nNextID;
		InitScene();
	}
}

SCENE_ID ChangeScene(SCENE_ID id)
{
	g_nNextID = id;
	return g_nID;
}