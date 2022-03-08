#include <stdio.h>
#include <math.h>

int main()
{
	float x;
	scanf("%a", &x);
	float res = (sin(x) * sin(x) * log(15)) / sqrt(fabs(log(0.5 * x) / log(3)));
	printf("Wynik: %f", x);
	return 0;
}