/*2019113288 서정윤 저는 이 소스 코드를
다른 소스 코드를 복사하지 않고 직접 작성하였습니다.*/

#include <stdio.h>
int j = 0;
// 입력된 n번째 항을 계산하여 전역변수로 저장해줌
unsigned long long a = 1, b = 1, f;
void fib(unsigned long long* fn, unsigned long long x);
int main()
{
	int i, t, temp = 1;
	unsigned long long n;
	unsigned long long* fn;

	scanf("%d", &t);

	// t개의 배열 생성
	fn = (unsigned long long*)malloc(sizeof(unsigned long long) * t);

	for (i = 0; i < t; i++) {
		scanf("%llu", &n);
		if (n <= 1)
		{
			fn[j++] = 1; // 0번째, 1번째 항은 1
		}
		else
		{
			fib(fn, n - temp); //n - 1과 n의 차이 만큼 반복하도록 반복횟수를 넘겨줌
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