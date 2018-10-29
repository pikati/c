//----------------------------------//
//	kadai05 �o�g���R���V�A�� light	//
//	�s�J�^��						//
//----------------------------------//

//�퓬�Ɋւ��ẮA�O�̉ۑ�𗬗p���Ă���̂Ń^�[�Q�b�g�I�����\������邯�ǋC�ɂ��Ȃ��ł�������

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
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

//���������@���A�C�e�����h�䂩�i�퓬���̃R�}���h�j
#define STR 1
#define MAGIC 2
#define ITEM 3
#define GARD 4

/*�L�����N�^�[�̏�񂪒�`����Ă���\����*/
typedef struct {
	char name[NAME_LEN + 1];//���O
	int mhp;//�ő�HP
	int hp;//����HP
	int mmp;//�ő�MP
	int mp;//����MP
	int atk;//�U����
	int def;//�h���
	int matk;//���@�U����
	int mdef;//���@�h���
	int spd;//�f����
	int exp;//�o���l
	int lev;//���x��
	int elem;//����
	int sex;//����
	int skill[5];
	int id;
}chara;

/*�X�L���̏��̍\����*/
typedef struct {
	char name[21];//�X�L���̖��O
	int id;//�X�L����ID
	int mp;//�X�L���̏���MP
	int elem;//�X�L���̑���
	float mag;//�X�L���̔{��
	int effect;//1�P��2�S��3��
	char dis[256];//�X�L���̐���
	int lev;//�o���郌�x��
	int max_heal;//�X�L���̍ő��
	int min_heal;//�X�L���̍Œ��
}Skill;

Skill skill[30];

int sget_cursor(int c, int cursor, int cmax);//�X�L���p�̃J�[�\���ړ�

/// <summary>
/// �����������
/// </summary>
void init();

/// <summary>
/// �������ǂ����𔻒f����֐�
/// </summary>
/// <param name="*num">����</param>
/// <returns>��������������false ���l�݂̂Ȃ�true</returns>
bool check_num(char *num);

/// <summary>
/// ��킹��Q�l��I��
/// </summary>
void chose_charactor();

/// <summary>
/// �݂�Ȃ̃X�e�[�^�X��\�������
/// </summary>
void disp_status();

/// <summary>
/// �����ɑΉ����������𕶎��ŕԂ���
/// </summary>
/// <param name="elem">�L�����N�^�[�̑����Ƃ��̒l</param>
/// <returns>�����i�S�p�����j</returns>
const char *get_elem(int elem);

/// <summary>
/// ������L�����N�^�[��I������
/// </summary>
void select_charactor();

/// <summary>
/// ������X�e�[�^�X��I�������
/// </summary>
void select_status(int num);

/// <summary>
/// �I�������L������퓬�p�̕ϐ��ɂԂ�����
/// </summary>
/// <param name="num">�\���̂Ō����L�����N�^�[�̏��Ԃ݂�����</param>
/// <param name="order">1�l�ڂ�2�l�ڂ��𔻒f</param>
void set_charactor(int num, int order);

/// <summary>
/// ���O�ݒ�
/// </summary>
/// <param name="*name">�ύX�������L�����N�^�[��name�̃|�C���^</param>
void set_name(char *name);

/// <summary>
/// ���ʑI��
/// </summary>
/// <param name="*name">�ύX�������L�����N�^�[��sex�̃|�C���^</param>
void set_sex(int *sex);

/// <summary>
/// HP�ݒ�
/// </summary>
/// <param name="*name">�ύX�������L�����N�^�[��hp�̃|�C���^</param>
/// <param name="*name">�ύX�������L�����N�^�[��mhp�̃|�C���^</param>
void set_hp(int *hp, int *mhp);

/// <summary>
/// MP�ݒ�
/// </summary>
/// <param name="*name">�ύX�������L�����N�^�[��mp�̃|�C���^</param>
/// <param name="*name">�ύX�������L�����N�^�[��mmp�̃|�C���^</param>
void set_mp(int *mp, int *mmp);

/// <summary>
/// �U���ݒ�
/// </summary>
/// <param name="*name">�ύX�������L�����N�^�[��atk�̃|�C���^</param>
void set_atk(int *atk);

/// <summary>
/// �h��ݒ�
/// </summary>
/// <param name="*name">�ύX�������L�����N�^�[��def�̃|�C���^</param>
void set_def(int *def);

/// <summary>
/// ���@�U���ݒ�
/// </summary>
/// <param name="*name">�ύX�������L�����N�^�[��matk�̃|�C���^</param>
void set_matk(int *matk);

/// <summary>
/// ���@�h��ݒ�
/// </summary>
/// <param name="*name">�ύX�������L�����N�^�[��mdef�̃|�C���^</param>
void set_mdef(int *mdef);

/// <summary>
/// �f�����ݒ�
/// </summary>
/// <param name="*name">�ύX�������L�����N�^�[��spd�̃|�C���^</param>
void set_spd(int *spd);

/// <summary>
/// �����I��
/// </summary>
/// <param name="*name">�ύX�������L�����N�^�[��elem�̃|�C���^</param>
void set_elem(int *elem);

/// <summary>
/// �X�L���I��I��
/// </summary>
/// <param name="*name">�ύX�������L�����N�^�[�̏ꏊ�i1�l�ڂȂ�0 2�l�ڂȂ�1�ł��j</param>
void set_skill(int num);

/*-------------------�ȉ��퓬�֌W�̃v���g�^�C�v�錾---------------------*/

/// <summary>
/// �퓬�֌W�̊֐����Ăяo���֐�����
/// </summary>
void battle_mgr();

/// <summary>
/// �퓬���Ă���L�����̖��O��HP�Ȃǂ�\�������
/// </summary>
/// <param name="enenum">�G�̐�</param>
void draw_battle(int enenum);

/// <summary>
/// �e�L�����̍U�����@�����߂��
/// </summary>
/// <param name="*a">�U�����@�����߂����L�����̍\���̃|�C���^</param>
/// <returns>�L�����N�^�[�̃X�L����ID�̂ǂꂩ</returns>
int decide_attack_type(chara *a);

/// <summary>
/// �΂�����邽�߂̔{����Ԃ���
/// </summary>
/// <returns>0.9�`1.1</returns>
float get_rand_mag();

/// <summary>
/// �U�����鑊���I�������i����͎����j
/// </summary>
/// <param name="nennum">�G�̐�</param>
/// <param name="skill_id">�g�����Ƃ��Ă���X�L����ID</param>
void select_target(int enenum, int skill_id);

