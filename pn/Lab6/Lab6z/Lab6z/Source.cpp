#include <stdio.h>
#include <time.h> 
#include <stdlib.h> 
#include <string.h>
//plik naglowkowy do zadan z liczbami zespolonymi
#include "complex.h"

#include <random> 
using namespace std;

void writeVector(const int* vec, const char fileName[])
{
	FILE* file;
	file = fopen(fileName, "wt");
	int i;
	if (file == NULL)
	{
		printf("error\n");
	}
	else
	{
		for (i = 0; i < 100; i++)
		{
			fprintf(file, "%d ", vec[i]);
		}
	}
	fclose(file);
}

int* randomVector()
{
	int* vector = (int*)malloc(100 * (sizeof(int)));
	int i;
	for (i = 0; i < 100; i++)
	{
		vector[i] = rand();
	}
	return vector;
}

int* readVector(const char fileName[])
{
	int* vector = (int*)malloc(100 * (sizeof(int)));
	FILE* file;
	file = fopen(fileName, "rt");
	int i = 0;
	if (file == NULL)
	{
		printf("error\n");
	}
	else
	{
		while (!feof(file))
		{
			fscanf(file, "%d ", &vector[i]);
			i++;
		}
	}
	fclose(file);
	return vector;
}

void print(const int* tab)
{
	int i;
	for (i = 0; i < 100; i++)
	{
		printf("%d ", tab[i]);
	}
}

float random()
{
	static default_random_engine e{};
	uniform_real_distribution<float> d;
	return d(e);
}

float* floatVector()
{
	int n;
	printf("n = ");
	scanf("%d", &n);
	float* vector = (float*)malloc(n * (sizeof(float)));
	int i;
	for (i = 0; i < n; i++)
	{
		vector[i] = random();
	}
	return vector;
}

void writeFloatVector(const float* vec, const char fileNameT[], const char fileNameB[], const int n)
{
	FILE* fileT;
	FILE* fileB;
	fileT = fopen(fileNameT, "wt");
	fileB = fopen(fileNameB, "wb");
	int i;
	if (fileT == NULL)
	{
		printf("error\n");
	}
	else
	{
		if (fileB == NULL)
		{
			printf("error\n");
		}
		else
		{
			for (i = 0; i < n; i++)
			{
				fprintf(fileT, "%f ", vec[i]);
				fwrite(&vec[i], sizeof(float), 1, fileB);
			}
		}
	}
	fclose(fileT);
	fclose(fileB);
}

int* readBinaryInt(const char fileName[])
{
	int* vector;
	FILE* file;
	file = fopen(fileName, "rb");
	int i = 0;
	if (file == NULL)
	{
		printf("error\n");
		return NULL;
	}
	else
	{
		fseek(file, 0, SEEK_END);
		int size = ftell(file);
		fseek(file, 0, SEEK_SET);
		vector = (int*)malloc(size * sizeof(int));
		while (!feof(file))
		{
			fread(&vector[i], sizeof(int), 1, file);
			i++;
		}
	}
	fclose(file);
	return vector;
}

float* readBinaryFloat(const char fileName[])
{
	float* vector;
	FILE* file;
	file = fopen(fileName, "rb");
	int i = 0;
	if (file == NULL)
	{
		printf("error\n");
		return NULL;
	}
	else
	{
		fseek(file, 0, SEEK_END);
		int size = ftell(file);
		fseek(file, 0, SEEK_SET);
		vector = (float*)malloc(size * sizeof(float));
		while (!feof(file))
		{
			fread(&vector[i], sizeof(float), 1, file);
			i++;
		}
	}
	fclose(file);
	return vector;
}

void print2(const int* tab)
{
	int i;
	for (i = 0; i < 50; i++)
	{
		printf("%d ", tab[i]);
		if (i % 4 == 0)
		{
			printf("\n");
		}
	}
}

