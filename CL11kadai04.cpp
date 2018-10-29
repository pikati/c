#include <stdio.h>

int main() {
	int i;
	int b;
	int count = 0;
	int a[3];
	
	for (i = 0; i <= 100;i++) {
		if (i % 3 == 0 && i % 5 == 0 && i != 0) {
			printf("‚ ‚Ù‚¾ƒƒ“\n");
		}
		else if (i % 3 == 0) {
			printf("‚ ‚Ù‚ ‚Ù%d‚ ‚Ù‚ ‚Ù\n", i);
		}
		else if (i % 5 == 0) {
			printf("‚í‚ñ\n");
		}
		else if (i == 22) {
			printf("(=^EE^=)22‚É‚á‚ñ‚É‚á‚ñ\n");
		}
		else if (i >= 20 && i <= 29) {
			printf("‚É‚á‚ñ%d\n", i);
		}
		else if (i % 10 == 2) {
			printf("%d‚É‚á‚ñ\n", i);
		}
		else {
			printf("%d\n", i);
		}
	}

	getchar();
	return 0;
}