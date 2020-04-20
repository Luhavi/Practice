#include <stdio.h>

int main() {
	int num = 0;

	// while문도 for문과 같은 반복문이다
	// 조건식이 만족할 때 계속 반복 되고 만족하지 못하면 벗어난다

	while (/*조건식*/ num < 10) {
		printf("%d\n", num);
		num++;
	}
	
	// 숫자에서 0은 false 즉 만족하지 못함을 뜻하고 나머지 숫자는 true 만족함을 뜻하는데
	// 조건식에 1을 쓰고 실행 시키면 while문이 무한 반복한다
	// 이때 break를 사용하여 빠져 나올 수 있는데 보통 if문으로 감싸서
	// 일정한 조건이 됬을때 while문에서 빠져 나올 수 있도록 한다

	while (1)
	{
		printf("%d\n", num);
		num--;
		if (num == 0) {
			break;
		}
	}
}