void print3(const float* tab)
{
	int i;
	for (i = 0; i < 50; i++)
	{
		printf("%f ", tab[i]);
		if (i % 4 == 0)
		{
			printf("\n");
		}
	}
}


//zadanie 6

//zapisanie liczb zespolonych w pliku binarnym
void write_complex(const char filename[], complex* numbers, int n)
{
	//otwarcie pliku binarnego w trybie zapisu
	FILE* file;
	file = fopen(filename, "wb");
	int i;
	if (file == NULL)
	{
		printf("error\n");
	}
	else
	{
		//jesli poprawnie otwarty, przejdz po n elementach tablicy i zapisz w pliku
		for (i = 0; i < n; i++)
		{
			fwrite(&numbers[i], sizeof(complex), 1, file);
			//kontrolne wypisanie wartosci
			printf("The number is %f + %f i\n", numbers[i].real, numbers[i].imaginary);
		}
	}
	printf("Writing done\n");
	//zamkniecie pliku
	fclose(file);
}

//odczytanie liczb zespolonych z pliku binarnego
void read_complex(const char filename[])
{
	//otwarcie pliku w trybie odczytu
	FILE* file;
	file = fopen(filename, "rb");
	int i = 0;
	if (file == NULL)
	{
		printf("error\n");
	}
	else
	{
		//jesli ok to wczytuj kolejne liczby zespolone do zmiennej tempr
		//az do konca pliku i wypisuj
		complex tempr;
		while (fread(&tempr, sizeof(complex), 1, file))
		{
			printf("The number is %f + %f i\n", tempr.real, tempr.imaginary);
		}
	}
	//zamkniecie pliku
	fclose(file);
}


//zadanie 8

//struktura bedaca wezlem listy
struct complexNode 
{
	complex number;
	complexNode* next;
};

//funkcja tworzaca liste liczb zespolonych
struct complexNode* create_list(int amount)
{
	int i;
	//utworz wskaznik na liste
	complexNode* list = NULL;
	for (i = 0; i < amount; i++)
	{
		if (list == NULL)
		{
			//jesli lista jest pusta, to zaalokuj pamiec
			//wylosuj wartosc i ustaw wskaznik kolejnego elementu na NULL
			list = (complexNode*)malloc(sizeof(complexNode));
			list->number.real = random();
			list->number.imaginary = random();
			list->next = NULL;			
		}
		else
		{
			//jesli lista nie jest pusta, utworz wskaznik temp wskazujacy na poczatek listy
			complexNode* temp = list;
			//przechodz przez kolejne elementy listy az do ostatniego
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			//zaalokuj pamiec dla nastepnego elementu
			//i wylosuj wartosci liczby, oznacz next jako null
			temp->next = (complexNode*)malloc(sizeof(complexNode));
			temp->next->number.real = random();
			temp->next->number.imaginary = random();
			temp->next->next = NULL;
		}
	}
	//zwrocenie wskaznika do listy
	return list;
}

//wypisanie listy liczb zespolonych
void print_list(complexNode* list)
{
	//utworzenie wskaznika na liste
	complexNode* temp = list;
	int i = 1;
	while (temp != NULL)
	{
		//wypisuj wartosci liczb i ustawiaj wskaznik na kolejny element
		//tak dlugo az wskaznik kolejnego elementu nie wskazuje na NULL
		printf("%d liczba: %f + %f i\n", i, temp->number.real, temp->number.imaginary);
		i++;
		temp = temp->next;
	}
}

//posortowanie listy liczb zespolonych wg pewnego okreslonego porzadku
//algorytm - selection sort
void sort_list(complexNode* list, int(*order)(const complex, const complex))
{
	struct complexNode* temp = list;
	while (temp)
	{
		struct complexNode* min = temp;
		struct complexNode* r = temp->next;
		while (r)
		{
			//sprawdzenie porzadku - funkcja przekazana przez wskaznik
			//czy r jest mniejsze lub rowne min = czy min jest wieksze od r
			//znajdowanie minimum
			if (order(r->number, min->number))
			{
				min = r;
			}
			r = r->next;
		}
		//temp otrzymuje wartosc minimum
		//minimum otrzymuje wartosc temp - obecnie sprawdzany element
		//temp przechodzi do kolejnego elementu
		complex x = temp->number;
		temp->number = min->number;
		min->number = x;
		temp = temp->next;
	}
}


