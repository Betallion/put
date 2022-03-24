#include <stdio.h>
#include <math.h>
#include <string.h>

int isTriangleTrojkat(float a, float b, float c)
{
	if (a + b > c || a + c > b || b + c > a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

float calculateArea(float a, float b, float c)
{
	if (isTriangleTrojkat(a, b, c) == 1)
	{
		float p = (a + b + c) / 2.0;
		float area = sqrt(p * (p - a) * (p - b) * (p - c));
		return area;
	}
	else 
	{
		return 0.0;
	}
}

float toDegree(float rad)
{
	const float pi = 22.0 / 7.0;
	float res = rad * (180.0 / pi);
	return res;
}

int isPalindrome(char str[])
{
	int len = strlen(str) - 1;
	int mid = len / 2, start = 0, end = len, isPal = 0;
	int pstart = start, pend = end;
	while (start < mid)
	{
		if (str[start] == str[end])
		{
			isPal = 1;
		}
		else
		{
			isPal = 0;
		}
		start++;
		end--;
	}
	return isPal;
}

char halfPalindrome(char str[], char half[])
{
	int len = strlen(str) - 1;
	int start = 0, end = len;
	while (start <= end)
	{
		half[start] = str[start];
		start++;
		end--;
	}
	half[start] = '\0';
	return 0;
}

int iterativeFibb(int n)
{
	int a = 1;
	int b = 1;
	int res = 0;
	if (n == 1)
	{
		return 0;
	}
	else
	{
		if (n == 2 || n == 3)
		{
			return 1;
		}
		else
		{
			while (n >= 4)
			{
				res = a + b;
				a = b;
				b = res;
				n--;
			}
			return res;
		}
	}
}

int recursiveFibb(int n)
{
	if (n == 1) return 0;
	else
	{
		if (n == 2 || n == 3) return 1;
		else return recursiveFibb(n - 1) + recursiveFibb(n - 2);
	}
}

void changeText(char str[])
{
	int i, len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		else
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] -= 32;
			}
			else
			{
				continue;
			}
		}
	}
}

int pot(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	else
	{
		while (b > 0)
		{
			a = a * a;
			b--;
		}
		return a;
	}
}

int silnia(int n)
{
	int res = 1;
	int e = 1;
	if (n == 0)
	{
		return 1;
	}
	else
	{
		while (n >= 1)
		{
			res = res * e;
			e++;
			n--;
		}
		return res;
	}
}

void task1()
{
	char c1;
	int i1;
	short s1;
	long l1;
	float f1;
	double d1;
	int size_char = sizeof(c1);
	int size_int = sizeof(i1);
	int size_short = sizeof(s1);
	int size_long = sizeof(l1);
	int size_float = sizeof(f1);
	int size_double = sizeof(d1);
	printf("%d\n%d\n%d\n%d\n%d\n%d\n", size_char, size_int, size_short, size_long, size_float, size_double);
}
void task2()
{
	float x;
	scanf("%a", &x);
	printf("%f\n", x);
	printf("%e\n", x);
	printf("%a\n", x);
	printf("%.3f\n", x);
	printf("%.3e\n", x);
}
void task3()
{
	int direction;
	unsigned int number;
	printf("Direction ->:\n");
	scanf("%d", &direction);
	printf("Number:\n");
	if (direction == 16)
	{
		scanf("%d", &number);
	}
	else {
		if (direction == 10)
		{
			scanf("%x", &number);
		}
	}


	if (direction == 10)
	{
		printf("%d", number);
	}
	else {
		if (direction == 16)
		{
			printf("%x", number);
		}
	}
}
void task4()
{
	unsigned int Alfa;
	printf("unsigned int number:\n");
	scanf("%d", &Alfa);
	Alfa = Alfa >> 28;
	unsigned int res = Alfa & 0xB;
	if (res == 11)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}
