#include <stdio.h>
#include <stdlib.h>

/* Наименьшее общее кратное двух чисел, через цикл */
unsigned int lcm_cycle(unsigned int lcm, unsigned int a, unsigned int b) {
	unsigned int i;
	for( i = lcm; ; i++) {
		if (i%a == 0 && i%b == 0)
			break;
	}
	return i;
}

/* Наименьшее общее кратное двух чисел, через рекурсию */
unsigned int lcm_recurse(unsigned int lcm, unsigned int a, unsigned int b) {
	if (!(lcm%a == 0 && lcm%b == 0))
		return lcm_recurse(lcm + 1, a, b);
	else return lcm;
}

int main() {
	
	unsigned int a, b, lcm;

	printf("Введите два натуральных числа (через пробел): ");
	scanf("%d%d", &a, &b);

	if(a >= b) lcm = a;
	else lcm = b;

	printf("Наименьшее общее кратное (через цикл) - %d\n", lcm_cycle(lcm, a, b));
	printf("Наименьшее общее кратное (через рекурсию) - %d\n", lcm_recurse(lcm, a, b));

}