/// <summary>
/// �U�����鏇�Ԃ����߂��
/// </summary>
/// <param name="target">�U���Ώۂ̓G�̒l�i�퓬��0�j</param>
/// <param name="enenum">�G�̐�</param>
/// <param name="s_or_i">���������@��</param>
/// <param name="skill_id">�g�����Ƃ��Ă���X�L����ID</param>
void order_of_attack(int target, int enenum, int s_or_i, int skill_id);

/// <summary>
/// �G�̍U������
/// </summary>
/// <param name="id">�G��ID</param>
/// <param name="enenum">�G�̐�</param>
void enemy_turn(int id, int enenum);

/// /// <summary>
/// �_���[�W���v�Z����HP�����炵�Ă����\�������
/// </summary>
/// <param name="atacker">�U������l�̐��l�i0�Ȃ疡��1�Ȃ�G�j</param>
/// <param name="target">�U�������l�̒l�i�z��̓Y�����I�ȁj</param>
/// <param name="s_or_i">���������@��</param>
/// <param name="elem">�X�L���̑���</param>
/// <param name="range">get_rand_mag�֐��̒l</param>
/// <param name="mag">�X�L���̔{��</param>
/// <param name="skill_id">�X�L����ID</param>
/// <param name="enenum">�G�̐�</param>
void damage(int atacker, int target, int s_or_i, int elem, float range, float mag, int skill_id, int enenum);


/*---�O���[�o���ϐ���`---*/
chara charactor[4]{
	{
		"1�l��", 18, 18, 0, 0, 12, 8, 2, 2, 1, 0, 1, 0, 0, {24,24,24,24,24}, 1
	},
	{
		"2�l��", 12, 12, 0, 0, 15, 8, 2, 2, 4, 0, 1, 0, 0, {24,24,24,24,24}, 2
	},
	{
		"3�l��", 22, 22, 0, 0, 12, 5, 2, 2, 2, 0, 1, 0, 0, {24,24,24,24,24}, 3
	},
	{
		"4�l��", 16, 16, 0, 0, 13, 10, 2, 2, 3, 0, 1, 0, 0, {24,24,24,24,24}, 4
	}
};
chara *p = charactor;
chara *party;
chara *e;
int timer = 1000;

int main() {
	init();
	printf("\n\n\t4�l�p�[�e�B������4�l�̃X�e�[�^�X���Z�b�g���Ăق����ȁI");
	wait_key();
	select_charactor();
}

