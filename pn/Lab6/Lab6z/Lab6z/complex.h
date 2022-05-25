#pragma once

//zadanie 5 - struktura

struct complex
{
	float real, imaginary;
};

//zadanie 5 - operacje

complex add(const complex a, const complex b);

complex subtract(const complex a, const complex b);

complex multiply(const complex a, const complex b);

int equals(const complex a, const complex b);

//zadanie 7 - ustalanie porzadku

int less_or_equal_1(const complex a, const complex b);

int less_or_equal_2(const complex a, const complex b);

int less_or_equal_3(const complex a, const complex b);