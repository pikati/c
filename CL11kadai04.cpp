#include <stdio.h>

int main() {
	int i;
	int b;
	int count = 0;
	int a[3];
	
	for (i = 0; i <= 100;i++) {
		if (i % 3 == 0 && i % 5 == 0 && i != 0) {
			printf("あほだワン\n");
		}
		else if (i % 3 == 0) {
			printf("あほあほ%dあほあほ\n", i);
		}
		else if (i % 5 == 0) {
			printf("わん\n");
		}
		else if (i == 22) {
			printf("(=^・・^=)22にゃんにゃん\n");
		}
		else if (i >= 20 && i <= 29) {
			printf("にゃん%d\n", i);
		}
		else if (i % 10 == 2) {
			printf("%dにゃん\n", i);
		}
		else {
			printf("%d\n", i);
		}
	}

	getchar();
	return 0;
}