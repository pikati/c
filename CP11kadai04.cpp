//------------------------------//
//	kadai04 ルイーダの酒場		//
//	ピカタん					//
//------------------------------//

//マイナスの値を入力したときにマイナスですよって言いたかったけど面倒そうなので断念

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pikatanlib.h"

//名前の長さ
#define NAME_LEN 22

//属性
#define NO 0
#define FIRE 1
#define WATER 2
#define WIND 3
#define SOIL 4
#define LIGHT 5
#define DARK 6

//性別
#define MALE 0
#define FEMALE 1

bool check_num(char *num);//文字が混じってたらfalse数値のみならtrue
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
	char name[NAME_LEN + 1];//名前
	int hp;//HP
	int mp;//MP
	int atk;//攻撃力
	int def;//防御力
	int matk;//魔法攻撃力
	int mdef;//魔法防御力
	int spd;//素早さ
	int exp;//経験値
	int lev;//レベル
	int elem;//属性
	int sex;//性別
}chara;

chara charactor[4]{
	{
		"1人目", 10, 0, 5, 3, 2, 2, 3, 0, 1, 0, 0
	},
	{
		"2人目", 10, 0, 5, 3, 2, 2, 3, 0, 1, 0, 0
	},
	{
		"3人目", 10, 0, 5, 3, 2, 2, 3, 0, 1, 0, 0
	},
	{
		"4人目", 10, 0, 5, 3, 2, 2, 3, 0, 1, 0, 0
	}
};
chara *p = charactor;

int main() {
	disable_cursor();
	printf("\n\n\t4人パーティだから4人のステータスをセットしてほしいな！");
	wait_key();
	select_charactor();
}

void select_charactor() {

	enum {
		first, second, third, fourth, disp, end
	};

	int cmax = 5;//選択肢の数マイナス1
	int cursor = 0;//カーソルの位置
	int c = 0;//文字

	while (true) {
		clear();

		printf("\n\n\tだれのステータスを変更する？\n\n");
		
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
			printf("\tステータス表示\n\n");
			exit_cursor();
		}
		else {
			printf("\tステータス表示\n\n");
		}
		if (cursor == end) {
			hit_cursor();
			printf("\t終わる\n\n");
			exit_cursor();
		}
		else {
			printf("\t終わる\n\n");
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
	int cursor = 0;//カーソルの位置
	int c = 0;//文字

	while (true) {
		clear();

		printf("\n\n\tどのステータスを変更する？\n\n");

		if (cursor == name) {
			hit_cursor();
			printf("\t名前\t");
			exit_cursor();
		}
		else {
			printf("\t名前\t");
		}
		if (cursor == atk) {
			hit_cursor();
			printf("\t攻撃力　　\t");
			exit_cursor();
		}
		else {
			printf("\t攻撃力　　\t");
		}
		if (cursor == spd) {
			hit_cursor();
			printf("\t素早さ\n\n");
			exit_cursor();
		}
		else {
			printf("\t素早さ\n\n");
		}
		if (cursor == sex) {
			hit_cursor();
			printf("\t性別\t");
			exit_cursor();
		}
		else {
			printf("\t性別\t");
		}
		if (cursor == def) {
			hit_cursor();
			printf("\t防御力　　\t");
			exit_cursor();
		}
		else {
			printf("\t防御力　　\t");
		}
		if (cursor == elem) {
			hit_cursor();
			printf("\t属性\n\n");
			exit_cursor();
		}
		else {
			printf("\t属性\n\n");
		}
		if (cursor == hp) {
			hit_cursor();
			printf("\tHP　\t");
			exit_cursor();
		}
		else {
			printf("\tHP　\t");
		}
		if (cursor == matk) {
			hit_cursor();
			printf("\t魔法攻撃力\t");
			exit_cursor();
		}
		else {
			printf("\t魔法攻撃力\t");
		}
		if (cursor == re) {
			hit_cursor();
			printf("\t戻る\n\n");
			exit_cursor();
		}
		else {
			printf("\t戻る\n\n");
		}
		if (cursor == mp) {
			hit_cursor();
			printf("\tMP　\t");
			exit_cursor();
		}
		else {
			printf("\tMP　\t");
		}
		if (cursor == mdef) {
			hit_cursor();
			printf("\t魔法防御力\n\n");
			exit_cursor();
		}
		else {
			printf("\t魔法防御力\n\n");
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
				printf("%d人目の名前　　　：%-10s", j + 1, (p + j)->name);
			}
			if (i == 1) {
				if ((p + j)->sex == 0) {
					printf("%d人目の性別　　　：男　　　　", j + 1);
				}
				else {
					printf("%d人目の性別　　　：女　　　　", j + 1);
				}
			}
			if (i == 2) {
				printf("%d人目のHP　　　　：%-10d", j + 1, (p + j)->hp);
			}
			if (i == 3) {
				printf("%d人目のMP　　　　：%-10d", j + 1, (p + j)->mp);
			}
			if (i == 4) {
				printf("%d人目の攻撃力　　：%-10d", j + 1, (p + j)->atk);
			}
			if (i == 5) {
				printf("%d人目の防御力　　：%-10d", j + 1, (p + j)->def);
			}
			if (i == 6) {
				printf("%d人目の魔法攻撃力：%-10d", j + 1, (p + j)->matk);
			}
			if (i == 7) {
				printf("%d人目の魔法防御力：%-10d", j + 1, (p + j)->mdef);
			}
			if (i == 8) {
				printf("%d人目の素早さ　　：%-10d", j + 1, (p + j)->spd);
			}
			if (i == 9) {
				printf("%d人目の属性　　　：%-10s", j + 1, get_elem((p + j)->elem));
			}
		}
		printf("\n\n");
	}
	wait_key();
}

