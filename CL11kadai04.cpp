#include <stdio.h>

int main() {
	int i;
	int b;
	int count = 0;
	int a[3];
	
	for (i = 0; i <= 100;i++) {
		if (i % 3 == 0 && i % 5 == 0 && i != 0) {
			printf("���ق�����\n");
		}
		else if (i % 3 == 0) {
			printf("���ق���%d���ق���\n", i);
		}
		else if (i % 5 == 0) {
			printf("���\n");
		}
		else if (i == 22) {
			printf("(=^�E�E^=)22�ɂ��ɂ��\n");
		}
		else if (i >= 20 && i <= 29) {
			printf("�ɂ��%d\n", i);
		}
		else if (i % 10 == 2) {
			printf("%d�ɂ��\n", i);
		}
		else {
			printf("%d\n", i);
		}
	}

	getchar();
	return 0;
}