/*2019113288 ������ ���� �� �ҽ� �ڵ带
�ٸ� �ҽ� �ڵ带 �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.*/

#include <stdio.h>
int j = 0;
// �Էµ� n��° ���� ����Ͽ� ���������� ��������
unsigned long long a = 1, b = 1, f;
void fib(unsigned long long* fn, unsigned long long x);
int main()
{
	int i, t, temp = 1;
	unsigned long long n;
	unsigned long long* fn;

	scanf("%d", &t);

	// t���� �迭 ����
	fn = (unsigned long long*)malloc(sizeof(unsigned long long) * t);

	for (i = 0; i < t; i++) {
		scanf("%llu", &n);
		if (n <= 1)
		{
			fn[j++] = 1; // 0��°, 1��° ���� 1
		}
		else
		{
			fib(fn, n - temp); //n - 1�� n�� ���� ��ŭ �ݺ��ϵ��� �ݺ�Ƚ���� �Ѱ���
			temp = n;
		}
	}

	for (i = 0; i < t; i++)
		printf("%llu\n", fn[i]);

	free(fn);
}
void fib(unsigned long long* fn, unsigned long long x)
{
	int i;

		for (i = 0; i < x; i++)
		{
			f = (a + b) % 1000000;
			a = b;
			b = f;
		}
		fn[j++] = f;
}