#include <stdio.h>

int main() {

	// 2중 for문의 경우 사실 for문 안에 for문이 있다는걸 잘 생각해보면 어렵지 않다
	// 2중 for문으로 구구단을 직접 돌려 보면 알기 쉽다

	for (int i = 2; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			printf("%dX%d =%d\t", i, j, i*j);
			// 바깥쪽 for문이 2로 시작 하여 안쪽 for문을 만나 9번 실행이 되고 
			// 안쪽 for문에서 나가 바깥쪽 for문이 다시 돌게 되어
			// 바깥쪽 for문이 한번 돌면 안쪽 for문이 9번 도는 구조를 갖는다
			// 3중 for문 같은 경우도 똑같이 생각 할 수 있다
		}
		printf("\n");
	}

	return 0;
}