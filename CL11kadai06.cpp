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
		puts("�`�悷��}�`��I��ł�������");
		puts("�����`:1�@�����`:2�@�O�p�`:3�@�t���̎O�p�`:4�@�Ђ��`:5�@��:6�@�����:7�@�I��:0");
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

	puts("1�ӂ̒�������͂��Ă�������");
	scanf_s("%d", &max);
	max += 2;

	for (height = 0; height < max - 1; height++) {
		//��ԏ�̒i
		for (; height == 0;) {
			printf(" ");
			for (i = 0; i < max - 2; i++) {
				printf("�Q");
			}
			printf(" ");
			break;
		}
		//��Ɖ��ȊO�̒i
		for (; !(height == 0 || height == max - 2);) {
			printf("|");
			for (i = 0; i < max - 2; i++) {
				printf("�@");
			}
			printf("|");
			break;
		}
		//��ԉ��̒i
		for (; height == max - 2;) {
			printf("|");
			for (i = 0; i < max - 2; i++) {
				printf("�Q");
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

	puts("�c�Ɖ��̒�������͂��Ă�������");
	printf("�c�̒���:");
	scanf_s("%d", &maxH);
	printf("���̒���:");
	scanf_s("%d", &maxW);

	maxH += 2;
	maxW += 2;

	for (height = 0; height < maxH - 1; height++) {
		//��ԏ�̒i
		for (; height == 0;) {
			printf(" ");
			for (i = 0; i < maxW - 2; i++) {
				printf("�Q");
			}
			printf(" ");
			break;
		}
		//��Ɖ��ȊO�̒i
		for (; !(height == 0 || height == maxH - 2);) {
			printf("|");
			for (i = 0; i < maxW - 2; i++) {
				printf("�@");
			}
			printf("|");
			break;
		}
		//��ԉ��̒i
		for (; height == maxH - 2;) {
			printf("|");
			for (i = 0; i < maxW - 2; i++) {
				printf("�Q");
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

	puts("�i���i�����j����͂��Ă�������");
	scanf_s("%d", &height);

	center = height - 2;

	for (i = 0; i < height; i++) {
		for (j = i; j <= center; j++) {
			printf("�@");
		}
		printf("�^");
		j = 0;
		for (; i == height - 1; i++) {
			j = i * 2;
		}
		for (; i == height; i--);
		for (; j < i * 2; j++) {
			printf("�@");
		}
		for (; i == height - 1; i++) {
			j = 0;
		}
		for (; i == height; i--);
		for (; j < i * 2; j++) {
			for (; i < height - 1;) {
				printf("�_");
				break;
			}
			for (; i < height;) {
				printf("�Q");
				break;
			}
		}
		printf("�_");
		puts("");
	}
}

void triangleReverse() {
	int i;
	int j;
	int height;
	int center;

	puts("�i���i�����j����͂��Ă�������");
	scanf_s("%d", &height);

	center = height - 2;

	for (i = height - 1; i >= 0; i--) {
		for (j = i; j <= center; j++) {
			printf("�@");
		}
		printf("��");
		j = 0;
		for (; i == height - 1; i++) {
			j = i * 2 - 1;
		}
		for (; i == height; i--);
		for (; j < i * 2 - 1; j++) {
			printf("�@");
		}
		for (; i == height - 1; i++) {
			j = 0;
		}
		for (; i == height; i--);
		for (; j < i * 2; j++) {
			printf("��");
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

	puts("�Ђ��`�̑傫������͂��Ă�������");
	scanf_s("%d", &max);

	odd_number = max % 2;
	print_number = 2 - odd_number;

	for (i = 0; i < max / 2 + odd_number; i++) {

		space_number = (max - print_number) / 2;

		for (j = 0; j < space_number; j++) {
			printf("�@");
		}

		for (j = 0; j < print_number; j++) {
			printf("��");
		}
		print_number += 2;
		printf("\n");
	}

	print_number -= 2 * (odd_number + 1);

	for (i = 0; i < max / 2; i++) {

		space_number = (max - print_number) / 2;

		for (j = 0; j < space_number; j++) {
			printf("�@");
		}

		for (j = 0; j < print_number; j++) {
			printf("��");
		}
		print_number -= 2;
		printf("\n");
	}
}

void house() {
	int max;

	puts("�Ƃ̑傫������͂��Ă��������i5�ȏゾ�ƃh�A���t���܂���j");
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
			//���������ɃX�y�[�X
			for (space = m * 2; space > i * 2; space--) {
				printf(" ");
			}
			width = (i + 1) * 4 - 1;
			for (j = 0; j < width; j++) {
				//�ŏ��͕K�������̍���
				for (; j == 0;) {
					printf("�^");
					break;
				}
				//�����̈�ԉ��̒i
				for (; j < i && i != m - 1;) {
					printf(" ");
					break;
				}
				//�����̈�ԉ��̒i
				for (; j < i && i == m - 1;) {
					printf("_");
					break;
				}

				for (; j == i;) {
					printf("/");
					break;
				}
				//��ԉE�ȊO�����̒i�����E���̈ʒu����ԉ��̒i�ł͂Ȃ��Ƃ�
				for (; j < width - 2 && j > i && i != m - 1;) {
					printf(" ");
					break;
				}
				for (; j < width - 2 && j > i && i == m - 1;) {
					printf("_");
					break;
				}
				//��ԉE��
				for (; j == width - 1; j++) {
					printf("�_");
				}
			}
			puts("");
		}
		break;
	}

	/*
	for (; m >= 10;) {
		          �^/�_
		        �^ /   �_
		      �^  /      �_
		    �^   /         �_
		  �^    /            �_
		�^     /               �_
	  �^      /                  �_
	�^       /                     �_
  �^        /                        �_
�^_________/___________________________�_

		for (i = 0; i < m; i++) {
			for (space = m * 2; space > i * 2; space--) {
				printf(" ");
			}
			width = (i + 1) * 4 - 1;
			for (j = 0; j < width; j++) {
				//�����̍���
				for (; j == 0;) {
					printf("�^");
					break;
				}
				//�����̈�ԉ��̒i
				for (; j < i && i != m - 1;) {
					printf(" ");
					break;
				}
				//�����̈�ԉ��̒i
				for (; j < i && i == m - 1;) {
					printf("_");
					break;
				}

				for (; j == i;) {
					printf("/");
					break;
				}
				//��ԉE�ȊO�����̒i�����E���̈ʒu����ԉ��̒i�ł͂Ȃ��Ƃ�
				for (; j < width - 2 && j > i && i != m - 1;) {
					printf(" ");
					break;
				}
				for (; j < width - 2 && j > i && i == m - 1;) {
					printf("_");
					break;
				}
				//��ԉE��
				for (; j == width - 1; j++) {
					printf("�_");
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
			printf("�@");
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
			printf("�@");
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
						printf("�");
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

	//����낤����
	//�l�p�����v��낤����
	for (; m >= 10;) {
		for (i = 5; i < m - 1; i += 2) {
			door_knob++;
		}
		for (height = 1; height < max; height++) {
			printf("�@");
			for (; height != max - 1;) {
				printf("|");
				for (i = 0; i < max - 2; i++) {
					//���Ԃ񂱂���
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
						printf("�");
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

	puts("�傫������͂��Ă�������");
	scanf_s("%d", &size);

	//��1/3
	for (i = 0; i < size; i++) {
		for (j = i; j < size - 1; j++) {
			printf("�@");
		}
		printf("�^");
		for (j = 0; j < i; j++) {
			printf("�@");
		}
		printf("�b");
		for (j = 0; j < i; j++) {
			printf("�@");
		}
		printf("�_");
		puts("");
	}
	//��1/3
	for (i = 0; i < size; i++) {
		for (j = 0; j < size * 2 + 1; j++) {
			for (; j == 0 || j == size * 2;) {
				printf("�b");
				break;
			}
			for (; j != 0 && j < size;) {
				printf("�@");
				break;
			}
			for (; j != size * 2 && j > size;) {
				printf("�@");
				break;
			}
			for (; j == size ;) {
				printf("�b");
				break;
			}
		}
		puts("");
	}
	//��1/3
	for (i = 0; i < size; i++) {
		for (j = 0; j < i; j++) {
			printf("�@");
		}
		printf("�_");
		for (j = i; j < size - 1; j++) {
			printf("�@");
		}
		printf("�b");
		for (j = i; j < size - 1; j++) {
			printf("�@");
		}
		printf("�^");
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

