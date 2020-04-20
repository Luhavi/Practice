#include <stdio.h>

int main() {
	int num;

	scanf_s("%d", &num);

	// if문은 (조건식) 할때 (실행식) 해준다
	// 즉 조건식이 만족할 때 실행식을 실행하고 
	// 만족하지 못할 때는 실행하지 않는다
	if (/*조건식*/num > 10) {
		//실행식
		printf("10보다 크다");
	}
	else if(num == 10){
		// else if문의 경우 위의 조건식이 만족하지 못할때
		// if문을 실행한다 else if문이 여러개 있을 때
		// 위의 if문이 만족하면 아래의 if문은 만족하더라도 실행되지 않는다
		printf("10이다");
	}
	else {
		//else문의 경우 위의 조건식들이 모두 만족하지 못할때 실행된다
		printf("10보다 작다");
	}
}