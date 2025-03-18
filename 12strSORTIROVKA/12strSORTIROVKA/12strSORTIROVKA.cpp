#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <cmath>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Метод прямого выбора
void selectionSort(vector<int>& arr, bool printSteps = false) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int min = arr[i], index = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < min) {
                min = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = min;
        if (printSteps) {
            printArray(arr);
        }
    }
}

// Метод прямого включения
void insertionSort(vector<int>& arr, bool printSteps = false) {
    for (int i = 1; i < arr.size(); i++) {
        int x = arr[i], j = i;
        while (j > 0 && x < arr[j - 1]) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = x;
        if (printSteps) {
            printArray(arr);
        }
    }
}

// Шейкерная сортировка
void cocktailSort(vector<int>& arr, bool printSteps = false) {
    int left = 0, right = arr.size() - 1, k = right;
    do {
        for (int j = right; j > left; j--)
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                k = j;
            }
        left = k + 1;

        for (int j = left; j < right; j++)
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                k = j;
            }
        right = k - 1;
    } while (left < right);
}

// Сортировка Шелла
void shellSort(vector<int>& arr, bool printSteps = false) {
    for (int gap = arr.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < arr.size(); i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
            if (printSteps) {
                printArray(arr);
            }
        }
    }
}

// Быстрая сортировка
void quickSort(vector<int>& arr, int low, int high, bool printSteps = false) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1, printSteps);
        quickSort(arr, pi + 1, high, printSteps);

        if (printSteps) {
            printArray(arr);
        }
    }
}

// Обертка для быстрой сортировки
void quickSortWrapper(vector<int>& arr, bool printSteps) {
    quickSort(arr, 0, arr.size() - 1, printSteps);
}

// Функция для замера времени сортировки
template <typename Func>
long double measureTime2(Func func, vector<int> arr, bool printSteps = false) {
    auto start = chrono::high_resolution_clock::now();
    func(arr, printSteps);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<long double> diff = end - start;
    long double seconds = diff.count();
    seconds = roundl(seconds * 100000) / 100000;
    cout << "Время работы сортировки: " << seconds << " секунд\n";

    start = chrono::high_resolution_clock::now();
    func(arr, printSteps);
    end = chrono::high_resolution_clock::now();
    diff = end - start;
    seconds = diff.count();
    seconds = roundl(seconds * 100000) / 100000;
    cout << "Время работы сортировки сортированного: " << seconds << " секунд\n";

    reverse(arr.begin(), arr.end());
    start = chrono::high_resolution_clock::now();
    func(arr, printSteps);
    end = chrono::high_resolution_clock::now();
    diff = end - start;
    seconds = diff.count();
    seconds = roundl(seconds * 100000) / 100000;

    return seconds;
}

int main() {
    setlocale(LC_ALL, "ru");
    int n, t;
    cout << "Введите размер массива: ";
    cin >> n;

    vector<int> arr(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }

    cout << "Время работы метода прямого выбора в обратном порядке: " << measureTime2(selectionSort, arr, false) << " секунд\n";
    cout << "Время работы метода прямого включения в обратном порядке: " << measureTime2(insertionSort, arr, false) << " секунд\n";
    cout << "Время работы шейкерной сортировки в обратном порядке: " << measureTime2(cocktailSort, arr, false) << " секунд\n";
    cout << "Время работы сортировки Шелла в обратном порядке: " << measureTime2(shellSort, arr, false) << " секунд\n";
    cout << "Время работы быстрой сортировки в обратном порядке: " << measureTime2(quickSortWrapper, arr, false) << " секунд\n";

    cout << "Введите размер тестого массива(до 10 элементов): ";
    cin >> t;
    if (t <= 100) {
        vector<int> arr2(t);
        for (int i = 0; i < t; i++) {
            arr2[i] = dis(gen);
        }
        printArray(arr2);
        cout << "Время работы метода прямого выбора в обратном порядке: " << measureTime2(selectionSort, arr2, true) << " секунд\n";
        printArray(arr2);
        cout << "Время работы метода прямого включения в обратном порядке: " << measureTime2(insertionSort, arr2, true) << " секунд\n";
        printArray(arr2);
        cout << "Время работы шейкерной сортировки в обратном порядке: " << measureTime2(cocktailSort, arr2, true) << " секунд\n";
        printArray(arr2);
        cout << "Время работы сортировки Шелла в обратном порядке: " << measureTime2(shellSort, arr2, true) << " секунд\n";
        printArray(arr2);
        cout << "Время работы быстрой сортировки в обратном порядке: " << measureTime2(quickSortWrapper, arr2, true) << " секунд\n";
    }
    else {
        cout << "Вы указали тестовый массив больше 10 элементов: ";
        return 0;
    }
    return 0;
}
