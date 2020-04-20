#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
{
	HWND     hwnd;
	MSG	 msg;
	WNDCLASS WndClass; //윈도우 클래스 타입 변수
	WndClass.style = CS_HREDRAW | CS_VREDRAW; //윈도우의 크기를 변경하면 다시그리는 형태의 윈도우라는 의미
	WndClass.lpfnWndProc = WndProc; // 메세지 처리를 위한 함수
	WndClass.cbClsExtra = 0; // 메모리
	WndClass.cbWndExtra = 0; // 메모리
	WndClass.hInstance = hInstance; // 메모리
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // 아이콘
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); // 커서
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);// 바탕색
	WndClass.lpszMenuName = NULL; // 메뉴
	WndClass.lpszClassName = "Window Class Name";// 클래스 이름
	RegisterClass(&WndClass);// 커널에 등록

	hwnd = CreateWindow("Window Class Name", // 윈도우 생성
		"Window Title Name", // 클래스 이름
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	static char str[100];

	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_CHAR:   
		hdc = GetDC(hwnd);
		str[0] = wParam;
		str[1] = '\0';
		TextOut(hdc, 0, 0, str, strlen(str));
		ReleaseDC(hwnd, hdc);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}