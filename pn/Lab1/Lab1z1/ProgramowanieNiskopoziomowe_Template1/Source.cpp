#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c;
	int rozw;
	double srozw;
	scanf("%lf %lf %lf", &a, &b, &c);
	double delta = b * b - 4 * a * c;
	if (delta > 0) {
		rozw = 2;
	}
	else {
		if (delta == 0) {
			rozw = 1;
		}
		else {
			rozw = 0;
		}
	}
	srozw = -(b / a);
	printf("%d rozwiazan rzeczywistych\n", rozw);
	if (rozw > 0) {
		printf("suma to %f", srozw);
	}
	return 0;
}