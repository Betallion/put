#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

static int pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0, pos5 = 0, pos6 = 0, pos7 = 0;

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

void halfPalindrome(char str[], char half[])
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

int isTriangle(float a, float b, float c)
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
	if (isTriangle(a, b, c) == 1)
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

void clearArray(int array[52][2])
{
	int i, j;
	for (i = 0; i < 52; i++)
	{
		for (j = i + 1; j < 52; j++)
		{
			int a = array[i][0];
			int b = array[j][0];
			if (a > b)
			{
				int temp = *array[j];
				*array[j] = *array[i];
				*array[i] = temp;
			}
		}
		array[i][1] = 0;
	}
}

void insert_intoVector(int array[52][2], char sign)
{
	int j;
	for (j = 0; j < 52; j++)
	{
		if (array[j][0] == sign)
		{
			array[j][1]++;
			break;
		}
	}
}

void sortVector(int array[52][2])
{
	int i, j;
	for (i = 0; i < 52; i++)
	{
		for (j = i + 1; j < 52; j++)
		{
			int a = array[i][1];
			int b = array[j][1];
			if (a <= b)
			{
				int tempC = array[j][0], tempV = array[j][1];
				array[j][0] = array[i][0];
				array[j][1] = array[i][1];
				array[i][0] = tempC;
				array[i][1] = tempV;
			}
		}
	}
}

void printVector(int array[52][2])
{
	int i;
	for (i = 0; i < 52; i++)
	{
		printf("Kod litery: %d, liczba wystapien: %d\n", array[i][0], array[i][1]);
	}
}

void task1()
{
	char temp, str[100];
	printf("Text:");
	scanf("%c", &temp);
	scanf("%[^\n]", &str);
	changeText(str);
	printf("Reversed text:\n%s\n", str);
}

void task2()
{
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	if (isTriangle(a, b, c))
	{
		printf("To jest trojkat\n");
		float area = calculateArea(a, b, c);
		printf("Pole to %f\n", area);
	}
	else
	{
		printf("Nie jest to trojkat\n");
	}
}

void task3()
{
	float rad;
	scanf("%a", &rad);
	float res = toDegree(rad);
	printf("%f\n", res);
}

void task4()
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

void task5(int occ[52][2])
{
	clearArray(occ);
	char text[128];
	int i;

	scanf("%s", &text);

	for (i = 0; i < 127; i++)
	{
		insert_intoVector(occ, text[i]);
	}

	sortVector(occ);
	printVector(occ);

}

unsigned int** generateVector()
{
	int i;
	unsigned int** octNumbers = (unsigned int**)calloc(8, sizeof(unsigned int*));
	for (i = 0; i < 8; i++)
	{
		octNumbers[i] = (unsigned int*)calloc(100, sizeof(unsigned int));
	}
	return octNumbers;
}

void insert_intoVector2D(unsigned int** octNumbers, int read)
{
	if (read % 8 > 0)
	{
		int index = read % 8;
		switch (index)
		{
		case 1:
			octNumbers[1][pos1] = read;
			pos1++;
			break;
		case 2:
			octNumbers[2][pos2] = read;
			pos2++;
			break;
		case 3:
			octNumbers[3][pos3] = read;
			pos3++;
			break;
		case 4:
			octNumbers[4][pos4] = read;
			pos4++;
			break;
		case 5:
			octNumbers[5][pos5] = read;
			pos5++;
			break;
		case 6:
			octNumbers[6][pos6] = read;
			pos6++;
			break;
		case 7:
			octNumbers[7][pos7] = read;
			pos7++;
			break;
		default:
			break;
		}
	}
}

