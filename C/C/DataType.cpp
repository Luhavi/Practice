#include <stdio.h>

	// ���� ���� ���
	// ������ �ڷ��� �����̸� = ���� ��
	// ���⼭ ���� �ִ� ���� �����̶�� �Ѵ�
	// ������
	char		_char = 'a';		// 1byte
	// ������
	short		num = 1;		// 2byte
	int			num1 = 2;		// 4byte
	long		num2 = 3;		// 4byte
	long long	num3 = 4;		// 8byte
	// �Ǽ���
	float		Rnum = 3.14;		// 4byte
	double		Rnum1 = 3.1415;	// 8byte
	long double Rnum2 = 3.141592;	// 8byte �̻�

	// sizeof �Լ��� ���� �����ִ� byte ���� �³� üũ �غ� ���̴�
	int main() {

		printf(" char : %d \n", sizeof(char));
		printf(" short : %d \n int : %d \n long : %d \n long long : %d \n", sizeof(short), sizeof(int), sizeof(long), sizeof(long long));
		printf(" float : %d \n double : %d \n long double : %d", sizeof(float), sizeof(double), sizeof(long double));


		return 0;
	}