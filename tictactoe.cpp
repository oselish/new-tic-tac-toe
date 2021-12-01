#include <iostream>
#include <string>
#include <typeinfo>
#include <Windows.h>
using namespace std;
char field[10] = {'0','1','2','3','4','5','6','7','8','9'};
bool is_win()
{
    char player;
    for (int i = 1; i <= 9; i+=3)
    {
        if ((field[i] == field[i + 3] && field[i + 3] == field[i + 6]) ||
            (field[i] == field[i + 1] && field[i + 1] == field[i + 2]))
        {
            player = field[i];
            if (player == 'X') cout << "\nПобедили крестики!!!" << endl;
            else if (player == 'O') cout << "\nПобедили нолики!!!" << endl;
            return true;
        }
        else if ((field[1] == field[5] && field[5] == field[9]) ||
                 (field[3] == field[5] && field[5] == field[7]))
        {
            player = field[5];
            if (player == 'X') cout << "\nПобедили крестики!!!" << endl;
            else if (player == 'O') cout << "\nПобедили нолики!!!" << endl;
            return true;
        }
    }
    int c = 0;
    for (int i = 1; i <= 9; i++)
        if (field[i] == 'X' || field[i] == 'O')
            c++;
    if (c == 9)
    {
        cout << "Ничья!" << endl;
        return true;
    }
    return false;
}
void show_field()
{
    for (int i = 1; i <= 9; i+=3)
    {
        cout << " " << field[i] << " | " << field[i + 1] << " | " << field[i + 2] << endl;
        if (i < 6) cout << "---+---+---" << endl;
    }
}
bool check(char XO)
{
    int XorO = int(XO) - '0';
    if (XorO < 1 || XorO > 9)
        cout << "Значение должно быть целочисленным от 1 до 9!!!";
    else if (field[XorO] == 'O' || field[XorO] == 'X')
        cout << "Клетка уже занята!";
    else return false;
    return true;
}
int main()
{
    setlocale(LC_ALL, "ru");
    while (true)
    {
        show_field();           // Отображение поля в консоли
        if (is_win()) return 0; // И проверка поля
        char X, O;
        //////////////////// Крестики ////////////////////
        do
        {
            cout << "\nХод крестиков: "; cin >> X;
        } while (check(X));
        int x = int(X) - '0';
        field[x] = 'X';
        cout << endl;
        show_field();           // Отображение поля в консоли
        if (is_win()) return 0; // И проверка поля
        //////////////////// Нолики ////////////////////
        do
        {
            cout << "\nХод ноликов: "; cin >> O;
        } while (check(O));
        int o = int(O) - '0';
        field[o] = 'O';
        cout << endl;
    }
}
