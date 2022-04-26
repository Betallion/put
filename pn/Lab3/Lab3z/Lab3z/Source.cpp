#include <stdio.h> 
#include <string.h>
#include <stdlib.h>



struct Student
{
	char imie[15] = { '\0' };
	char nazwisko[30] = { '\0' };
	int indeks = NULL;
	char kierunek[30] = { '\0' };
	int rok = NULL;
	int grupa = NULL;
};

void task1()
{
	//zadanie 1
	printf("Z1-------------------\n");
	struct Student Kacper;
	scanf("%s %s %d %s %d %d", &Kacper.imie, &Kacper.nazwisko, &Kacper.indeks, &Kacper.kierunek, &Kacper.rok, &Kacper.grupa);
	getchar();
	printf("Imie: %s\nNazwisko: %s\nIndeks: %d\nKierunek: %s\nRok: %d\nGrupa: %d\n", Kacper.imie, Kacper.nazwisko, Kacper.indeks, Kacper.kierunek, Kacper.rok, Kacper.grupa);
}

void task2()
{
	//zadanie 2
	printf("Z2-------------------\n");
	struct Student ft_INF_8[15];
	int i = 0, j, c;
	for (i = 0; i < 15; i++)
	{
		char buf[100];
		fgets(buf, sizeof(buf), stdin);
		if (buf[0] == '\n')
		{
			break;
		}
		sscanf(buf, "%s %s %d %s %d %d", &ft_INF_8[i].imie, &ft_INF_8[i].nazwisko, &ft_INF_8[i].indeks, &ft_INF_8[i].kierunek, &ft_INF_8[i].rok, &ft_INF_8[i].grupa);
	}
	for (i = 0; i < 15; i++)//sort
	{
		for (j = i + 1; j < 15; j++)
		{
			struct Student temp;
			if (strcmp(ft_INF_8[i].nazwisko, ft_INF_8[j].nazwisko) > 0)
			{
				temp = ft_INF_8[i];
				ft_INF_8[i] = ft_INF_8[j];
				ft_INF_8[j] = temp;
			}
			else if (strcmp(ft_INF_8[i].nazwisko, ft_INF_8[j].nazwisko) == 0)
			{
				if (strcmp(ft_INF_8[i].imie, ft_INF_8[j].imie) > 0)
				{
					temp = ft_INF_8[i];
					ft_INF_8[i] = ft_INF_8[j];
					ft_INF_8[j] = temp;
				}
			}
			else
			{
				continue;
			}
		}
	}
	for (i = 0; i < 15; i++)//print
	{
		if (ft_INF_8[i].imie[0] != '\0')
		{
			printf("------------------------------\n");
			printf("Imie: %s\nNazwisko: %s\nIndeks: %d\nKierunek: %s\nRok: %d\nGrupa: %d\n", ft_INF_8[i].imie, ft_INF_8[i].nazwisko, ft_INF_8[i].indeks, ft_INF_8[i].kierunek, ft_INF_8[i].rok, ft_INF_8[i].grupa);
		}
	}
	printf("------------------------------\n");
}

void task3()
{
	//zadanie 3
	printf("Z3-------------------\n");
	printf("Rozmiar tablicy: \n");
	int size;
	scanf("%d", &size);
	struct Student* ft_INF_8 = (struct Student*)malloc(size * sizeof(*ft_INF_8));
	int i = 0, j, c;
	getchar();
	for (i = 0; i < size; i++)
	{
		char buf[100];
		fgets(buf, sizeof(buf), stdin);
		if (buf[0] == '\n')
		{
			int j;
			for (j = i; j < size; j++)
			{
				(ft_INF_8+j)->imie[0] = '\0';
				(ft_INF_8+j)->nazwisko[0] = '\0';
				(ft_INF_8+j)->indeks = 0;
				(ft_INF_8+j)->kierunek[0] = '\0';
				(ft_INF_8+j)->rok = 0;
				(ft_INF_8+j)->grupa = 0;
			}
			break;
		}
		sscanf(buf, "%s %s %d %s %d %d", &(ft_INF_8+i)->imie, &(ft_INF_8+i)->nazwisko, &(ft_INF_8+i)->indeks, &(ft_INF_8+i)->kierunek, &(ft_INF_8+i)->rok, &(ft_INF_8+i)->grupa);
	}


	for (i = 0; i < size; i++)//sort
	{
		for (j = i + 1; j < size; j++)
		{
			struct Student* temp = (struct Student*)malloc(size * sizeof(*ft_INF_8));
			if (strcmp((ft_INF_8+i)->nazwisko, (ft_INF_8+j)->nazwisko) > 0)
			{
				*temp = *(ft_INF_8+i);
				*(ft_INF_8+i) = *(ft_INF_8+j);
				*(ft_INF_8+j) = *temp;
			}
			else if (strcmp((ft_INF_8+i)->nazwisko, (ft_INF_8+j)->nazwisko) == 0)
			{
				if (strcmp((ft_INF_8+i)->imie, (ft_INF_8+j)->imie) > 0)
				{
					*temp = *(ft_INF_8+i);
					*(ft_INF_8+i) = *(ft_INF_8+j);
					*(ft_INF_8+j) = *temp;
				}
			}
			else
			{
				continue;
			}
			free(temp);
		}
	}
	
	for (i = 0; i < size; i++)//print
	{
		if ((ft_INF_8+i)->imie[0] != '\0')
		{
			printf("------------------------------\n");
			printf("Imie: %s\nNazwisko: %s\nIndeks: %d\nKierunek: %s\nRok: %d\nGrupa: %d\n", (ft_INF_8 + i)->imie, (ft_INF_8 + i)->nazwisko, (ft_INF_8 + i)->indeks, (ft_INF_8 + i)->kierunek, (ft_INF_8 + i)->rok, (ft_INF_8 + i)->grupa);
		}
	}
	printf("------------------------------\n");
	free(ft_INF_8);
}

