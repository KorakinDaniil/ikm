#include "head.h"

// Функция для сложения длинных чисел
string addLargeNumbers(const string& num1, const string& num2)
{
    string result;
    long long int carry = 0;
    long long int i = num1.size() - 1;
    long long int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        long long int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        long long int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        long long int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';

        i--;
        j--;
    }

    reverse(result.begin(), result.end());
    return result;
}

// Функция для умножения длинных чисел
string multiplyLargeNumbers(const string& num1, const string& num2)
{
    string result(num1.size() + num2.size(), '0');

    for (long long int i = num1.size() - 1; i >= 0; i--)
    {
        for (long long int j = num2.size() - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + (result[i + j + 1] - '0');

            result[i + j + 1] = (sum % 10) + '0'; // Сохраняем последнюю цифру
            result[i + j] += sum / 10; // Добавляем перенос
        }
    }

    // Удаляем ведущие нули
    size_t start = 0;
    while (start < result.size() && result[start] == '0')
    {
        start++;
    }

    return start == result.size() ? "0" : result.substr(start);
}

// Функция для вычитания длинных чисел
string subtractLargeNumbers(string num1, string num2){
    while (num1.length() < num2.length()) num1 = '0' + num1;
    while (num2.length() < num1.length()) num2 = '0' + num2;

    string result = "";
    int carry = 0;

    for (long long int i = num1.length() - 1; i >= 0; i--) {
        int digit1 = num1[i] - '0';
        int digit2 = num2[i] - '0' + carry;

        if (digit1 < digit2) {
            digit1 += 10;
            carry = 1;
        }
        else {
            carry = 0;
        }

        result += (digit1 - digit2) + '0';
    }

    reverse(result.begin(), result.end());
    // Удаляем ведущие нули
    while (result.length() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }

    return result;
}

// Функция для деления длинных чисел
string divideLargeNumbers(const string& num1, const string& num2)
{
    if (num1 == "0" || isLessThan(num1, num2)) return "0"; // Если делимое 0 или меньше делителя

    string result;  // Результат деления
    string current; // Текущее значение (остаток)
    string divisor = num2; // Делитель
    long long int n1 = num1.size();
    long long int n2 = num2.size();

    for (long long int i = 0; i < n1; i++)
    {
        current += num1[i]; //Добавляем следующую цифру к текущему значению
        int count = 0; // Счетчик частного для данного остатка

        // Пока текущее значение больше или равно делителю
        while (!isLessThan(current, divisor))
        {
            current = subtractLargeNumbers(current, divisor); // Вычитаем делитель
            count++; // Увеличиваем счетчик
        }
        result += (count + '0'); // Добавляем количество кратных
    }

    // Удаление ведущих нулей
    size_t start = 0;
    while (start < result.size() && result[start] == '0')
    {
        start++;
    }

    return start == result.size() ? "0" : result.substr(start); // Если всё нули, возвращаем "0"
}

// Функция для вычисления факториала
string factorial(long long int n)
{
    string result = "1"; // Факториал 0! и 1! равен 1

    for (long long int i = 2; i <= n; i++)
    {
        result = multiplyLargeNumbers(result, to_string(i));
    }

    return result;
}

// Функция для сравнения двух чисел
bool isLessThan(const string& num1, const string& num2)
{
    if (num1.size() < num2.size()) return true;
    if (num1.size() > num2.size()) return false;
    return num1 < num2; // Сравниваем строку
}

// Функция для нахождения наибольшего общего делителя (НОД) 
string gcd(const string& a, const string& b)
{
    if (b == "0") return a; // НОД(a, 0) = a
    if (isLessThan(a, b)) return gcd(b, a); // Обмен значений, чтобы a всегда было больше b
    return gcd(b, subtractLargeNumbers(a, b)); // Используем алгоритм Евклида
}

// Функция для сложения дробей и вывода результата
void addFractions(int n, string* results)
{
    string sumNumerator = "0", sumDenominator = "1";

    results[0] = "1"; // Сохраняем результат для 0!
    results[1] = "1"; // Сохраняем результат для 1!

    // Высчитываем факториал
    for (long long int i = 2; i <= n; i++)
    {
        string fact = factorial(i);
        results[i] = fact; // Сохраняем результат текущей итерации
    }

    for (long long int i = 1; i <= n; i++)
    {
        // Новый знаменатель: sumDenominator * i!
        string newDenominator = multiplyLargeNumbers(sumDenominator, results[i]);

        // Новый числитель: (sumNumerator * i!) + (1 * (i-1)!)
        string newNumerator = addLargeNumbers(multiplyLargeNumbers(sumNumerator, results[i]), multiplyLargeNumbers("1", results[i - 1]));

        sumNumerator = newNumerator;
        sumDenominator = newDenominator;
    }
    
    //Сокращение дроби
    /*string numGCD = gcd(sumNumerator, sumDenominator);
    sumNumerator = divideLargeNumbers(sumNumerator, numGCD);
    sumDenominator = divideLargeNumbers(sumDenominator, numGCD);*/

    cout << sumNumerator << "/" << sumDenominator << endl;
}
