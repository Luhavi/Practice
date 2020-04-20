#include <stdio.h>
#include <stdlib.h>
# define MAX_SIZE 8
int sorted[MAX_SIZE]; 


void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}


void merge_sort(int list[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2; 
		merge_sort(list, left, mid); 
		merge_sort(list, mid + 1, right); 
		merge(list, left, mid, right); 
	}
}

void main() {
	int datalength = 0;
	printf("얼마나 값을 넣을지 정해주세요 \n -> ");
	scanf_s("%d", &datalength);
	int * data = (int *)malloc(sizeof(int)*datalength);
	for (int i = 0; i < datalength; i++) {
		printf("값을 넣어주세요 \n -> ");
		scanf_s("%d", &data[i]);
	}

	merge_sort(data, 0, datalength - 1);

	for (int i = 0; i < datalength; i++) {
		printf("%d ", data[i]);
	}

}