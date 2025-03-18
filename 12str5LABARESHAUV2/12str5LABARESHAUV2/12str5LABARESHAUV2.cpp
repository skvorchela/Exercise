﻿#include <iostream>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream f;
    f.open("input9.txt");
    if (!f.is_open()) {
        cout << "Не удалось открыть файл" << endl;
        return -1;
    }

    int n1, n2;
    if (!(f >> n1 >> n2)) {
        cout << "Некорректные данные в файле" << endl;
        f.close();
        return -1;
    }

    if (n1 > 20 || n2 > 20) {
        cout << "Превышен максимально допустимый размер массива!" << endl;
        return -1;
    }

    int** a = new int* [n1];
    for (int i = 0; i < n1; i++)
        a[i] = new int[n2];

    int** b = new int* [n1];
    for (int i = 0; i < n1; i++)
        b[i] = new int[n2];

    int** c = new int* [n1];
    for (int i = 0; i < n1; i++)
        c[i] = new int[n2];

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++) {
            if (!(f >> a[i][j])) {
                cout << "Некорректные данные в файле" << endl;
                f.close();
                return -1;
            }
        }

    f.close();

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            c[i][j] = 0;

    for (int j = 0; j < n2; j++) {    // копируем последнюю строку
        b[n1 - 1][j] = a[n1 - 1][j];
    }
    // записываем предпоследнюю строку
    b[n1 - 2][0] = a[n1 - 2][0] + b[n1 - 1][1];// первый элемент предпоследней строки
    b[n1 - 2][n2 - 1] = a[n1 - 2][n2 - 1] + b[n1 - 1][n2 - 2]; //последний элемент предпоследней строки
    for (int j = 1; j < n2 - 1; j++) //проходим по всем элементам строки кроме первого и последнего
        if (b[n1 - 1][j - 1] < b[n1 - 1][j + 1]) b[n1 - 2][j] = a[n1 - 2][j] + b[n1 - 1][j - 1];//сравниваем последнюю строку и последний столбец со следующим столбцом
        else b[n1 - 2][j] = a[n1 - 2][j] + b[n1 - 1][j + 1];//в ином случае пишем значение предп строки послед столбца как предпослед элем массива а столбца и строки + большего из b
    // записываем все оставшиеся строки
    for (int i = n1 - 3; i >= 0; i--) {    // идём с предпоследней строки массива б и вверх до первой
        if (b[i + 1][1] < b[i + 2][0]) b[i][0] = a[i][0] + b[i + 1][1];// для первого столбца каждой строки если знач в элем б на строке ниже и во втором столбце
        // меньше чем знач элем б через строку ниже и первом столбце, то запис сумма элем а в текущ строке и первом столбце и меньшего из двух знач б в строках ниже
        else b[i][0] = a[i][0] + b[i + 2][0]; // иначе запис сумма элемента этой троки а 1 столбца и большего знач б
        if (b[i + 1][n2 - 2] < b[i + 2][n2 - 1]) b[i][n2 - 1] = a[i][n2 - 1] + b[i + 1][n2 - 2];// для послед столбца каждой строки если значи в элементе б на строке ниже и предпоследнем столбце меньше
        // чем знач элем б через строку ниже и послед столбце, то запис в б сумма элемента массива а в текущ строке и послед столбце и меньшего знач б в строках ниже
        else b[i][n2 - 1] = a[i][n2 - 1] + b[i + 2][n2 - 1];
        for (int j = 1; j < n2 - 1; j++) { // по всем элем текущей строки
            int min = b[i + 2][j];
            if (b[i + 1][j - 1] < min) min = b[i + 1][j - 1]; // если знач элем б на строке ниже и в предыд столбце меньше мин, то мин меняется
            if (b[i + 1][j + 1] < min) min = b[i + 1][j + 1]; // если знач элем б на строке ниже и в след столбце меньше мин, то мин меняется
            b[i][j] = a[i][j] + min;
        }
    }

    int min = b[0][0], mini = 0, minj = 0;   // находим минимум в верхней строке
    for (int j = 0; j < n2; j++) { //по все столбцам верхней строки
        if (b[0][j] < min) {
            min = b[0][j];
            minj = j;
        }
    }
    c[mini][minj] = 1;
    cout << "Минимальная сумма: " << min << endl << endl;
    // проход по массиву в обратном порядке
    while (mini < n1 - 2) { //пока текущая строка нне достигнет предпоследней строки
        if (minj == 0) //обработка первого столбца
            if (b[mini + 2][minj] < b[mini + 1][minj + 1]) { //меньше ли значение б через 2 строки ниже в том же стобце чем знач б ниже в след столбце
                mini += 2;
                c[mini][minj] = 1;
            }
            else {
                mini++;
                minj++;
                c[mini][minj] = 1;
            }
        else if (minj == n2 - 1) //если текущ столбец равен последнему, то есть обраб последнего столбца
            if (b[mini + 2][minj] < b[mini + 1][minj - 1]) { //меньше ли знач б через 2 строки ниже и тп
                mini += 2;
                c[mini][minj] = 1;
            }
            else {
                mini++;
                minj--;
                c[mini][minj] = 1;
            }
        else { //обработка остальных столбцов
            int k = 0; //перем для хран индекса минимального значения, на две строки вниз
            min = b[mini + 2][minj]; //через две строки ниже чем в текущ столбце
            if (b[mini + 1][minj - 1] < min) { //строка ниже в прдыд столбце
                min = b[mini + 1][minj - 1];
                k = 1;
            }
            if (b[mini + 1][minj + 1] < min) {
                min = b[mini + 1][minj + 1];
                k = 2;
            }
            switch (k) {
            case 0: mini += 2; //на две строки вниз
                break; 
            case 1: { //на одну строку вниз и влево
                mini++;
                minj--;
            }
                  break;
            case 2: { //на одну строку вниз и в право
                mini++;
                minj++;
            }
                  break;
            }
            c[mini][minj] = 1;
        }
    }
    //продолж поиска миним пути в матрице, когда текущий элем (mini minj) не наход в последн строке
    if (mini != n1 - 1) { //при равных условиях выберем второй элемент, находится ли в последней строке
        if (minj == 0) { //если столбец первый то вниз и вправо
            mini++;
            minj++;
            c[mini][minj] = 1;
        }

        else if (minj == n2 - 1) { //второй то вниз и влево
            mini++;
            minj--;
            c[mini][minj] = 1;
        }

        else {
            if (b[mini + 1][minj - 1] < b[mini + 1][minj + 1]) { //сравниваем значения на строке ниже и выбираем меньшее
                mini++;
                minj--;
                c[mini][minj] = 1;
            }
            else {
                mini++;
                minj++;
                c[mini][minj] = 1;
            }
        }
    }

    cout << "Исходный массив:" << endl;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (c[i][j] == 1) cout << "\033[1;32m";
            cout << a[i][j] << ' ';
            if (c[i][j] == 1) cout << "\033[0m";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Массив с наименьшими суммами для каждой ячейки" << endl;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (c[i][j] == 1) cout << "\033[1;32m";
            cout << b[i][j] << ' ';
            if (c[i][j] == 1) cout << "\033[0m";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Массив пути:" << endl;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (c[i][j] == 1) cout << "\033[1;32m";
            cout << c[i][j] << ' ';
            if (c[i][j] == 1) cout << "\033[0m";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < n1; i++) {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }
    delete[] a;
    delete[] b;
    delete[] c;

    system("pause");
    return 0;
}
