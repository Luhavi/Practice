#include <stdio.h>

int main() {
	int num = 0;

	printf("������ ����� ����ұ��?\n >> ");

	scanf_s("%d", &num);

	for (int i = 1; i < 10; i++) {
		printf("%d X %d = %d\n",num,i,num * i);
	}
}