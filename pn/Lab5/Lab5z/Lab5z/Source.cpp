#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <math.h>

float firstSum(unsigned int first, unsigned int second)
{
	unsigned int i;
	float sum = 0;
	if (first < second)
	{
		for (i = first; i <= second; i++)
		{
			float temp = i * i;
			sum += (1 / temp);
		}
	}
	else {
		for (i = first; i >= second; i--)
		{
			float temp = i * i;
			sum += (1 / temp);
		}
	}

	return sum;
}

double secondSum(unsigned int precision)
{
	double resultBefore = 0;
	double resultAfter = 1.0;
	double precisionValue = 1.0;
	unsigned int i;
	for (i = 0; i < precision; i++)
	{
		precisionValue /= 10;
	}
	i = 1;
	while (fabs(resultAfter - resultBefore) > precisionValue)
	{
		double temp = pow(-1, i);
		resultBefore = resultAfter;
		resultAfter += temp / ((2 * i) + 1);
		i++;
	}
	return resultAfter;
}

double** createMatrix(unsigned int rows, unsigned int cols)
{
	unsigned int i;
	double** matrix = (double**)calloc(rows, sizeof(double*));
	for (i = 0; i < rows; i++)
	{
		matrix[i] = (double*)calloc(cols, sizeof(double));
	}
	return matrix;
}

double** randomizeMatrix(double** matrix, unsigned int rows, unsigned int cols)
{
	srand(time(0));
	unsigned int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			matrix[i][j] = rand();
		}
	}
	return matrix;
}

double** addMatrices(double** firstMatrix, double** secondMatrix, unsigned int rows, unsigned int cols)
{
	double** newMatrix = createMatrix(rows, cols);
	unsigned int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			newMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
		}
	}
	return newMatrix;
}

double** multiplyMatrices(double** firstMatrix, double** secondMatrix, unsigned int firstRows, unsigned int rowCol, unsigned int secondCols)
{
	double** newMatrix = createMatrix(firstRows, secondCols);
	unsigned int i, j;
	for (i = 0; i < firstRows; i++)
	{
		for (j = 0; j < secondCols; j++)
		{

		}
	}
	return newMatrix;
}

double calculateMatrixDeterminant()
{

}

void taskX()
{
	
}

int main()
{
	float result = firstSum(1, 10000);
	float result2 = firstSum(10000, 1);
	printf("first: %f, second: %f\n", result, result2);

	double result3 = secondSum(4);
	result3 *= 4;
	printf("result: %f\n", result3);
	getchar();

	// tasks
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

