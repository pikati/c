//------------------------------//
//	kadai04 ���C�[�_�̎���		//
//	�s�J�^��					//
//------------------------------//

//�}�C�i�X�̒l����͂����Ƃ��Ƀ}�C�i�X�ł�����Č��������������ǖʓ|�����Ȃ̂Œf�O

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pikatanlib.h"

//���O�̒���
#define NAME_LEN 22

//����
#define NO 0
#define FIRE 1
#define WATER 2
#define WIND 3
#define SOIL 4
#define LIGHT 5
#define DARK 6

//����
#define MALE 0
#define FEMALE 1

bool check_num(char *num);//�������������Ă���false���l�݂̂Ȃ�true
void disp_status();
const char *get_elem(int elem);
void select_charactor();
void select_status(int num);
void set_name(char *name);
void set_sex(int *sex);
void set_hp(int *hp);
void set_mp(int *mp);
void set_atk(int *atk);
void set_def(int *def);
void set_matk(int *matk);
void set_mdef(int *mdef);
void set_spd(int *spd);
void set_elem(int *elem);

typedef struct {
	char name[NAME_LEN + 1];//���O
	int hp;//HP
	int mp;//MP
	int atk;//�U����
	int def;//�h���
	int matk;//���@�U����
	int mdef;//���@�h���
	int spd;//�f����
	int exp;//�o���l
	int lev;//���x��
	int elem;//����
	int sex;//����
}chara;

chara charactor[4]{
	{
		"1�l��", 10, 0, 5, 3, 2, 2, 3, 0, 1, 0, 0
	},
	{
		"2�l��", 10, 0, 5, 3, 2, 2, 3, 0, 1, 0, 0
	},
	{
		"3�l��", 10, 0, 5, 3, 2, 2, 3, 0, 1, 0, 0
	},
	{
		"4�l��", 10, 0, 5, 3, 2, 2, 3, 0, 1, 0, 0
	}
};
chara *p = charactor;

int main() {
	disable_cursor();
	printf("\n\n\t4�l�p�[�e�B������4�l�̃X�e�[�^�X���Z�b�g���Ăق����ȁI");
	wait_key();
	select_charactor();
}

void select_charactor() {

	enum {
		first, second, third, fourth, disp, end
	};

	int cmax = 5;//�I�����̐��}�C�i�X1
	int cursor = 0;//�J�[�\���̈ʒu
	int c = 0;//����

	while (true) {
		clear();

		printf("\n\n\t����̃X�e�[�^�X��ύX����H\n\n");
		
		if (cursor == first) {
			hit_cursor();
			printf("\t%s\n\n", p->name);
			exit_cursor();
		}
		else {
			printf("\t%s\n\n", p->name);
		}
		if (cursor == second) {
			hit_cursor();
			printf("\t%s\n\n", (p + 1)->name);
			exit_cursor();
		}
		else {
			printf("\t%s\n\n", (p + 1)->name);
		}
		if (cursor == third) {
			hit_cursor();
			printf("\t%s\n\n", (p + 2)->name);
			exit_cursor();
		}
		else {
			printf("\t%s\n\n", (p + 2)->name);
		}
		if (cursor == fourth) {
			hit_cursor();
			printf("\t%s\n\n", (p + 3)->name);
			exit_cursor();
		}
		else {
			printf("\t%s\n\n", (p + 3)->name);
		}
		if (cursor == disp) {
			hit_cursor();
			printf("\t�X�e�[�^�X�\��\n\n");
			exit_cursor();
		}
		else {
			printf("\t�X�e�[�^�X�\��\n\n");
		}
		if (cursor == end) {
			hit_cursor();
			printf("\t�I���\n\n");
			exit_cursor();
		}
		else {
			printf("\t�I���\n\n");
		}

		c = get_key();
		cursor = get_cursor(c, cursor, cmax);

		if (c == ENTER) {
			if (cursor == disp) {
				disp_status();
			}
			else if (cursor == end) {
				exit(EXIT_SUCCESS);
			}
			else {
				select_status(cursor);
			}
		}
	}
}

