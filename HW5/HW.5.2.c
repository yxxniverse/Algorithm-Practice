/*
[2019113288 서정윤] 저는 이 코드를
다른 소스코드를 복사하지 않고 직접 작성하였습니다
*/
#include <stdio.h>
#define MAX 17
#define INF 10000000
typedef struct _nodetype* node_pointer;
typedef struct _nodetype{
	int key;
	int p;
	node_pointer left;
	node_pointer right;
}nodetype;
void optsearchtree(int n, int p[], int* minavg, int R[][MAX], int A[][MAX]);
node_pointer tree(int i, int j, int R[][MAX], int keys[MAX]);
int minimum(int A[][MAX], int p[], int *minK, int i, int j);
void preorder(node_pointer ptr, int *pre, int n);
void inorder(node_pointer ptr, int *in, int n);
int main()
{
	int n, min;
	int R[MAX][MAX], A[MAX][MAX];
	int k[MAX], p[MAX];
	node_pointer root;

	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf_s("%d", &k[i]);
	for (int i = 1; i <= n; i++)
		scanf_s("%d", &p[i]);

	optsearchtree(n, p, &min, R, A);

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			printf("%d", A[i][j]);
			if (j != n)
				printf(" ");
		}
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			printf("%d", R[i][j]);
			if (j != n)
				printf(" ");
		}
		printf("\n");
	}

	root = tree(1, n, R, k);

	int pre = 1, in = 1;
	preorder(root, &pre, n);
	printf("\n");
	inorder(root, &in, n);
	printf("\n");
}
void optsearchtree(int n, int p[], int* minavg, int R[][MAX], int A[][MAX])
{
	int i, j, k, diagonal;

	for (i = 1; i <= n; i++) {
		A[i][i] = p[i];  
		A[i][i - 1] = 0;
		R[i][i] = i; 
		R[i][i - 1] = 0;
	}
	A[n + 1][n] = 0;
	R[n + 1][n] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++)
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			A[i][j] = minimum(A, p, &k, i, j);
			R[i][j] = k;
		}
	*minavg = A[1][n];
}
int minimum(int A[][MAX], int p[], int *minK, int i, int j)
{
	int minValue = INF;
	*minK = 0;
	for (int k = i; k <= j; k++) {
		int value = A[i][k - 1] + A[k + 1][j];
		for (int m = i; m <= j; m++)
			value += p[m];
		if (minValue > value) {
			minValue = value;
			*minK = k;
		}
	}
	return minValue;
}
node_pointer tree(int i, int j, int R[][MAX], int keys[MAX])
{
	int k;
	node_pointer p;

	k = R[i][j];
	if (k == 0)
		return NULL;
	else {
		p = (node_pointer)malloc(sizeof(nodetype));
		p->key = keys[k];
		p->left = tree(i, k - 1, R, keys);
		p->right = tree(k + 1, j, R, keys);
		return p;
	}
}
void preorder(node_pointer ptr, int *pre, int n)
{
	if (ptr) {
		printf("%d", ptr->key);
		if (*pre != n)
			printf(" ");
		(*pre)++;
		preorder(ptr->left, pre, n);
		preorder(ptr->right, pre, n);
	}	
}
void inorder(node_pointer ptr, int *in, int n)
{
	if (ptr) {
		inorder(ptr->left, in, n);
		printf("%d", ptr->key);
		if (*in != n)
			printf(" ");
		(*in)++;
		inorder(ptr->right, in, n);
	}
}