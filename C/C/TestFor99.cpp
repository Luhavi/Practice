#include <stdio.h>

int main() {
	int num = 0;

	printf("구구단 몇단을 출력할까요?\n >> ");

	scanf_s("%d", &num);

	for (int i = 1; i < 10; i++) {
		printf("%d X %d = %d\n",num,i,num * i);
	}
}