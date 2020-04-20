#include <stdio.h>
#include<stdlib.h>
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
# define MAX_SIZE 5

void selection_sort(int list[], int n) {
	int i, j, least, temp;

	for (i = 0; i < n - 1; i++) {
		least = i;

		for (j = i + 1; j < n; j++) {
			if (list[j] < list[least])
				least = j;
		}

		if (i != least) {
			SWAP(list[i], list[least], temp);
		}
	}
}

int main() {
	int datalength = 0;
	printf("얼마나 값을 넣을지 정해주세요 \n -> ");
	scanf_s("%d", &datalength);
	int * data = (int *)malloc(sizeof(int)*datalength);
	for (int i = 0; i < datalength; i++) {
		printf("값을 넣어주세요 \n -> ");
		scanf_s("%d", &data[i]);
	}

	selection_sort(data, datalength);

	for (int i = 0; i < datalength; i++) {
		printf("%d ", data[i]);
	}
	return 0;
}