void select_status(int n) {

	enum {
		name, sex, hp, mp, atk, def, matk, mdef, spd, elem, re
	};

	int cmax = 10;
	int cursor = 0;//�J�[�\���̈ʒu
	int c = 0;//����

	while (true) {
		clear();

		printf("\n\n\t�ǂ̃X�e�[�^�X��ύX����H\n\n");

		if (cursor == name) {
			hit_cursor();
			printf("\t���O\t");
			exit_cursor();
		}
		else {
			printf("\t���O\t");
		}
		if (cursor == atk) {
			hit_cursor();
			printf("\t�U���́@�@\t");
			exit_cursor();
		}
		else {
			printf("\t�U���́@�@\t");
		}
		if (cursor == spd) {
			hit_cursor();
			printf("\t�f����\n\n");
			exit_cursor();
		}
		else {
			printf("\t�f����\n\n");
		}
		if (cursor == sex) {
			hit_cursor();
			printf("\t����\t");
			exit_cursor();
		}
		else {
			printf("\t����\t");
		}
		if (cursor == def) {
			hit_cursor();
			printf("\t�h��́@�@\t");
			exit_cursor();
		}
		else {
			printf("\t�h��́@�@\t");
		}
		if (cursor == elem) {
			hit_cursor();
			printf("\t����\n\n");
			exit_cursor();
		}
		else {
			printf("\t����\n\n");
		}
		if (cursor == hp) {
			hit_cursor();
			printf("\tHP�@\t");
			exit_cursor();
		}
		else {
			printf("\tHP�@\t");
		}
		if (cursor == matk) {
			hit_cursor();
			printf("\t���@�U����\t");
			exit_cursor();
		}
		else {
			printf("\t���@�U����\t");
		}
		if (cursor == re) {
			hit_cursor();
			printf("\t�߂�\n\n");
			exit_cursor();
		}
		else {
			printf("\t�߂�\n\n");
		}
		if (cursor == mp) {
			hit_cursor();
			printf("\tMP�@\t");
			exit_cursor();
		}
		else {
			printf("\tMP�@\t");
		}
		if (cursor == mdef) {
			hit_cursor();
			printf("\t���@�h���\n\n");
			exit_cursor();
		}
		else {
			printf("\t���@�h���\n\n");
		}

		c = get_key();
		cursor = get_cursor(c, cursor, cmax);

		switch (c) {
		case ENTER:
			if (cursor == name) {
				set_name((p + n)->name);
			}
			else if (cursor == sex) {
				set_sex(&(p + n)->sex);
			}
			else if (cursor == hp) {
				set_hp(&(p + n)->hp);
			}
			else if (cursor == mp) {
				set_mp(&(p + n)->mp);
			}
			else if (cursor == atk) {
				set_atk(&(p + n)->atk);
			}
			else if (cursor == def) {
				set_def(&(p + n)->def);
			}
			else if (cursor == matk) {
				set_matk(&(p + n)->matk);
			}
			else if (cursor == mdef) {
				set_mdef(&(p + n)->mdef);
			}
			else if (cursor == spd) {
				set_spd(&(p + n)->spd);
			}
			else if (cursor == elem) {
				set_elem(&(p + n)->elem);
			}
			else if (cursor == re) {
				return;
			}
		}
	}
}

void disp_status() {
	int i;
	int j;

	clear();
	printf("\n\n");
	for (i = 0; i < 13; i++) {
		for (j = 0; j < 4; j++) {
			if (i == 0) {
				printf("%d�l�ڂ̖��O�@�@�@�F%-10s", j + 1, (p + j)->name);
			}
			if (i == 1) {
				if ((p + j)->sex == 0) {
					printf("%d�l�ڂ̐��ʁ@�@�@�F�j�@�@�@�@", j + 1);
				}
				else {
					printf("%d�l�ڂ̐��ʁ@�@�@�F���@�@�@�@", j + 1);
				}
			}
			if (i == 2) {
				printf("%d�l�ڂ�HP�@�@�@�@�F%-10d", j + 1, (p + j)->hp);
			}
			if (i == 3) {
				printf("%d�l�ڂ�MP�@�@�@�@�F%-10d", j + 1, (p + j)->mp);
			}
			if (i == 4) {
				printf("%d�l�ڂ̍U���́@�@�F%-10d", j + 1, (p + j)->atk);
			}
			if (i == 5) {
				printf("%d�l�ڂ̖h��́@�@�F%-10d", j + 1, (p + j)->def);
			}
			if (i == 6) {
				printf("%d�l�ڂ̖��@�U���́F%-10d", j + 1, (p + j)->matk);
			}
			if (i == 7) {
				printf("%d�l�ڂ̖��@�h��́F%-10d", j + 1, (p + j)->mdef);
			}
			if (i == 8) {
				printf("%d�l�ڂ̑f�����@�@�F%-10d", j + 1, (p + j)->spd);
			}
			if (i == 9) {
				printf("%d�l�ڂ̑����@�@�@�F%-10s", j + 1, get_elem((p + j)->elem));
			}
		}
		printf("\n\n");
	}
	wait_key();
}