//zadanie 9 - przepisanie zawartosci pliku marks.txt do pliku binarnego

//struktura zawierajaca dane z pliku tekstowego
struct studentFirst 
{
	int indeks;
	char imie[40];
	char nazwisko[40];
	float wynik;
};

void rewrite(const char txtfile[], const char binfile[])
{
	//otwarcie plikow - tekstowego do odczytu, binarnego do zapisu
	FILE* fileT;
	FILE* fileB;
	fileT = fopen(txtfile, "rt");
	fileB = fopen(binfile, "wb");
	int i;
	if (fileT == NULL)
	{
		printf("error\n");
	}
	else
	{
		if (fileB == NULL)
		{
			printf("error\n");
		}
		else
		{
			//jesli pliki sie otworzyly - odczytaj liczbe wierszy
			//i zapisz w pliku binarnym
			int num;
			fscanf(fileT, "%d", &num);
			fwrite(&num, sizeof(int), 1, fileB);
			struct studentFirst st;
			//tyle ile jest wierszy, tyle razy odczytaj wartosci z pliku tekstowego
			//do struktury i zapisz ja w pliku binarnym
			for (i = 0; i < num; i++)
			{
				fscanf(fileT, "%d %s %s %f", &st.indeks, st.nazwisko, st.imie, &st.wynik);
				fwrite(&st, sizeof(studentFirst), 1, fileB);
			}
		}
	}
	//zamkniecie plikow
	fclose(fileT);
	fclose(fileB);

	//plik binarny jest wiekszy od pliku tekstowego
	//jest to spowodowane tym, ze w strukturze
	//wielkosc pol imie i nazwisko jest stala
	//i za kazdym razem wpisywane jest cale pole
}


/*
void printResult2(const char filename[])
{
	FILE* file;
	file = fopen(filename, "rb");
	int n;
	if (file == NULL)
	{
		printf("error\n");
	}
	else
	{
		fread(&n, sizeof(int), 1, file);
		studentFirst data;
		int i;
		for (i = 0; i < n; i++)
		{
			fread(&data, sizeof(studentFirst), 1, file);
			printf("Indeks: %d, Nazwisko: %s, Imie: %s, Punkty: %f\n", data.indeks, data.nazwisko, data.imie, data.wynik);
		}
	}
	fclose(file);
}
*/

//zadanie 10 - dodanie obliczonej wartosci procentowej do wynikow w pliku binarnym

//struktura studenta z dodanym polem na wartosc procentowa
struct studentSecond 
{
	int indeks;
	char imie[40];
	char nazwisko[40];
	float wynik;
	float procent;
};


//dodanie procentow do kazdego wiersza
void addPercentage(const char filename[])
{
	//otwarcie pliku w trybie do odczytu i zapisu
	FILE* file;
	file = fopen(filename, "rb+");
	int n;
	if (file == NULL)
	{
		printf("error\n");
	}
	else
	{
		//odczytywana jest liczba wierszy i alokowana tablica struktur
		//o rozmiarze rownym liczbie wierszy
		fread(&n, sizeof(int), 1, file);
		studentSecond* data = (studentSecond*)malloc(n * sizeof(studentSecond));
		int i;
		for (i = 0; i < n; i++)
		{
			//do kolejnych komorek tablicy wczytywane sa
			//struktury odczytane z pliku binarnego
			//a nastepnie do nowych struktur wpisywana
			//jest wartosc procentowa
			//test byl na max 20 punktow, wiec wynik * 5 daje procenty
			fread(&data[i], sizeof(studentFirst), 1, file);
			float procent = data[i].wynik * 5;
			data[i].procent = procent;
		}
		//przesuniecie sie na poczatek pliku
		//i ponowne wpisanie liczby wierszy
		fseek(file, 0, SEEK_SET);
		fwrite(&n, sizeof(int), 1, file);
		//wpisanie nowych struktur do pliku
		for (i = 0; i < n; i++)
		{
			fwrite(&data[i], sizeof(studentSecond), 1, file);
		}
		//zwolnienie z pamieci tablicy struktur
		free(data);
	}
	//zamkniecie pliku
	fclose(file);

}

