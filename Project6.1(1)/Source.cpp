#include <iostream>
#include <ctime>
using namespace std;

// Функція для створення масиву цілих чисел 'a' з випадковими значеннями у заданому діапазоні [Low, High].
void Create(int* a, const int size, const int Low, const int High, int i) {
    if (i < size) {
        a[i] = Low + rand() % (High - Low + 1);
        Create(a, size, Low, High, i + 1);
    }
}

// Функція для обчислення суми позитивних елементів у масиві 'mas', які не діляться на 3.
int Sum(int mas[], const int n, int i = 0, int s = 0) {
    if (i < n) {
        if (mas[i] > 0 && mas[i] % 3 != 0) {
            s += mas[i];
        }
        return Sum(mas, n, i + 1, s);
    }
    return s;
}

// Функція для підрахунку кількості позитивних елементів у масиві 'mas', які не діляться на 3.
int Num(int mas[], const int n, int i = 0, int num = 0) {
    if (i < n) {
        if (mas[i] > 0 && mas[i] % 3 != 0) {
            num++;
        }
        return Num(mas, n, i + 1, num);
    }
    return num;
}

// Функція для встановлення значення 0 для позитивних елементів у масиві 'mas', які не діляться на 3.
void Fun0(int mas[], const int n, int i = 0) {
    if (i < n) {
        if (mas[i] > 0 && mas[i] % 3 != 0) {
            mas[i] = 0;
        }
        Fun0(mas, n, i + 1);
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    const int n = 22;
    int a[n];
    int Low = -10;
    int High = 35;

    // Заповнюємо масив 'a' випадковими значеннями в діапазоні [-10, 35].
    Create(a, n, Low, High, 0);

    // Виводимо значення у масиві 'a'.
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    // Розраховуємо та виводимо суму позитивних елементів у 'a', які не діляться на 3.
    cout << "\nS = " << Sum(a, n) << endl;

    // Підраховуємо та виводимо кількість позитивних елементів у 'a', які не діляться на 3.
    cout << "N = " << Num(a, n) << endl;

    // Встановлюємо значення 0 для позитивних елементів у 'a', які не діляться на 3 за допомогою функції Fun0.
    Fun0(a, n);

    // Виводимо змінений масив після використання Fun0.
    cout << "\nFun0" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
