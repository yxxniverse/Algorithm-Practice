/*2019113288 서정윤 저는 이 소스코드를
다른 소스코드를 복사하지 않고 직접 작성하였습니다*/

#include <stdio.h>
int** makearray(int rows, int cols);
int searchloc(int** array, int searchnum, int minrow, int maxrow, int mincol, int maxcol);
int main()
{
	int i, j, rows, cols, testcase, ** array, searchnum;

	scanf("%d %d", &rows, &cols);
	array = makearray(rows, cols);

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++)
			scanf("%d", &array[i][j]);
	}
	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		scanf("%d", &searchnum);
		if (searchloc(array, searchnum, 0, rows, 0, cols) == 0)
			printf("NONE\n");
	}

	free(array);
}
int** makearray(int rows, int cols)
{
	int** x, i;
	x = (int**)malloc(sizeof(*x) * rows);
	for (i = 0; i < rows; i++)
		x[i] = (int*)malloc(sizeof(int) * cols);

	return x;
}
int searchloc(int** array, int searchnum, int minrow, int maxrow, int mincol, int maxcol)
{

	int i, j;
	int midrow = (minrow + maxrow) / 2;
	int midcol = (mincol + maxcol) / 2;

	if (searchnum > array[maxrow - 1][maxcol - 1])
		return 0;

	else if (array[midrow][midcol] == searchnum)
	{
		printf("%d %d\n", midrow, midcol);
		return 1;
	}

	else if (array[midrow][midcol] > searchnum)
	{
		for (i = 0; i < midrow; i++)
		{
			for (j = 0; j < maxcol; j++)
			{
				if (array[i][j] == searchnum)
				{
					printf("%d %d\n", i, j);
					return 1;
				}
			}
		}

		for (i = midrow; i < maxrow; i++)
		{
			for (j = 0; j < midcol; j++)
			{
				if (array[i][j] == searchnum)
				{
					printf("%d %d\n", i, j);
					return 1;
				}
			}
		}
		return 0;
	}

	else
	{
		for (i = 0; i < maxrow; i++)
		{
			for (j = midcol + 1; j < maxcol; j++)
			{
				if (array[i][j] == searchnum)
				{
					printf("%d %d\n", i, j);
					return 1;
				}
				continue;
			}
		}

		for (i = midrow + 1; i < maxrow; i++)
		{
			for (j = 0; j <= midcol; j++)
			{
				if (array[i][j] == searchnum)
				{
					printf("%d %d\n", i, j);
					return 1;
				}
				continue;
			}
		}
		return 0;
	}

}