void set_name(char *name) {
	clear();

	printf("\n\n\t���O����͂��Ă��������i�S�p10�����ȉ��j\n\n\t");
	printf("���O�F");
	enable_cursor();
	scanf_s("%s", name, 22);
	disable_cursor();
}

void set_sex(int *sex) {

	enum {
		male, female
	};

	int cmax = 1;
	int cursor = 0;//�J�[�\���̈ʒu
	int c = 0;//����

	while (true) {
		clear();

		printf("\n\n\t���ʂ�I�����Ă�������\n\n");

		if (cursor == male) {
			hit_cursor();
			printf("\t�j\n\n");
			exit_cursor();
		}
		else {
			printf("\t�j\n\n");
		}
		if (cursor == female) {
			hit_cursor();
			printf("\t��\n\n");
			exit_cursor();
		}
		else {
			printf("\t��\n\n");
		}

		c = get_key();
		cursor = get_cursor(c, cursor, cmax);

		if (c == ENTER) {
			if (cursor == male) {
				*sex = MALE;
				return;
			}
			else {
				*sex = FEMALE;
				return;
			}
		}
	}
}

void set_hp(int *hp) {

	bool flag = true;
	char num[11];

	do {
		clear();
		printf("\n\n\tHP����͂��Ă��������i1�ȏ�999�ȉ��j\n\n\t");
		printf("HP�F");
		enable_cursor();
		scanf_s("%s", num, 10);
		disable_cursor();
		if (!check_num(num) || atoi(num) == 0) {
			printf("1�ȏ�̐��l����͂��Ă�������");
			flag = false;
			wait_key();
		}
		else if (atoi(num) > 999) {
			printf("HP��999�𒴂��Ă��܂�");
			flag = false;
			wait_key();
		}
		else {
			flag = true;
			*hp = atoi(num);
		}

	} while (!flag);

}

void set_mp(int *mp) {

	bool flag = true;
	char num[11];

	do {
		clear();
		printf("\n\n\tMP����͂��Ă��������i0�ȏ�999�ȉ��j\n\n\t");
		printf("MP�F");
		enable_cursor();
		scanf_s("%s", num, 10);
		disable_cursor();
		if (!check_num(num)) {
			printf("0�ȏ�̐��l����͂��Ă�������");
			flag = false;
			wait_key();
		}
		else if (atoi(num) > 999) {
			printf("MP��999�𒴂��Ă��܂�");
			flag = false;
			wait_key();
		}
		else {
			flag = true;
			*mp = atoi(num);
		}
	} while (!flag);
}

void set_atk(int *atk) {

	bool flag = true;
	char num[11];

	do {
		clear();
		printf("\n\n\t�U���͂���͂��Ă��������i0�ȏ�999�ȉ��j\n\n\t");
		printf("�U���́F");
		enable_cursor();
		scanf_s("%s", num, 10);
		disable_cursor();
		if (!check_num(num)) {
			printf("0�ȏ�̐��l����͂��Ă�������");
			flag = false;
			wait_key();
		}
		else if (atoi(num) > 999) {
			printf("�U���͂�999�𒴂��Ă��܂�");
			flag = false;
			wait_key();
		}
		else {
			flag = true;
			*atk = atoi(num);
		}
	} while (!flag);
}

void set_def(int *def) {

	bool flag = true;
	char num[11];

	do {
		clear();
		printf("\n\n\t�h��͂���͂��Ă��������i0�ȏ�999�ȉ��j\n\n\t");
		printf("�h��́F");
		enable_cursor();
		scanf_s("%s", num, 10);
		disable_cursor();
		if (!check_num(num)) {
			printf("0�ȏ�̐��l����͂��Ă�������");
			flag = false;
			wait_key();
		}
		else if (atoi(num) > 999) {
			printf("�h��͂�999�𒴂��Ă��܂�");
			flag = false;
			wait_key();
		}
		else {
			flag = true;
			*def = atoi(num);
		}
	} while (!flag);
}

