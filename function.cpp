#include "head.h"

// ������� ��� �������� ������� �����
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

// ������� ��� ��������� ������� �����
string multiplyLargeNumbers(const string& num1, const string& num2)
{
    string result(num1.size() + num2.size(), '0');

    for (long long int i = num1.size() - 1; i >= 0; i--)
    {
        for (long long int j = num2.size() - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + (result[i + j + 1] - '0');

            result[i + j + 1] = (sum % 10) + '0'; // ��������� ��������� �����
            result[i + j] += sum / 10; // ��������� �������
        }
    }

    // ������� ������� ����
    size_t start = 0;
    while (start < result.size() && result[start] == '0')
    {
        start++;
    }

    return start == result.size() ? "0" : result.substr(start);
}

// ������� ��� ��������� ������� �����
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
    // ������� ������� ����
    while (result.length() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }

    return result;
}

// ������� ��� ������� ������� �����
string divideLargeNumbers(const string& num1, const string& num2)
{
    if (num1 == "0" || isLessThan(num1, num2)) return "0"; // ���� ������� 0 ��� ������ ��������

    string result;  // ��������� �������
    string current; // ������� �������� (�������)
    string divisor = num2; // ��������
    long long int n1 = num1.size();
    long long int n2 = num2.size();

    for (long long int i = 0; i < n1; i++)
    {
        current += num1[i]; // ��������� ��������� ����� � �������� ��������
        int count = 0; // ������� �������� ��� ������� �������

        // ���� ������� �������� ������ ��� ����� ��������
        while (!isLessThan(current, divisor))
        {
            current = subtractLargeNumbers(current, divisor); // �������� ��������
            count++; // ����������� �������
        }
        result += (count + '0'); // ��������� ���������� �������
    }

    // �������� ������� �����
    size_t start = 0;
    while (start < result.size() && result[start] == '0')
    {
        start++;
    }

    return start == result.size() ? "0" : result.substr(start); // ���� �� ����, ���������� "0"
}

// ������� ��� ���������� ����������
string factorial(long long int n)
{
    string result = "1"; // ��������� 0! � 1! ����� 1

    for (long long int i = 2; i <= n; i++)
    {
        result = multiplyLargeNumbers(result, to_string(i));
    }

    return result;
}

// ������� ��� ��������� ���� �����
bool isLessThan(const string& num1, const string& num2)
{
    if (num1.size() < num2.size()) return true;
    if (num1.size() > num2.size()) return false;
    return num1 < num2; // ���������� ������
}

// ������� ��� ���������� ����������� ������ �������� (���) 
string gcd(const string& a, const string& b)
{
    if (b == "0") return a; // ���(a, 0) = a
    if (isLessThan(a, b)) return gcd(b, a); // ����� ��������, ����� a ������ ���� ������ b
    return gcd(b, subtractLargeNumbers(a, b)); // ���������� �������� �������
}

// ������� ��� �������� ������ � ������ ����������
void addFractions(int n, string* results)
{
    string sumNumerator = "0", sumDenominator = "1";

    results[0] = "1"; // ��������� ��������� ��� 0!
    results[1] = "1"; // ��������� ��������� ��� 1!

    // ����������� ���������
    for (long long int i = 2; i <= n; i++)
    {
        string fact = factorial(i);
        results[i] = fact; // ��������� ��������� ������� ��������
    }

    for (long long int i = 1; i <= n; i++)
    {
        // ����� �����������: sumDenominator * i!
        string newDenominator = multiplyLargeNumbers(sumDenominator, results[i]);

        // ����� ���������: (sumNumerator * i!) + (1 * (i-1)!)
        string newNumerator = addLargeNumbers(multiplyLargeNumbers(sumNumerator, results[i]), multiplyLargeNumbers("1", results[i - 1]));

        sumNumerator = newNumerator;
        sumDenominator = newDenominator;
    }

    /*string numGCD = gcd(sumNumerator, sumDenominator);
    sumNumerator = divideLargeNumbers(sumNumerator, numGCD);
    sumDenominator = divideLargeNumbers(sumDenominator, numGCD);*/

    cout << sumNumerator << "/" << sumDenominator << endl;
}