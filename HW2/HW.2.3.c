/*2019113288 서정윤 저는 이 소스 코드를
다른 소스코드를 복사하지 않고 직접 작성하였습니다.*/

#include <stdio.h>
#include <math.h>
#define MAX 1024
int board[MAX][MAX];
int count = 0;
void tromino(int srow, int scol, int size, int xrow, int xcol);
void fillCenterExcept(int mrow, int mcol, int part);
void print_board(int m);
int main()
{
	int n, xrow, xcol;
	scanf("%d %d %d", &n, &xrow, &xcol);
	int m = pow(2, n);
	board[xrow][xcol] = 0;
	tromino(0, 0, m, xrow, xcol);

	print_board(m);
}
void tromino(int srow, int scol, int size, int xrow, int xcol)
{
	int i, j;
	int xrow1, xcol1, xrow2, xcol2, xrow3, xcol3, xrow4, xcol4;
	int mrow = srow + (size / 2);
	int mcol = scol + (size / 2);

	if (size == 2)
	{
		count++;
		if ((mrow - 1) != xrow || (mcol - 1) != xcol)
			board[mrow - 1][mcol - 1] = count;
		if ((mrow - 1) != xrow || (mcol) != xcol)
			board[mrow - 1][mcol] = count;
		if ((mrow) != xrow || (mcol - 1) != xcol)
			board[mrow][mcol - 1] = count;
		if ((mrow) != xrow || (mcol) != xcol)
			board[mrow][mcol] = count;
		return;
	}
	else
	{
		xrow1 = mrow - 1;
		xcol1 = mcol - 1;
		xrow2 = mrow - 1;
		xcol2 = mcol;
		xrow3 = mrow;
		xcol3 = mcol - 1;
		xrow4 = mrow;
		xcol4 = mcol;

		if (xrow < mrow && xcol < mcol)
		{
			fillCenterExcept(mrow, mcol, 1);
			xrow1 = xrow;
			xcol1 = xcol;
		}
		else if (xrow < mrow && xcol >= mcol)
		{
			fillCenterExcept(mrow, mcol, 2);
			xrow2 = xrow;
			xcol2 = xcol;
		}
		else if (xrow >= mrow && xcol < mcol)
		{
			fillCenterExcept(mrow, mcol, 3);
			xrow3 = xrow;
			xcol3 = xcol;
		}
		else if (xrow >= mrow && xcol >= mcol)
		{
			fillCenterExcept(mrow, mcol, 4);
			xrow4 = xrow;
			xcol4 = xcol;
		}
	}
	tromino(srow, scol, size / 2, xrow1, xcol1);
	tromino(srow, scol + size / 2, size / 2, xrow2, xcol2);
	tromino(srow + size / 2, scol, size / 2, xrow3, xcol3);
	tromino(srow + size / 2, scol + size / 2, size / 2, xrow4, xcol4);
}
void fillCenterExcept(int mrow, int mcol, int part)
{
	count++;
	if (part != 1)
		board[mrow - 1][mcol - 1] = count;
	if (part != 2)
		board[mrow - 1][mcol] = count;
	if (part != 3)
		board[mrow][mcol - 1] = count;
	if (part != 4)
		board[mrow][mcol] = count;
}
void print_board(int m)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
}