void set_matk(int *matk) {

	bool flag = true;
	char num[11];

	do {
		clear();
		printf("\n\n\t���@�U���͂���͂��Ă��������i0�ȏ�999�ȉ��j\n\n\t");
		printf("���@�U���́F");
		enable_cursor();
		scanf_s("%s", num, 10);
		disable_cursor();
		if (!check_num(num)) {
			printf("0�ȏ�̐��l����͂��Ă�������");
			flag = false;
			wait_key();
		}
		else if (atoi(num) > 999) {
			printf("���@�U���͂�999�𒴂��Ă��܂�");
			flag = false;
			wait_key();
		}
		else {
			flag = true;
			*matk = atoi(num);
		}
	} while (!flag);
}

void set_mdef(int *mdef) {

	bool flag = true;
	char num[11];

	do {
		clear();
		printf("\n\n\t���@�h��͂���͂��Ă��������i0�ȏ�999�ȉ��j\n\n\t");
		printf("���@�h��́F");
		enable_cursor();
		scanf_s("%s", num, 10);
		disable_cursor();
		if (!check_num(num)) {
			printf("0�ȏ�̐��l����͂��Ă�������");
			flag = false;
			wait_key();
		}
		else if (atoi(num) > 999) {
			printf("���@�h��͂�999�𒴂��Ă��܂�");
			flag = false;
			wait_key();
		}
		else {
			flag = true;
			*mdef = atoi(num);
		}
	} while (!flag);
}

void set_spd(int *spd) {

	bool flag = true;
	char num[11];

	do {
		clear();
		printf("\n\n\t�f��������͂��Ă��������i0�ȏ�999�ȉ��j\n\n\t");
		printf("�f�����F");
		enable_cursor();
		scanf_s("%s", num, 10);
		disable_cursor();
		if (!check_num(num)) {
			printf("0�ȏ�̐��l����͂��Ă�������");
			flag = false;
			wait_key();
		}
		else if (atoi(num) > 999) {
			printf("�f������999�𒴂��Ă��܂�");
			flag = false;
			wait_key();
		}
		else {
			flag = true;
			*spd = atoi(num);
		}
	} while (!flag);
}

void set_elem(int *elem) {

	int cmax = 6;
	int cursor = 0;//�J�[�\���̈ʒu
	int c = 0;//����

	while (true) {
		clear();

		printf("\n\n\t������I�����Ă�������\n\n");

		if (cursor == NO) {
			hit_cursor();
			printf("\t��\n\n");
			exit_cursor();
		}
		else {
			printf("\t��\n\n");
		}
		if (cursor == FIRE) {
			hit_cursor();
			printf("\t��\n\n");
			exit_cursor();
		}
		else {
			printf("\t��\n\n");
		}
		if (cursor == WATER) {
			hit_cursor();
			printf("\t��\n\n");
			exit_cursor();
		}
		else {
			printf("\t��\n\n");
		}
		if (cursor == WIND) {
			hit_cursor();
			printf("\t��\n\n");
			exit_cursor();
		}
		else {
			printf("\t��\n\n");
		}
		if (cursor == SOIL) {
			hit_cursor();
			printf("\t�y\n\n");
			exit_cursor();
		}
		else {
			printf("\t�y\n\n");
		}
		if (cursor == LIGHT) {
			hit_cursor();
			printf("\t��\n\n");
			exit_cursor();
		}
		else {
			printf("\t��\n\n");
		}
		if (cursor == DARK) {
			hit_cursor();
			printf("\t��\n\n");
			exit_cursor();
		}
		else {
			printf("\t��\n\n");
		}

		c = get_key();
		cursor = get_cursor(c, cursor, cmax);

		if (c == ENTER) {
			*elem = cursor;
			return;
		}
	}
}

const char *get_elem(int elem) {
	switch (elem) {
	case NO:
		return "��";
	case FIRE:
		return "��";
	case WATER:
		return "��";
	case WIND:
		return "��";
	case SOIL:
		return "�y";
	case RIGHT:
		return "��";
	case DARK:
		return "��";
	default:
		return "��";
	}
}

bool check_num(char *num) {
	int i;

	for (i = 0; i < strlen(num); i++) {
		if (!isdigit(num[i])) {
			return false;
		}
	}
	return true;
}