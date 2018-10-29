//------------------------------------------------------//
//					課題1 リスト美人                    //
//					ピカタん							//
//------------------------------------------------------//

#include<stdio.h>
#pragma warning(disable : 4996)

//2つの値を入力してその差(絶対値)を表示する
int main(void)
{
	int num1 = 0;//1個目の入力した値を入れる変数
	int num2 = 0;//2個目の入力した値を入れる変数
	int ans = 0;//差を入れる変数

	printf("aの中身を入力：");
	scanf("%d", &num1);

	printf("bの中身を入力：");
	scanf("%d", &num2);

	ans = num1 + num2;

	printf("aとbの合計は%dです。\n", ans);

	//1個目の入力が大きいとき
	if (num1 > num2) {
		ans = num1 - num2; 
	}
	//2個目の入力が大きいとき
	else if (num2 > num1) {
		ans = num2 - num1; 
	}
	//値が同じとき
	else {
		ans = 0;
	}

	printf("aとbの差分は%dです。\n", ans);

	getchar();
	return 0;
}
