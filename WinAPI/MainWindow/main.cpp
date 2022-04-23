#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<cstdio>
#include"resource.h"

#define IDC_STATIC	1000	//Ресурс для static text

CONST CHAR g_szClassName[] = "MyWindowClass";	//Имя класса окна
CONST CHAR g_szWindowTitle[] = "My First Window";
//g_ - Global
//sz - string zero (NULL Terminated Line)
//https://ru.wikipedia.org/wiki/%D0%92%D0%B5%D0%BD%D0%B3%D0%B5%D1%80%D1%81%D0%BA%D0%B0%D1%8F_%D0%BD%D0%BE%D1%82%D0%B0%D1%86%D0%B8%D1%8F

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	//1) Регистрация класса окна:
	WNDCLASSEX wc;	//wc - Window Class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.style = 0;
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_STAR));	//Icon - отображается в панели задач
	wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_BOAT));//SmallIcon - отображается в строке заголовка
	//wc.hIcon = (HICON)LoadImage(hInstance, "skull.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	//wc.hIconSm = (HICON)LoadImage(hInstance, "halloween.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	wc.hCursor = LoadCursor(hInstance, (LPCSTR)IDC_CURSOR1);
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = (WNDPROC)WndProc;	//Имя функции - это указатель на функцию, 
	//оно содержит адрес, по которому функция загружена в память.
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_szClassName;

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Class registration failed! :-(", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}

	//2) Создание окна:

	int screen_width = GetSystemMetrics(SM_CXSCREEN);
	int screen_height = GetSystemMetrics(SM_CYSCREEN);
	int window_width = screen_width * .75;
	int window_height = screen_height * .75;
	int start_x = screen_width * .125;
	int start_y = screen_height * .125;

	HWND hwnd = CreateWindowEx
	(
		NULL,	//exStyle
		g_szClassName,
		g_szWindowTitle,
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX,// | WS_MAXIMIZEBOX,
		//WS_OVERLAPPEDWINDOW,	//Главное окно, у которого есть строка заголовка, 
		//кнопки управления окном, может изменяться по размерам....
		start_x, start_y,	//Положение окна на экране
		window_width, window_height,	//Размер окна
		NULL,	//Parent Window
		NULL,	//ID ресурса меню, если окно главное (OVERLAPPED),
				//или ID этого окна, если окно дочернее
		hInstance,
		NULL
	);
	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window creation failed!", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);	//Задает режим отображения окна
	UpdateWindow(hwnd);	//Рисует окно.

	//3) Запуск цикла сообщений:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
	{
		//CreateWindowExA - ANSI-кодировка
		//CreateWindowExW - Wide-кодировка (Unicode)
		HWND hStatic = CreateWindowEx
		(
			0,
			"Static",
			"Эта статическая строка будет отображать размер окна, и его положение на экране",
			WS_CHILD | WS_VISIBLE,
			10, 10,
			800,
			50,
			hwnd,
			(HMENU)IDC_STATIC,
			GetModuleHandle(NULL),	//GetModuleHandle(NULL) - Возвращает hInstance
			0
		);
	}
	break;
	case WM_COMMAND:break;
	case WM_SIZE:
	case WM_MOVE:
	{
		CONST INT SIZE = 256;
		CHAR sz_msg[SIZE] = {};

		RECT rect;	//прямоугольник окна
		GetWindowRect(hwnd, &rect);

		int window_width = rect.right - rect.left;
		int window_height = rect.bottom - rect.top;
		sprintf(sz_msg, "%s - Size: %ix%i, Position: %ix%i", g_szWindowTitle, window_width, window_height, rect.left, rect.top);
		//https://www.cplusplus.com/reference/cstdio/sprintf/
		//https://www.cplusplus.com/reference/cstdio/printf/
		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_msg);
		SendMessage(GetDlgItem(hwnd, IDC_STATIC), WM_SETTEXT, 0, (LPARAM)sz_msg);
	}
	break;
	case WM_CLOSE:
		if (MessageBox(hwnd, "Вы действительно хотите закрыть окно?", "Question", MB_YESNO | MB_ICONQUESTION) == IDYES)
			DestroyWindow(hwnd);
		break;
	case WM_DESTROY:	//уничтожить окно
		PostQuitMessage(NULL);
		break;
	default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return FALSE;
}