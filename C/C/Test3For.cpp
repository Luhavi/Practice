#include <stdio.h>
#include <Windows.h>

int main() {
	int hour,min,sec;

	printf("�ð� : "); scanf_s("%d", &hour);
	printf("�� : "); scanf_s("%d", &min);
	printf("�� : "); scanf_s("%d", &sec);

	for (int i = hour; i < 24; i++) {
		for (int j = min; j < 60; j++) {
			for (int k = sec; k < 60; k++) {
				if (hour != 0) {
					hour = 0;
					min = 0;
					sec = 0;
				}
				printf("%d�� %d�� %d��",i,j,k);
				Sleep(1000);
				system("cls");
			}
		}
		if (i == 23) {
			i = -1;
		}
	}
}