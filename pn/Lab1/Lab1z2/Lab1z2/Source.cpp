#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c;
	int rozw = 0;
	double e = 0.0001;
	double r0, r1, r2;

	scanf("%d %d %d", &a, &b, &c);
	double delta = b * b - 4 * a * c;
	if (delta > 0) {
		r1 = -b - sqrt(delta) / 2 * a;
		r2 = -b + sqrt(delta) / 2 * a;
		if (round(r1) - r1 < e) {
			rozw++;
		}
		if (round(r2) - r2 < e) {
			rozw++;
		}
	}
	else {
		if (delta == 0) {
			r0 = -1 * b / 2 * a;
			if (round(r0) - r0 < e) {
				rozw++;
			}
		}
		else {
			rozw = 0;
		}
	}
	printf("%d rozwiazan calkowitych\n", rozw);
	if (rozw == 1) {
		printf("%f", r0);
	}
	if (rozw == 2) {
		printf("%f %f", r1, r2);
	}
	return 0;
}