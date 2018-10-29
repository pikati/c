#include <stdio.h>
#include <windows.h>
#include <math.h>

void select_figure();
void square();
void rectangle();
void triangle();
void diamond();
void triangle();
void triangleReverse();
void house();
void roof(int);
void wall(int);
void abalone();
void init();

int main() {
	//init();
	select_figure();
	
	return 0;
}

void select_figure() {
	int select;

	while (true) {
		puts("描画する図形を選んでください");
		puts("正方形:1　長方形:2　三角形:3　逆さの三角形:4　ひし形:5　家:6　あわび:7　終了:0");
		scanf_s("%d", &select);
		puts("");
		switch (select)
		{
		case 0:
			return;
		case 1:
			square();
			break;
		case 2:
			rectangle();
			break;
		case 3:
			triangle();
			break;
		case 4:
			triangleReverse();
			break;
		case 5:
			diamond();
			break;
		case 6:
			house();
			break;
		case 7:
			abalone();
			break;
		default:
			break;
		}
		puts("");
	}
}

void square() {
	int height;
	int max;
	int i;

	puts("1辺の長さを入力してください");
	scanf_s("%d", &max);
	max += 2;

	for (height = 0; height < max - 1; height++) {
		//一番上の段
		for (; height == 0;) {
			printf(" ");
			for (i = 0; i < max - 2; i++) {
				printf("＿");
			}
			printf(" ");
			break;
		}
		//上と下以外の段
		for (; !(height == 0 || height == max - 2);) {
			printf("|");
			for (i = 0; i < max - 2; i++) {
				printf("　");
			}
			printf("|");
			break;
		}
		//一番下の段
		for (; height == max - 2;) {
			printf("|");
			for (i = 0; i < max - 2; i++) {
				printf("＿");
			}
			printf("|");
			break;
		}
		puts("");
	}
}

void rectangle() {
	int height;
	int maxH;
	int maxW;
	int i;

	puts("縦と横の長さを入力してください");
	printf("縦の長さ:");
	scanf_s("%d", &maxH);
	printf("横の長さ:");
	scanf_s("%d", &maxW);

	maxH += 2;
	maxW += 2;

	for (height = 0; height < maxH - 1; height++) {
		//一番上の段
		for (; height == 0;) {
			printf(" ");
			for (i = 0; i < maxW - 2; i++) {
				printf("＿");
			}
			printf(" ");
			break;
		}
		//上と下以外の段
		for (; !(height == 0 || height == maxH - 2);) {
			printf("|");
			for (i = 0; i < maxW - 2; i++) {
				printf("　");
			}
			printf("|");
			break;
		}
		//一番下の段
		for (; height == maxH - 2;) {
			printf("|");
			for (i = 0; i < maxW - 2; i++) {
				printf("＿");
			}
			printf("|");
			break;
		}

		
		puts("");
	}
}

void triangle() {
	int i;
	int j;
	int height;
	int center;

	puts("段数（高さ）を入力してください");
	scanf_s("%d", &height);

	center = height - 2;

	for (i = 0; i < height; i++) {
		for (j = i; j <= center; j++) {
			printf("　");
		}
		printf("／");
		j = 0;
		for (; i == height - 1; i++) {
			j = i * 2;
		}
		for (; i == height; i--);
		for (; j < i * 2; j++) {
			printf("　");
		}
		for (; i == height - 1; i++) {
			j = 0;
		}
		for (; i == height; i--);
		for (; j < i * 2; j++) {
			for (; i < height - 1;) {
				printf("＼");
				break;
			}
			for (; i < height;) {
				printf("＿");
				break;
			}
		}
		printf("＼");
		puts("");
	}
}

void triangleReverse() {
	int i;
	int j;
	int height;
	int center;

	puts("段数（高さ）を入力してください");
	scanf_s("%d", &height);

	center = height - 2;

	for (i = height - 1; i >= 0; i--) {
		for (j = i; j <= center; j++) {
			printf("　");
		}
		printf("＊");
		j = 0;
		for (; i == height - 1; i++) {
			j = i * 2 - 1;
		}
		for (; i == height; i--);
		for (; j < i * 2 - 1; j++) {
			printf("　");
		}
		for (; i == height - 1; i++) {
			j = 0;
		}
		for (; i == height; i--);
		for (; j < i * 2; j++) {
			printf("＊");
		}
		puts("");
	}
}

