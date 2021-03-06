#define _HAS_CXX17 1
#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <filesystem>
#include <iomanip>
using namespace std;
using namespace std::chrono;
using namespace std::filesystem;


//wezel drzewa
struct BSTNode
{
	int data;
	BSTNode* left;
	BSTNode* right;
	BSTNode* up;
	int height;
};

//maksimum z 2 wartosci
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//zwraca wysokosc drzewa
int height(BSTNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return root->height;
}

//zwraca minimalna wartosc w drzewie
BSTNode* minValue(BSTNode* root)
{
	BSTNode* current = root;
	while (current->left != nullptr)
	{
		current = current->left;
	}
	return current;
}

//zwraca maksymalna wartosc w drzewie
BSTNode* maxValue(BSTNode* root)
{
	BSTNode* current = root;
	while (current->right != nullptr)
	{
		current = current->right;
	}
	return current;
}

//wypisuje minimalna wartosc w drzewie + kroki
void printMinValue(BSTNode* root)
{
	BSTNode* current = root;
	while (current->left != nullptr)
	{
		cout << current->data << " ";
		current = current->left;
	}
	cout << "[min]:" << current->data << endl;
}

//wypisuje maksymalna wartosc w drzewie + kroki
void printMaxValue(BSTNode* root)
{
	BSTNode* current = root;
	while (current->right != nullptr)
	{
		cout << current->data << " ";
		current = current->right;
	}
	cout << "[max]:" << current->data << endl;
}

