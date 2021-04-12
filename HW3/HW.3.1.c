/*2019113288 서정윤 저는 이 소스코드를
다른 소스코드를 복사하지 않고 직접 작성하였습니다*/

#include <stdio.h>
#define MAX 128
const int threshold = 2;
int strsnCount = 0;
int isPow(int n);
void madd(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]);
void msub(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]);
void mmult(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]);
void partition(int n, int A[MAX][MAX], int A11[MAX][MAX], int A12[MAX][MAX], int A21[MAX][MAX], int A22[MAX][MAX]);
void combine(int n, int A[MAX][MAX], int A11[MAX][MAX], int A12[MAX][MAX], int A21[MAX][MAX], int A22[MAX][MAX]);
void strassen(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]);
int main()
{
	int n, i, j;
	int A[MAX][MAX] = { 0 }, B[MAX][MAX] = { 0 }, C[MAX][MAX] = { 0 };

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			scanf("%d", &B[i][j]);
	}

	strassen(isPow(n), A, B, C);

	printf("%d\n", strsnCount);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", C[i][j]);
		printf("\n");
	}

}
int isPow(int n)
{
	int result = 1;

	if (!(n & (n - 1))) return n;
	else
		while (result < n)
			result <<= 1;
	return result;
		
}
void madd(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX])
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
}
void msub(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX])
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
}
void mmult(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX])
{
	int i, j, k;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			C[i][j] = 0;
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				C[i][j] += A[i][k] * B[k][j];
}
void partition(int n, int A[MAX][MAX], int A11[MAX][MAX], int A12[MAX][MAX], int A21[MAX][MAX], int A22[MAX][MAX])
{
	int i, j;
	int m = n / 2;
	for (i = 0;i < m; i++)
		for (j = 0; j < m; j++) {
			A11[i][j] = A[i][j];
			A12[i][j] = A[i][j + m];
			A21[i][j] = A[i + m][j];
			A22[i][j] = A[i + m][j + m];
		}
}
void combine(int n, int A[MAX][MAX], int A11[MAX][MAX], int A12[MAX][MAX], int A21[MAX][MAX], int A22[MAX][MAX])
{
	int i, j;
	int m = n / 2;
	for (i = 0;i < m; i++)
		for (j = 0; j < m; j++) {
			A[i][j] = A11[i][j] ;
			A[i][j + m] = A12[i][j];
			A[i + m][j] = A21[i][j];
			A[i + m][j + m] = A22[i][j];
		}
}
void strassen(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX])
{
	strsnCount++;

	int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
	int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
	int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];
	int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX],
		M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];
	int L[MAX][MAX], R[MAX][MAX];
	
	if (n <= threshold) {
		mmult(n, A, B, C);
	}
	else {
		int m = n / 2;
		partition(n, A, A11, A12, A21, A22);
		partition(n, B, B11, B12, B21, B22);
			
		madd(m, A11, A22, L);
		madd(m, B11, B22, R);
		strassen(m, L, R, M1);

		madd(m, A21, A22, L);
		strassen(m, L, B11, M2);

		msub(m, B12, B22, R);
		strassen(m, A11, R, M3);

		msub(m, B21, B11, R);
		strassen(m, A22, R, M4);

		madd(m, A11, A12, L);
		strassen(m, L, B22, M5);

		msub(m, A21, A11, L);
		madd(m, B11, B12, R);
		strassen(m, L, R, M6);

		msub(m, A12, A22, L);
		madd(m, B21, B22, R);
		strassen(m, L, R, M7);

		madd(m, M1, M4, L);
		msub(m, L, M5, R);
		madd(m, R, M7, C11);

		madd(m, M3, M5, C12);

		madd(m, M2, M4, C21);

		madd(m, M1, M3, L);
		msub(m, L, M2, R);
		madd(m, R, M6, C22);

		combine(n, C, C11, C12, C21, C22);

	}
}