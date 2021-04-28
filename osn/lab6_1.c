#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

	int i, j, n, A[20];
	int temp, k, m = 0, count;

	printf("Введите кол-во элементов = ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		A[i] = rand()%51-25;
		printf("%d ", A[i]);
	}
	printf("\n");

	printf("Введите искомое число = ");
	scanf("%d", &k);

	for (i = 0; i < n; i++) {
		if (A[i] == k) break;
		m++;
	}

	if (m != 0)
    {
		    for (i = 0; i < m/2; i++) {
			  temp = A[i];
			  A[i] = A[m-1 - i];
			  A[m-1 - i] = temp;
		}
		count = (n-m)/2;
		for (i = m+1, j = 0; count > 0; count--, j++) {
			temp = A[i+j];
			A[i+j] = A[n-1 - j];
			A[n-1 - j] = temp;
		}
	}

	if (m == 0) {
		for (i = 0; i < (n / 2); i++) {
			temp = A[i];
			A[i] = A[n-1 - i];
			A[n-1 - i] = temp;
		}
	}

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
printf("\n");
return 0;
}
