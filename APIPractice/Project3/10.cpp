#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
{
	HWND     hwnd;
	MSG	 msg;
	WNDCLASS WndClass; //������ Ŭ���� Ÿ�� ����
	WndClass.style = CS_HREDRAW | CS_VREDRAW; //�������� ũ�⸦ �����ϸ� �ٽñ׸��� ������ �������� �ǹ�
	WndClass.lpfnWndProc = WndProc; // �޼��� ó���� ���� �Լ�
	WndClass.cbClsExtra = 0; // �޸�
	WndClass.cbWndExtra = 0; // �޸�
	WndClass.hInstance = hInstance; // �޸�
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // ������
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); // Ŀ��
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);// ������
	WndClass.lpszMenuName = NULL; // �޴�
	WndClass.lpszClassName = "Window Class Name";// Ŭ���� �̸�
	RegisterClass(&WndClass);// Ŀ�ο� ���

	hwnd = CreateWindow("Window Class Name", // ������ ����
		"Window Title Name", // Ŭ���� �̸�
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
	PAINTSTRUCT ps;
	HPEN hpen, oldpen;

	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:   //Printf
		hdc = BeginPaint(hwnd, &ps);
		hpen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
		oldpen = (HPEN)SelectObject(hdc, hpen);
		Ellipse(hdc, 20, 20, 150, 150); //��
		SelectObject(hdc, oldpen);
		DeleteObject(hpen);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}