//wypisanie zawartosci pliku binarnego z procentami
void printResult(const char filename[])
{
	//otwarcie pliku w trybie do odczytu
	FILE* file;
	file = fopen(filename, "rb");
	int n;
	if (file == NULL)
	{
		printf("error\n");
	}
	else
	{
		//jesli ok odczytywana jest liczba wierszy 
		//i tworzona tymczasowa struktura do odczytywania danych
		fread(&n, sizeof(int), 1, file);
		studentSecond data;
		int i;
		for (i = 0; i < n; i++)
		{
			//tyle ile jest wierszy, tyle razy odczytywane sa dane
			//ktore sa nastepnie wypisane w sposob sformatowany
			fread(&data, sizeof(studentSecond), 1, file);
			printf("Indeks: %d, Nazwisko: %s, Imie: %s, Punkty: %f, Procenty: %f\n", data.indeks, data.nazwisko, data.imie, data.wynik, data.procent);
		}
	}
	//zamkniecie pliku
	fclose(file);
}

//zadanie 11
//struktura wezla slownika 
struct dictNode 
{
	char character;
	int amount;
	dictNode* next;
};

//wstawienie znaku do slownika
void insertIntoDict(dictNode** dict, char c)
{
	//jesli slownik jest pusty
	if (*dict == NULL)
	{
		//sprawdzenie czy znak jest dozwolony
		//czyli jest to mala/wielka litera lub cyfra
		if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		{
			//alokacja wezla slownika, ustalenie znaku i ustawienie licznika na 1
			dictNode* temp = (dictNode*)malloc(sizeof(dictNode));
			temp->character = c;
			temp->amount = 1;
			temp->next = NULL;
			*dict = temp;
		}
	}
	else
	{
		//jesli slownik nie jest pusty
		dictNode* temp = *dict;
		if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) 
		{
			//przechodzenie po kolejnych wezlach
			//jesli ktorys z wezlow ma ten sam znak ktory
			//jest wstawiany to licznik jest zwiekszany o 1
			while (temp->next != NULL)
			{
				if (temp->character == c)
				{
					temp->amount += 1;
					return;
				}
				temp = temp->next;
			}
			if (temp->character == c)
			{
				temp->amount += 1;
				return;
			}
			else
			{
				//jesli w przeszukiwaniu nie natrafiono na ten znak
				//to alokowana jest pamiec na kolejny wezel i
				//znak jest wstawiany do slownika, z licznikiem ustawionym na 1
				temp->next = (dictNode*)malloc(sizeof(dictNode));
				temp->next->character = c;
				temp->next->amount = 1;
				temp->next->next = NULL;
			}
			
		}
	}
}

//struktura wezla drzewa BST
struct nodeBST {
	char character;
	int amount;
	struct nodeBST* left, * right;
};

//wypisanie drzewa BST - inorder
void print_BST(struct nodeBST* root) {
	if (root != NULL) {
		print_BST(root->left);
		printf("%c:    %d\n", root->character, root->amount);
		print_BST(root->right);
	}
}

