// 오목게임만들기.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "오목게임만들기.h"
#include <math.h>
#define MAX_LOADSTRING 100
#define CELL_SIZE 30
#define SR (CELL_SIZE * 0.4)
#define SCREEN_SIZE (CELL_SIZE*20)
// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

struct OMOK {
	POINT StoneDraw[19][19];			//바둑알의 위치를 기억하는 2차원 배열
};
OMOK omok;
int StoneMemory[19][19] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};
// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY));

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

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_POPUP,
      CW_USEDEFAULT, 0, SCREEN_SIZE, SCREEN_SIZE, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//

//바둑판 그리기 함수
#define R CELL_SIZE * 0.1
VOID GridPaint(HDC hdc) {
	for (int i = 0; i < 19; i++) {
		MoveToEx(hdc, (i + 1)*CELL_SIZE, CELL_SIZE, NULL);
		LineTo(hdc, (i + 1)*CELL_SIZE, SCREEN_SIZE - CELL_SIZE);
		MoveToEx(hdc, CELL_SIZE, (i + 1)*CELL_SIZE, NULL);
		LineTo(hdc, SCREEN_SIZE - CELL_SIZE, (i + 1)*CELL_SIZE);
	}
	SelectObject(hdc, GetStockObject(BLACK_BRUSH));
	//화점
	Ellipse(hdc, SCREEN_SIZE * 0.5 - R, SCREEN_SIZE * 0.5 - R,
		SCREEN_SIZE * 0.5 + R, SCREEN_SIZE * 0.5 + R);
}
double LengthPts(int x1, int y1, int x2, int y2) {
	double result;
	result = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
	return sqrt(result);
}
BOOL InCircle(int x, int y, int mx, int my) {
	if (LengthPts(x, y, mx, my) < SR)return TRUE;
	return FALSE;
}
//돌을 가득 그린다.

VOID StonePaint(HDC hdc) {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			omok.StoneDraw[i][j].x = CELL_SIZE * (j + 1);
			omok.StoneDraw[i][j].y = CELL_SIZE * (i + 1);
			if (StoneMemory[i][j] == 1) {
				SelectObject(hdc, GetStockObject(BLACK_BRUSH));
				Ellipse(hdc, omok.StoneDraw[i][j].x - SR,
					omok.StoneDraw[i][j].y - SR,
					omok.StoneDraw[i][j].x + SR,
					omok.StoneDraw[i][j].y + SR);
			}
			if (StoneMemory[i][j] == 2) {
				SelectObject(hdc, GetStockObject(WHITE_BRUSH));
				Ellipse(hdc, omok.StoneDraw[i][j].x - SR,
					omok.StoneDraw[i][j].y - SR,
					omok.StoneDraw[i][j].x + SR,
					omok.StoneDraw[i][j].y + SR);
			}
		}
	}
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int mx, my;
	static int cnt=1;
	switch (message)
    {

	case WM_LBUTTONDOWN:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				omok.StoneDraw[i][j].x = CELL_SIZE * (j + 1);
				omok.StoneDraw[i][j].y = CELL_SIZE * (i + 1);
				if (InCircle(omok.StoneDraw[i][j].x,omok.StoneDraw[i][j].y,
					mx,	my)) {
					if(cnt%2 == 1)
						StoneMemory[i][j] = 1;
					else
						StoneMemory[i][j] = 2;
				}
			}
		}
		cnt++;
		InvalidateRgn(hWnd, NULL, TRUE);
		break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			GridPaint(hdc);
			StonePaint(hdc);
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
