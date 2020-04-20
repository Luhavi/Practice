#include <stdio.h>

	// 변수 선언 방법
	// 변수의 자료형 변수이름 = 넣을 값
	// 여기서 값을 넣는 것을 대입이라고 한다
	// 문자형
	char		_char = 'a';		// 1byte
	// 정수형
	short		num = 1;		// 2byte
	int			num1 = 2;		// 4byte
	long		num2 = 3;		// 4byte
	long long	num3 = 4;		// 8byte
	// 실수형
	float		Rnum = 3.14;		// 4byte
	double		Rnum1 = 3.1415;	// 8byte
	long double Rnum2 = 3.141592;	// 8byte 이상

	// sizeof 함수로 옆에 쓰여있는 byte 수가 맞나 체크 해볼 것이다
	int main() {

		printf(" char : %d \n", sizeof(char));
		printf(" short : %d \n int : %d \n long : %d \n long long : %d \n", sizeof(short), sizeof(int), sizeof(long), sizeof(long long));
		printf(" float : %d \n double : %d \n long double : %d", sizeof(float), sizeof(double), sizeof(long double));


		return 0;
	}