/*2019113288 서정윤 저는 이 소스코드를 
다른 소스코드를 복사하지 않고 직접 작성하였습니다*/

#include <stdio.h>
int search(int* s, int low, int high);
int main()
{
	int i, j, t, n, * s;

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d",&n);

		s = (int*)malloc(sizeof(int) * n);

		for (j = 0; j < n; j++)
			scanf("%d", s + j);

		search(s, 0, n - 1);

	}
}
int search(int* s, int low, int high)
{
	int mid, i;
	
	mid = (high + low) / 2;

	if (low > high)
		printf("NONE\n");
	else
	{
		if (mid == s[mid])
			printf("%d\n", s[mid]);
		else if (mid < s[mid])
			search(s, low, mid - 1);
		else
			search(s, mid + 1, high);
	}
}