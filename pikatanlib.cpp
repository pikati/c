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

	// �o�͗p�n���h���̎擾
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// CONSOLE_CURSOR_INFO�\���̂̌��݂̏�Ԃ��擾����
	GetConsoleCursorInfo(hOut, &cci);

	// �����o�ϐ��ł���bVisible���J�[�\���̕\���E��\���𐧌䂷��ϐ��Ȃ̂ŁA�����FALSE�ɂ��鎖�ŃJ�[�\�����\���ɂł���
	cci.bVisible = FALSE;

	// �ύX�����\���̏����R���\�[��Window�ɃZ�b�g����
	SetConsoleCursorInfo(hOut, &cci);
}

void enable_cursor() {
	HANDLE hOut;
	CONSOLE_CURSOR_INFO cci;

	// �o�͗p�n���h���̎擾
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// CONSOLE_CURSOR_INFO�\���̂̌��݂̏�Ԃ��擾����
	GetConsoleCursorInfo(hOut, &cci);

	// �����o�ϐ��ł���bVisible���J�[�\���̕\���E��\���𐧌䂷��ϐ��Ȃ̂ŁA�����FALSE�ɂ��鎖�ŃJ�[�\�����\���ɂł���
	cci.bVisible = TRUE;

	// �ύX�����\���̏����R���\�[��Window�ɃZ�b�g����
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