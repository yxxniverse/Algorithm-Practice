/* 
[2019113288 서정윤] 저는 이 소스코드를
다른 소스코드를 복사하지 않고 직접 작성하였습니다.
*/
#include <stdio.h>
#define MAX 16
#define INF 100000000
int minmult(int n, int d[], int P[][MAX], int M[][MAX]);
int minimum(int i, int j, int* minK, int M[][MAX], int d[MAX]);
void order(int i, int j, int P[][MAX]);
int main()
{

	int n;
	int d[MAX], M[MAX][MAX], P[MAX][MAX];

	scanf_s("%d", &n);
	for (int i = 0; i <= n; i++)
		scanf_s("%d", &d[i]);

	minmult(n, d, P, M);

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			printf("%d", P[i][j]);
			if (j != n)
				printf(" ");
		}
		if (i != n)
			printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			printf("%d", M[i][j]);
			if (j != n)
				printf(" ");
		}
		if (i != n)
			printf("\n");
	}
	order(1, n, P);
	
}
int minmult(int n, int d[], int P[][MAX], int M[][MAX])
{
	int i, j, k, diagonal;

	for (i = 1; i <= n; i++)
		M[i][i] = 0 ;
	for(diagonal = 1; diagonal <= n - 1; diagonal++)
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			M[i][j] = minimum(i, j, &k, M, d);
			P[i][j] = k;
		}

	return M[1][n];
}
int minimum(int i, int j, int* minK, int M[][MAX], int d[MAX])
{
	int minV = INF;
	for (int k = i; k <= j - 1; k++) {
		int value = M[i][k] + M[k + 1][j] + d[i - 1]*d[k]*d[j];
		if(minV > value) {
			minV = value;
			*minK = k;
		}
	}
	return minV;
}
void order(int i, int j, int P[][MAX]){

	if (i == j)
		printf("A%d", i);
	else {
		int k = P[i][j];
		printf("(");
		order(i, k, P);
		order(k + 1, j, P);
		printf(")");
	}
}