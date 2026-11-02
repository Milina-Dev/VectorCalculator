#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

enum OPERATOR
{
	PLUS = 1,
	MINUS,
	MULTIPLY,
	SCAN_MULTIPLY
};

/**
 * Складывает два вектора.
 */
string plus_vec(string a, string b)
{
    string c;
    int x1, y1, x2, y2;

    int sep = a.find(';');
    x1 = stoi(a.substr(a.find('(') + 1, sep - a.find('(') - 1));
    y1 = stoi(a.substr(sep + 1, a.find(')') - sep - 1));

    sep = b.find(';');
    x2 = stoi(b.substr(b.find('(') + 1, sep - b.find('(') - 1));
    y2 = stoi(b.substr(sep + 1, b.find(')') - sep - 1));

    c = "c = (" + to_string(x1 + x2) + ";" + to_string(y1 + y2) + ")";

    return c;
}

/**
 * Вычитает два вектора.
 */
string minus_vec(string a, string b)
{
    string c;
    int x1, y1, x2, y2;

    int sep = a.find(';');
    x1 = stoi(a.substr(a.find('(') + 1, sep - a.find('(') - 1));
    y1 = stoi(a.substr(sep + 1, a.find(')') - sep - 1));

    sep = b.find(';');
    x2 = stoi(b.substr(b.find('(') + 1, sep - b.find('(') - 1));
    y2 = stoi(b.substr(sep + 1, b.find(')') - sep - 1));

    c = "c = (" + to_string(x1 - x2) + ";" + to_string(y1 - y2) + ")";

    return c;
}

/**
 * Умножает координаты двух векторов.
 */
string multiply_vec(string a, string b)
{
    string c;
    int x1, y1, x2, y2;

    int sep = a.find(';');
    x1 = stoi(a.substr(a.find('(') + 1, sep - a.find('(') - 1));
    y1 = stoi(a.substr(sep + 1, a.find(')') - sep - 1));

    sep = b.find(';');
    x2 = stoi(b.substr(b.find('(') + 1, sep - b.find('(') - 1));
    y2 = stoi(b.substr(sep + 1, b.find(')') - sep - 1));

    c = "c = (" + to_string(x1 * x2) + ";" + to_string(y1 * y2) + ")";

    return c;
}

/**
 * Вычисляет скалярное произведение векторов.
 */
string scal_multiply_vec(string a, string b)
{
    string c;
    int x1, y1, x2, y2;

    int sep = a.find(';');
    x1 = stoi(a.substr(a.find('(') + 1, sep - a.find('(') - 1));
    y1 = stoi(a.substr(sep + 1, a.find(')') - sep - 1));

    sep = b.find(';');
    x2 = stoi(b.substr(b.find('(') + 1, sep - b.find('(') - 1));
    y2 = stoi(b.substr(sep + 1, b.find(')') - sep - 1));

    c = "c = " + to_string(x1 * x2 + y1 * y2);

    return c;
}
/** 
* Главная функция программы
*/
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string a, b, c;
    int choice;
    OPERATOR oper;

    cout << "Операции" << endl;
    cout << "1. Сложение" << endl;
    cout << "2. Вычитание" << endl;
    cout << "3. Умножение" << endl;
    cout << "4. Скалярное произведение" << endl;
    cout << "Выберите операцию: ";
    cin >> choice;

    oper = (OPERATOR)choice;

    cout << "Введите вектора a и b: ";
    cin >> a >> b;

    switch (oper)
    {
    case PLUS:
        c = plus_vec(a, b);
        break;

    case MINUS:
        c = minus_vec(a, b);
        break;

    case MULTIPLY:
        c = multiply_vec(a, b);
        break;

    case SCAN_MULTIPLY:
        c = scal_multiply_vec(a, b);
        break;

    default:
        c = "Ошибка: неверная операция";
        break;
    }

    cout << c << endl;

    return 0;
}