/*2019113288 서정윤저는 이 코드를
다른 소스코드를 복사하지 않고
직접 작성하였습니다*/

#include <stdio.h>
#include <string.h>
#define MAX 50010
long long B[MAX];
long long bin2(int r, int n, int k);
int main()
{
	int i;
	int t, n, k;
	int n_1;
	int r;

	scanf("%d", &t);

	n_1 = 0;
	B[0] = 1;

	for (i = 0; i < t; i++) {
		scanf("%d %d", &n, &k);
		printf("%lld\n", bin2(n_1, n, k));
		n_1 = n;
	}
}
long long bin2(int n_1, int n, int k)
{
	int i, j;
	int min;
	for (i = 0; i < n - n_1; i++) {
		for (j = n; j >= 0; j--) {
			if (j == 0 || j == n)
				B[j] = 1;
			else
				B[j] = (B[j - 1] + B[j]) % 100000000;
		}
	}
	return B[k];
}