#include "head.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    long long int n;
    bool validInput;
    string* results = new string[MAX_DIGITS]; // Массив для хранения результатов факториала
    cout << "Введите натуральное число N > 10: ";
    // Проверка на ошибки ввода
    do
    {
        validInput = true;
        cin >> n;

        if (cin.fail() || n <= 10)
        {
            validInput = false;
            cin.clear(); // Очистка флага ошибки
            cin.ignore(1000, '\n'); // Игнорирование некорректного ввода
            cout << "Ошибка: введите строго натуральное число (больше 10)." << endl;
        }
        // Проверка на дробные числа
        else if (cin.peek() != '\n')
        {
            validInput = false;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ошибка: введите строго натуральное число (больше 10)." << endl;
        }
    } while (!validInput);

    cout << "Результат: ";
    addFractions(n, results);
    delete[] results;
    return 0;
}