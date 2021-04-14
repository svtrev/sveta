#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Вычисление интеграла с помощью метода средних прямоугольников */
double integral (int n) {
   int i;
   double x, h, integ = 0;
	h = (M_PI)/n;

	for (i = 0; i <= n; i++) {
		x = -M_PI_2 +  i*h + (h/2);

		if (x <= 0)
			integ += ((x*x) - 2*(x*x*x)) * cos(x*x);
		else if (x <= M_PI_2)
			integ += exp(sin(2*x));
	}

   return integ*h;
}

int main() {
	

	double I, e;
	int n = 1;


	/* Вычисляем погрешность по правилу Рунге */
	printf ("Введите требуемую точность e = ");
	scanf("%lf", &e);

	while((fabs(integral(2*n) - integral(n)))/3 >= e) {
		/*d = (fabs(integral(2*n) - integral(n)))/3; */
		n *= 2;
	}
	I = integral(n);

	printf("Значение интеграла I = %.5lf\n", I);

	return 0;
}
