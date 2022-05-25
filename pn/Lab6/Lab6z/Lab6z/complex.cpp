#include "complex.h"
#include <stdio.h>
#include <math.h>

//zadanie 5 - dodawanie

complex add(const complex a, const complex b)
{
	complex result;
	result.real = a.real + b.real;
	result.imaginary = a.imaginary + b.imaginary;
	return result;
}

//zadanie 5 - odejmowanie

complex subtract(const complex a, const complex b)
{
	complex result;
	result.real = a.real - b.real;
	result.imaginary = a.imaginary - b.imaginary;
	return result;
}

//zadanie 5 - mnozenie

complex multiply(const complex a, const complex b)
{
	complex result;
	result.real = (a.real * b.real) - (a.imaginary * b.imaginary);
	result.imaginary = (a.imaginary * b.real) + (a.real * b.imaginary);
	return result;
}

//zadanie 5 - rownosc

int equals(const complex a, const complex b)
{
	if (a.real == b.real && a.imaginary == b.imaginary)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//zadanie 7 - ustalanie porzadku

//1 - obliczanie modulow liczb i porownanie
int less_or_equal_1(const complex a, const complex b)
{
	float am = sqrt((a.real * a.real) + (a.imaginary * a.imaginary));
	float bm = sqrt((b.real * b.real) + (b.imaginary * b.imaginary));
	if (am > bm)
	{
		return 0;
	}
	return 1;
}

//2 - porownanie wylacznie czesci rzeczywistych
int less_or_equal_2(const complex a, const complex b)
{
	if (a.real > b.real)
	{
		return 0;
	}
	return 1;
}

//3 - porownanie czesci rzeczywistych, a jesli sa rowne to potem urojonych
int less_or_equal_3(const complex a, const complex b)
{
	if (a.real > b.real)
	{
		return 0;
	}
	else if (a.real == b.real)
	{
		if (a.imaginary > b.imaginary)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}
}