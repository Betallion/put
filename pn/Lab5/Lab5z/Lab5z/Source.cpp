#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <math.h>

//----------------------
//Polynomial
//----------------------


struct Polynomial
{
	unsigned int degree;
	int value;
};

struct Polynomial* getPolynomial()
{
	int n, i;
	printf("n = ");
	scanf("%d", &n);
	struct Polynomial* poly = (struct Polynomial*)malloc((n + 1) * sizeof(struct Polynomial));
	for (i = n; i >= 0; i--)
	{
		scanf("%d", &poly[i].value);
		poly[i].degree = i;
	}
	return poly;
}

float* dividers(int p, int q)
{
	int i, j, pcount = 0, qcount = 0;

	for (i = 1; i <= abs(p); i++)
	{
		if (abs(p) % i == 0)
		{
			pcount += 2;
		}
	}
	for (i = 1; i <= abs(q); i++)
	{
		if (abs(q) % i == 0)
		{
			qcount += 2;
		}
	}
	float* d = (float*)malloc(pcount * qcount * sizeof(float));
	int counter = 0;
	for (i = 1; i <= abs(p); i++)
	{
		for (j = 1; j <= abs(q); i++)
		{
			if (abs(p) % i == 0)
			{
				if (abs(q) % i == 0)
				{
					d[counter] = (float)abs(p) / (float)abs(q);
					d[counter + 1] = -(float)abs(p) / (float)abs(q);
					d[counter + 2] = (float)abs(p) / -(float)abs(q);
					d[counter + 3] = -(float)abs(p) / -(float)abs(q);
					counter += 4;
				}
			}
			
		}
		
	}
	
	return d;
}

int count(int x)
{
	int i, count = 0;
	for (i = 1; i <= abs(x); i++)
	{
		if (abs(x) % i == 0)
		{
			count += 2;
		}
	}
	return count;
}

int floatcompare(const void* x, const void* y)
{
	if (*(const float*)x < *(const float*)y) return -1;
	return *(const float*)x > *(const float*)y;
}

void polynomialResult(struct Polynomial* poly, unsigned int degree)
{
	int p = poly[0].value;
	int q = poly[degree].value;
	int pcount = count(p);
	int qcount = count(q);
	float* d = dividers(p, q);
	int i, j;
	qsort(d, pcount * qcount, sizeof(float), floatcompare);
	for (i = 0; i < pcount * qcount; i++)
	{
		float tempsum = 0.0;
		for (j = 0; j <= degree; j++)
		{
			tempsum += poly[j].value * pow(d[i], poly[j].degree);
		}
		if (tempsum == 0.0)
		{
			printf("\n%f jest pierwiastkiem\n", d[i]);
		}

	}
	free(d);
}

//----------------------
//BST
//----------------------

struct nodeBST {
	int key;
	struct nodeBST* left, *right;
};

struct nodeBST* create_BST(int value) {
	struct nodeBST* temp = (struct nodeBST*)malloc(sizeof(struct nodeBST));
	temp->key = value;
	temp->left = temp->right = NULL;
	return temp;
}

void print_BST(struct nodeBST* root) {
	if (root != NULL) {
		print_BST(root->left);
		printf("%d -> ", root->key);
		print_BST(root->right);
	}
}

struct nodeBST* insert_intoBST(struct nodeBST* node, int value) {
	if (node == NULL)
	{
		node = (struct nodeBST*)malloc(sizeof(struct nodeBST));
		node->key = value;
		node->left = node->right = NULL;
		return node;
	}
	if (value < node->key)
	{
		node->left = insert_intoBST(node->left, value);
	}
	else
	{
		node->right = insert_intoBST(node->right, value);
	}
	return node;
}

