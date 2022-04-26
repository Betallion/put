#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
	char imie[15] = { '\0' };
	char nazwisko[30] = { '\0' };
	int indeks = NULL;
	char kierunek[30] = { '\0' };
	int rok = NULL;
	int grupa = NULL;
};

void createArray1(struct Student* array, int size)
{
	array = (struct Student*)malloc(size * sizeof(*array));
}

struct Student* createArray2(int size)
{
	struct Student* array = (struct Student*)malloc(size * sizeof(*array));
	return array;
}

struct Student* deleteStudent(struct Student* array, int indeks)
{

	return array;
}

struct Student* insertStudent(struct Student* array, struct Student* student)
{
	int i;
	//getchar();
	for (i = 0; i < size; i++)
	{
		char buf[100];
		fgets(buf, sizeof(buf), stdin);
		if (buf[0] == '\n')
		{
			int j;
			for (j = i; j < size; j++)
			{
				(array + j)->imie[0] = '\0';
				(array + j)->nazwisko[0] = '\0';
				(array + j)->indeks = 0;
				(array + j)->kierunek[0] = '\0';
				(array + j)->rok = 0;
				(array + j)->grupa = 0;
			}
			break;
		}
		sscanf(buf, "%s %s %d %s %d %d", &(array + i)->imie, &(array + i)->nazwisko, &(array + i)->indeks, &(array + i)->kierunek, &(array + i)->rok, &(array + i)->grupa);
	}
	return array;
}

struct Student* sortArray(struct Student* array)
{
	int i, size = sizeof(*array) / sizeof(struct Student);
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			struct Student* temp = (struct Student*)malloc(size * sizeof(*array));
			if (strcmp((array + i)->nazwisko, (array + j)->nazwisko) > 0)
			{
				*temp = *(array + i);
				*(array + i) = *(array + j);
				*(array + j) = *temp;
			}
			else if (strcmp((array + i)->nazwisko, (array + j)->nazwisko) == 0)
			{
				if (strcmp((array + i)->imie, (array + j)->imie) > 0)
				{
					*temp = *(array + i);
					*(array + i) = *(array + j);
					*(array + j) = *temp;
				}
			}
			else
			{
				continue;
			}
			free(temp);
		}
	}
	return array;
}




int main()
{

	return 0;
}