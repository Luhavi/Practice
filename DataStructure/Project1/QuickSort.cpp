#include <iostream>
using namespace std;

void QuickSort(int * data, int start, int end) {
	if (start >= end) {
		return;
	}
	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp;
	while (i <= j)
	{
		while (i <= end && data[i] <= data[pivot]) {
			i++;
		}
		while (j > start && data[j] >= data[pivot]){
			j--;
		}

		if (i > j) {
			temp = data[pivot];
			data[pivot] = data[j];
			data[j] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	QuickSort(data, start, j - 1);
	QuickSort(data, j + 1, end);

}

int main(void) {
	int datalength = 0;
	printf( "얼마나 값을 넣을지 정해주세요 \n -> ");
	scanf_s("%d",&datalength);
	int * data = (int *)malloc(sizeof(int)*datalength);
	for (int i = 0; i < datalength; i++) {
		printf( "값을 넣어주세요 \n -> ");
		scanf_s("%d", &data[i]);
	}

	QuickSort(data, 0, datalength - 1);

	for (int i = 0; i < datalength; i++) {
		printf("%d ", data[i]);
	}

}