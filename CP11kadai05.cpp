//----------------------------------//
//	kadai05 バトルコロシアム light	//
//	ピカタん						//
//----------------------------------//

//戦闘に関しては、前の課題を流用しているのでターゲット選択が表示されるけど気にしないでください

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
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

//物理か魔法かアイテムか防御か（戦闘時のコマンド）
#define STR 1
#define MAGIC 2
#define ITEM 3
#define GARD 4

/*キャラクターの情報が定義されている構造体*/
typedef struct {
	char name[NAME_LEN + 1];//名前
	int mhp;//最大HP
	int hp;//現在HP
	int mmp;//最大MP
	int mp;//現在MP
	int atk;//攻撃力
	int def;//防御力
	int matk;//魔法攻撃力
	int mdef;//魔法防御力
	int spd;//素早さ
	int exp;//経験値
	int lev;//レベル
	int elem;//属性
	int sex;//性別
	int skill[5];
	int id;
}chara;

/*スキルの情報の構造体*/
typedef struct {
	char name[21];//スキルの名前
	int id;//スキルのID
	int mp;//スキルの消費MP
	int elem;//スキルの属性
	float mag;//スキルの倍率
	int effect;//1単体2全体3回復
	char dis[256];//スキルの説明
	int lev;//覚えるレベル
	int max_heal;//スキルの最大回復
	int min_heal;//スキルの最低回復
}Skill;

Skill skill[30];

int sget_cursor(int c, int cursor, int cmax);//スキル用のカーソル移動

/// <summary>
/// 初期化するよ
/// </summary>
void init();

/// <summary>
/// 数字かどうかを判断する関数
/// </summary>
/// <param name="*num">文字</param>
/// <returns>文字があったらfalse 数値のみならtrue</returns>
bool check_num(char *num);

/// <summary>
/// 戦わせる２人を選択
/// </summary>
void chose_charactor();

/// <summary>
/// みんなのステータスを表示するよ
/// </summary>
void disp_status();

/// <summary>
/// 引数に対応した属性を文字で返すよ
/// </summary>
/// <param name="elem">キャラクターの属性とかの値</param>
/// <returns>属性（全角文字）</returns>
const char *get_elem(int elem);

/// <summary>
/// いじるキャラクターを選択する
/// </summary>
void select_charactor();

/// <summary>
/// いじるステータスを選択するよ
/// </summary>
void select_status(int num);

/// <summary>
/// 選択したキャラを戦闘用の変数にぶち込む
/// </summary>
/// <param name="num">構造体で見たキャラクターの順番みたいな</param>
/// <param name="order">1人目か2人目かを判断</param>
void set_charactor(int num, int order);

/// <summary>
/// 名前設定
/// </summary>
/// <param name="*name">変更したいキャラクターのnameのポインタ</param>
void set_name(char *name);

/// <summary>
/// 性別選択
/// </summary>
/// <param name="*name">変更したいキャラクターのsexのポインタ</param>
void set_sex(int *sex);

/// <summary>
/// HP設定
/// </summary>
/// <param name="*name">変更したいキャラクターのhpのポインタ</param>
/// <param name="*name">変更したいキャラクターのmhpのポインタ</param>
void set_hp(int *hp, int *mhp);

/// <summary>
/// MP設定
/// </summary>
/// <param name="*name">変更したいキャラクターのmpのポインタ</param>
/// <param name="*name">変更したいキャラクターのmmpのポインタ</param>
void set_mp(int *mp, int *mmp);

/// <summary>
/// 攻撃設定
/// </summary>
/// <param name="*name">変更したいキャラクターのatkのポインタ</param>
void set_atk(int *atk);

/// <summary>
/// 防御設定
/// </summary>
/// <param name="*name">変更したいキャラクターのdefのポインタ</param>
void set_def(int *def);

/// <summary>
/// 魔法攻撃設定
/// </summary>
/// <param name="*name">変更したいキャラクターのmatkのポインタ</param>
void set_matk(int *matk);

/// <summary>
/// 魔法防御設定
/// </summary>
/// <param name="*name">変更したいキャラクターのmdefのポインタ</param>
void set_mdef(int *mdef);

/// <summary>
/// 素早さ設定
/// </summary>
/// <param name="*name">変更したいキャラクターのspdのポインタ</param>
void set_spd(int *spd);

