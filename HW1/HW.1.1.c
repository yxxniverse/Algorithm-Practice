/*2019113288 ������ ���� �� �ҽ� �ڵ带
�ٸ� �ҽ� �ڵ带 �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.*/

#include <stdio.h>
#include <stdlib.h>
void sort(unsigned int* array, int n);
int main()
{
	int i, n;
	unsigned int* array;
	unsigned long long  sum;

	do {
		scanf("%d", &n);
	} while (n <= 5 && n >= 1000);

	array = (unsigned int*)malloc(sizeof(unsigned int) * n);

	for (i = 0; i < n; i++)
		scanf("%u", array + i);

	sort(array, n);

	for (i = 0; i < n; i++)
		printf("%u ", *(array + i));

	sum = (unsigned long long) * (array + 1) + (unsigned long long) * (array + n - 2);
	printf("%u %u %llu", *(array + 1), *(array + n - 2), sum);

	free(array);

}
void sort(unsigned int* array, int n)
{
	int i, j, t;
	
	for (i = 0; i < n - 1; i++) {
		for (j = 1; j < n - i; j++) {
			if (array[j - 1] > array[j]) {
				t = array[j - 1];
				array[j - 1] = array[j];
				array[j] = t;

			}
		}
	}
}