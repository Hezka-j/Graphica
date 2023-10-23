#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);

	system("title Real Graphic");
	system("mode con cols=100 lines=30");

	HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));//для рисовки фигур(стиль линии, толщина, цвет)
	HBRUSH brush = CreateSolidBrush(RGB(255, 200, 16));//заливка фигур

	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	
	int x = 50;
	int y = 50;
	int width = 600;//5 : 3
	int height = 400;

	Rectangle(hdc, x, y, x + width,y + height);

	DeleteObject(pen);
	DeleteObject(brush);

	pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));//(red, green, blue)
	brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);

	Rectangle(hdc, x, y,x + width,y + height / 3 * 2);

	DeleteObject(pen);
	DeleteObject(brush);

	pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	brush = CreateSolidBrush(RGB(0, 0, 0));

	SelectObject(hdc, pen);
	SelectObject(hdc, brush);

	Rectangle(hdc, x, y,x + width,y + height / 3);
	
	DeleteObject(pen);
	DeleteObject(brush);
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 100;
	SetConsoleCursorInfo(h, &cci);

	Sleep(INFINITE);
}