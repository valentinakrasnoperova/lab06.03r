#include <iostream>
#include <iomanip>
#include <time.h>
#include "func.h"

using namespace std;


template <typename T>
void Create_r(T* arr, const int size, T Low, T High, int i) {
    if (i == size) {
        return;
    }
    arr[i] = Low + rand() % (High - Low + 1);
    Create_r(arr, size, Low, High, i + 1);
}

void Create_r(int* arr, const int size, const int Low, const int High, int i) {
    if (i == size) {
        return;
    }
    arr[i] = Low + rand() % (High - Low + 1);
    Create_r(arr, size, Low, High, i + 1);
}

template <typename T>
void Print_r(T* arr, const int size, int i) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << arr[i];
    Print_r(arr, size, i + 1);
}

void Print_r(int* arr, const int size, int i) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << arr[i];
    Print_r(arr, size, i + 1);
}

template <typename T>
int Sum_r(T* arr, const int size, T i) {
    if (i == size) {
        return 0;
    }
    if (arr[i] > 0) {
        return Sum_r(arr, size, i + 1) + arr[i];
    }
    return Sum_r(arr, size, i + 1);
}


int main() {
    srand((unsigned)time(NULL));  // ініціалізація генератора випадкових чисел
    const int SIZE = 10;
    int arr[SIZE];

    int Low = 10;
    int High = 70;

    Create_r<int>(arr, SIZE, Low, High,0);
    Create_r(arr, SIZE, Low, High,0);
    Print_r<int>(arr, SIZE,0);
    Print_r(arr, SIZE,0);
    cout << "Sum= " << Sum_r<int>(arr, SIZE, 0) << endl;
    cout << "Sum = " << Sum_r(arr, SIZE, 0) << endl;
    return 0;
}