void diamond() {
	int max;
	int odd_number;
	int print_number;
	int space_number;
	int i;
	int j;

	puts("ひし形の大きさを入力してください");
	scanf_s("%d", &max);

	odd_number = max % 2;
	print_number = 2 - odd_number;

	for (i = 0; i < max / 2 + odd_number; i++) {

		space_number = (max - print_number) / 2;

		for (j = 0; j < space_number; j++) {
			printf("　");
		}

		for (j = 0; j < print_number; j++) {
			printf("＊");
		}
		print_number += 2;
		printf("\n");
	}

	print_number -= 2 * (odd_number + 1);

	for (i = 0; i < max / 2; i++) {

		space_number = (max - print_number) / 2;

		for (j = 0; j < space_number; j++) {
			printf("　");
		}

		for (j = 0; j < print_number; j++) {
			printf("＊");
		}
		print_number -= 2;
		printf("\n");
	}
}

void house() {
	int max;

	puts("家の大きさを入力してください（5以上だとドアが付きますよ）");
	scanf_s("%d", &max);
	roof(max);
	wall(max);
}

void roof(int m) {
	int i;
	int j;
	int space;
	int space2 = 10;
	int width;
	
	for (;;) {
		for (i = 0; i < m; i++) {
			//いい感じにスペース
			for (space = m * 2; space > i * 2; space--) {
				printf(" ");
			}
			width = (i + 1) * 4 - 1;
			for (j = 0; j < width; j++) {
				//最初は必ず屋根の左側
				for (; j == 0;) {
					printf("／");
					break;
				}
				//屋根の一番下の段
				for (; j < i && i != m - 1;) {
					printf(" ");
					break;
				}
				//屋根の一番下の段
				for (; j < i && i == m - 1;) {
					printf("_");
					break;
				}

				for (; j == i;) {
					printf("/");
					break;
				}
				//一番右以外かつ今の段数より右側の位置かつ一番下の段ではないとき
				for (; j < width - 2 && j > i && i != m - 1;) {
					printf(" ");
					break;
				}
				for (; j < width - 2 && j > i && i == m - 1;) {
					printf("_");
					break;
				}
				//一番右側
				for (; j == width - 1; j++) {
					printf("＼");
				}
			}
			puts("");
		}
		break;
	}

	/*
	for (; m >= 10;) {
		          ／/＼
		        ／ /   ＼
		      ／  /      ＼
		    ／   /         ＼
		  ／    /            ＼
		／     /               ＼
	  ／      /                  ＼
	／       /                     ＼
  ／        /                        ＼
／_________/___________________________＼

		for (i = 0; i < m; i++) {
			for (space = m * 2; space > i * 2; space--) {
				printf(" ");
			}
			width = (i + 1) * 4 - 1;
			for (j = 0; j < width; j++) {
				//屋根の左側
				for (; j == 0;) {
					printf("／");
					break;
				}
				//屋根の一番下の段
				for (; j < i && i != m - 1;) {
					printf(" ");
					break;
				}
				//屋根の一番下の段
				for (; j < i && i == m - 1;) {
					printf("_");
					break;
				}

				for (; j == i;) {
					printf("/");
					break;
				}
				//一番右以外かつ今の段数より右側の位置かつ一番下の段ではないとき
				for (; j < width - 2 && j > i && i != m - 1;) {
					printf(" ");
					break;
				}
				for (; j < width - 2 && j > i && i == m - 1;) {
					printf("_");
					break;
				}
				//一番右側
				for (; j == width - 1; j++) {
					printf("＼");
				}
			}
			puts("");
		}
		break;
	}
	*/
}