/// <summary>
/// 属性選択
/// </summary>
/// <param name="*name">変更したいキャラクターのelemのポインタ</param>
void set_elem(int *elem);

/// <summary>
/// スキル選択選択
/// </summary>
/// <param name="*name">変更したいキャラクターの場所（1人目なら0 2人目なら1です）</param>
void set_skill(int num);

/*-------------------以下戦闘関係のプロトタイプ宣言---------------------*/

/// <summary>
/// 戦闘関係の関数を呼び出す関数だよ
/// </summary>
void battle_mgr();

/// <summary>
/// 戦闘しているキャラの名前やHPなどを表示するよ
/// </summary>
/// <param name="enenum">敵の数</param>
void draw_battle(int enenum);

/// <summary>
/// 各キャラの攻撃方法を決めるよ
/// </summary>
/// <param name="*a">攻撃方法を決めたいキャラの構造体ポインタ</param>
/// <returns>キャラクターのスキルのIDのどれか</returns>
int decide_attack_type(chara *a);

/// <summary>
/// ばらつかせるための倍率を返すよ
/// </summary>
/// <returns>0.9～1.1</returns>
float get_rand_mag();

/// <summary>
/// 攻撃する相手を選択するよ（今回は自動）
/// </summary>
/// <param name="nennum">敵の数</param>
/// <param name="skill_id">使おうとしているスキルのID</param>
void select_target(int enenum, int skill_id);

/// <summary>
/// 攻撃する順番を決めるよ
/// </summary>
/// <param name="target">攻撃対象の敵の値（戦闘は0）</param>
/// <param name="enenum">敵の数</param>
/// <param name="s_or_i">物理か魔法か</param>
/// <param name="skill_id">使おうとしているスキルのID</param>
void order_of_attack(int target, int enenum, int s_or_i, int skill_id);

/// <summary>
/// 敵の攻撃だよ
/// </summary>
/// <param name="id">敵のID</param>
/// <param name="enenum">敵の数</param>
void enemy_turn(int id, int enenum);

/// /// <summary>
/// ダメージを計算してHPを減らしてそれを表示するよ
/// </summary>
/// <param name="atacker">攻撃する人の数値（0なら味方1なら敵）</param>
/// <param name="target">攻撃される人の値（配列の添え字的な）</param>
/// <param name="s_or_i">物理か魔法か</param>
/// <param name="elem">スキルの属性</param>
/// <param name="range">get_rand_mag関数の値</param>
/// <param name="mag">スキルの倍率</param>
/// <param name="skill_id">スキルのID</param>
/// <param name="enenum">敵の数</param>
void damage(int atacker, int target, int s_or_i, int elem, float range, float mag, int skill_id, int enenum);


/*---グローバル変数定義---*/
chara charactor[4]{
	{
		"1人目", 18, 18, 0, 0, 12, 8, 2, 2, 1, 0, 1, 0, 0, {24,24,24,24,24}, 1
	},
	{
		"2人目", 12, 12, 0, 0, 15, 8, 2, 2, 4, 0, 1, 0, 0, {24,24,24,24,24}, 2
	},
	{
		"3人目", 22, 22, 0, 0, 12, 5, 2, 2, 2, 0, 1, 0, 0, {24,24,24,24,24}, 3
	},
	{
		"4人目", 16, 16, 0, 0, 13, 10, 2, 2, 3, 0, 1, 0, 0, {24,24,24,24,24}, 4
	}
};
chara *p = charactor;
chara *party;
chara *e;
int timer = 1000;

int main() {
	init();
	printf("\n\n\t4人パーティだから4人のステータスをセットしてほしいな！");
	wait_key();
	select_charactor();
}

