#include "main.h"
#include "Polygon.h"
#include "input.h"
#include "debug.h"
#include "game.h"


#define CLASS_NAME      "Sample"
#define WINDOW_NAME     "Sample App"


// プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
void Uninit(void);
void Update(void);
void Draw(void);

// グローバル変数
static HWND hWnd=NULL;


DWORD TimeNow;
DWORD TimeOld;
static int nCount;
static int CountFrame;

static float r = 255;
static float g = 255.0;
static float b = 255.0;
static float a2 = 0;
static float a3 = 0;
static float alice_x = 300;
static float alice_y = 300;
static float doichux = 600;
static float doichuy = 10;
static float g_ftestangle = 0.0f;
static float g_fScale = 1.0f;




static LPDIRECT3D9        g_pD3D = NULL;
static LPDIRECT3DDEVICE9  g_pD3DDevice = NULL;

float x, y;
#ifdef _DEBUG
//LPD3DXFONT	  
#endif

// ウィンドウプロシージャ、ウィンドウに対するメッセージ処理を行う
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		// ウィンドウが破棄されたとき
	case WM_DESTROY:
		PostQuitMessage(0);	// WM_QUITメッセージをメッセージキューに送る
		return 0;
	}
	// デフォルトのメッセージ処理を行う
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrewInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),
		CS_VREDRAW | CS_HREDRAW,
		WndProc,
		0,
		0,
		hInstance,
		NULL,
		LoadCursor(NULL,IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		CLASS_NAME,
		NULL
	};

	RegisterClassEx(&wcex);

	hWnd = CreateWindowEx
	(
		0,
		CLASS_NAME,
		WINDOW_NAME,
		WS_MAXIMIZEBOX ^ WS_SIZEBOX ^ (WS_OVERLAPPEDWINDOW),
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
	);


	if (!Init(hInstance, hWnd, TRUE))
	{
		return -1;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;


	TimeNow = TimeOld = timeGetTime();

	// 分解能の設定
	timeBeginPeriod(1);

	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else
			{
				// メッセージ処理
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			// ゲーム処理
			TimeNow = timeGetTime();

			if ((TimeNow - TimeOld) * 60 >= (1000))
			{
				// 更新
				Update();
				// 描画
				Draw();

				TimeOld = TimeNow;
			}
		}
	}

	Uninit();

	timeEndPeriod(1);

	return (int)msg.wParam;
}

HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// Direct3Dオブジェクトの取得
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_pD3D == NULL)
	{
		return E_FAIL;
	}

	// 現在のディスプレイモードを取得
	D3DDISPLAYMODE d3ddm;

	if (FAILED(g_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
	{
		return E_FAIL;
	}

	// デバイスのプレゼンテーションパラメータ
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.BackBufferWidth = WINDOW_WIDTH;
	d3dpp.BackBufferHeight = WINDOW_HEIGHT;
	d3dpp.BackBufferFormat = d3ddm.Format;
	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.Windowed = bWindow;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;

	// DirectXデバイスの作成
	if (FAILED(g_pD3D->CreateDevice
	(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp,
		&g_pD3DDevice
	)))
	{
		// 上記の設定が失敗したら
		MessageBox(hWnd, "DirectXの初期化が失敗しました", "エラー", MB_OK);
		return false;
	}
	x = 0;
	y = 0;

	// レンダーステートの設定					 SRC_RGB * SRC_a + DEST_RGB * (1 - SRC_a)
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);	  // 今から描くもの、ポリゴンテクスチャ
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);  // すでに描画した

																		  // テクスチャステージステートの設定
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	// サンプラーステートの設定
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);

	// フィルタリング
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);


	InitKeyboard(hInstance, hWnd);

	if (!InitPolygon())
	{
		MessageBox(hWnd, "テクスチャが読み込めなかった", "エラー", MB_OK);
		return false;
	}

	nCount = 0;
	CountFrame = 0;

	InitDebugText();

	InitGame();
	return true;
}

void Uninit(void)
{

	UninitDebugText();

	UninitGame();

	UninitKeyboard();
	if (g_pD3DDevice != NULL)
	{
		// デバイスの開放
		g_pD3DDevice->Release();
		g_pD3DDevice = NULL;
	}

	if (g_pD3D != NULL)
	{
		// Direct3Dオブジェクトの開放
		g_pD3D->Release();
		g_pD3D = NULL;
	}

}

void Update(void)
{	
	//if (GetKeyboardPress(DIK_Q))
	//{
	//	g_ftestangle += -0.03;
	//}
	//if (GetKeyboardPress(DIK_E))
	//{
	//	g_ftestangle += 0.03;
	//}
	////POINT mousePos;
	////GetCursorPos(&mousePos);
	////ScreenToClient(hWnd, &mousePos);
	////if (GetAsyncKeyState(VK_LBUTTON))
	////{
	////	doichux = mousePos.x - 80;
	////	doichuy = mousePos.y - 80;
	////}
	UpdateKeyboard();
	UpdateGame();
}

void Draw(void)
{
	g_pD3DDevice->Clear
	(
		0,
		NULL,
		(D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0,0, 0, 255),
		1.0f,										   // Zバッファのクリア値
		0
	);

	// Direct3Dによる描画の開始
	if (SUCCEEDED(g_pD3DDevice->BeginScene()))
	{
		DrawGame();

		// Direct3Dによる描画の終了
		g_pD3DDevice->EndScene();
	}

	g_pD3DDevice->Present
	(
		NULL, NULL, NULL, NULL
	);
}

LPDIRECT3DDEVICE9 GetD3DDevice(void)
{
	// Direct3Dデバイスの取得
	return g_pD3DDevice;
}