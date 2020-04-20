// WindowsProject1.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "WindowsProject1.h"

#define MAX_LOADSTRING 100

struct Ball
{
	float x, y;
	float xS, yS;
};

Ball g_Ball;
// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 여기에 코드를 입력합니다.

	// 전역 문자열을 초기화합니다.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 응용 프로그램 초기화를 수행합니다:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

	MSG msg;

	// 기본 메시지 루프입니다:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(100, 100, 100));
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static RECT rt;
	switch (message)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 100 / 6, NULL);
		g_Ball.x = 20; g_Ball.y = 20;
		g_Ball.yS = 3;
		break;
	case WM_TIMER:
		g_Ball.y += g_Ball.yS;
		g_Ball.yS += 0.5f;
		GetClientRect(hWnd, &rt);


		{
			if (g_Ball.x > rt.right - 20)
				g_Ball.x = rt.right - 20;
			if (g_Ball.y > rt.bottom - 20)
				g_Ball.y = rt.bottom - 20;
			if (g_Ball.x < rt.left + 20)
				g_Ball.x = rt.left + 20;
			if (g_Ball.y < rt.top + 20)
				g_Ball.y = rt.top + 20;
		}
		InvalidateRgn(hWnd, NULL, TRUE);
		break;
	case WM_KEYDOWN:
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
			g_Ball.yS = -15;
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			g_Ball.x -= 20;
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			g_Ball.x += 20;
		//이동처리

		//범위처리
		{
			if (g_Ball.x > rt.right - 20)
				g_Ball.x = rt.right - 20;
			if (g_Ball.y > rt.bottom - 20)
				g_Ball.y = rt.bottom - 20;
			if (g_Ball.x < rt.left + 20)
				g_Ball.x = rt.left + 20;
			if (g_Ball.y < rt.top + 20)
				g_Ball.y = rt.top + 20;
		}
		//범위처리

		InvalidateRgn(hWnd, NULL, TRUE);
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		Ellipse(hdc, g_Ball.x - 20, g_Ball.y - 20, g_Ball.x + 20, g_Ball.y + 20);
		//
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}