#include<stdio.h>
#include<stdlib.h>


void swap(int * array, int a, int b) {
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

void heapify(int * array, int n, int i) {
	int p = i;
	int l = i * 2 + 1;
	int r = i * 2 + 2;

	if (l < n && array[p] < array[l]) {
		p = l;
	}

	if (r < n && array[p] < array[r]) {
		p = r;
	}

	if (i != p) {
		swap(array, p, i);
		heapify(array, n, p);
	}
}

void heapSort(int * array, int arraylength) {
	int n = arraylength;

	// init, max heap
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(array, n, i);
	}

	// for extract max element from heap
	for (int i = n - 1; i > 0; i--) {
		swap(array, 0, i);
		heapify(array, i, 0);
	}
}


int main(void) {
	int datalength = 0;
	printf("얼마나 값을 넣을지 정해주세요 \n -> ");
	scanf_s("%d", &datalength);
	int * data = (int *)malloc(sizeof(int)*datalength);
	for (int i = 0; i < datalength; i++) {
		printf("값을 넣어주세요 \n -> ");
		scanf_s("%d", &data[i]);
	}

	heapSort(data,datalength);

	for (int i = 0; i < datalength; i++) {
		printf("%d ", data[i]);
	}

}