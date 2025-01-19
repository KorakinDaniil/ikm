#ifndef ConsoleApplication1
#define ConsoleApplication1

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

const int MAX_DIGITS = 10000; // Максимальное количество цифр в числе

string addLargeNumbers(const string& num1, const string& num2);// Функция для сложения длинных чисел
string multiplyLargeNumbers(const string& num1, const string& num2);// Функция для умножения длинных чисел
string subtractLargeNumbers(const string num1, const string num2);// Функция для вычитания длинных чисел
string divideLargeNumbers(const string& num1, const string& num2);// Функция для деления длинных чисел

string factorial(long long int n);// Функция для вычисления факториала

bool isLessThan(const string& num1, const string& num2);// Функция для сравнения двух чисел
string gcd(const string& a, const string& b);// Функция для нахождения наибольшего общего делителя (НОД)

void addFractions(int n, string* results);// Функция для вычисления суммы дробей

string replaceNonZerosWithZeros(const string& input);// Функция для замены постороннего символа на ноль

#endif 
