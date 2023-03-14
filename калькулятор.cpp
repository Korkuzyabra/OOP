#include <iostream>
using namespace std;
enum MathOperator
{
    Add = 1,
    Minus,
    Multiply,
    Divide,
};
int main()
{
    setlocale(LC_ALL, "Russian");
    int num1, num2, num3, choice;
    bool exit = true;
    while (exit) {
        cout << "Введите целые числа : " << endl;
        cin >> num1 >> num2;
        cout << "Введите номер операции :" << endl << "1: Сложение" << endl << "2: Вычитание" << endl << "3: Умножение" << endl
            << "4: Деление" << endl;
        cin >> choice;
        switch (choice) {
        case Add:
            num3 = num1 + num2;
            cout << num3 << endl;
            break;
        case Minus:
            num3 = num1 - num2;
            cout << num3 << endl;
            break;
        case Multiply:
            num3 = num1 * num2;
            cout << num3 << endl;
            break;
        case Divide:
            num3 = num1 / num2;
            cout << num3 << endl;
            break;
        default:
            cout << "Введите число от 1 до 4" << endl;
        }
        cout << "Нажмите 1, чтобы продолжить и 0, чтобы выйти" << endl;;
        cin >> exit;
    }
}