void reduceVector(unsigned int** octNumbers)
{
	int i, j;
	for (i = 1; i < 8; i++)
	{
		int pos;
		j = i;
		switch (j)
		{
		case 1:
			pos = pos1;
			break;
		case 2:
			pos = pos2;
			break;
		case 3:
			pos = pos3;
			break;
		case 4:
			pos = pos4;
			break;
		case 5:
			pos = pos5;
			break;
		case 6:
			pos = pos6;
			break;
		case 7:
			pos = pos7;
			break;
		default:
			pos = 0;
			break;
		}
		if (pos == 0)
		{
			unsigned int* temp = (unsigned int*)realloc(octNumbers[i], sizeof(unsigned int));
			octNumbers[i] = temp;
		}
		else
		{
			//printf("%d", pos);
			unsigned int* temp = (unsigned int*)realloc(octNumbers[i], pos * sizeof(unsigned int));
			if (temp == NULL)
			{
				printf("\noops");
				free(octNumbers[i]);
				exit(0);
			}
			else
			{
				octNumbers[i] = temp;
			}

		}
	}
	
	
}

void print_irrVector(unsigned int** octNumbers)
{
	int i, j;
	for (i = 1; i < 8; i++)
	{
		printf("%d wiersz: ", i);
		int pos;
		j = i;
		switch (j)
		{
		case 1:
			pos = pos1;
			break;
		case 2:
			pos = pos2;
			break;
		case 3:
			pos = pos3;
			break;
		case 4:
			pos = pos4;
			break;
		case 5:
			pos = pos5;
			break;
		case 6:
			pos = pos6;
			break;
		case 7:
			pos = pos7;
			break;
		default:
			pos = 0;
			break;
		}
		for (j = 0; j < pos; j++)
		{
			printf("%d ", octNumbers[i][j]);
		}
		printf("\n");
	}
}

void print_irrVectorBinary(unsigned int** octNumbers)
{
	int i, j;
	for (i = 1; i < 8; i++)
	{
		printf("%d wiersz: ", i);
		int pos;
		j = i;
		switch (j)
		{
		case 1:
			pos = pos1;
			break;
		case 2:
			pos = pos2;
			break;
		case 3:
			pos = pos3;
			break;
		case 4:
			pos = pos4;
			break;
		case 5:
			pos = pos5;
			break;
		case 6:
			pos = pos6;
			break;
		case 7:
			pos = pos7;
			break;
		default:
			pos = 0;
			break;
		}
		for (j = 0; j < pos; j++)
		{
			char bin[65];
			printf("%s ", _itoa(octNumbers[i][j], bin, 2));
			j++;
		}
		printf("\n");
	}
}


void task6()
{
	int i;
	unsigned int** octNumbers = generateVector();
	pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0, pos5 = 0, pos6 = 0, pos7 = 0;
	for (i = 0; i < 100; i++)
	{
		int read;
		scanf("%d", &read);
		if (read == 0)
		{
			break;
		}
		if (read % 8 > 0)
		{
			insert_intoVector2D(octNumbers, read);
		}
	}
	int sizeBefore = sizeof(**octNumbers)*8*100;
	reduceVector(octNumbers);
	int sizeAfter = sizeof(unsigned int)*(pos1+pos2+pos3+pos4+pos5+pos6+pos7);
	printf("\nRozmiar przed:%d Rozmiar po:%d\n", sizeBefore, sizeAfter);
	print_irrVector(octNumbers);
	print_irrVectorBinary(octNumbers);

	for (i = 0; i < 8; i++)
	{
		free(octNumbers[i]);
	}
	free(octNumbers);
}

unsigned int** generateVector2()
{
	int i;
	unsigned int** octNumbers = new unsigned int*[8];
	for (i = 0; i < 8; i++)
	{
		octNumbers[i] = new unsigned int[100];
	}
	return octNumbers;
}