void task5()
{
	unsigned int State;
	unsigned int Mask;
	printf("State:\n");
	scanf("%x", &State);
	printf("Mask:\n");
	scanf("%x", &Mask);
	Mask = ~Mask;
	unsigned int res = State & Mask;
	printf("%x", res);
}
void task6()
{
	int code = 0;
	char character = 0;
	int i;
	for (i = 1; i < 256; i++)
	{
		printf("Code: %d Character: %c\n", code, character);
		code++;
		character++;
		if (i % 40 == 0)
		{
			getchar();
		}
	}
}
void task8()
{
	int op;
	float first, second, res;
	printf("Pierwsza liczba:\n");
	scanf("%a", &first);
	printf("Druga liczba:\n");
	scanf("%a", &second);
	printf("Wybierz operacje arytmetyczna:\n1) dodawanie\n2) odejmowanie\n3) mnozenie\n4) dzielenie\n");
	scanf("%d", &op);
	switch (op)
	{
	case 1:
		res = first + second;
		printf("%f", res);
		break;
	case 2:
		res = first - second;
		printf("%f", res);
		break;
	case 3:
		res = first * second;
		printf("%f", res);
		break;
	case 4:
		if (second == 0)
		{
			printf("Nie mozna dzielic przez 0\n");
		}
		else 
		{
			res = first / second;
			printf("%f", res);
		}
		break;
	default:
		printf("Niepoprawna operacja\n");
		break;
	}

}
void task9()
{
	int i;
	for (i = 1; i <= 500; i++)
	{
		if (i % 7 == 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}
void task10()
{
	int sq, i;
	float res1 = 0, res2 = 0;
	for (i = 1; i <= 10000; i++)
	{
		sq = i * i;
		res1 += 1 / sq;
	}
	for (i = 10000; i <= 1; i--)
	{
		sq = i * i;
		res2 += sq;
	}
	printf("Od 1 do 10000: %f\nOd 10000 do 1: %f\n", res1, res2);
}
void task11()
{
	int i, limit = 100000;
	float res = 0;
	for (i = 0; i < limit; i++)
	{
		res += pot(-1, i) / (2 * i + 1);
	}
	res = res * 4;
	printf("%f\n", res);
}
void task12()
{
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	if (a + b > c || a + c > b || b + c > a)
	{
		printf("Z tych trzech odcinkow mozna zbudowac trojkat\n");
		float p = (a + b + c) / 2.0;
		float res = sqrt(p * (p - a) * (p - b) * (p - c));
		printf("Pole powierzchni trojkata to %f\n", res);
	}
	else
	{
		printf("Z tych odcinkow nie mozna zbudowac trojkata\n");
	}
}
void task13()
{
	float rad;
	const float pi = 22.0 / 7.0;
	scanf("%a", &rad);
	float res = rad * (180.0 / pi);
	printf("%f\n", res);
}
void task14()
{
	char temp, str[100];
	printf("Text:");
	scanf("%c", &temp);
	scanf("%[^\n]", &str);
	changeText(str);
	printf("Reversed text:\n%s\n", str);
}
void task15()
{
	char temp, str[100];
	printf("Text: ");
	scanf("%c", &temp);
	scanf("%[^\n]", &str);
	int len = strlen(str) - 1;
	int mid = len / 2, start = 0, end = len, isPal = 0;
	int pstart = start, pend = end;
	while (start < mid)
	{
		if (str[start] == str[end])
		{
			isPal = 1;
		}
		else
		{
			isPal = 0;
		}
		start++;
		end--;
	}
	if (isPal == 1)
	{
		printf("To jest palindrom\nHalf palindrome: ");
		while (pstart <= pend)
		{
			printf("%c", str[pstart]);
			pstart++;
			pend--;
		}
		printf("\n");
	}
	else
	{
		printf("To nie jest palindrom\n");
	}
	
}
void task17()
{
	float rad;
	scanf("%a", &rad);
	float res = toDegree(rad);
	printf("%f\n", res);
}
void task18()
{
	char temp, str[100], half[100];
	printf("Text: ");
	scanf("%c", &temp);
	scanf("%[^\n]", &str);
	int isPal;
	isPal = isPalindrome(str);
	if (isPal == 1)
	{
		printf("To jest palindrom\nHalf palindrome: ");
		halfPalindrome(str, half);
		printf("%s\n", half);
	}
	else
	{
		printf("To nie jest palindrom\n");
	}
}
void task19()
{
	int el;
	scanf("%d", &el);
	printf("iterative: \n");
	int ires = iterativeFibb(el);
	printf("%d\n", ires);
	getchar();
	getchar();
	printf("recursive: \n");
	int rres = recursiveFibb(el);
	printf("%d\n", rres);
}
void task20()
{
	int p, i, j, el, gap;
	scanf("%d", &p);
	for (i = 1; i <= p; i++)
	{
		el = 1;
		gap = p - i;
		while (gap > 0)
		{
			printf(" ");
			gap--;
		}
		for (j = 1; j <= i; j++)
		{
			printf("%d ", el);
			el = el * (i - j) / j;
		}
		printf("\n");
	}

}
int main()
{
	int check = 1;
	do
	{
		int task;
		printf("Ktore zadanie chcesz wykonac? ");
		scanf("%d", &task);
		char cont;
		switch (task)
		{
		case 1:
			task1();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 2:
			task2();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 3:
			task3();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 4:
			task4();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 5:
			task5();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 6:
			task6();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 8:
			task8();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 9:
			task9();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 10:
			task10();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 11:
			task11();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 12:
			task12();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 13:
			task13();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 14:
			task14();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 15:
			task15();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 17:
			task17();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 18:
			task18();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 19:
			task19();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 20:
			task20();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		default:
			printf("niepoprawna liczba\n");
			break;
		}
	} while (check == 1);
	return 0;
}

