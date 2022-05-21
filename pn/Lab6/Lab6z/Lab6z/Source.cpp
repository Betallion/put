#include <stdio.h>
#include <time.h> 
#include <stdlib.h> 

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

void taskX()
{
	
}

int main()
{
	srand(time(NULL));
	int* vector = randomVector();
	//printf("%d", vector[0]); 
	writeVector(vector, "plik.txt");
	getchar();
	int* vector2 = readVector("plik.txt");
	print(vector2);
	getchar();
	float* vector3 = floatVector();
	int n;
	printf("\n%d\n", sizeof(float));
	printf("n = ");
	scanf("%d", &n);
	writeFloatVector(vector3, "plik1.txt", "plik1.bin", n);
	getchar();
	int* vector4;
	float* vector5;
	vector4 = readBinaryInt("plik1.bin");
	vector5 = readBinaryFloat("plik1.bin");
	print2(vector4);
	printf("\n");
	print3(vector5);
	getchar();


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
		case X:
			taskX();
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

