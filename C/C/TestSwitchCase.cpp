#include <stdio.h>

int main() {
	int num;
	scanf_s("%d", &num);

	// switch case���� �ϳ��� �񱳴���� ���� ���� ���ϴµ� ȿ�� ���̴�
	// if���� ������ ���� �� ���� ȿ�����̴�
	// �� case���� break�� ���� �ÿ� ��� ���๮�� ���� �Ǳ� ������ �����ؾ��Ѵ�
	// default�� ��� ���� ���� ���� �� ���� �ȴ�

	switch (/*�� ���*/num)
	{
	case /*�� ��*/1: /*���๮*/printf("���ڰ� 1�̴�");
		break;
	case /*�� ��*/2: /*���๮*/printf("���ڰ� 2�̴�");
		break;
	case /*�� ��*/3: /*���๮*/printf("���ڰ� 3�̴�");
		break;
	case /*�� ��*/4: /*���๮*/printf("���ڰ� 4�̴�");
		break;
	case /*�� ��*/5: /*���๮*/printf("���ڰ� 5�̴�");
		break;
	default: /*���๮*/ printf("1~5������ ���ڰ� �ƴϴ�");
		break;
	}
}