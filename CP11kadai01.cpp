//------------------------------------------------------//
//					�ۑ�1 ���X�g���l                    //
//					�s�J�^��							//
//------------------------------------------------------//

#include<stdio.h>
#pragma warning(disable : 4996)

//2�̒l����͂��Ă��̍�(��Βl)��\������
int main(void)
{
	int num1 = 0;//1�ڂ̓��͂����l������ϐ�
	int num2 = 0;//2�ڂ̓��͂����l������ϐ�
	int ans = 0;//��������ϐ�

	printf("a�̒��g����́F");
	scanf("%d", &num1);

	printf("b�̒��g����́F");
	scanf("%d", &num2);

	ans = num1 + num2;

	printf("a��b�̍��v��%d�ł��B\n", ans);

	//1�ڂ̓��͂��傫���Ƃ�
	if (num1 > num2) {
		ans = num1 - num2; 
	}
	//2�ڂ̓��͂��傫���Ƃ�
	else if (num2 > num1) {
		ans = num2 - num1; 
	}
	//�l�������Ƃ�
	else {
		ans = 0;
	}

	printf("a��b�̍�����%d�ł��B\n", ans);

	getchar();
	return 0;
}
