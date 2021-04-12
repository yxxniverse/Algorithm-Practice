/*2019113288 서정윤저는 이 코드를
다른 소스코드를 복사하지 않고
직접 작성하였습니다*/

#include <stdio.h>
#define MAX 128
void searchMax(int tree[][MAX], int n);
int D[MAX][MAX];
int P[MAX][MAX];
int main()
{
	int i, j;
	int n, token;
	int tree[MAX][MAX];

	scanf("%d", &n);
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++)
			scanf("%d", &tree[i][j]);
	}

	searchMax(tree, n);

	// 경로의 최대값
	printf("%d\n", D[1][1]);

	i = 1;  j = 1;
	while(i <= n) {
			printf("%d ", tree[i][j]);
			// P[i][j]값이 1이면 오른쪽 아래로 내려감
			if (P[i][j] == 1)
				j++;
			i++;
	}
}
void searchMax(int tree[][MAX], int n)
{
	int i, j;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++)
			D[i][j] = tree[i][j];

	for (i = n - 1; i >= 1; i--) {
		for(j = 1; j <=i; j++)
			// 최대 경로의 합이 여러개 있으면 오른쪽 부분으로 내려옴
			if (D[i][j] + D[i + 1][j + 1] >= D[i][j] + D[i + 1][j]) {
				D[i][j] = D[i][j] + D[i + 1][j + 1];
				// 아래 오른쪽으로 내려가면 P[i][j] = 1
				P[i][j] = 1; 
			}
			else {
				D[i][j] = D[i][j] + D[i + 1][j];
				// 아래쪽으로 내려가면 P[i][j] = -1
				P[i][j] = -1;
			}	
	}
}