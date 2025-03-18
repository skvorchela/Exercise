#include <iostream> 
#include <fstream> 
using namespace std; 

int main() 
{
    setlocale(LC_ALL, "Russian"); 
    int* dvoichka, n; //будующий массив для двоичного предст гвоздя, испол ли гвоздь в комбинации
    int* num; 
    char* vrem; //визуал комбинации
    int x; 
    int xx = 1;

    int kolvochis = 0; 
    ifstream f("input.txt");
    while (!f.eof()) { // Цикл выполняется, пока не достигнут конец файла
        if (!(f >> x)) break; // Если не удается прочитать число из файла, прерываем цикл
        kolvochis++; // Увеличиваем счетчик чисел
    }
    f.close(); 
    cout << "Количество чисел в файле: " << kolvochis << endl; // Выводим количество чисел в файле

    num = new int[kolvochis + 1]; // Выделяем память под массив num
    num[0] = 0; // Иниц первый элем массива нулем

    f.open("input.txt"); // Открываем файл input.txt для чтения
    while (!f.eof()) { // Цикл выполняется, пока не достигнут конец файла
        if (!(f >> x)) break;
        num[xx] = x; // Сохраняем прочитанное число в массиве num
        xx++; // Увеличиваем счетчик
    }
    f.close(); // Закрываем файл

    n = kolvochis + 1; // num[0]=0, чтобы не выйти за пределы массива
    if (n > 20 || kolvochis <= 0) { 
        cout << "Файл пуст или не найден" << endl; // Выводим сообщение об ошибке
        system("pause");
        return 0; 
    }
    else { 
        cout << "Числа в файле: "; 
        for (int i = 0; i <= kolvochis; i++) { //выводим числа из файла
            cout << num[i] << " "; 
        }
        cout << endl;

        dvoichka = new int[n];
        for (int i = 0; i <= n - 1; i++) { 
            dvoichka[i] = 0; // Иниц каждый элем нулем
        }
        cout << endl;

        int P;
        int L;

        cout << "Количество гвоздей N=" << n << endl;
        cout << "Количество единиц длины P="; 
        cin >> P; 
        cout << "Длина веревки L="; 
        cin >> L; 
        cout << endl; 
        cout << "Возможные варианты соединений:" << endl;

        ofstream f1("output.txt");

        vrem = new char[n]; //для символ предст возможных комб
        vrem[0] = ' ';

        while (dvoichka[0] == 0) { // Цикл вып, пока первый элем dvoichka равен нулю
            int k = 1; //отслеж текущего номера гвоздя
            int vremL = 0; 
            int soedin = 0; 

            for (int i = 1; i <= n - 1; i++) // Цикл по всем элементам массива dvoichka
            {
                if (dvoichka[i] == 0)vrem[i] = ' '; // Если элем массива dvoichka равен нулю, то соотв элем массива vrem становится пробелом
                else {
                    vremL = vremL + (num[i] * P); vrem[i] = '-'; // В противном случае увел vremL на num[i] * P и присв элем массива vrem значение '-'
                    soedin++; // Увел счетчик soedin, сколько соединений в каждой комбинации
                }
            }

            // Условие, которое учит доп единицы верёвки на привязывание
            if (vremL + (soedin * 2) == L) // Если vremL + soedin * 2 равно L
            {
                for (int i = 1; i <= n - 1; i++) 
                {
                    cout << k << vrem[i]; 
                    f1 << k << vrem[i]; k++; // Записываем k и соотв элем массива vrem в файл
                };
                f1 << k << endl; 
                cout << k << endl;
            }

            int j = n - 1; 
            while (dvoichka[j] == 1) 
            {
                dvoichka[j] = 0; 
                j--; 
            }
            dvoichka[j] = 1; 
            k = 1; 
        }

        f1.close(); 
        delete[] dvoichka; 
        delete[] num; 
    }
    delete[]vrem; 

    system("pause"); 
    return 0; 
}
