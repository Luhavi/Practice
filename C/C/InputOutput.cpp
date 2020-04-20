#include <stdio.h>

int main() {

	char name[100];
	char address[100];
	int old;

	printf("안녕 이름이 뭐야? \n");
	printf("> ");
	scanf_s("%s", name, sizeof(name));

	printf("나이는 ?\n");
	printf("> ");
	scanf_s("%d", &old);

	printf("어디에 살아? \n");
	printf("> ");
	scanf_s("%s", address, sizeof(address));

	printf("아 그렇구나!\n");
	printf("너의 이름은 %s이고\n", name);
	printf("나이는 %d이고\n",old);
	printf("%s에 사는구나\n", address);
	printf("앞으로 잘 부탁해!");

	return 0;

}