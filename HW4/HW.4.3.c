/*2019113288 ���������� �� �ڵ带
�ٸ� �ҽ��ڵ带 �������� �ʰ�
���� �ۼ��Ͽ����ϴ�*/

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

	// ����� �ִ밪
	printf("%d\n", D[1][1]);

	i = 1;  j = 1;
	while(i <= n) {
			printf("%d ", tree[i][j]);
			// P[i][j]���� 1�̸� ������ �Ʒ��� ������
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
			// �ִ� ����� ���� ������ ������ ������ �κ����� ������
			if (D[i][j] + D[i + 1][j + 1] >= D[i][j] + D[i + 1][j]) {
				D[i][j] = D[i][j] + D[i + 1][j + 1];
				// �Ʒ� ���������� �������� P[i][j] = 1
				P[i][j] = 1; 
			}
			else {
				D[i][j] = D[i][j] + D[i + 1][j];
				// �Ʒ������� �������� P[i][j] = -1
				P[i][j] = -1;
			}	
	}
}