//wstawianie wezla slownika do drzewa BST
struct nodeBST* insert_intoBST(struct nodeBST* node, char character, int amount) {
	//jesli nie ma danego wezla to alokowana jest pamiec
	//i do wezla wstawiany jest znak i liczba jego wystapien
	if (node == NULL)
	{
		node = (struct nodeBST*)malloc(sizeof(struct nodeBST));
		node->character = character;
		node->amount = amount;
		node->left = node->right = NULL;
		return node;
	}
	//jesli wstawiany znak ma nizszy kod ASCII od obecnie sprawdzanego
	//to przechodzi on rekurencyjnie w lewa galaz drzewa
	if (character < node->character)
	{
		node->left = insert_intoBST(node->left, character, amount);
	}
	else //to samo, tylko jesli ma wyzszy kod ASCII to przechodzi w prawa galaz
	{
		node->right = insert_intoBST(node->right, character, amount);
	}
	return node;
}

//wrzucenie wezlow slownika do drzewa BST
nodeBST* dictToBST(dictNode* dict)
{
	nodeBST* bst = NULL;
	//przechodzenie po kazdym wezle slownika
	while (dict != NULL)
	{
		bst = insert_intoBST(bst, dict->character, dict->amount);
		dict = dict->next;
	}
	return bst;
}

void task1()
{
	int* vector = randomVector();
	writeVector(vector, "plik.txt");
}
void task2()
{
	int* vector2 = readVector("plik.txt");
	print(vector2);
}
void task3()
{
	float* vector3 = floatVector();
	int n;
	printf("\n%d\n", sizeof(float));
	printf("n = ");
	scanf("%d", &n);
	writeFloatVector(vector3, "plik1.txt", "plik1.bin", n);
}
void task4()
{
	int* vector4;
	float* vector5;
	vector4 = readBinaryInt("plik1.bin");
	vector5 = readBinaryFloat("plik1.bin");
	print2(vector4);
	printf("\n");
	print3(vector5);
}
void task5()
{
	complex a;
	complex b;
	a.real = random();
	a.imaginary = random();
	b.real = random();
	b.imaginary = random();
	complex c = add(a, b);
	printf("%f + %f i  +  %f + %f i  =  %f + %f i\n", a.real, a.imaginary, b.real, b.imaginary, c.real, c.imaginary);
	c = subtract(a, b);
	printf("%f + %f i  -  %f + %f i  =  %f + %f i\n", a.real, a.imaginary, b.real, b.imaginary, c.real, c.imaginary);
	c = multiply(a, b);
	printf("%f + %f i  *  %f + %f i  =  %f + %f i\n", a.real, a.imaginary, b.real, b.imaginary, c.real, c.imaginary);
	int d = equals(a, b);
	printf("%f + %f i  =  %f + %f i : %d \n", a.real, a.imaginary, b.real, b.imaginary, d);
}
void task6()
{
	complex numbers[5];
	numbers[0].real = random();
	numbers[0].imaginary = random();
	numbers[1].real = random();
	numbers[1].imaginary = random();
	numbers[2].real = random();
	numbers[2].imaginary = random();
	numbers[3].real = random();
	numbers[3].imaginary = random();
	numbers[4].real = random();
	numbers[4].imaginary = random();
	write_complex("complex.bin", numbers, 5);
	read_complex("complex.bin");

}
void task7()
{

}
void task8()
{
	complexNode* list = create_list(10);
	print_list(list);
	sort_list(list, less_or_equal_1);
	print_list(list);
	sort_list(list, less_or_equal_2);
	print_list(list);
	sort_list(list, less_or_equal_3);
	print_list(list);
}
void task9()
{
	rewrite("marks.txt", "marks.bin");
}
void task10()
{
	addPercentage("marks.bin");
	printResult("marks.bin");
}
void task11()
{
	char text[200];
	scanf("%s", text);
	int i;
	dictNode* dict = NULL;
	for (i = 0; i < 200; i++)
	{
		insertIntoDict(&dict, text[i]);
	}
	nodeBST* bst = dictToBST(dict);
	print_BST(bst);
}

int main()
{
	srand(time(NULL));

	//tasks
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
		default:
			printf("niepoprawna liczba\n");
			break;
		}

	} while (check == 1);
	return 0;
}

