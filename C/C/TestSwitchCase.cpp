#include <stdio.h>

int main() {
	int num;
	scanf_s("%d", &num);

	// switch case문은 하나의 비교대상을 여러 값에 비교하는데 효과 적이다
	// if문을 여러개 쓰는 것 보다 효율적이다
	// 각 case문에 break가 없을 시에 모든 실행문이 실행 되기 때문에 조심해야한다
	// default는 모든 값이 맞지 않을 때 실행 된다

	switch (/*비교 대상*/num)
	{
	case /*비교 값*/1: /*실행문*/printf("숫자가 1이다");
		break;
	case /*비교 값*/2: /*실행문*/printf("숫자가 2이다");
		break;
	case /*비교 값*/3: /*실행문*/printf("숫자가 3이다");
		break;
	case /*비교 값*/4: /*실행문*/printf("숫자가 4이다");
		break;
	case /*비교 값*/5: /*실행문*/printf("숫자가 5이다");
		break;
	default: /*실행문*/ printf("1~5사이의 숫자가 아니다");
		break;
	}
}