//wypisuje drzewo - pre order
void printPreOrder(BSTNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->data << " ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

//wypisuje drzewo - in order
void printInOrder(BSTNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	printInOrder(root->left);
	cout << root->data << " ";
	printInOrder(root->right);
}

//usuwa cale drzewo - post order, element po elemencie
void destroyTree(BSTNode* root)
{
	if (root != nullptr)
	{
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
	}
}

//wstawia element do drzewa
BSTNode* insertBST(BSTNode* &root, int data)
{
	if (root == nullptr) //tworzenie nowego wezla
	{
		root = new BSTNode;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
		root->height = 0;
		root->up = nullptr;
		return root;
	}

	if (data < root->data) //nowy element mniejszy od obecnego
	{
		root->left = insertBST(root->left, data);
		root->left->up = root;
	}
	else //nowy element wiekszy od obecnego
	{
		root->right = insertBST(root->right, data);
		root->right->up = root;
	}
	root->height = max(height(root->left), height(root->right)) + 1; //wysokosc drzewa
	return root;
}


//usuwa element o danej wartosci z drzewa
BSTNode* removeBST(BSTNode* root, int data)
{
	if (root == nullptr)
	{
		return root;
	}
	if (data < root->data)
	{
		root->left = removeBST(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = removeBST(root->right, data);
	}
	else
	{
		if (root->right == nullptr || root->left == nullptr)
		{
			BSTNode* temp = root->left ? root->left : root->right;
			if (temp == nullptr)//brak dzieci
			{
				temp = root;
				root = nullptr;
			}
			else //jedno dziecko
			{
				*root = *temp;
			}
			delete temp;
		}
		else //2 dzieci
		{
			BSTNode* temp = minValue(root->right);
			root->data = temp->data;
			root->right = removeBST(root->right, temp->data);
		}
	}//wysokosc
	if (root == nullptr)
	{
		return root;
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}




//obrot w lewo
void rotateLeft(BSTNode* &root, BSTNode* A)
{
	BSTNode* B = A->right;
	BSTNode* p = A->up;

	if (B != nullptr)// czy istnieje prawe dziecko A
	{
		A->right = B->left;
		if (A->right != nullptr)
		{
			A->right->up = A;
		}
		B->left = A;
		B->up = p;
		A->up = B;
		if (p != nullptr) //jesli A nie byl korzeniem - zmiana rodzica
		{
			if (p->left == A)
			{
				p->left = B;
			}
			else
			{
				p->right = B;
			}
		}
		else root = B;
	}
}

//obrot w prawo
void rotateRight(BSTNode* &root, BSTNode* A)
{
	BSTNode* B = A->left;
	BSTNode* p = A->up;

	if (B != nullptr)
	{
		A->left = B->right;
		if (A->left != nullptr)
		{
			A->left->up = A;
		}
		B->right = A;
		B->up = p;
		A->up = B;

		if (p != nullptr)
		{
			if (p->left == A)
			{
				p->left = B;
			}
			else
			{
				p->right = B;
			}
		}
		else root = B;
	}
}

int log2(int x)
{
	int y = 1;
	while ((x >>= 1) > 0)
	{
		y <<= 1;
	}
	return y;
}

//rownowazenie drzewa - algorytm dsw
void balanceBST(BSTNode* &root)
{
	BSTNode* p;
	int n = 0; //liczba wezlow
	p = root;
	//krok 1 - jedna galaz, obroty w prawo
	while (p)
		if (p->left)
		{
			rotateRight(root, p);
			p = p->up;
		}
		else
		{
			n++;
			p = p->right;
		}

	int s = n + 1 - log2(n + 1); //liczba lisci na najnizszym poziomie

	p = root;
	//tworzenie drzewa bst - co drugi wezel jest obracany
	for (int i = 0; i < s; i++)
	{
		rotateLeft(root, p);
		p = p->up->right;
	}

	n -= s;

	//obrot w lewo az do uzyskania zrownowazonego drzewa
	while (n > 1)
	{
		n >>= 1;
		p = root;
		for (int i = 0; i < n; i++)
		{
			rotateLeft(root, p);
			p = p->up->right;
		}
	}
}


int main(int argc, char* argv[])
{
	BSTNode* root = nullptr;

	//tworzenie drzewa
	if (argc > 1)
	{
		int length = 0;
		fstream create;
		fstream maxvalue;
		fstream inorder;
		fstream balance;
		fstream data;
		string file = argv[1];
		data.open(file.c_str(), fstream::in);
		int num;
		auto start = high_resolution_clock::now();
		while (!data.eof())
		{
			data >> num;
			length++;
			insertBST(root, num);
		}
		auto stop = high_resolution_clock::now();
		duration<double> durationCreate = stop - start;
		data.close();

		//max wartosc
		start = high_resolution_clock::now();
		maxValue(root);
		stop = high_resolution_clock::now();
		duration<double> durationMax = stop - start;

		//wypisanie in order
		start = high_resolution_clock::now();
		printInOrder(root);
		stop = high_resolution_clock::now();
		duration<double> durationInorder = stop - start;

		//bst - rownowazenie
		start = high_resolution_clock::now();
		balanceBST(root);
		stop = high_resolution_clock::now();
		duration<double> durationBalance = stop - start;

		double ddc = durationCreate.count();
		double ddm = durationMax.count();
		double ddi = durationInorder.count();
		double ddb = durationBalance.count();

		path dir = current_path();
		string dirstr = dir.string();

		string createName = dirstr + "/times/bst_create.txt";
		string maxName = dirstr + "/times/bst_max.txt";
		string inorderName = dirstr + "/times/bst_inorder.txt";
		string balanceName = dirstr + "/times/bst_balance.txt";

		create.open(createName.c_str(), fstream::out | fstream::app);
		//create << std::fixed << std::setprecision(8) << ddc << endl;
		create << ddc << endl;
		create.close();

		maxvalue.open(maxName.c_str(), fstream::out | fstream::app);
		maxvalue << std::fixed << std::setprecision(6) << ddm << endl;
		maxvalue.close();

		inorder.open(inorderName.c_str(), fstream::out | fstream::app);
		inorder << ddi << endl;
		inorder.close();

		balance.open(balanceName.c_str(), fstream::out | fstream::app);
		balance << std::fixed << std::setprecision(5) << ddb << endl;
		balance.close();

	}


	
	const int n = 7;
	int num[n] = {7, 6, 3, 15, 20, 25, 35};

	for (int i = 0; i < n; i++)
	{
		insertBST(root, num[i]);

	}
    
	cout << "Pre order" << endl;
	printPreOrder(root);
	cout << endl << "Max" << endl;

	printMaxValue(root);
	cout << endl;
	

	return 0;
}