void select_charactor() {

	/*1人目、2人目、3人目、4人目、表示、戦闘、終わるの数値*/
	enum {
		first, second, third, fourth, disp, next, end
	};

	int cmax = 6;//選択肢の数マイナス1
	int cursor = 0;//カーソルの位置
	int c = 0;//文字

	while (true) {
		clear();

		printf("\n\n\tだれのステータスを変更する？\n\n");

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
			printf("\tステータス表示\n\n");
			out_cursor();
		}
		else {
			printf("\tステータス表示\n\n");
		}
		if (cursor == next) {
			in_cursor();
			printf("\t戦う2人を選ぶ\n\n");
			out_cursor();
		}
		else {
			printf("\t戦う2人を選ぶ\n\n");
		}
		if (cursor == end) {
			in_cursor();
			printf("\t終わる\n\n");
			out_cursor();
		}
		else {
			printf("\t終わる\n\n");
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
	int cursor = 0;//カーソルの位置
	int c = 0;//文字

	while (true) {
		clear();

		printf("\n\n\tどのステータスを変更する？\n\n");

		if (cursor == name) {
			in_cursor();
			printf("\t名前\t");
			out_cursor();
		}
		else {
			printf("\t名前\t");
		}
		if (cursor == atk) {
			in_cursor();
			printf("\t攻撃力　　\t");
			out_cursor();
		}
		else {
			printf("\t攻撃力　　\t");
		}
		if (cursor == spd) {
			in_cursor();
			printf("\t素早さ\n\n");
			out_cursor();
		}
		else {
			printf("\t素早さ\n\n");
		}
		if (cursor == sex) {
			in_cursor();
			printf("\t性別\t");
			out_cursor();
		}
		else {
			printf("\t性別\t");
		}
		if (cursor == def) {
			in_cursor();
			printf("\t防御力　　\t");
			out_cursor();
		}
		else {
			printf("\t防御力　　\t");
		}
		if (cursor == elem) {
			in_cursor();
			printf("\t属性\n\n");
			out_cursor();
		}
		else {
			printf("\t属性\n\n");
		}
		if (cursor == hp) {
			in_cursor();
			printf("\tHP　\t");
			out_cursor();
		}
		else {
			printf("\tHP　\t");
		}
		if (cursor == matk) {
			in_cursor();
			printf("\t魔法攻撃力\t");
			out_cursor();
		}
		else {
			printf("\t魔法攻撃力\t");
		}
		if (cursor == skill) {
			in_cursor();
			printf("\tスキル設定\n\n");
			out_cursor();
		}
		else {
			printf("\tスキル設定\n\n");
		}
		if (cursor == mp) {
			in_cursor();
			printf("\tMP　\t");
			out_cursor();
		}
		else {
			printf("\tMP　\t");
		}
		if (cursor == mdef) {
			in_cursor();
			printf("\t魔法防御力\t");
			out_cursor();
		}
		else {
			printf("\t魔法防御力\t");
		}
		if (cursor == re) {
			in_cursor();
			printf("\t戻る\n\n");
			out_cursor();
		}
		else {
			printf("\t戻る\n\n");
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
			in_cursor();
			printf("\t男\n\n");
			out_cursor();
		}
		else {
			printf("\t男\n\n");
		}
		if (cursor == female) {
			in_cursor();
			printf("\t女\n\n");
			out_cursor();
		}
		else {
			printf("\t女\n\n");
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
			*mhp = *hp = atoi(num);
		}

	} while (!flag);

}

void set_mp(int *mp, int *mmp) {

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
			*mmp = *mp = atoi(num);
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
			in_cursor();
			printf("\t無\n\n");
			out_cursor();
		}
		else {
			printf("\t無\n\n");
		}
		if (cursor == FIRE) {
			in_cursor();
			printf("\t火\n\n");
			out_cursor();
		}
		else {
			printf("\t火\n\n");
		}
		if (cursor == WATER) {
			in_cursor();
			printf("\t水\n\n");
			out_cursor();
		}
		else {
			printf("\t水\n\n");
		}
		if (cursor == WIND) {
			in_cursor();
			printf("\t風\n\n");
			out_cursor();
		}
		else {
			printf("\t風\n\n");
		}
		if (cursor == SOIL) {
			in_cursor();
			printf("\t土\n\n");
			out_cursor();
		}
		else {
			printf("\t土\n\n");
		}
		if (cursor == LIGHT) {
			in_cursor();
			printf("\t光\n\n");
			out_cursor();
		}
		else {
			printf("\t光\n\n");
		}
		if (cursor == DARK) {
			in_cursor();
			printf("\t闇\n\n");
			out_cursor();
		}
		else {
			printf("\t闇\n\n");
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
	int cursor = 0;//カーソルの位置
	int c = 0;//文字
	int select_skill = 0;//何番目のスキルを変更しようとしていか
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
				printf("%-20s", "戻る");
			}
			else if (i == 24) {
				printf("%-20s", "決定！");
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
			printf("\n\t消費MP:%3d\n", skill[cursor].mp);
		}
		else {
			printf("\n\n\n\n");
		}
		
		printf("\n\n\tスキル1：%-25sスキル2：%-25s", skill[skill_num[0]].name, skill[skill_num[1]].name);
		printf("\n\n\tスキル3：%-25sスキル4：%-25s", skill[skill_num[2]].name, skill[skill_num[3]].name);
	
		c = get_key();
		cursor = sget_cursor(c, cursor, cmax);

		switch (c)
		{
		case ENTER:
			//戻るを選択したとき
			if (cursor == 23) {
				if (select_skill == 0) {
					return;
				}
				else{
					select_skill--;
					skill_num[select_skill] = 24;
				}
			}
			//決定！を選択したとき
			else if (cursor == 24) {
				for (int i = 0; i < 4; i++) {
					(p + n)->skill[i + 1] = skill[skill_num[i]].id;
				}
				return;
			}
			//スキルを選択したとき
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

	for (i = 0; (unsigned)i < strlen(num); i++) {
		if (!isdigit(num[i])) {
			return false;
		}
	}
	return true;
}

void chose_charactor() {
	
	int chose_num = 0;//1人選ぶと1、2人選ぶと2になる->人数管理用変数
	int cmax = 5;//選択肢の数マイナス1
	int cursor = 0;//カーソルの位置
	int c = 0;//文字
	char name1[NAME_LEN + 1] = "";
	char name2[NAME_LEN + 1] = "";
	bool b_name1 = true;
	bool b_name2 = true;

	enum {
		first, second, third, fourth, battle, re,
	};
	
	while (true) {
		clear();

		/*選択肢*/
		if (chose_num == 0 || chose_num == 1) {
			printf("\n\n\t戦わせる%d人目を選択してください\n\n", chose_num + 1);
		}
		else {
			printf("\n\n\t問題なかったら戦闘開始！\n\n");
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
			printf("\t戦闘開始！\n\n");
			out_cursor();
		}
		else {
			printf("\t戦闘開始！\n\n");
		}
		if (cursor == re) {
			in_cursor();
			printf("\t戻る\n\n");
			out_cursor();
		}
		else {
			printf("\t戻る\n\n");
		}

		printf("\n\t1人目:%s\n\n", name1);
		printf("\n\t2人目:%s\n\n", name2);


		c = get_key();
		cursor = get_cursor(c, cursor, cmax, 0);
		if (c == ENTER) {
			/*戻るを選択したときにchose_numの値に応じて設定した名前を消す（データは消していないけど上書きするのでよし）*/
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
			/*戦闘開始！を選択したときに２人選択しているなら先頭に移動そうでないなら入力を促す*/
			else if (cursor == battle) {
				if (chose_num == 2) {
					battle_mgr();
				}
				else {
					printf("\t２人選択してから戦闘開始してね！！！");
					wait_key();
				}
			}
			/*名前を選択したときに条件を満たしていれば情報をセット*/
			else {
				/*表示している名前と選択したキャラの名前が一致していたらfalseにする、そうでないならtrueにする*/
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
				/*名前のフラグがtrueならキャラの情報をセットし、表示する名前をセットする、そうでないなら再入力を促す*/
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
					printf("\t同じ人は選べないよ！");
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
	return a->skill[rand() % 5];//乱数でskillの場所を決めてその値を返す
}

void battle_mgr() {
	draw_battle(1);
}

void draw_battle(int enenum) {
	int cmax = 4;
	int cursor = 0;//カーソルの位置
	int c = 0;//文字
	//int result[2] = { 0, 0 };//経験値とお金
	//int levup_exp = 0;
	//bool is_esc = false;

	enum s {
		attack,//こうげき
		defence,//ぼうぎょ
		escape,//にげる
		spell,//じゅもん
		tool,//どうぐ
	};

	while (true) {
		//clear();
		printf("\n");
		printf("\t ＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿\n");//全角30＋半角スペース1
		printf("\t｜%-15s%-15s                            ", party->name, e->name);
		printf("｜\n");
		printf("\t｜HP %3d/%3d     HP %3d/%3d                                 ", party->hp, party->mhp, e->hp, e->mhp);
		printf("｜\n");
		printf("\t｜MP %3d/%3d     MP %3d/%3d                                 ", party->mp, party->mmp, e->mp, e->mmp);
		printf("｜\n");
		printf("\t ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣");
		printf("\n\n\n\n\n\n\n\n\n\n");

		select_target(1, decide_attack_type(party));

		/*if (cursor == attack) {
			in_cursor();
			printf("\tこうげき");
			out_cursor();
		}
		else {
			printf("\tこうげき");
		}

		if (cursor == spell) {
			in_cursor();
			printf("\tじゅもん\n\n");
			out_cursor();
		}
		else {
			printf("\tじゅもん\n\n");
		}

		if (cursor == defence) {
			in_cursor();
			printf("\tぼうぎょ");
			out_cursor();
		}
		else {
			printf("\tぼうぎょ");
		}

		if (cursor == tool) {
			in_cursor();
			printf("\tどうぐ\n\n");
			out_cursor();
		}
		else {
			printf("\tどうぐ\n\n");
		}

		if (cursor == escape) {
			in_cursor();
			printf("\tにげる");
			out_cursor();
		}
		else {
			printf("\tにげる");
		}*/

		//敵のステータス表示機能
		/*for (int k = 0; k < enenum;k++) {
			printf("\n\n名前:%s\nHP%3d/%3d  MP%3d/%3d", e[k].name, e[k].hp, e[k].mhp, e[k].mp, e[k].mmp);
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
			printf("\n\n\t%sは死んでしまった！", party->name);
			wait_key();
			exit(EXIT_SUCCESS);
		}
		if (e->hp <= 0) {
			printf("\n\n\t%sは死んでしまった！", e->name);
			wait_key();
			exit(EXIT_SUCCESS);
		}
	}
}

void select_target(int enenum, int skill_id) {
	int cursor = 0;//カーソルの位置
	int c = 0;//文字
	while (true) {
		//clear();

		//攻撃するターゲットを選択するよ
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
		//選択した敵をスキルに応じて攻撃するよ
			for (int n = 0; n <= enenum; n++) {
				//if (cursor == n) {
				//攻撃の場合
					if (skill_id == 24) {
						order_of_attack(n, enenum, STR, skill_id);
					}
					//魔法の場合
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
	int order[6] = { -1, -1, -1, -1, -1, -1 };//攻撃順が入りますindexが若いほど速い
	int spd_order[6] = { -1, -1, -1, -1, -1, -1 };//すばやさの高い順になるやつ
	int i, j, temp;

	spd_order[0] = party->spd;
	for (i = 0; i < enenum; i++) {
		spd_order[i + 1] = e[i].spd;
	}

	//降順そーと
	for (i = 0; i < enenum; i++) {
		for (j = enenum; j > i; j--) {
			if (spd_order[j - 1] < spd_order[j]) {
				temp = spd_order[j - 1];
				spd_order[j - 1] = spd_order[j];
				spd_order[j] = temp;
			}
		}
	}

	//素早さの順に、orderにIDを入れるよ
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

	//敵か味方の攻撃を決めるよ
	for (i = 0; i < enenum + 1; i++) {//敵の数＋味方の数だけ繰り返す
		//味方の攻撃の場合
		if (order[i] == party->id) {
			//アイテムの時
			if (s_or_i == ITEM) {
				//use_item(target, skill_id);
			}
			//防御の時
			else if (s_or_i == GARD) {
				damage(0, -1, -1, -1, -1, 0.25, -1, enenum);
			}
			//攻撃の時
			else {
				damage(0, target, s_or_i, skill[skill_id - 1].elem, get_rand_mag(), skill[skill_id - 1].mag, skill_id, enenum);
			}
		}
		//敵の攻撃の時
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

		//プレイヤーのHPが0になった時
		if (party->hp == 0) {
			//orderに代入した要素の数だけ繰り返す
			for (j = 0; j < enenum + 1; j++) {
				//orderの中にプレイヤーのIDが見つかったら
				if (order[j] == party->id) {
					//プレイヤーのIDを削除する
					order[j] = -1;
					//順番変わるからソートしよう
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
		//毎回敵の数だけ繰り返す
		for (j = 0; j < enenum; j++) {
			//どっかの敵のHPが0になったら
			if ((e + j)->hp == 0) {
				//orderに代入した要素の数だけ繰り返す
				for (int k = 0; k < enenum + 1; k++) {
					//HPが0になった敵のIDが見つかったら
					if (order[k] == (e + j)->id) {
						//HPが0の敵のIDを削除する
						order[j] = -1;
						spd_order[j] = -1;
						//順番変わるからソートしよう
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
	printf("\n\n\t%sのこうげき！", (e + (id - 2))->name);
	//Sleep(timer);
	int ene_skill_num;//敵の持っているスキルの何番目を使うかを格納する変数

	ene_skill_num = decide_attack_type(e);


	//ここめんどくさくなかったらスキルに物理か魔法かを入れるメンバを追加して一個の関数で済ますようにするとスマートだよ
	if (ene_skill_num == 24) {
		damage(1, 0, STR, skill[ene_skill_num - 1].elem, get_rand_mag(), skill[ene_skill_num - 1].mag, ene_skill_num, enenum);
	}
	else {
		damage(1, 0, MAGIC, skill[ene_skill_num - 1].elem, get_rand_mag(), skill[ene_skill_num - 1].mag, ene_skill_num, enenum);
	}

	//敵の属性付きの通常攻撃ができたら有効にしようね
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
		"火", "水", "風", "土", "光", "闇"
	};

	/*if (is_gard) {
		mag *= 0.25f;
	}*/

	//味方の攻撃の時
	//clear();

	if (atacker == 0) {
		//clear();
		printf("\n\n\t%sのこうげき！", party->name);
		//if (skill_id == -1) {
		//	printf("\n\n\tぼうぎょした！");
		//	//Sleep(timer);
		//	//clear();
		//	return;
		//}
		if (skill_id != 24) {
			if (party->mp < skill[skill_id - 1].mp) {
				printf("\n\n\tMPが足りない！");
			}
			else {
				printf("\n\n\t%sは%sをとなえた！", party->name, skill[skill_id - 1].name);
				party->mp -= skill[skill_id - 1].mp;
			}
		}
		//Sleep(timer);
		//clear();
		
		//単体攻撃の時
		if (skill[skill_id - 1].effect == 1) {

			//属性によって倍率を決める
			if ((e + target)->elem == FIRE && elem == WATER || (e + target)->elem == WATER && elem == SOIL || (e + target)->elem == SOIL && elem == WIND ||
				(e + target)->elem == WIND && elem == FIRE || (e + target)->elem == LIGHT && elem == DARK || (e + target)->elem == DARK && elem == LIGHT) {
				bairitu[0] = 1.5;
			}
			if ((e + target)->elem == WATER && elem == FIRE || (e + target)->elem == SOIL && elem == WATER || (e + target)->elem == WIND && elem == SOIL ||
				(e + target)->elem == FIRE && elem == WIND) {
				bairitu[0] = 0.5;
			}

			//ダメージの計算と
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
			//HP減少
			(e + target)->hp -= damage;
			if ((e + target)->hp <= 0) {
				(e + target)->hp = 0;
			}

			printf("\n\n\t%sに%dのダメージを与えた！", (e + target)->name, damage);

			if (bairitu[0] == 1.5) {
				//Sleep(timer);
				printf("\n\n\t%sは%s属性の攻撃に弱いみたいだ！", (e + target)->name, element[elem - 1]);
			}
			else if (bairitu[0] == 0.5) {
				//Sleep(timer);
				printf("\n\n\t%sには%s属性の攻撃は効きにくいみたいだ…！", (e + target)->name, element[elem - 1]);
			}
		}

		//複数こうげきのとき
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
				printf("\n\n\t%sに%dのダメージを与えた！", e[i].name, damage);

				if (bairitu[i] == 1.5f) {
					//Sleep(timer);
					printf("\n\n\t%sは%s属性の攻撃に弱いみたいだ！", e[i].name, element[elem - 1]);
				}
				else if (bairitu[i] == 0.5f) {
					//Sleep(timer);
					printf("\n\n\t%sには%s属性の攻撃は効きにくいみたいだ…！", e[i].name, element[elem - 1]);
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
			printf("\n\n\tHPが%d回復した！", heal);
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
			printf("\n\n\t%sは%sをとなえた！", (e + target)->name, skill[skill_id - 1].name);
			//Sleep(timer);
			if ((e + target)->mp < skill[skill_id - 1].mp) {
				printf("\n\n\t失敗wwww");
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
			printf("\n\n\t%sはHPが%d回復した！", e[minhp_id - 1].name, heal);
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

			printf("\n\n\t%sは%dのダメージを受けた!", party->name, damage);
		}
		//Sleep(timer);
	}
	//clear();
	printf("\n");
}

void init_skill() {
	strcpy_s(skill[0].name, "フレイムシュート");
	skill[0].id = 1;
	skill[0].mp = 1;
	skill[0].elem = FIRE;
	skill[0].mag = 1.2f;
	skill[0].effect = 1;
	strcpy_s(skill[0].dis, "敵1体に火属性のダメージを与える");
	skill[0].lev = 4;

	strcpy_s(skill[1].name, "ファイアストーム");
	skill[1].id = 2;
	skill[1].mp = 6;
	skill[1].elem = FIRE;
	skill[1].mag = 1.8f;
	skill[1].effect = 1;
	strcpy_s(skill[1].dis, "敵1体に火属性の中ダメージを与える");
	skill[1].lev = 17;

	strcpy_s(skill[2].name, "ヴォルカニックケージ");
	skill[2].id = 3;
	skill[2].mp = 9;
	skill[2].elem = FIRE;
	skill[2].mag = 2.2f;
	skill[2].effect = 1;
	strcpy_s(skill[2].dis, "敵1体に火属性の大ダメージを与える");
	skill[2].lev = 29;

	strcpy_s(skill[3].name, "アイスニードル");
	skill[3].mp = 3;
	skill[3].id = 4;
	skill[3].elem = WATER;
	skill[3].mag = 0.7f;
	skill[3].effect = 2;
	strcpy_s(skill[3].dis, "敵全体に水属性の小ダメージを与える");
	skill[3].lev = 8;

	strcpy_s(skill[4].name, "ブリザード");
	skill[4].id = 5;
	skill[4].mp = 8;
	skill[4].elem = WATER;
	skill[4].mag = 1.0f;
	skill[4].effect = 2;
	strcpy_s(skill[4].dis, "敵全体に水属性のダメージを与える");
	skill[4].lev = 22;

	strcpy_s(skill[5].name, "メイルシュトローム");
	skill[5].id = 6;
	skill[5].mp = 13;
	skill[5].elem = WATER;
	skill[5].mag = 1.5f;
	skill[5].effect = 2;
	strcpy_s(skill[5].dis, "敵全体に水属性の中ダメージを与える");
	skill[5].lev = 31;

	strcpy_s(skill[6].name, "ウィンドアロー");
	skill[6].mp = 5;
	skill[6].id = 7;
	skill[6].elem = WIND;
	skill[6].mag = 1.1f;
	skill[6].effect = 2;
	strcpy_s(skill[6].dis, "敵全体に風属性のダメージを与える");
	skill[6].lev = 9;


	strcpy_s(skill[7].name, "ストーム");
	skill[7].mp = 11;
	skill[7].id = 8;
	skill[7].elem = WIND;
	skill[7].mag = 1.8f;
	skill[7].effect = 2;
	strcpy_s(skill[7].dis, "敵全体に風属性の中ダメージを与える");
	skill[7].lev = 26;


	strcpy_s(skill[8].name, "サイクロン");
	skill[8].mp = 18;
	skill[8].id = 9;
	skill[8].elem = WIND;
	skill[8].mag = 2.3f;
	skill[8].effect = 2;
	strcpy_s(skill[8].dis, "敵全体に風属性の大ダメージを与える");
	skill[8].lev = 37;


	strcpy_s(skill[9].name, "ストーンブラスト");
	skill[9].mp = 6;
	skill[9].id = 10;
	skill[9].elem = SOIL;
	skill[9].mag = 1.6f;
	skill[9].effect = 2;
	strcpy_s(skill[9].dis, "敵1体に土属性の中ダメージを与える");
	skill[9].lev = 12;


	strcpy_s(skill[10].name, "ロックブレイク");
	skill[10].mp = 10;
	skill[10].id = 11;
	skill[10].elem = SOIL;
	skill[10].mag = 2.2f;
	skill[10].effect = 1;
	strcpy_s(skill[10].dis, "敵1体に土属性の大ダメージを与える");
	skill[10].lev = 24;


	strcpy_s(skill[11].name, "グランドダッシャー");
	skill[11].mp = 20;
	skill[11].id = 12;
	skill[11].elem = SOIL;
	skill[11].mag = 3.5f;
	skill[11].effect = 1;
	strcpy_s(skill[11].dis, "敵1体に土属性の特大ダメージを与える");
	skill[11].lev = 45;


	strcpy_s(skill[12].name, "レイ");
	skill[12].mp = 8;
	skill[12].id = 13;
	skill[12].elem = LIGHT;
	skill[12].mag = 1.4f;
	skill[12].effect = 2;
	strcpy_s(skill[12].dis, "敵全体に光属性のダメージを与える");
	skill[12].lev = 14;


	strcpy_s(skill[13].name, "ライトクロス");
	skill[13].mp = 12;
	skill[13].id = 14;
	skill[13].elem = LIGHT;
	skill[13].mag = 2.5f;
	skill[13].effect = 1;
	strcpy_s(skill[13].dis, "敵1体に光属性の大ダメージを与える");
	skill[13].lev = 33;


	strcpy_s(skill[14].name, "スターフレア");
	skill[14].mp = 25;
	skill[14].id = 15;
	skill[14].elem = LIGHT;
	skill[14].mag = 3.0f;
	skill[14].effect = 2;
	strcpy_s(skill[14].dis, "敵全体に光属性の大ダメージを与える");
	skill[14].lev = 47;


	strcpy_s(skill[15].name, "シャドウアロー");
	skill[15].mp = 12;
	skill[15].id = 16;
	skill[15].elem = DARK;
	skill[15].mag = 2.5f;
	skill[15].effect = 1;
	strcpy_s(skill[15].dis, "敵1体に闇属性の大ダメージを与える");
	skill[15].lev = 27;

	strcpy_s(skill[16].name, "ダークネス");
	skill[16].mp = 20;
	skill[16].id = 17;
	skill[16].elem = DARK;
	skill[16].mag = 2.6f;
	skill[16].effect = 2;
	strcpy_s(skill[16].dis, "敵全体に闇属性の大ダメージを与える");
	skill[16].lev = 40;

	strcpy_s(skill[17].name, "ヘルゲート");
	skill[17].mp = 32;
	skill[17].id = 18;
	skill[17].elem = DARK;
	skill[17].mag = 3.5f;
	skill[17].effect = 2;
	strcpy_s(skill[17].dis, "敵全体に闇属性の特大ダメージを与える");
	skill[17].lev = 55;

	strcpy_s(skill[18].name, "ヒール");
	skill[18].mp = 2;
	skill[18].id = 19;
	skill[18].elem = NO;
	skill[18].mag = 0;
	skill[18].effect = 3;
	strcpy_s(skill[18].dis, "HPを10～30回復する");
	skill[18].lev = 2;
	skill[18].max_heal = 30;
	skill[18].min_heal = 10;

	strcpy_s(skill[19].name, "ピクシーヒール");
	skill[19].mp = 6;
	skill[19].id = 20;
	skill[19].elem = NO;
	skill[19].mag = 0;
	skill[19].effect = 3;
	strcpy_s(skill[19].dis, "HPを25～60回復する");
	skill[19].lev = 10;
	skill[19].max_heal = 60;
	skill[19].min_heal = 25;

	strcpy_s(skill[20].name, "キュア");
	skill[20].mp = 10;
	skill[20].id = 21;
	skill[20].elem = NO;
	skill[20].mag = 0;
	skill[20].effect = 3;
	strcpy_s(skill[20].dis, "HPを80～120回復する");
	skill[20].lev = 18;
	skill[20].max_heal = 120;
	skill[20].min_heal = 80;

	strcpy_s(skill[21].name, "フェアリーキュア");
	skill[21].mp = 18;
	skill[21].id = 22;
	skill[21].elem = NO;
	skill[21].mag = 0;
	skill[21].effect = 3;
	strcpy_s(skill[21].dis, "HPを180～350回復する");
	skill[21].lev = 32;
	skill[21].max_heal = 350;
	skill[21].min_heal = 180;

	strcpy_s(skill[22].name, "リザレクション");
	skill[22].mp = 50;
	skill[22].id = 23;
	skill[22].elem = NO;
	skill[22].mag = 0;
	skill[22].effect = 3;
	strcpy_s(skill[22].dis, "HPを全回復する");
	skill[22].lev = 45;
	skill[22].max_heal = 10000;
	skill[22].min_heal = 9999;

	strcpy_s(skill[23].name, "こうげき");
	skill[23].mp = 0;
	skill[23].id = 24;
	skill[23].elem = NO;
	skill[23].mag = 1;
	skill[23].effect = 1;
	strcpy_s(skill[23].dis, "こうげき");
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
