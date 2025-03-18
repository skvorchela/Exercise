#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_N = 20;
int numbers[MAX_N];
int subset[MAX_N]; //массив для хран текущего подмножества
int N;

// Функция для проверки, является ли последовательность арифметической прогрессией
bool isArithmeticProgression(int arr[], int len) {
    int d = arr[1] - arr[0]; // Разность между первыми двумя элементами массива
    for (int i = 2; i < len; ++i) { // Начинаем с третьего элемента массива
        if (arr[i] - arr[i - 1] != d) { // Если разность между остальными элементами не равна разности между первыми двумя, возвращаем false
            return false;
        }
    }
    return true;
}

// Рекурсивная функция для перебора всех возможных подмножеств
void generateSubsets(int arr[], int subset[], int n, int subsetSize, int index, ofstream& outputFile) { //индекс это текущ индекс в исходном массиве
    if (index == n) { // Достигли конца массива
        if (subsetSize >= 3 && isArithmeticProgression(subset, subsetSize)) { // Подмножество должно быть не менее 3 элементов и быть арифметической прогрессией
            for (int i = 0; i < subsetSize; ++i) { // Записываем подходящее подмножество в файл
                outputFile << subset[i] << " ";
            }
            outputFile << endl;
        }
        return;
    }
    // Включаем текущий элемент в подмножество
    subset[subsetSize] = arr[index];
    generateSubsets(arr, subset, n, subsetSize + 1, index + 1, outputFile);
    // Не включаем текущий элемент в подмножество
    generateSubsets(arr, subset, n, subsetSize, index + 1, outputFile);
}

int main() {
    ifstream inputFile("input.txt"); // Открытие файла для чтения
    ofstream outputFile("output.txt"); // Открытие файла для записи

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Не удалось открыть файлы." << endl;
        return 1;
    }

    N = 0; //количество элементов в массиве numbers
    string line; // Переменная для чтения строк из файла
    while (getline(inputFile, line) && N < MAX_N) { // Считываем строки из файла, пока не достигнем конца файла или не прочитаем MAX_N строк
        numbers[N++] = stoi(line); // Преобразуем строку в целое число и добавляем его в массив numbers, N увеличивается после каждого чтения строки
    }

    // Сортировка массива пузырьком
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (numbers[j] > numbers[j + 1]) { // Сравниваем соседние элементы массива
                swap(numbers[j], numbers[j + 1]); // Меняем местами, если элементы не в порядке
            }
        }
    }

    generateSubsets(numbers, subset, N, 0, 0, outputFile); // Генерируем все подмножества и записываем подходящие в файл

    inputFile.close(); // Закрываем входной файл
    outputFile.close(); // Закрываем выходной файл

    return 0;
}