struct nodeBST* min_valueBST(struct nodeBST* node) {
	struct nodeBST* current = node;
	while (current && current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

struct nodeBST* delete_fromBST(struct nodeBST* root, int value) {
	if (root == NULL)
	{
		return root;
	}
	if (value < root->key)
	{
		root->left = delete_fromBST(root->left, value);
	}
	else if (value > root->key)
	{
		root->right = delete_fromBST(root->right, value);
	}
	else 
	{
		if (root->left == NULL) 
		{
			struct nodeBST* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) 
		{
			struct nodeBST* temp = root->left;
			free(root);
			return temp;
		}
		struct nodeBST* temp = min_valueBST(root->right);
		root->key = temp->key;
		root->right = delete_fromBST(root->right, temp->key);
	}
	return root;
}

int is_contained_inBST(struct nodeBST* node, int value)
{
	if (node == NULL)
	{
		return 0;
	}
	if (node->key == value)
	{
		return 1;
	}
	if (node->key < value)
	{
		return is_contained_inBST(node->right, value);
	}
	else
	{
		return is_contained_inBST(node->left, value);
	}
}

int calculate_height_ofBST(struct nodeBST* node)
{
	if (node == NULL)
	{
		return 0;
	}
	else
	{
		int left, right;
		left = calculate_height_ofBST(node->left);
		right = calculate_height_ofBST(node->right);
		if (left > right)
		{
			return left + 1;
		}
		else
		{
			return right + 1;
		}
	}
}

void clear_BST(struct nodeBST* node)
{
	if (node != NULL)
	{
		clear_BST(node->left);
		clear_BST(node->right);
		free(node);
	}
}

int is_empty_BST(struct nodeBST* node)
{
	if (node == NULL)
	{
		return 1;
	}
	return 0;
}

//----------------------
//Sort - list, array
//----------------------

struct listNode
{
	int value;
	struct listNode* next;
};

void insertIntoList(struct listNode* head, int val) {
	struct listNode* current = head;
	while (current->next != NULL) 
	{
		current = current->next;
	}
	current->next = (struct listNode*)malloc(sizeof(struct listNode));
	current->next->value = val;
	current->next->next = NULL;
}


int* generateNumbers()
{
	int* numbers = (int*)malloc(300 * sizeof(int));
	int i;
	for (i = 0; i < 300; i++)
	{
		numbers[i] = rand() % 1000;
	}
	return numbers;
}

int* arrayFromNumbers(int* numbers)
{
	int* array = (int*)malloc(300 * sizeof(int));
	int i;
	for (i = 0; i < 300; i++)
	{
		array[i] = numbers[i];
	}
	return array;
}

struct listNode* listFromNumbers(int* numbers)
{
	int i;
	struct listNode* list = (struct listNode*)malloc(sizeof(struct listNode));
	list->next = NULL;
	list->value = 0;
	for (i = 0; i < 300; i++)
	{
		insertIntoList(list, numbers[i]);
	}
	return list;
}

void printArray(int* array)
{
	int i;
	for (i = 0; i < 300; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%d ", array[i]);
	}
}

void printList(struct listNode* list)
{
	int i;
	for (i = 0; i < 300; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%d ", list->value);
		list = list->next;
	}
}

void selectionSortArray(int* array)
{
	int i, j, min;
	for (i = 0; i < 299; i++)
	{
		min = i;
		for (j = i + 1; j < 300; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		int temp = array[min];
		array[min] = array[i];
		array[i] = temp;
	}
}

void selectionSortList(struct listNode* list)
{
	struct listNode* temp = list;
	while (temp)
	{
		struct listNode* min = temp;
		struct listNode* r = temp->next;
		while (r)
		{
			if (min->value > r->value)
			{
				min = r;
			}
			r = r->next;
		}
		int x = temp->value;
		temp->value = min->value;
		min->value = x;
		temp = temp->next;
	}
}

void measureTimes(int* array, struct listNode* list)
{
	double arrayGenSum = 0;
	double arraySortSum = 0;
	double arrayPrintSum = 0;
	double listGenSum = 0;
	double listSortSum = 0;
	double listPrintSum = 0;
	int i;
	for (i = 0; i < 1000; i++)
	{
		int* numbers = generateNumbers();
		clock_t start;
		clock_t end;
		start = clock();
		array = arrayFromNumbers(numbers);
		end = clock();
		arrayGenSum += ((double)(end - start)) / CLOCKS_PER_SEC;
		start = clock();
		selectionSortArray(array);
		end = clock();
		arraySortSum += ((double)(end - start)) / CLOCKS_PER_SEC;
		start = clock();
		printArray(array);
		end = clock();
		arrayPrintSum += ((double)(end - start)) / CLOCKS_PER_SEC;
		start = clock();
		list = listFromNumbers(numbers);
		end = clock();
		listGenSum += ((double)(end - start)) / CLOCKS_PER_SEC;
		start = clock();
		selectionSortList(list);
		end = clock();
		listSortSum += ((double)(end - start)) / CLOCKS_PER_SEC;
		start = clock();
		printList(list);
		end = clock();
		listPrintSum += ((double)(end - start)) / CLOCKS_PER_SEC;
	}
	arrayGenSum /= 1000.0;
	arraySortSum /= 1000.0;
	arrayPrintSum /= 1000.0;
	listGenSum /= 1000.0;
	listSortSum /= 1000.0;
	listPrintSum /= 1000.0;
	printf("\nSredni czas generowania\nlista: %f, tablica: %f", listGenSum, arrayGenSum);
	printf("\nSredni czas sortowania\nlista: %f, tablica: %f", listSortSum, arraySortSum);
	printf("\nSredni czas wypisywania\nlista: %f, tablica: %f\n", listPrintSum, arrayPrintSum);
}



//----------------------
//Sort - 3 algorithms
//----------------------

void swap(int* a, int* b) 
{
	int t = *a;
	*a = *b;
	*b = t;
}

void bubbleSort(int* array, int size) 
{
	int step, i;
	for (step = 0; step < size - 1; step++) 
	{
		for (i = 0; i < size - step - 1; i++) 
		{
			if (array[i] > array[i + 1]) 
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
}

int partition(int* array, int low, int high) 
{
	int pivot = array[high];
	int i = (low - 1);
	int j;
	for (j = low; j < high; j++) 
	{
		if (array[j] <= pivot) 
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void quickSortS(int* array, int low, int high)
{
	if (low < high) 
	{
		int pi = partition(array, low, high);
		quickSortS(array, low, pi - 1);
		quickSortS(array, pi + 1, high);
	}
}

void quickSort(int* array, int n)
{
	int low = 0;
	quickSortS(array, low, n);
}

void makeHeap(int* array, int n, int i) 
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && array[left] > array[largest])
	{
		largest = left;
	}

	if (right < n && array[right] > array[largest])
	{
		largest = right;
	}
	if (largest != i) 
	{
		swap(&array[i], &array[largest]);
		makeHeap(array, n, largest);
	}
}

void heapSort(int* array, int n) 
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
	{
		makeHeap(array, n, i);
	}
	for (i = n - 1; i >= 0; i--) 
	{
		swap(&array[0], &array[i]);
		makeHeap(array, i, 0);
	}
}

double measureTimeOf(int* data, int size, void(*sort)(int[], int))
{
	clock_t start;
	clock_t end;
	start = clock();
	sort(data, size);
	end = clock();
	double result = ((double)(end - start)) / CLOCKS_PER_SEC;
	return result;
}







//----------------------
//Sums
//----------------------

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
	unsigned int i, j, k;
	for (i = 0; i < firstRows; i++)
	{
		for (j = 0; j < secondCols; j++)
		{
			for (k = 0; k < rowCol; k++)
			{
				newMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}
	return newMatrix;
}

void cofactor(double** matrix, double** temp, int x, int y, int n)
{
	//double** temp = createMatrix(n, n);
	int i = 0, j = 0, row, col;
	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n; col++)
		{
			if (row != x && col != y)
			{
				temp[i][j++] = matrix[row][col];
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
	//return temp;
}

double calculateMatrixDeterminant(double** matrix, unsigned int n)
{
	double det = 0;
	int i;
	if (n == 1)
	{
		return matrix[0][0];
	}
	double** temp = createMatrix(n, n);
	int sign = 1;
	for (i = 0; i < n; i++)
	{
		cofactor(matrix, temp, 0, i, n);
		det += sign * matrix[0][i] * calculateMatrixDeterminant(temp, n - 1);
		sign = -sign;
	}
	return det;
}

void task1()
{
	float result = firstSum(1, 10000);
	float result2 = firstSum(10000, 1);
	printf("first: %f, second: %f\n", result, result2);
}
void task2()
{
	double result3 = secondSum(4);
	result3 *= 4;
	printf("result: %f\n", result3);
}
void task3()
{

}
void task4()
{

}
void task5()
{
	struct nodeBST* bst = NULL;
	printf(is_empty_BST(bst) ? "\nBST is empty\n" : "\nBST is not empty\n");
	bst = insert_intoBST(bst, 5);
	bst = insert_intoBST(bst, 3);
	bst = insert_intoBST(bst, 7);
	bst = insert_intoBST(bst, 4);
	bst = insert_intoBST(bst, 2);
	printf(is_empty_BST(bst) ? "BST is empty\n" : "BST is not empty\n");
	printf("BST contains element of value 3: %d\n", is_contained_inBST(bst, 3));
	printf("BST contains element of value 9: %d\n", is_contained_inBST(bst, 9));
	print_BST(bst);
	bst = delete_fromBST(bst, 4);
	print_BST(bst);
	bst = delete_fromBST(bst, 8);
	printf("Height of BST: %d\n", calculate_height_ofBST(bst));
	clear_BST(bst);
	printf(is_empty_BST(bst) ? "BST is empty\n" : "BST is not empty\n");
}
void task6()
{
	int* array = NULL;
	struct listNode* list = NULL;
	measureTimes(array, list);
}

int* copyData(int* data)
{
	int* data1 = (int*)malloc(300 * sizeof(int));
	int i;
	for (i = 0; i < 300; i++)
	{
		data1[i] = data[i];
	}
	return data1;
}
void task7()
{
	int i, size = 300;
	double avgBS = 0.0;
	double avgHS = 0.0;
	double avgQS = 0.0;
	for (i = 0; i < 1000; i++)
	{
		int* data = generateNumbers();
		int* dataBS = copyData(data);
		int* dataHS = copyData(data);
		int* dataQS = copyData(data);
		avgBS += measureTimeOf(dataBS, size, bubbleSort);
		avgHS += measureTimeOf(dataHS, size, heapSort);
		avgQS += measureTimeOf(dataQS, size, quickSort);
	}
	avgBS /= 1000.0;
	avgHS /= 1000.0;
	avgQS /= 1000.0;
	printf("\nBS %f\nHS %f\nQS %f\n", avgBS, avgHS, avgQS);
}







void task8()
{

}

int main()
{
	srand(time(NULL));
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
		default:
			printf("niepoprawna liczba\n");
			break;
		}

	} while (check == 1);
	return 0;
}