void select_charactor() {

	/*1�l�ځA2�l�ځA3�l�ځA4�l�ځA�\���A�퓬�A�I���̐��l*/
	enum {
		first, second, third, fourth, disp, next, end
	};

	int cmax = 6;//�I�����̐��}�C�i�X1
	int cursor = 0;//�J�[�\���̈ʒu
	int c = 0;//����

	while (true) {
		clear();

		printf("\n\n\t����̃X�e�[�^�X��ύX����H\n\n");

		if (cursor == first) {
			in_cursor();
			printf("\t%s\n\n", p->name);
			out_cursor();
		}
		else {
			printf("\t%s\n\n", p->name);
		}
		if (cursor == second) {
			in_cursor();
			printf("\t%s\n\n", (p + 1)->name);
			out_cursor();
		}
		else {
			printf("\t%s\n\n", (p + 1)->name);
		}
		if (cursor == third) {
			in_cursor();
			printf("\t%s\n\n", (p + 2)->name);
			out_cursor();
		}
		else {
			printf("\t%s\n\n", (p + 2)->name);
		}
		if (cursor == fourth) {
			in_cursor();
			printf("\t%s\n\n", (p + 3)->name);
			out_cursor();
		}
		else {
			printf("\t%s\n\n", (p + 3)->name);
		}
		if (cursor == disp) {
			in_cursor();
			printf("\t�X�e�[�^�X�\��\n\n");
			out_cursor();
		}
		else {
			printf("\t�X�e�[�^�X�\��\n\n");
		}
		if (cursor == next) {
			in_cursor();
			printf("\t�키2�l��I��\n\n");
			out_cursor();
		}
		else {
			printf("\t�키2�l��I��\n\n");
		}
		if (cursor == end) {
			in_cursor();
			printf("\t�I���\n\n");
			out_cursor();
		}
		else {
			printf("\t�I���\n\n");
		}

		c = get_key();
		cursor = get_cursor(c, cursor, cmax, 0);

		if (c == ENTER) {
			if (cursor == disp) {
				disp_status();
			}
			else if (cursor == next) {
				chose_charactor();
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
		name, sex, hp, mp, atk, def, matk, mdef, spd, elem, skill, re
	};

	int cmax = 11;
	int cursor = 0;//�J�[�\���̈ʒu
	int c = 0;//����

	while (true) {
		clear();

		printf("\n\n\t�ǂ̃X�e�[�^�X��ύX����H\n\n");

		if (cursor == name) {
			in_cursor();
			printf("\t���O\t");
			out_cursor();
		}
		else {
			printf("\t���O\t");
		}
		if (cursor == atk) {
			in_cursor();
			printf("\t�U���́@�@\t");
			out_cursor();
		}
		else {
			printf("\t�U���́@�@\t");
		}
		if (cursor == spd) {
			in_cursor();
			printf("\t�f����\n\n");
			out_cursor();
		}
		else {
			printf("\t�f����\n\n");
		}
		if (cursor == sex) {
			in_cursor();
			printf("\t����\t");
			out_cursor();
		}
		else {
			printf("\t����\t");
		}
		if (cursor == def) {
			in_cursor();
			printf("\t�h��́@�@\t");
			out_cursor();
		}
		else {
			printf("\t�h��́@�@\t");
		}
		if (cursor == elem) {
			in_cursor();
			printf("\t����\n\n");
			out_cursor();
		}
		else {
			printf("\t����\n\n");
		}
		if (cursor == hp) {
			in_cursor();
			printf("\tHP�@\t");
			out_cursor();
		}
		else {
			printf("\tHP�@\t");
		}
		if (cursor == matk) {
			in_cursor();
			printf("\t���@�U����\t");
			out_cursor();
		}
		else {
			printf("\t���@�U����\t");
		}
		if (cursor == skill) {
			in_cursor();
			printf("\t�X�L���ݒ�\n\n");
			out_cursor();
		}
		else {
			printf("\t�X�L���ݒ�\n\n");
		}
		if (cursor == mp) {
			in_cursor();
			printf("\tMP�@\t");
			out_cursor();
		}
		else {
			printf("\tMP�@\t");
		}
		if (cursor == mdef) {
			in_cursor();
			printf("\t���@�h���\t");
			out_cursor();
		}
		else {
			printf("\t���@�h���\t");
		}
		if (cursor == re) {
			in_cursor();
			printf("\t�߂�\n\n");
			out_cursor();
		}
		else {
			printf("\t�߂�\n\n");
		}

		c = get_key();
		cursor = get_cursor(c, cursor, cmax, 4);

		switch (c) {
		case ENTER:
			if (cursor == name) {
				set_name((p + n)->name);
			}
			else if (cursor == sex) {
				set_sex(&(p + n)->sex);
			}
			else if (cursor == hp) {
				set_hp(&(p + n)->hp, &(p + n)->mhp);
			}
			else if (cursor == mp) {
				set_mp(&(p + n)->mp, &(p + n)->mmp);
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
			else if (cursor == skill){
				set_skill(n);
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
			in_cursor();
			printf("\t�j\n\n");
			out_cursor();
		}
		else {
			printf("\t�j\n\n");
		}
		if (cursor == female) {
			in_cursor();
			printf("\t��\n\n");
			out_cursor();
		}
		else {
			printf("\t��\n\n");
		}

		c = get_key();
		cursor = get_cursor(c, cursor, cmax, 0);

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

void set_hp(int *hp, int *mhp) {

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
			*mhp = *hp = atoi(num);
		}

	} while (!flag);

}

void set_mp(int *mp, int *mmp) {

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
			*mmp = *mp = atoi(num);
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
			in_cursor();
			printf("\t��\n\n");
			out_cursor();
		}
		else {
			printf("\t��\n\n");
		}
		if (cursor == FIRE) {
			in_cursor();
			printf("\t��\n\n");
			out_cursor();
		}
		else {
			printf("\t��\n\n");
		}
		if (cursor == WATER) {
			in_cursor();
			printf("\t��\n\n");
			out_cursor();
		}
		else {
			printf("\t��\n\n");
		}
		if (cursor == WIND) {
			in_cursor();
			printf("\t��\n\n");
			out_cursor();
		}
		else {
			printf("\t��\n\n");
		}
		if (cursor == SOIL) {
			in_cursor();
			printf("\t�y\n\n");
			out_cursor();
		}
		else {
			printf("\t�y\n\n");
		}
		if (cursor == LIGHT) {
			in_cursor();
			printf("\t��\n\n");
			out_cursor();
		}
		else {
			printf("\t��\n\n");
		}
		if (cursor == DARK) {
			in_cursor();
			printf("\t��\n\n");
			out_cursor();
		}
		else {
			printf("\t��\n\n");
		}

		c = get_key();
		cursor = get_cursor(c, cursor, cmax, 0);

		if (c == ENTER) {
			*elem = cursor;
			return;
		}
	}
}

void set_skill(int n) {
	int i;
	int cmax = 24;
	int cursor = 0;//�J�[�\���̈ʒu
	int c = 0;//����
	int select_skill = 0;//���Ԗڂ̃X�L����ύX���悤�Ƃ��Ă���
	int skill_num[4];

	for (i = 0; i < 4; i++) {
		skill_num[i] = (p + n)->skill[i + 1] - 1;
		if (skill_num[i] != 23) {
			select_skill++;
		}
	}
	
	clear();
	while (true) {
		printf("\n");
		for (i = 0; i <= cmax; i++) {
			if (i % 3 == 0) {
				printf("\t");
			}
			if (cursor == i) {
				in_cursor();
			}
			if (i == 23) {
				printf("%-20s", "�߂�");
			}
			else if (i == 24) {
				printf("%-20s", "����I");
			}
			else {
				printf("%-20s", skill[i].name);
			}
			if (cursor == i) {
				out_cursor();
			}
			if (i % 3 == 2) {
				printf("\n\n");
			}

		}
		printf("\n\n\n");

		if (cursor < 23) {
			printf("\n\t%-50s\n", skill[cursor].dis);
			printf("\n\t����MP:%3d\n", skill[cursor].mp);
		}
		else {
			printf("\n\n\n\n");
		}
		
		printf("\n\n\t�X�L��1�F%-25s�X�L��2�F%-25s", skill[skill_num[0]].name, skill[skill_num[1]].name);
		printf("\n\n\t�X�L��3�F%-25s�X�L��4�F%-25s", skill[skill_num[2]].name, skill[skill_num[3]].name);
	
		c = get_key();
		cursor = sget_cursor(c, cursor, cmax);

		switch (c)
		{
		case ENTER:
			//�߂��I�������Ƃ�
			if (cursor == 23) {
				if (select_skill == 0) {
					return;
				}
				else{
					select_skill--;
					skill_num[select_skill] = 24;
				}
			}
			//����I��I�������Ƃ�
			else if (cursor == 24) {
				for (int i = 0; i < 4; i++) {
					(p + n)->skill[i + 1] = skill[skill_num[i]].id;
				}
				return;
			}
			//�X�L����I�������Ƃ�
			else {
				if (select_skill < 4) {
					skill_num[select_skill] = cursor;
					select_skill++;
				}
			}
			break;
		case 0x1b:
			return;
		default:
			break;
		}
		clear();
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

	for (i = 0; (unsigned)i < strlen(num); i++) {
		if (!isdigit(num[i])) {
			return false;
		}
	}
	return true;
}

void chose_charactor() {
	
	int chose_num = 0;//1�l�I�Ԃ�1�A2�l�I�Ԃ�2�ɂȂ�->�l���Ǘ��p�ϐ�
	int cmax = 5;//�I�����̐��}�C�i�X1
	int cursor = 0;//�J�[�\���̈ʒu
	int c = 0;//����
	char name1[NAME_LEN + 1] = "";
	char name2[NAME_LEN + 1] = "";
	bool b_name1 = true;
	bool b_name2 = true;

	enum {
		first, second, third, fourth, battle, re,
	};
	
	while (true) {
		clear();

		/*�I����*/
		if (chose_num == 0 || chose_num == 1) {
			printf("\n\n\t��킹��%d�l�ڂ�I�����Ă�������\n\n", chose_num + 1);
		}
		else {
			printf("\n\n\t���Ȃ�������퓬�J�n�I\n\n");
		}
		if (cursor == first) {
			in_cursor();
			printf("\t%s\n\n", p->name);
			out_cursor();
		}
		else {
			printf("\t%s\n\n", p->name);
		}
		if (cursor == second) {
			in_cursor();
			printf("\t%s\n\n", (p + 1)->name);
			out_cursor();
		}
		else {
			printf("\t%s\n\n", (p + 1)->name);
		}
		if (cursor == third) {
			in_cursor();
			printf("\t%s\n\n", (p + 2)->name);
			out_cursor();
		}
		else {
			printf("\t%s\n\n", (p + 2)->name);
		}
		if (cursor == fourth) {
			in_cursor();
			printf("\t%s\n\n", (p + 3)->name);
			out_cursor();
		}
		else {
			printf("\t%s\n\n", (p + 3)->name);
		}
		if (cursor == battle) {
			in_cursor();
			printf("\t�퓬�J�n�I\n\n");
			out_cursor();
		}
		else {
			printf("\t�퓬�J�n�I\n\n");
		}
		if (cursor == re) {
			in_cursor();
			printf("\t�߂�\n\n");
			out_cursor();
		}
		else {
			printf("\t�߂�\n\n");
		}

		printf("\n\t1�l��:%s\n\n", name1);
		printf("\n\t2�l��:%s\n\n", name2);


		c = get_key();
		cursor = get_cursor(c, cursor, cmax, 0);
		if (c == ENTER) {
			/*�߂��I�������Ƃ���chose_num�̒l�ɉ����Đݒ肵�����O�������i�f�[�^�͏����Ă��Ȃ����Ǐ㏑������̂ł悵�j*/
			if (cursor == re) {
				if (chose_num == 2) {
					chose_num = 1;
					strcpy_s(name2, "");
				}
				else if (chose_num == 1) {
					chose_num = 0;
					strcpy_s(name1, "");
				}
				else {
					return;
				}
			}
			/*�퓬�J�n�I��I�������Ƃ��ɂQ�l�I�����Ă���Ȃ�擪�Ɉړ������łȂ��Ȃ���͂𑣂�*/
			else if (cursor == battle) {
				if (chose_num == 2) {
					battle_mgr();
				}
				else {
					printf("\t�Q�l�I�����Ă���퓬�J�n���ĂˁI�I�I");
					wait_key();
				}
			}
			/*���O��I�������Ƃ��ɏ����𖞂����Ă���Ώ����Z�b�g*/
			else {
				/*�\�����Ă��閼�O�ƑI�������L�����̖��O����v���Ă�����false�ɂ���A�����łȂ��Ȃ�true�ɂ���*/
				if (!strcmp(name1, (p + cursor)->name)) {
					b_name1 = false;
				}
				else {
					b_name1 = true;
				}
				if (!strcmp(name2, (p + cursor)->name)) {
					b_name2 = false;
				}
				else {
					b_name2 = true;
				}
				/*���O�̃t���O��true�Ȃ�L�����̏����Z�b�g���A�\�����閼�O���Z�b�g����A�����łȂ��Ȃ�ē��͂𑣂�*/
				if (b_name1 && b_name2) {
					set_charactor(cursor, chose_num);
					if (chose_num == 0) {
						strcpy_s(name1, (p + cursor)->name);
					}
					else if (chose_num == 1) {
						strcpy_s(name2, (p + cursor)->name);
					}
					chose_num++;
				}
				else {
					printf("\t�����l�͑I�ׂȂ���I");
					wait_key();
				}
			}
		}
	}
}

void set_charactor(int num, int order) {
	if (order == 0) {
		party = (p + num);
		party->id = 1;
	}
	else if (order == 1) {
		e = (p + num);
		e->id = 2;
	}
}

int decide_attack_type(chara *a) {
	return a->skill[rand() % 5];//������skill�̏ꏊ�����߂Ă��̒l��Ԃ�
}

void battle_mgr() {
	draw_battle(1);
}

void draw_battle(int enenum) {
	int cmax = 4;
	int cursor = 0;//�J�[�\���̈ʒu
	int c = 0;//����
	//int result[2] = { 0, 0 };//�o���l�Ƃ���
	//int levup_exp = 0;
	//bool is_esc = false;

	enum s {
		attack,//��������
		defence,//�ڂ�����
		escape,//�ɂ���
		spell,//�������
		tool,//�ǂ���
	};

	while (true) {
		//clear();
		printf("\n");
		printf("\t �Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q\n");//�S�p30�{���p�X�y�[�X1
		printf("\t�b%-15s%-15s                            ", party->name, e->name);
		printf("�b\n");
		printf("\t�bHP %3d/%3d     HP %3d/%3d                                 ", party->hp, party->mhp, e->hp, e->mhp);
		printf("�b\n");
		printf("\t�bMP %3d/%3d     MP %3d/%3d                                 ", party->mp, party->mmp, e->mp, e->mmp);
		printf("�b\n");
		printf("\t �P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P");
		printf("\n\n\n\n\n\n\n\n\n\n");

		select_target(1, decide_attack_type(party));

		/*if (cursor == attack) {
			in_cursor();
			printf("\t��������");
			out_cursor();
		}
		else {
			printf("\t��������");
		}

		if (cursor == spell) {
			in_cursor();
			printf("\t�������\n\n");
			out_cursor();
		}
		else {
			printf("\t�������\n\n");
		}

		if (cursor == defence) {
			in_cursor();
			printf("\t�ڂ�����");
			out_cursor();
		}
		else {
			printf("\t�ڂ�����");
		}

		if (cursor == tool) {
			in_cursor();
			printf("\t�ǂ���\n\n");
			out_cursor();
		}
		else {
			printf("\t�ǂ���\n\n");
		}

		if (cursor == escape) {
			in_cursor();
			printf("\t�ɂ���");
			out_cursor();
		}
		else {
			printf("\t�ɂ���");
		}*/

		//�G�̃X�e�[�^�X�\���@�\
		/*for (int k = 0; k < enenum;k++) {
			printf("\n\n���O:%s\nHP%3d/%3d  MP%3d/%3d", e[k].name, e[k].hp, e[k].mhp, e[k].mp, e[k].mmp);
			printf("\natk;%3d def:%3d matk:%3d mdef:%3d", e[k].atk, e[k].def, e[k].matk, e[k].mdef);
			printf("\nspd;%d elem:%d exp:%d, lev:%d id:%d\n",  e[k].spd, e[k].elem, e[k].exp, e[k].lev, e[k].id);
		}*/

		/*c = get_key();
		cursor = get_cursor(c, cursor, cmax, 3);
		switch (c)
		{
		case ENTER:
			if (cursor == attack) {
				select_target(e, enenum, 24);
			}
			if (cursor == spell) {
				draw_skill(true, e, enenum);
			}
			if (cursor == defence) {
				gard(e, enenum);
			}
			if (cursor == tool) {
				draw_tool_battle(e, enenum);
			}
			if (cursor == escape) {
				is_esc = true;
			}
			break;
		default:
			break;
		}*/

		//enenum = check_hp(e, result, enenum);


		if (party->hp <= 0) {
			printf("\n\n\t%s�͎���ł��܂����I", party->name);
			wait_key();
			exit(EXIT_SUCCESS);
		}
		if (e->hp <= 0) {
			printf("\n\n\t%s�͎���ł��܂����I", e->name);
			wait_key();
			exit(EXIT_SUCCESS);
		}
	}
}

void select_target(int enenum, int skill_id) {
	int cursor = 0;//�J�[�\���̈ʒu
	int c = 0;//����
	while (true) {
		//clear();

		//�U������^�[�Q�b�g��I�������
		for (int n = 0; n < enenum; n++) {
			if (n <= enenum) {
				if (cursor == n) {
					in_cursor();
					printf("\n\n\t%-s\n", (e + n)->name);
					out_cursor();
				}
				else {
					printf("\n\n\t%-s\n", (e + n)->name);
				}
			}
		}

		/*c = get_key();
		cursor = get_cursor(c, cursor, enenum);

		switch (c)
		{
		case ENTER:*/
		//�I�������G���X�L���ɉ����čU�������
			for (int n = 0; n <= enenum; n++) {
				//if (cursor == n) {
				//�U���̏ꍇ
					if (skill_id == 24) {
						order_of_attack(n, enenum, STR, skill_id);
					}
					//���@�̏ꍇ
					else {
						order_of_attack(n, enenum, MAGIC, skill_id);
					}

					return;
				//}
			}
			break;
		/*case 0x1b:
			return;
		default:
			break;
		}*/
	}
}

void order_of_attack(int target, int enenum, int s_or_i, int skill_id) {
	int order[6] = { -1, -1, -1, -1, -1, -1 };//�U����������܂�index���Ⴂ�قǑ���
	int spd_order[6] = { -1, -1, -1, -1, -1, -1 };//���΂₳�̍������ɂȂ���
	int i, j, temp;

	spd_order[0] = party->spd;
	for (i = 0; i < enenum; i++) {
		spd_order[i + 1] = e[i].spd;
	}

	//�~�����[��
	for (i = 0; i < enenum; i++) {
		for (j = enenum; j > i; j--) {
			if (spd_order[j - 1] < spd_order[j]) {
				temp = spd_order[j - 1];
				spd_order[j - 1] = spd_order[j];
				spd_order[j] = temp;
			}
		}
	}

	//�f�����̏��ɁAorder��ID�������
	for (i = 0; i < enenum + 1; i++) {
		for (j = 0; j < enenum + 1; j++) {
			if (spd_order[i] == (e + j)->spd) {
				order[i] = (e + j)->id;
			}
			else if (spd_order[i] == party->spd) {
				order[i] = party->id;
			}
		}
	}
	/*for (i = 0; i < enenum + 1; i++) {
		printf("order%d:%d\n", i, order[i]);
	}
	waitkey();*/

	//�G�������̍U�������߂��
	for (i = 0; i < enenum + 1; i++) {//�G�̐��{�����̐������J��Ԃ�
		//�����̍U���̏ꍇ
		if (order[i] == party->id) {
			//�A�C�e���̎�
			if (s_or_i == ITEM) {
				//use_item(target, skill_id);
			}
			//�h��̎�
			else if (s_or_i == GARD) {
				damage(0, -1, -1, -1, -1, 0.25, -1, enenum);
			}
			//�U���̎�
			else {
				damage(0, target, s_or_i, skill[skill_id - 1].elem, get_rand_mag(), skill[skill_id - 1].mag, skill_id, enenum);
			}
		}
		//�G�̍U���̎�
		else if (order[i] == e[0].id) {
			enemy_turn(e->id, enenum);
		}
		/*else if (order[i] == e[1].id) {
			enemy_turn(e, e[1].id, enenum);
		}
		else if (order[i] == e[2].id) {
			enemy_turn(e, e[2].id, enenum);
		}
		else if (order[i] == e[3].id) {
			enemy_turn(e, e[3].id, enenum);
		}
		else if (order[i] == e[4].id) {
			enemy_turn(e, e[4].id, enenum);
		}*/

		//�v���C���[��HP��0�ɂȂ�����
		if (party->hp == 0) {
			//order�ɑ�������v�f�̐������J��Ԃ�
			for (j = 0; j < enenum + 1; j++) {
				//order�̒��Ƀv���C���[��ID������������
				if (order[j] == party->id) {
					//�v���C���[��ID���폜����
					order[j] = -1;
					//���ԕς�邩��\�[�g���悤
					for (i = 0; i < enenum; i++) {
						for (j = enenum; j > i; j--) {
							if (spd_order[j - 1] < spd_order[j]) {
								temp = spd_order[j - 1];
								spd_order[j - 1] = spd_order[j];
								spd_order[j] = temp;
							}
						}
					}
					for (i = 0; i < enenum + 1; i++) {
						for (j = 0; j < enenum + 1; j++) {
							if (spd_order[i] == (e + j)->spd) {
								order[i] = (e + j)->id;
							}
							else if (spd_order[i] == party->spd) {
								order[i] = party->id;
							}
						}
					}
				}
			}

		}
		//����G�̐������J��Ԃ�
		for (j = 0; j < enenum; j++) {
			//�ǂ����̓G��HP��0�ɂȂ�����
			if ((e + j)->hp == 0) {
				//order�ɑ�������v�f�̐������J��Ԃ�
				for (int k = 0; k < enenum + 1; k++) {
					//HP��0�ɂȂ����G��ID������������
					if (order[k] == (e + j)->id) {
						//HP��0�̓G��ID���폜����
						order[j] = -1;
						spd_order[j] = -1;
						//���ԕς�邩��\�[�g���悤
						for (i = 0; i < enenum; i++) {
							for (j = enenum; j > i; j--) {
								if (spd_order[j - 1] < spd_order[j]) {
									temp = spd_order[j - 1];
									spd_order[j - 1] = spd_order[j];
									spd_order[j] = temp;
								}
							}
						}
						for (i = 0; i < enenum + 1; i++) {
							for (j = 0; j < enenum + 1; j++) {
								if (spd_order[i] == (e + j)->spd) {
									order[i] = (e + j)->id;
								}
								else if (spd_order[i] == party->spd) {
									order[i] = party->id;
								}
							}
						}
					}
				}
			}
		}
	}
	//is_gard = false;
}

void enemy_turn(int id, int enenum) {
	//clear();
	printf("\n\n\t%s�̂��������I", (e + (id - 2))->name);
	//Sleep(timer);
	int ene_skill_num;//�G�̎����Ă���X�L���̉��Ԗڂ��g�������i�[����ϐ�

	ene_skill_num = decide_attack_type(e);


	//�����߂�ǂ������Ȃ�������X�L���ɕ��������@�������郁���o��ǉ����Ĉ�̊֐��ōς܂��悤�ɂ���ƃX�}�[�g����
	if (ene_skill_num == 24) {
		damage(1, 0, STR, skill[ene_skill_num - 1].elem, get_rand_mag(), skill[ene_skill_num - 1].mag, ene_skill_num, enenum);
	}
	else {
		damage(1, 0, MAGIC, skill[ene_skill_num - 1].elem, get_rand_mag(), skill[ene_skill_num - 1].mag, ene_skill_num, enenum);
	}

	//�G�̑����t���̒ʏ�U�����ł�����L���ɂ��悤��
	/*else if (e[id - 1].elem == WATER) {



		ene_skill_num = ene_skill_id(e, id);
		damage(1, id - 1, STR, ene_skill[e[id - 1].skl[ene_skill_num]].elem, range(), ene_skill[e[id - 1].skl[ene_skill_num]].mag, e, ene_skill_id(e, id), enenum);
	}
	else if (e[id - 1].elem == WIND) {



		ene_skill_num = ene_skill_id(e, id);
		damage(1, id - 1, STR, ene_skill[e[id - 1].skl[ene_skill_num]].elem, range(), ene_skill[e[id - 1].skl[ene_skill_num]].mag, e, ene_skill_id(e, id), enenum);
	}
	else if (e[id - 1].elem == SOIL) {



		ene_skill_num = ene_skill_id(e, id);
		damage(1, id - 1, STR, ene_skill[e[id - 1].skl[ene_skill_num]].elem, range(), ene_skill[e[id - 1].skl[ene_skill_num]].mag, e, ene_skill_id(e, id), enenum);
	}
	else if (e[id - 1].elem == LIGHT) {


		ene_skill_num = ene_skill_id(e, id);
		damage(1, id - 1, STR, ene_skill[e[id - 1].skl[ene_skill_num]].elem, range(), ene_skill[e[id - 1].skl[ene_skill_num]].mag, e, ene_skill_id(e, id), enenum);
	}
	else if (e[id - 1].elem == DARK) {



		ene_skill_num = ene_skill_id(e, id);
		damage(1, id - 1, STR, ene_skill[e[id - 1].skl[ene_skill_num]].elem, range(), ene_skill[e[id - 1].skl[ene_skill_num]].mag, e, ene_skill_id(e, id), enenum);
	}*/
}

void damage(int atacker, int target, int s_or_i, int elem, float range, float mag, int skill_id, int enenum) {
	float bairitu[5] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
	int heal;
	int damage = 0;

	char element[][3]{
		"��", "��", "��", "�y", "��", "��"
	};

	/*if (is_gard) {
		mag *= 0.25f;
	}*/

	//�����̍U���̎�
	//clear();

	if (atacker == 0) {
		//clear();
		printf("\n\n\t%s�̂��������I", party->name);
		//if (skill_id == -1) {
		//	printf("\n\n\t�ڂ����債���I");
		//	//Sleep(timer);
		//	//clear();
		//	return;
		//}
		if (skill_id != 24) {
			if (party->mp < skill[skill_id - 1].mp) {
				printf("\n\n\tMP������Ȃ��I");
			}
			else {
				printf("\n\n\t%s��%s���ƂȂ����I", party->name, skill[skill_id - 1].name);
				party->mp -= skill[skill_id - 1].mp;
			}
		}
		//Sleep(timer);
		//clear();
		
		//�P�̍U���̎�
		if (skill[skill_id - 1].effect == 1) {

			//�����ɂ���Ĕ{�������߂�
			if ((e + target)->elem == FIRE && elem == WATER || (e + target)->elem == WATER && elem == SOIL || (e + target)->elem == SOIL && elem == WIND ||
				(e + target)->elem == WIND && elem == FIRE || (e + target)->elem == LIGHT && elem == DARK || (e + target)->elem == DARK && elem == LIGHT) {
				bairitu[0] = 1.5;
			}
			if ((e + target)->elem == WATER && elem == FIRE || (e + target)->elem == SOIL && elem == WATER || (e + target)->elem == WIND && elem == SOIL ||
				(e + target)->elem == FIRE && elem == WIND) {
				bairitu[0] = 0.5;
			}

			//�_���[�W�̌v�Z��
			if (s_or_i == STR) {
				if (party->atk - (e + target)->def <= 0) {
					damage = 1;
				}
				else {
					damage = int((float)(party->atk - (e + target)->def) * bairitu[0] * range * mag);
				}
			}
			if (s_or_i == MAGIC) {
				if (party->matk - (e + target)->mdef <= 0) {
					damage = 1;
				}
				else {
					damage = int((float)(party->matk - (e + target)->mdef) * bairitu[0] * range * mag);
				}
			}
			//Sleep(timer);
			//HP����
			(e + target)->hp -= damage;
			if ((e + target)->hp <= 0) {
				(e + target)->hp = 0;
			}

			printf("\n\n\t%s��%d�̃_���[�W��^�����I", (e + target)->name, damage);

			if (bairitu[0] == 1.5) {
				//Sleep(timer);
				printf("\n\n\t%s��%s�����̍U���Ɏア�݂������I", (e + target)->name, element[elem - 1]);
			}
			else if (bairitu[0] == 0.5) {
				//Sleep(timer);
				printf("\n\n\t%s�ɂ�%s�����̍U���͌����ɂ����݂������c�I", (e + target)->name, element[elem - 1]);
			}
		}

		//�������������̂Ƃ�
		else if (skill[skill_id - 1].effect == 2) {
			for (int i = 0; i < enenum; i++) {
				if (e[enenum - 1].elem == FIRE && elem == WATER || e[enenum - 1].elem == WATER && elem == SOIL || e[enenum - 1].elem == SOIL && elem == WIND ||
					e[enenum - 1].elem == WIND && elem == FIRE || e[enenum - 1].elem == LIGHT && elem == DARK || e[enenum - 1].elem == DARK && elem == LIGHT) {
					bairitu[enenum - 1] = 1.5f;
				}
				if (e[enenum - 1].elem == WATER && elem == FIRE || e[enenum - 1].elem == SOIL && elem == WATER || e[enenum - 1].elem == WIND && elem == SOIL ||
					e[enenum - 1].elem == FIRE && elem == WIND) {
					bairitu[enenum - 1] = 0.5f;
				}
			}

			for (int i = 0; i < enenum; i++) {
				if (s_or_i == STR) {
					if (party->atk <= (e + target)->def) {
						damage = 1;
					}
					else {
						damage = int((float)(party->atk - e[i].def) * bairitu[0] * range * mag);
					}	
				}

				if (s_or_i == MAGIC) {
					if (party->matk <= e[i].mdef) {
						damage = 1;
					}
					else {
						damage = int((float)(party->matk - e[i].mdef) * bairitu[0] * range * mag);
					}
				}

				//Sleep(timer);
				//clear();
				e[i].hp -= damage;
				if (e[i].hp <= 0) {
					e[i].hp = 0;
				}
				printf("\n\n\t%s��%d�̃_���[�W��^�����I", e[i].name, damage);

				if (bairitu[i] == 1.5f) {
					//Sleep(timer);
					printf("\n\n\t%s��%s�����̍U���Ɏア�݂������I", e[i].name, element[elem - 1]);
				}
				else if (bairitu[i] == 0.5f) {
					//Sleep(timer);
					printf("\n\n\t%s�ɂ�%s�����̍U���͌����ɂ����݂������c�I", e[i].name, element[elem - 1]);
				}
			}
		}
		else if (skill[skill_id - 1].effect == 3) {

			heal = (int)(rand() % skill[skill_id - 1].min_heal + (skill[skill_id - 1].max_heal - skill[skill_id - 1].min_heal) + party->matk * 0.1);
			if (heal > skill[skill_id - 1].max_heal) {
				heal = skill[skill_id - 1].max_heal;
			}
			party->hp += heal;
			if (party->hp > party->mhp) {
				heal -= party->hp - party->mhp;
				party->hp = party->mhp;
			}
			printf("\n\n\tHP��%d�񕜂����I", heal);
			//Sleep(timer);
		}
	}

	if (atacker == 1) {

		if (skill[skill_id - 1].effect == 1) {
			if (party->elem == FIRE && elem == WATER || party->elem == WATER && elem == SOIL || party->elem == SOIL && elem == WIND ||
				party->elem == WIND && elem == FIRE || party->elem == LIGHT && elem == DARK || party->elem == DARK && elem == LIGHT) {
				bairitu[0] = 1.5;
			}
			if (party->elem == WATER && elem == FIRE || party->elem == SOIL && elem == WATER || party->elem == WIND && elem == SOIL ||
				party->elem == FIRE && elem == WIND) {
				bairitu[0] = 0.5;
			}
		}

		if (!(skill_id == 24)) {
			printf("\n\n\t%s��%s���ƂȂ����I", (e + target)->name, skill[skill_id - 1].name);
			//Sleep(timer);
			if ((e + target)->mp < skill[skill_id - 1].mp) {
				printf("\n\n\t���swwww");
				//Sleep(timer);
			}
			else {
				(e + target)->mp -= skill[skill_id - 1].mp;
			}
		}

		//clear();
		if (skill[skill_id - 1].effect == 3) {
			int minhp_id = 1;
			for (int i = 0; i < enenum - 1; i++) {
				if (e[i].hp > e[i + 1].hp) {
					minhp_id = e[i + 1].id;
				}
			}
			heal = skill[skill_id - 1].max_heal;
			e[minhp_id - 1].hp += heal;

			if (e[minhp_id - 1].hp > e[minhp_id - 1].mhp) {
				heal -= (e[minhp_id - 1].hp - e[minhp_id - 1].mhp);
				e[minhp_id - 1].hp = e[minhp_id - 1].mhp;
			}
			printf("\n\n\t%s��HP��%d�񕜂����I", e[minhp_id - 1].name, heal);
		}
		else {
			if (s_or_i == STR) {
				if ((e + target)->atk - party->def <= 0) {
					damage = 1;
				}
				else {
					damage = int(((e + target)->atk - party->def) * bairitu[0] * range * mag);
				}
			}
			if (s_or_i == MAGIC) {
				if ((e + target)->matk - party->mdef <= 0) {
					damage = 1;
				}
				else {
					damage = int(((e + target)->matk - party->mdef) * bairitu[0] * mag);
					
				}
			}

			party->hp -= damage;
			if (party->hp <= 0) {
				party->hp = 0;
			}

			printf("\n\n\t%s��%d�̃_���[�W���󂯂�!", party->name, damage);
		}
		//Sleep(timer);
	}
	//clear();
	printf("\n");
}

void init_skill() {
	strcpy_s(skill[0].name, "�t���C���V���[�g");
	skill[0].id = 1;
	skill[0].mp = 1;
	skill[0].elem = FIRE;
	skill[0].mag = 1.2f;
	skill[0].effect = 1;
	strcpy_s(skill[0].dis, "�G1�̂ɉΑ����̃_���[�W��^����");
	skill[0].lev = 4;

	strcpy_s(skill[1].name, "�t�@�C�A�X�g�[��");
	skill[1].id = 2;
	skill[1].mp = 6;
	skill[1].elem = FIRE;
	skill[1].mag = 1.8f;
	skill[1].effect = 1;
	strcpy_s(skill[1].dis, "�G1�̂ɉΑ����̒��_���[�W��^����");
	skill[1].lev = 17;

	strcpy_s(skill[2].name, "���H���J�j�b�N�P�[�W");
	skill[2].id = 3;
	skill[2].mp = 9;
	skill[2].elem = FIRE;
	skill[2].mag = 2.2f;
	skill[2].effect = 1;
	strcpy_s(skill[2].dis, "�G1�̂ɉΑ����̑�_���[�W��^����");
	skill[2].lev = 29;

	strcpy_s(skill[3].name, "�A�C�X�j�[�h��");
	skill[3].mp = 3;
	skill[3].id = 4;
	skill[3].elem = WATER;
	skill[3].mag = 0.7f;
	skill[3].effect = 2;
	strcpy_s(skill[3].dis, "�G�S�̂ɐ������̏��_���[�W��^����");
	skill[3].lev = 8;

	strcpy_s(skill[4].name, "�u���U�[�h");
	skill[4].id = 5;
	skill[4].mp = 8;
	skill[4].elem = WATER;
	skill[4].mag = 1.0f;
	skill[4].effect = 2;
	strcpy_s(skill[4].dis, "�G�S�̂ɐ������̃_���[�W��^����");
	skill[4].lev = 22;

	strcpy_s(skill[5].name, "���C���V���g���[��");
	skill[5].id = 6;
	skill[5].mp = 13;
	skill[5].elem = WATER;
	skill[5].mag = 1.5f;
	skill[5].effect = 2;
	strcpy_s(skill[5].dis, "�G�S�̂ɐ������̒��_���[�W��^����");
	skill[5].lev = 31;

	strcpy_s(skill[6].name, "�E�B���h�A���[");
	skill[6].mp = 5;
	skill[6].id = 7;
	skill[6].elem = WIND;
	skill[6].mag = 1.1f;
	skill[6].effect = 2;
	strcpy_s(skill[6].dis, "�G�S�̂ɕ������̃_���[�W��^����");
	skill[6].lev = 9;


	strcpy_s(skill[7].name, "�X�g�[��");
	skill[7].mp = 11;
	skill[7].id = 8;
	skill[7].elem = WIND;
	skill[7].mag = 1.8f;
	skill[7].effect = 2;
	strcpy_s(skill[7].dis, "�G�S�̂ɕ������̒��_���[�W��^����");
	skill[7].lev = 26;


	strcpy_s(skill[8].name, "�T�C�N����");
	skill[8].mp = 18;
	skill[8].id = 9;
	skill[8].elem = WIND;
	skill[8].mag = 2.3f;
	skill[8].effect = 2;
	strcpy_s(skill[8].dis, "�G�S�̂ɕ������̑�_���[�W��^����");
	skill[8].lev = 37;


	strcpy_s(skill[9].name, "�X�g�[���u���X�g");
	skill[9].mp = 6;
	skill[9].id = 10;
	skill[9].elem = SOIL;
	skill[9].mag = 1.6f;
	skill[9].effect = 2;
	strcpy_s(skill[9].dis, "�G1�̂ɓy�����̒��_���[�W��^����");
	skill[9].lev = 12;


	strcpy_s(skill[10].name, "���b�N�u���C�N");
	skill[10].mp = 10;
	skill[10].id = 11;
	skill[10].elem = SOIL;
	skill[10].mag = 2.2f;
	skill[10].effect = 1;
	strcpy_s(skill[10].dis, "�G1�̂ɓy�����̑�_���[�W��^����");
	skill[10].lev = 24;


	strcpy_s(skill[11].name, "�O�����h�_�b�V���[");
	skill[11].mp = 20;
	skill[11].id = 12;
	skill[11].elem = SOIL;
	skill[11].mag = 3.5f;
	skill[11].effect = 1;
	strcpy_s(skill[11].dis, "�G1�̂ɓy�����̓���_���[�W��^����");
	skill[11].lev = 45;


	strcpy_s(skill[12].name, "���C");
	skill[12].mp = 8;
	skill[12].id = 13;
	skill[12].elem = LIGHT;
	skill[12].mag = 1.4f;
	skill[12].effect = 2;
	strcpy_s(skill[12].dis, "�G�S�̂Ɍ������̃_���[�W��^����");
	skill[12].lev = 14;


	strcpy_s(skill[13].name, "���C�g�N���X");
	skill[13].mp = 12;
	skill[13].id = 14;
	skill[13].elem = LIGHT;
	skill[13].mag = 2.5f;
	skill[13].effect = 1;
	strcpy_s(skill[13].dis, "�G1�̂Ɍ������̑�_���[�W��^����");
	skill[13].lev = 33;


	strcpy_s(skill[14].name, "�X�^�[�t���A");
	skill[14].mp = 25;
	skill[14].id = 15;
	skill[14].elem = LIGHT;
	skill[14].mag = 3.0f;
	skill[14].effect = 2;
	strcpy_s(skill[14].dis, "�G�S�̂Ɍ������̑�_���[�W��^����");
	skill[14].lev = 47;


	strcpy_s(skill[15].name, "�V���h�E�A���[");
	skill[15].mp = 12;
	skill[15].id = 16;
	skill[15].elem = DARK;
	skill[15].mag = 2.5f;
	skill[15].effect = 1;
	strcpy_s(skill[15].dis, "�G1�̂Ɉő����̑�_���[�W��^����");
	skill[15].lev = 27;

	strcpy_s(skill[16].name, "�_�[�N�l�X");
	skill[16].mp = 20;
	skill[16].id = 17;
	skill[16].elem = DARK;
	skill[16].mag = 2.6f;
	skill[16].effect = 2;
	strcpy_s(skill[16].dis, "�G�S�̂Ɉő����̑�_���[�W��^����");
	skill[16].lev = 40;

	strcpy_s(skill[17].name, "�w���Q�[�g");
	skill[17].mp = 32;
	skill[17].id = 18;
	skill[17].elem = DARK;
	skill[17].mag = 3.5f;
	skill[17].effect = 2;
	strcpy_s(skill[17].dis, "�G�S�̂Ɉő����̓���_���[�W��^����");
	skill[17].lev = 55;

	strcpy_s(skill[18].name, "�q�[��");
	skill[18].mp = 2;
	skill[18].id = 19;
	skill[18].elem = NO;
	skill[18].mag = 0;
	skill[18].effect = 3;
	strcpy_s(skill[18].dis, "HP��10�`30�񕜂���");
	skill[18].lev = 2;
	skill[18].max_heal = 30;
	skill[18].min_heal = 10;

	strcpy_s(skill[19].name, "�s�N�V�[�q�[��");
	skill[19].mp = 6;
	skill[19].id = 20;
	skill[19].elem = NO;
	skill[19].mag = 0;
	skill[19].effect = 3;
	strcpy_s(skill[19].dis, "HP��25�`60�񕜂���");
	skill[19].lev = 10;
	skill[19].max_heal = 60;
	skill[19].min_heal = 25;

	strcpy_s(skill[20].name, "�L���A");
	skill[20].mp = 10;
	skill[20].id = 21;
	skill[20].elem = NO;
	skill[20].mag = 0;
	skill[20].effect = 3;
	strcpy_s(skill[20].dis, "HP��80�`120�񕜂���");
	skill[20].lev = 18;
	skill[20].max_heal = 120;
	skill[20].min_heal = 80;

	strcpy_s(skill[21].name, "�t�F�A���[�L���A");
	skill[21].mp = 18;
	skill[21].id = 22;
	skill[21].elem = NO;
	skill[21].mag = 0;
	skill[21].effect = 3;
	strcpy_s(skill[21].dis, "HP��180�`350�񕜂���");
	skill[21].lev = 32;
	skill[21].max_heal = 350;
	skill[21].min_heal = 180;

	strcpy_s(skill[22].name, "���U���N�V����");
	skill[22].mp = 50;
	skill[22].id = 23;
	skill[22].elem = NO;
	skill[22].mag = 0;
	skill[22].effect = 3;
	strcpy_s(skill[22].dis, "HP��S�񕜂���");
	skill[22].lev = 45;
	skill[22].max_heal = 10000;
	skill[22].min_heal = 9999;

	strcpy_s(skill[23].name, "��������");
	skill[23].mp = 0;
	skill[23].id = 24;
	skill[23].elem = NO;
	skill[23].mag = 1;
	skill[23].effect = 1;
	strcpy_s(skill[23].dis, "��������");
	skill[23].lev = 0;
}

float get_rand_mag() {
	return (float)(rand() % 21 + 90) / 100.f;
}

void init() {
	srand(unsigned(time(NULL)));
	disable_cursor();
	init_skill();
}

int sget_cursor(int c, int cursor, int cmax) {
	switch (c)
	{
	case UP:
		cursor -= 3;
		if (cursor < 0) {
			cursor += 3;
		}
		break;
	case DOWN:
		cursor += 3;
		if (cursor > cmax) {
			cursor -= 3;
		}
		break;
	case LEFT:
		cursor--;
		if (cursor % 3 == 2) {
			cursor++;
		}
		break;
	case RIGHT:
		cursor++;
		if (cursor % 3 == 0 || cursor > cmax) {
			cursor--;
		}
		break;
	default:
		break;
	}
	return cursor;
	/*
	1 2 3
	4 5 6
	31119
	41220
	51321
	61422
	71523
	816
	*/
}
