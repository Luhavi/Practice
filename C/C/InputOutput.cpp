#include <stdio.h>

int main() {

	char name[100];
	char address[100];
	int old;

	printf("�ȳ� �̸��� ����? \n");
	printf("> ");
	scanf_s("%s", name, sizeof(name));

	printf("���̴� ?\n");
	printf("> ");
	scanf_s("%d", &old);

	printf("��� ���? \n");
	printf("> ");
	scanf_s("%s", address, sizeof(address));

	printf("�� �׷�����!\n");
	printf("���� �̸��� %s�̰�\n", name);
	printf("���̴� %d�̰�\n",old);
	printf("%s�� ��±���\n", address);
	printf("������ �� ��Ź��!");

	return 0;

}