void task4()
{
	//zadanie 4
	printf("Z4-------------------\n");
	printf("Rozmiar tablicy: \n");
	int size;
	scanf("%d", &size);
	struct Student* ft_INF_8 = new struct Student[size];
	int i = 0, j, c;
	getchar();
	for (i = 0; i < size; i++)
	{
		char buf[100];
		fgets(buf, sizeof(buf), stdin);
		if (buf[0] == '\n')
		{
			int j;
			for (j = i; j < size; j++)
			{
				(ft_INF_8 + j)->imie[0] = '\0';
				(ft_INF_8 + j)->nazwisko[0] = '\0';
				(ft_INF_8 + j)->indeks = 0;
				(ft_INF_8 + j)->kierunek[0] = '\0';
				(ft_INF_8 + j)->rok = 0;
				(ft_INF_8 + j)->grupa = 0;
			}
			break;
		}
		sscanf(buf, "%s %s %d %s %d %d", &(ft_INF_8 + i)->imie, &(ft_INF_8 + i)->nazwisko, &(ft_INF_8 + i)->indeks, &(ft_INF_8 + i)->kierunek, &(ft_INF_8 + i)->rok, &(ft_INF_8 + i)->grupa);
	}


	for (i = 0; i < size; i++)//sort
	{
		for (j = i + 1; j < size; j++)
		{
			struct Student* temp = new struct Student[size];
			if (strcmp((ft_INF_8 + i)->nazwisko, (ft_INF_8 + j)->nazwisko) > 0)
			{
				*temp = *(ft_INF_8 + i);
				*(ft_INF_8 + i) = *(ft_INF_8 + j);
				*(ft_INF_8 + j) = *temp;
			}
			else if (strcmp((ft_INF_8 + i)->nazwisko, (ft_INF_8 + j)->nazwisko) == 0)
			{
				if (strcmp((ft_INF_8 + i)->imie, (ft_INF_8 + j)->imie) > 0)
				{
					*temp = *(ft_INF_8 + i);
					*(ft_INF_8 + i) = *(ft_INF_8 + j);
					*(ft_INF_8 + j) = *temp;
				}
			}
			else
			{
				continue;
			}
			delete [] temp;
		}
	}

	for (i = 0; i < size; i++)//print
	{
		if ((ft_INF_8 + i)->imie[0] != '\0')
		{
			printf("------------------------------\n");
			printf("Imie: %s\nNazwisko: %s\nIndeks: %d\nKierunek: %s\nRok: %d\nGrupa: %d\n", (ft_INF_8 + i)->imie, (ft_INF_8 + i)->nazwisko, (ft_INF_8 + i)->indeks, (ft_INF_8 + i)->kierunek, (ft_INF_8 + i)->rok, (ft_INF_8 + i)->grupa);
		}
	}
	printf("------------------------------\n");
	delete [] ft_INF_8;
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
			getchar();
			task1();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 2:
			getchar();
			task2();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 3:
			getchar();
			task3();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
			scanf("%c", &cont);
			if (cont == 't')
			{
				check = 0;
			}
			break;
		case 4:
			getchar();
			task4();
			printf("Zakonczyc dzialanie programu? (t/n)\n");
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