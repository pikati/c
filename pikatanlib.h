//--------------------------------------//
//	pikatanlib.h						//
//	ピカタん							//
//--------------------------------------//

//カーソルの説明
//コンソールのカーソル…その名の通りコンソールで現在の位置を示すカーソル
//out_cursor関数、in_cursor関数でのカーソル…どこの文字列を選択しているかを示す概念

#pragma once

//入力したキーの値
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

/*全画面クリア*/
void clear();

/*コンソールのカーソルを非表示にする*/
void disable_cursor();

/*コンソールのカーソルを表示させる*/
void enable_cursor();

/*矢印キーで操作した時にカーソルから外れた文字列を暗くする*/
void out_cursor();

/*文字列のカーソルの位置を決める 戻り値：更新したカーソルの位置 第1引数：入力した文字 第2引数：変更前のカーソルの位置 第3引数：カーソルの数-1 第4引数：列の数*/
int get_cursor(int c, int cursor, int cmax, int row);

/*文字入力する関数*/
int get_key();

/*矢印キーで操作した時にカーソルが示す文字列を明るくする*/
void in_cursor();

/*入力待ち*/
void wait_key();
