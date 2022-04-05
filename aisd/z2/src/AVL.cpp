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
struct AVLNode
{
	int data;
	AVLNode* left;
	AVLNode* right;
	AVLNode* up;
	int bf;
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
int height(AVLNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return root->height;
}

//zwraca minimalna wartosc w drzewie
AVLNode* minValue(AVLNode* root)
{
	AVLNode* current = root;
	while (current->left != nullptr)
	{
		current = current->left;
	}
	return current;
}

//zwraca maksymalna wartosc w drzewie
AVLNode* maxValue(AVLNode* root)
{
	AVLNode* current = root;
	while (current->right != nullptr)
	{
		current = current->right;
	}
	return current;
}

//wypisuje minimalna wartosc w drzewie + kroki
void printMinValue(AVLNode* root)
{
	AVLNode* current = root;
	while (current->left != nullptr)
	{
		cout << current->data << " ";
		current = current->left;
	}
	cout << "[min]:" << current->data << endl;
}

//wypisuje maksymalna wartosc w drzewie + kroki
void printMaxValue(AVLNode* root)
{
	AVLNode* current = root;
	while (current->right != nullptr)
	{
		cout << current->data << " ";
		current = current->right;
	}
	cout << "[max]:" << current->data << endl;
}

//wypisuje drzewo - pre order
void printPreOrder(AVLNode* root)
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
void printInOrder(AVLNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	printInOrder(root->left);
	cout << root->data << " ";
	printInOrder(root->right);
}

//wypisuje wartości bf - pre order
void printBfPreOrder(AVLNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	
	cout << root->bf << " ";
	
	printBfPreOrder(root->left);
	printBfPreOrder(root->right);
}
// wypisuje wartości height - pre order
void printHeightPreOrder(AVLNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	
	cout << root->height << " ";
	
	printHeightPreOrder(root->left);
	printHeightPreOrder(root->right);
}


void bfSet (AVLNode* root) { // ustawia wartości bf od dołu drzewa w prostej linii do góry
    
    root->bf = height(root->left) - height(root->right);
  
	if (root->up != nullptr) {
	    bfSet(root->up);
	}
}

void heightSet (AVLNode* root) { // ustawia height od dołu w prostej linii do góry
    
    root->height = max(height(root->left), height(root->right)) + 1;
    
	if (root->up != nullptr) {
	    heightSet(root->up);
	}
}

void rotateRR (AVLNode* A) { // obrót RR
    
	AVLNode* B = A->right;
	AVLNode* p = A->up;
	
	
	B->up = p;
    	
	if (p != nullptr) {
    	if (p->right == A) {
    	    p->right = B;
	    }
	    
	    else {
    	    p->left = B;
	    }
	}
	
	A->right = B->left;
	
	if (B->left != nullptr) {
	    B->left->up = A;
	}
	
	A->up = B;
	B->left = A;
	
	
	heightSet (A);
	bfSet(A);
}

void rotateRL (AVLNode* A) { // obrót RL
    
    AVLNode* B = A->right;
    AVLNode* C = B->left;
	AVLNode* p = A->up;
	
	C->up = p;
    	
	if (p != nullptr) {
	    if (p->right == A) {
    	    p->right = C;
	    }
	    
	    else {
    	    p->left = C;
	    }
	}
	
	A->right = C->left;
	
	if (C->left != nullptr) {
    	C->left->up = A;
	}
	
	B->left = C->right;
	
	if (C->right != nullptr) {
    	C->right->up = B;
	}
	
	C->left = A;
	A->up = C;
	
	C->right = B;
	B->up = C;
	
	heightSet (A);
	bfSet(A);
	heightSet (B);
	bfSet(B);
}

void rotateLR (AVLNode* A) { // obrót LR

    AVLNode* B = A->left;
    AVLNode* C = B->right;
	AVLNode* p = A->up;
	
	C->up = p;
    	
	if (p != nullptr) {
    	if (p->right == A) {
    	    p->right = C;
	    }
	    
	    else {
    	    p->left = C;
	    }
	}
	
	A->left = C->right;
	
	if (C->right != nullptr) {
    	C->right->up = A;
	}
	
	B->right = C->left;
	
	if (C->left != nullptr) {
    	C->left->up = B;
	}
	
	C->right = A;
	A->up = C;
	
	C->left = B;
	B->up = C;
	
	heightSet (A);
	bfSet(A);
	heightSet (B);
	bfSet(B);
}

void rotateLL (AVLNode* A) { // obrót LL
    
    AVLNode* B = A->left;
	AVLNode* p = A->up;
	
	
	B->up = p;
    	
	if (p != nullptr) {
    	if (p->right == A) {
    	    p->right = B;
	    }
	    
	    else {
    	    p->left = B;
	    }
	}
	
	A->left = B->right;
	
	if (B->right != nullptr) {
	    B->right->up = A;
	}
	
	A->up = B;
	B->right = A;
	
	heightSet(A);
	bfSet(A);
}


void bfCheck (AVLNode* root, int lastBf = 0) { // od dołu do góry sprawdza, czy wartości bf nie są równe 2 lub -2;
                                               // jeśli tak jest, na podstawie poprzednich wartości bf wybiera rotateRR, RL itd.
    if (abs (root->bf) <= 1) {
        if (root->up != nullptr){
            bfCheck (root->up, root->bf);
         }
    }
    
    else {
        if (root->bf < 0) {
            if (lastBf < 0) {
                rotateRR (root);
            }
            
            else if (lastBf > 0) {
                rotateRL (root);
            }
        }
        
        else if (root->bf > 0) {
            if (lastBf > 0) {
                rotateLL (root);
            }
            
            else if (lastBf < 0) {
                rotateLR (root);
            }
        }
    }
}

//wstawia element do drzewa
AVLNode* insertAVL(AVLNode* &root, AVLNode* rootUp, int data, AVLNode*& endNode)
{
	if (root == nullptr) //tworzenie nowego wezla
	{
		root = new AVLNode;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
		root->height = 0;
		root->up = rootUp;
		root->bf = 0;
		
		endNode = root;
		
		heightSet (root);
		
		bfSet (root);
		
		
		return root;
	}

	if (data < root->data) //nowy element mniejszy od obecnego
	{
		root->left = insertAVL(root->left, root, data, endNode);
		root->left->up = root;
	}
	else //nowy element wiekszy od obecnego
	{
		root->right = insertAVL (root->right, root, data, endNode);
		root->right->up = root;
	}
	
	
	return root;
}

AVLNode * predAVL ( AVLNode * p ) // znajduje poprzednik
{
  AVLNode * r;

  if( p )
  {
    if( p->left )
    {
      p = p->left;
      while( p->right ) p = p->right;
    }
    else
      do
      {
        r = p;
        p = p->up;
      } while( p && p->right != r );
  }
  return p;
}

AVLNode* findAVL (AVLNode* root, int data) {
    
    if (root == nullptr) {
        return root;
    }
    
    if (data < root->data)
	{
		root = findAVL(root->left, data);
	}
	else if (data > root->data)
	{
		root = findAVL(root->right, data);
	}
	else {
	    return root;
	}
	
    return root;
}

AVLNode * removeAVL ( AVLNode * & root, AVLNode * x) // usuwa 
{
    
    
    if (root == nullptr)
	{
		return root;
	}
    
    
  AVLNode  *t, *y, *z;
  bool nest;
  if( x->left && x->right )
  {
    y    = removeAVL ( root, predAVL ( x ) );
    nest = false;
  }
  else
  {
    if( x->left )
    {
      y = x->left; x->left = NULL;
    }
    else
    {
      y = x->right; x->right = NULL;
    }
    x->bf = 0;
    nest  = true;
  }

  if( y )
  {
    y->up    = x->up;
    y->left  = x->left;  if( y->left )   y->left->up  = y;
    y->right = x->right; if( y->right )  y->right->up = y;
    y->bf    = x->bf;
  }

  if( x->up )
  {
    if( x->up->left == x ) x->up->left = y; else x->up->right = y;
  }
  else root = y;

  if( nest )
  {
    z = y;
    y = x->up;
    while( y )
    {
      if( !y->bf )
      {             // Przypadek nr 1
        if( y->left == z )  y->bf = -1; else y->bf = 1;
        break;
      }
      else
      {
        if( ( ( y->bf == 1 ) && ( y->left == z ) ) || ( ( y->bf == -1 ) && ( y->right == z ) ) )
        {           // Przypadek nr 2
          y->bf = 0;
          z = y; y = y->up;
        }
        else
        {
          if( y->left == z )  t = y->right; else t = y->left;
          if( !t->bf )
          {         // Przypadek 3A
            if( y->bf == 1 ) rotateLL (  y ); else rotateRR ( y );
            break;
          }
          else if( y->bf == t->bf )
          {         // Przypadek 3B
            if( y->bf == 1 ) rotateLL ( y ); else rotateRR (  y );
            z = t; y = t->up;
          }
          else
          {         // Przypadek 3C
            if( y->bf == 1 ) rotateLR ( y ); else rotateRL ( y );
            z = y->up; y = z->up;
          }
        }
      }
    }
  }
  return x;
}

void destroyTree(AVLNode* root)
{
	if (root != nullptr)
	{
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
	}
}

void pullRootUp (AVLNode*& root) { // sprawdza, czy root jest korzeniem, jeśli nie to robi tak że jest
    
    if (root->up != nullptr) {
        root = root->up;
    }
}

int main(int argc, char* argv[])
{
    AVLNode* root = nullptr;

/*
	const int n = 7;
	int num[n] = { 7, 6, 3, 15, 20, 25, 30};

	for (int i = 0; i < n; i++) // insertowanie
	{
	    AVLNode* endNode = nullptr; // zmienna trzymająca adres insertowanego node'a
	    
		insertAVL (root, NULL, num[i], endNode);
		
    	bfCheck (endNode); // w zasadzie sortowanie bf
    	
    	pullRootUp(root);
	}
    
    removeAVL(root, findAVL(root, 15)); // usuń 15
    
	pullRootUp(root);
	
	cout << "Bf: ";
    printBfPreOrder(root);
    
	cout << "\nHeight: ";
	
    printHeightPreOrder(root);
    
	cout << "\nData: ";
   
    printPreOrder(root);
*/



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
			AVLNode* endNode = nullptr;
			insertAVL (root, NULL, num, endNode);
		
    		bfCheck (endNode);
    	
    		pullRootUp(root);
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

		double ddc = durationCreate.count();
		double ddm = durationMax.count();
		double ddi = durationInorder.count();

		path dir = current_path();
		string dirstr = dir.string();

		string createName = dirstr + "/times/avl_create.txt";
		string maxName = dirstr + "/times/avl_max.txt";
		string inorderName = dirstr + "/times/avl_inorder.txt";

		create.open(createName.c_str(), fstream::out | fstream::app);
		create <<  ddc << endl;
		create.close();

		maxvalue.open(maxName.c_str(), fstream::out | fstream::app);
		maxvalue << std::fixed << std::setprecision(7) << ddm << endl;
		maxvalue.close();

		inorder.open(inorderName.c_str(), fstream::out | fstream::app);
		inorder << ddi << endl;
		inorder.close();

	}

}