void reduceVector2(unsigned int** octNumbers)
{
	int i, j;
	for (i = 1; i < 8; i++)
	{
		int pos;
		j = i;
		switch (j)
		{
		case 1:
			pos = pos1;
			break;
		case 2:
			pos = pos2;
			break;
		case 3:
			pos = pos3;
			break;
		case 4:
			pos = pos4;
			break;
		case 5:
			pos = pos5;
			break;
		case 6:
			pos = pos6;
			break;
		case 7:
			pos = pos7;
			break;
		default:
			pos = 0;
			break;
		}
		if (pos == 0)
		{
			unsigned int* temp = new unsigned int[1];
			octNumbers[i] = temp;
		}
		else
		{
			//printf("%d", pos);
			unsigned int* temp = new unsigned int[pos];
			if (temp == nullptr)
			{
				printf("\noops");
				delete [] octNumbers[i];
				exit(0);
			}
			else
			{
				for (j = 0; j < pos; j++)
				{
					temp[j] = octNumbers[i][j];
				}
				
				delete [] octNumbers[i];
				octNumbers[i] = temp;
			}

		}
	}


}

void task7()
{
	int i;
	unsigned int** octNumbers = generateVector2();
	pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0, pos5 = 0, pos6 = 0, pos7 = 0;
	for (i = 0; i < 100; i++)
	{
		int read;
		scanf("%d", &read);
		if (read == 0)
		{
			break;
		}
		if (read % 8 > 0)
		{
			insert_intoVector2D(octNumbers, read);
		}
	}
	int sizeBefore = sizeof(**octNumbers) * 8 * 100;
	reduceVector2(octNumbers);
	int sizeAfter = sizeof(unsigned int) * (pos1 + pos2 + pos3 + pos4 + pos5 + pos6 + pos7);
	printf("\nRozmiar przed:%d Rozmiar po:%d\n", sizeBefore, sizeAfter);
	print_irrVector(octNumbers);
	print_irrVectorBinary(octNumbers);

	for (i = 0; i < 8; i++)
	{
		delete [] octNumbers[i];
	}
	delete [] octNumbers;
}

void task8()
{
	char first[64];
	char second[64];
	scanf("%s", &first);
	scanf("%s", &second);
	char buff[64] = { 0 };
	char firstOfFirst = first[0];
	char firstOfSecond = second[0];
	char* check = strchr(first, firstOfSecond);
	//printf("%s", check);
	if (check == NULL)
	{
		strcat(buff, first);
	}
	else
	{
		char* firstPoint = &first[0];
		while (firstPoint != check)
		{
			strncat(buff, firstPoint, 1);
			//printf("\n%c\n", *firstPoint);
			firstPoint++;
		}
	}
	//char* amount = check - firstOfFirst;
	//firstOfSecond = second[0];
	char* lastOfSecond = strrchr(second, firstOfFirst);
	if (lastOfSecond == NULL)
	{
		strcat(buff, second);
	}
	else
	{
		char* secondPoint = &second[0];
		do
		{
			strncat(buff, secondPoint, 1);
			secondPoint++;
		} while (secondPoint != lastOfSecond+1);
	}
	strcpy(first, buff);

	printf("%s\n", first);
}

int main()
{
	int occ[52][2] = 
	{
		{65, 0},{66, 0},{67, 0},{68, 0},{69, 0},
		{70, 0},{71, 0},{72, 0},{73, 0},{74, 0},
		{75, 0},{76, 0},{77, 0},{78, 0},{79, 0},
		{80, 0},{81, 0},{82, 0},{83, 0},{84, 0},
		{85, 0},{86, 0},{87, 0},{88, 0},{89, 0},{90, 0},
		{97, 0},{98, 0},{99, 0},{100, 0},{101, 0},
		{102, 0},{103, 0},{104, 0},{105, 0},{106, 0},
		{107, 0},{108, 0},{109, 0},{110, 0},{111, 0},
		{112, 0},{113, 0},{114, 0},{115, 0},{116, 0},
		{117, 0},{118, 0},{119, 0},{120, 0},{121, 0},{122, 0}
	};

	int check = 1;
	do
	{
		int task;
		printf("Ktore zadanie chcesz wykonac? ");
		scanf("%d", &task);
		fflush(stdin);
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
			task5(occ);
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
		case 7:
			task7();
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
		default:
			printf("niepoprawna liczba\n");
			break;
		}

	} while (check == 1);
	return 0;
}

