#include "pikatanlib.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>

void clear() {
	system("cls");
}

void disable_cursor() {
	HANDLE hOut;
	CONSOLE_CURSOR_INFO cci;

	// 出力用ハンドルの取得
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// CONSOLE_CURSOR_INFO構造体の現在の状態を取得する
	GetConsoleCursorInfo(hOut, &cci);

	// メンバ変数であるbVisibleがカーソルの表示・非表示を制御する変数なので、これをFALSEにする事でカーソルを非表示にできる
	cci.bVisible = FALSE;

	// 変更した構造体情報をコンソールWindowにセットする
	SetConsoleCursorInfo(hOut, &cci);
}

void enable_cursor() {
	HANDLE hOut;
	CONSOLE_CURSOR_INFO cci;

	// 出力用ハンドルの取得
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// CONSOLE_CURSOR_INFO構造体の現在の状態を取得する
	GetConsoleCursorInfo(hOut, &cci);

	// メンバ変数であるbVisibleがカーソルの表示・非表示を制御する変数なので、これをFALSEにする事でカーソルを非表示にできる
	cci.bVisible = TRUE;

	// 変更した構造体情報をコンソールWindowにセットする
	SetConsoleCursorInfo(hOut, &cci);
}

void out_cursor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
}

int get_cursor(int c, int cursor, int cmax, int row) {
	switch (c)
	{
	case UP:
		cursor--;
		if (cursor < 0) {
			cursor = 0;
		}
		break;
	case DOWN:
		cursor++;
		if (cursor > cmax) {
			cursor = cmax;
		}
		break;
	case LEFT:
		cursor -= row;
		if (cursor < 0) {
			cursor += row;
		}
		break;
	case RIGHT:
		cursor += row;
		if (cursor > cmax) {
			cursor -= row;
		}
		break;
	default:
		break;
	}
	return cursor;
}

int get_key() {
	int c;
	c = _getch();
	if (c == 0xe0) {
		return _getch();
	}
	else {
		return c;
	}
}

void in_cursor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
}

void wait_key() {
	rewind(stdin);
	getchar();
}