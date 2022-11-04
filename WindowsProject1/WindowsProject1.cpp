#include <windows.h>
#include <tchar.h>
LRESULT CALLBACK WindowP(HWND, UINT, WPARAM, LPARAM);

TCHAR zlassWindow[] = TEXT("Окно"); // имя окна 

INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG Msg;
	WNDCLASSEX wcl;

 

	wcl.cbSize = sizeof(wcl);	 
	wcl.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	 
	wcl.lpfnWndProc = WindowP;	 
	wcl.cbClsExtra = 0;		 
	wcl.cbWndExtra = 0; 	 
	wcl.hInstance = hInst;	 
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	 
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);		 
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	 		
	wcl.lpszMenuName = NULL;	 
	wcl.lpszClassName = zlassWindow;	 
	wcl.hIconSm = NULL;	 
 
	if (!RegisterClassEx(&wcl))
 
	 
	hWnd = CreateWindowEx(
		0,		 
		zlassWindow,	 
		TEXT("Окно"),	 
	// стиль окна
		WS_OVERLAPPEDWINDOW,	 
		CW_USEDEFAULT,	 
		CW_USEDEFAULT,	 
		CW_USEDEFAULT,	 
		CW_USEDEFAULT,	 
		NULL,			 
		NULL,			 
		hInst,		 
		NULL);		 
			 
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);	 
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);	 
		DispatchMessage(&Msg);	 
	}
	 
}
 LRESULT CALLBACK WindowP(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, uMessage, wParam, lParam);
}