void set_name(char *name) {
	clear();

	printf("\n\n\t名前を入力してください（全角10文字以下）\n\n\t");
	printf("名前：");
	enable_cursor();
	scanf_s("%s", name, 22);
	disable_cursor();
}

void set_sex(int *sex) {

	enum {
		male, female
	};

	int cmax = 1;
	int cursor = 0;//カーソルの位置
	int c = 0;//文字

	while (true) {
		clear();

		printf("\n\n\t性別を選択してください\n\n");

		if (cursor == male) {
			hit_cursor();
			printf("\t男\n\n");
			exit_cursor();
		}
		else {
			printf("\t男\n\n");
		}
		if (cursor == female) {
			hit_cursor();
			printf("\t女\n\n");
			exit_cursor();
		}
		else {
			printf("\t女\n\n");
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
		printf("\n\n\tHPを入力してください（1以上999以下）\n\n\t");
		printf("HP：");
		enable_cursor();
		scanf_s("%s", num, 10);
		disable_cursor();
		if (!check_num(num) || atoi(num) == 0) {
			printf("1以上の数値を入力してください");
			flag = false;
			wait_key();
		}
		else if (atoi(num) > 999) {
			printf("HPが999を超えています");
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
		printf("\n\n\tMPを入力してください（0以上999以下）\n\n\t");
		printf("MP：");
		enable_cursor();
		scanf_s("%s", num, 10);
		disable_cursor();
		if (!check_num(num)) {
			printf("0以上の数値を入力してください");
			flag = false;
			wait_key();
		}
		else if (atoi(num) > 999) {
			printf("MPが999を超えています");
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
		printf("\n\n\t攻撃力を入力してください（0以上999以下）\n\n\t");
		printf("攻撃力：");
		enable_cursor();
		scanf_s("%s", num, 10);
		disable_cursor();
		if (!check_num(num)) {
			printf("0以上の数値を入力してください");
			flag = false;
			wait_key();
		}
		else if (atoi(num) > 999) {
			printf("攻撃力が999を超えています");
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
		printf("\n\n\t防御力を入力してください（0以上999以下）\n\n\t");
		printf("防御力：");
		enable_cursor();
		scanf_s("%s", num, 10);
		disable_cursor();
		if (!check_num(num)) {
			printf("0以上の数値を入力してください");
			flag = false;
			wait_key();
		}
		else if (atoi(num) > 999) {
			printf("防御力が999を超えています");
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
		printf("\n\n\t魔法攻撃力を入力してください（0以上999以下）\n\n\t");
		printf("魔法攻撃力：");
		enable_cursor();
		scanf_s("%s", num, 10);
		disable_cursor();
		if (!check_num(num)) {
			printf("0以上の数値を入力してください");
			flag = false;
			wait_key();
		}
		else if (atoi(num) > 999) {
			printf("魔法攻撃力が999を超えています");
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
		printf("\n\n\t魔法防御力を入力してください（0以上999以下）\n\n\t");
		printf("魔法防御力：");
		enable_cursor();
		scanf_s("%s", num, 10);
		disable_cursor();
		if (!check_num(num)) {
			printf("0以上の数値を入力してください");
			flag = false;
			wait_key();
		}
		else if (atoi(num) > 999) {
			printf("魔法防御力が999を超えています");
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
		printf("\n\n\t素早さを入力してください（0以上999以下）\n\n\t");
		printf("素早さ：");
		enable_cursor();
		scanf_s("%s", num, 10);
		disable_cursor();
		if (!check_num(num)) {
			printf("0以上の数値を入力してください");
			flag = false;
			wait_key();
		}
		else if (atoi(num) > 999) {
			printf("素早さが999を超えています");
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
	int cursor = 0;//カーソルの位置
	int c = 0;//文字

	while (true) {
		clear();

		printf("\n\n\t属性を選択してください\n\n");

		if (cursor == NO) {
			hit_cursor();
			printf("\t無\n\n");
			exit_cursor();
		}
		else {
			printf("\t無\n\n");
		}
		if (cursor == FIRE) {
			hit_cursor();
			printf("\t火\n\n");
			exit_cursor();
		}
		else {
			printf("\t火\n\n");
		}
		if (cursor == WATER) {
			hit_cursor();
			printf("\t水\n\n");
			exit_cursor();
		}
		else {
			printf("\t水\n\n");
		}
		if (cursor == WIND) {
			hit_cursor();
			printf("\t風\n\n");
			exit_cursor();
		}
		else {
			printf("\t風\n\n");
		}
		if (cursor == SOIL) {
			hit_cursor();
			printf("\t土\n\n");
			exit_cursor();
		}
		else {
			printf("\t土\n\n");
		}
		if (cursor == LIGHT) {
			hit_cursor();
			printf("\t光\n\n");
			exit_cursor();
		}
		else {
			printf("\t光\n\n");
		}
		if (cursor == DARK) {
			hit_cursor();
			printf("\t闇\n\n");
			exit_cursor();
		}
		else {
			printf("\t闇\n\n");
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
		return "無";
	case FIRE:
		return "火";
	case WATER:
		return "水";
	case WIND:
		return "風";
	case SOIL:
		return "土";
	case RIGHT:
		return "光";
	case DARK:
		return "闇";
	default:
		return "無";
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