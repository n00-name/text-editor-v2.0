#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <chrono>
#include <windows.h>

using namespace std;

void print_numbers(long long number0, long long number1, int sizenumber0step, const std::string& line, bool setting) {
    std::ofstream out("out.txt");
    if (!out.is_open()) {
        std::cerr << "Error: can't open file 'out.txt' for writing\n";
        return;
    }

    for (; number0 > number1; number0 -= sizenumber0step) {
        if (setting) {
            out << line << " ";
        }
        out << number0 << '\n';
    }

    for (; number0 < number1 + 1; number0 += sizenumber0step) {
        if (setting) {
            out << line << " ";
        }
        out << number0 << '\n';
    }
}

int main() {

    // Установка кодировки консоли
    system("title 2.0");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Получение параметров от пользователя
    long long start;
    long long end;
    int step;
    bool use_prefix;
    string prefix;

    cout << "Введите первое число: ";
    cin >> start;
    cout << "Введите второе число: ";
    cin >> end;
    cout << "Введите шаг чисел: ";
    cin >> step;
    cout << "Если Вам нужны символы перед цифрами, то введите 1, если нет, то 0: ";
    cin >> use_prefix;

    if (use_prefix) {
        cout << "Введите текст: ";
        cin.ignore(); // Очистка буфера ввода
        getline(cin, prefix);
    }
    else {
        prefix = "";
    }

    // Запись чисел в файл
    auto start_time = chrono::steady_clock::now();
    print_numbers(start, end, step, prefix, use_prefix);
    auto end_time = chrono::steady_clock::now();
    auto search_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    // Завершение программы
    cout << "Программа завершена" << endl << "Время работы программы: " << search_time.count() << "ms" << endl;

    return 0;
}