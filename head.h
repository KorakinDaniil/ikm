#ifndef ConsoleApplication1
#define ConsoleApplication1

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

const int MAX_DIGITS = 10000; // ������������ ���������� ���� � �����

string addLargeNumbers(const string& num1, const string& num2);// ������� ��� �������� ������� �����
string multiplyLargeNumbers(const string& num1, const string& num2);// ������� ��� ��������� ������� �����
string subtractLargeNumbers(const string num1, const string num2);// ������� ��� ��������� ������� �����
string divideLargeNumbers(const string& num1, const string& num2);// ������� ��� ������� ������� �����

string factorial(long long int n);// ������� ��� ���������� ����������

bool isLessThan(const string& num1, const string& num2);// ������� ��� ��������� ���� �����
string gcd(const string& a, const string& b);// ������� ��� ���������� ����������� ������ �������� (���)

void addFractions(int n, string* results);// ������� ��� ���������� ����� ������

#endif 