void wall(int m) {
	int height;
	int i;
	int j;
	int max;
	int door_knob = 5;
	max = m + 2;

	for (;m < 5;) {
		for (height = 1; height < max; height++) {
			printf("　");
			for (; !(height == 0 || height == max - 1);) {
				printf("|");
				for (i = 0; i < max - 2; i++) {
					printf(" ");
				}
				printf("|");
				for (i = 0; i < (max - 2) * 3 - 2; i++) {
					printf(" ");
				}
				printf("|");
				break;
			}
			for (; height == max - 1;) {
				for (j = 0; j < max + (max - 2) * 3 - 1; j++) {
					printf("-");
				}
				break;
			}
			puts("");
		}
		break;
	}
	
	for (;m >= 5 && m <= 9;) {
		for (i = 5; i < m - 1; i += 2) {
			door_knob++;
		}
		for (height = 1; height < max; height++) {
			printf("　");
			for (; height != max - 1;) {
				printf("|");
				for (i = 0; i < max - 2; i++) {
					printf(" ");
				}
				printf("|");
				for (i = 0; i < (max - 2) * 3 - 2 && height < 3; i++) {
					printf(" ");
				}
				for (i = 0; i < (max - 2) * 3 - 2 && height == 3; i++) {
					for (j = 0; j < m + 2; j++) {
						printf(" ");
					}
					for (j = 0; j < m - 1; j++) {
						printf("-");
					}
					for (j = 0; j < m - 3; j++) {
						printf(" ");
					}
					break;
				}
				for (i = 0; i < (max - 2) * 3 - 2 && height > 3; i++) {
					for (j = 0; j < m + 2; j++) {
						printf(" ");
					}
					printf("|");
					for (j = 0; j < m - 3 && height != door_knob; j++) {
						printf(" ");
					}
					for (j = 0; j < m - 4 && height == door_knob; j++) {
						printf(" ");
					}
					for (;height == door_knob;) {
						printf("･");
						break;
					}
					printf("|");
					for (j = 0; j < m - 3; j++) {
						printf(" ");
					}
					break;
				}

				printf("|");
				break;
			}
			for (; height == max - 1;) {
				for (j = 0; j < max + (max - 2) * 3 - 1; j++) {
					printf("-");
				}
				break;
			}
			puts("");
		}
		break;
	}

	//窓作ろうかな
	//四角い時計作ろうかな
	for (; m >= 10;) {
		for (i = 5; i < m - 1; i += 2) {
			door_knob++;
		}
		for (height = 1; height < max; height++) {
			printf("　");
			for (; height != max - 1;) {
				printf("|");
				for (i = 0; i < max - 2; i++) {
					//たぶんここ窓
					printf(" ");
				}
				printf("|");
				for (i = 0; i < (max - 2) * 3 - 2 && height < 3; i++) {
					printf(" ");
				}
				for (i = 0; i < (max - 2) * 3 - 2 && height == 3; i++) {
					for (j = 0; j < m + 2; j++) {
						printf(" ");
					}
					for (j = 0; j < m - 1; j++) {
						printf("-");
					}
					for (j = 0; j < m - 3; j++) {
						printf(" ");
					}
					break;
				}
				for (i = 0; i < (max - 2) * 3 - 2 && height > 3; i++) {
					for (j = 0; j < m + 2; j++) {
						printf(" ");
					}
					printf("|");
					for (j = 0; j < m - 3 && height != door_knob; j++) {
						printf(" ");
					}
					for (j = 0; j < m - 4 && height == door_knob; j++) {
						printf(" ");
					}
					for (; height == door_knob;) {
						printf("･");
						break;
					}
					printf("|");
					for (j = 0; j < m - 3; j++) {
						printf(" ");
					}
					break;
				}

				printf("|");
				break;
			}
			for (; height == max - 1;) {
				for (j = 0; j < max + (max - 2) * 3 - 1; j++) {
					printf("-");
				}
				break;
			}
			puts("");
		}
		break;
	}
}

void abalone() {
	int size;
	int i;
	int j;

	puts("大きさを入力してください");
	scanf_s("%d", &size);

	//上1/3
	for (i = 0; i < size; i++) {
		for (j = i; j < size - 1; j++) {
			printf("　");
		}
		printf("／");
		for (j = 0; j < i; j++) {
			printf("　");
		}
		printf("｜");
		for (j = 0; j < i; j++) {
			printf("　");
		}
		printf("＼");
		puts("");
	}
	//中1/3
	for (i = 0; i < size; i++) {
		for (j = 0; j < size * 2 + 1; j++) {
			for (; j == 0 || j == size * 2;) {
				printf("｜");
				break;
			}
			for (; j != 0 && j < size;) {
				printf("　");
				break;
			}
			for (; j != size * 2 && j > size;) {
				printf("　");
				break;
			}
			for (; j == size ;) {
				printf("｜");
				break;
			}
		}
		puts("");
	}
	//下1/3
	for (i = 0; i < size; i++) {
		for (j = 0; j < i; j++) {
			printf("　");
		}
		printf("＼");
		for (j = i; j < size - 1; j++) {
			printf("　");
		}
		printf("｜");
		for (j = i; j < size - 1; j++) {
			printf("　");
		}
		printf("／");
		puts("");
	}
}

void init() {
	const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX info = { sizeof info };
	info.dwFontSize.X = 6;
	info.dwFontSize.Y = 13;
	SetCurrentConsoleFontEx(hConsole, 0, &info);
}

