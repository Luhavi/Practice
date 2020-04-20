#include <stdio.h>
#include <stdlib.h>

// ���� ����
void bubble_sort(int * list, int n) {
	int i, j, temp;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (list[j] > list[j + 1]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

void main() {
	int datalength = 0;
	printf("�󸶳� ���� ������ �����ּ��� \n -> ");
	scanf_s("%d", &datalength);
	int * data = (int *)malloc(sizeof(int)*datalength);
	for (int i = 0; i < datalength; i++) {
		printf("���� �־��ּ��� \n -> ");
		scanf_s("%d", &data[i]);
	}

	bubble_sort(data, datalength);

	for (int i = 0; i < datalength; i++) {
		printf("%d\n", data[i]);
	}
}