#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
{
	HWND 	 hwnd;
	MSG 	 msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = "Window Class Name";
	RegisterClass(&WndClass);
	hwnd = CreateWindow("Window Class Name",
		"Window Title Name",
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
	HDC			hdc;
	PAINTSTRUCT ps;
	static int  x, y;
	static RECT rectView;

	switch (iMsg)
	{
	case WM_CREATE:
		GetClientRect(hwnd, &rectView);
		x = 20; y = 20;
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
		EndPaint(hwnd, &ps);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_RIGHT)
		{
			SetTimer(hwnd, 1, 100, NULL);
		}else if (wParam == VK_LEFT)
		{
			SetTimer(hwnd, 2, 100, NULL);
		} else if (wParam == VK_UP)
		{
			SetTimer(hwnd, 3, 100, NULL);
		}else if (wParam == VK_DOWN)
		{
			SetTimer(hwnd, 4, 100, NULL);
		}
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case 1:KillTimer(hwnd, 2);  x += 40;
			if (x + 20 > rectView.right) { x -= 40; KillTimer(hwnd, 1); }
			InvalidateRgn(hwnd, NULL, TRUE);
			break;

		case 2:KillTimer(hwnd, 1);  x -= 40;
			if (x - 20 < rectView.left) { x += 40; KillTimer(hwnd, 2); }
			InvalidateRgn(hwnd, NULL, TRUE);
			break;

		case 3:KillTimer(hwnd, 4);  y -= 40;
			if (y - 20 < rectView.top) { y += 40; KillTimer(hwnd, 3); }
			InvalidateRgn(hwnd, NULL, TRUE);
			break;

		case 4:KillTimer(hwnd, 3);  y += 40;
			if (y + 20 > rectView.bottom) { y -= 40; KillTimer(hwnd, 4); }
			InvalidateRgn(hwnd, NULL, TRUE);
			break;
		}
		break;
	case WM_DESTROY:
		KillTimer(hwnd, 1);
		KillTimer(hwnd, 2);
		KillTimer(hwnd, 3);
		KillTimer(hwnd, 4);
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}