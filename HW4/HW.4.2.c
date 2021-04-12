/*2019113288 서정윤저는 이 코드를 
다른 소스코드를 복사하지 않고
직접 작성하였습니다*/

#include <stdio.h>
#include <string.h>
#define INF 100000000
#define MAX 128
int W[MAX][MAX];
int P[MAX][MAX];
int D[MAX][MAX];
int way = 0;
void floyd2(int n);
int path(int u, int v,int pathway[]);
void printmatrix(int n);
void printroute(int u, int v);
int main()
{ 
	int i, j;
	int n, m, t;
	int u, v, w;

	scanf("%d %d", &n, &m);

	// 자기자신으로 가는 경우엔 가중치 0, 나머지는 무한대로 초기화
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) {
			if (i == j)
				W[i][j] = 0;
			else W[i][j] = INF;
		}

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		W[u][v] = w;
	}

	floyd2(n);

	printmatrix(n);

	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d %d", &u, &v);
		printroute(u, v);
	}
}
void floyd2(int n)
{
	int i, j, k;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			P[i][j] = 0;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			D[i][j] = W[i][j];

	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if ((D[i][k] + D[k][j]) < D[i][j]) {
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}
}
int path(int q, int r, int pathway[])
{
	if (P[q][r] != 0) {
		path(q, P[q][r], pathway);
		pathway[way++] = P[q][r];
		path(P[q][r], r, pathway);
	}
}
void printmatrix(int n)
{
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (D[i][j] == INF)
				printf("INF ");
			else printf("%d ", D[i][j]);
		}
		printf("\n");
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", P[i][j]);
		}
		printf("\n");
	}
}
void printroute(int u, int v)
{
	int pathway[128];

	way = 1;
	pathway[way++] = u;
	path(u, v, pathway);
	pathway[way] = v;

	for (int j = 1; j <= way; j++)
		printf("%d ", pathway[j]);

	if (D[u][v] == INF)
		printf("INF \n");
	else printf("%d \n", D[u][v]);
}