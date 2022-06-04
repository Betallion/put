#include <iostream>
#include <fstream>
#include <chrono>

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

void print2D(int** array, int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int** fillArray(int** elements, int size, int weight)
{
    //elements[i][0] = weight
    //elements[i][1] = value
    int** array = new int*[size + 1];
    for (int i = 0; i < size + 1; i++)
    {
        array[i] = new int[weight + 1];
        if (i == 0)
        {
            for (int j = 0; j < weight + 1; j++)
            {
                array[i][j] = 0;
            }
        }
        array[i][0] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= weight; j++)
        {
            if (elements[i][0] > j)
            {
                array[i + 1][j] = array[i][j];
            }
            else
            {
                array[i + 1][j] = max(array[i][j], array[i][j - elements[i][0]] + elements[i][1]);
            }
        }
    }
    return array;
}

void printResult(int** array, int** elements, int size, int weight)
{
    int tsize = size;
    int tweight = weight;
    std::cout << "Rozwiazanie:" << std::endl;
    while (tsize > 0)
    {
        if (array[tsize][tweight] > array[tsize - 1][tweight])
        {
            std::cout << "element " << tsize << " : waga " << elements[tsize - 1][0] << ", wartosc " << elements[tsize - 1][1] << std::endl;
            tweight -= elements[tsize - 1][0];
        }
        tsize--;
    }
}

int main(int argc, char* argv[])
{
   if (argc > 1)
   {
        std::fstream file;
        file.open(argv[1], std::ios::in);
        int size, weight;
        int** elements;
        if (!file)
        {
            std::cout << "file error";
        }
        else
        {
            file >> weight;
            file >> size;
            elements = new int*[size];
            for (int i = 0; i < size; i++)
            {
                elements[i] = new int[2];
            }
            int it = 0;
            while (true)
            {
                file >> elements[it][1] >> elements[it][0];
                it++;
                if (file.eof())
                {
                    break;
                }
            }
        }
        file.close();

        auto start = std::chrono::high_resolution_clock::now();
        int** array = fillArray(elements, size, weight);
        //print2D(array, size + 1, weight + 1);
        printResult(array, elements, size, weight);
        auto stop = std::chrono::high_resolution_clock::now();
        double dur = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
        dur *= 1e-9;
        std::cout << "Czas dzialania " << std::fixed << dur << " sekund" <<  std::endl;


        for (int i = 0; i < size; i++)
        {
            delete [] elements[i];
        }
        delete [] elements;
        for (int i = 0; i < size + 1; i++)
        {
            delete [] array[i];
        }
        delete [] array;
   }
   else
   {
       std::cout << "file not specified";
   }
    return 0;
}