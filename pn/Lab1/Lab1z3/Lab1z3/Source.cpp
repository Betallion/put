#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a + b > c) {
		printf("%d + %d > %d\n", a, b, c);
		if (a + c > b) {
			printf("%d + %d > %d\n", a, c, b);
			if (b + c > a) {
				printf("%d + %d > %d\nMozna zbudowac trojkat", b, c, a);
			}
			else {
				printf("%d + %d <= %d\nNie mozna zbudowac trojkata", b, c, a);
			}
		}
		else {
			printf("%d + %d <= %d\nNie mozna zbudowac trojkata", a, c, b);
		}
	}
	else {
		printf("%d + %d <= %d\nNie mozna zbudowac trojkata", a, b, c);
	}
	return 0;
}