#include <iostream>
#include <vector>
#include <locale>

void shell(std::vector<int>& arr) {
    int n = arr.size();
    for (int d = n / 2; d > 0; d /= 2) {
        for (int i = d; i < n; i++) {
            int t = arr[i];
            int j;
            for (j = i; j >= d && arr[j - d] > t; j -= d) {
                arr[j] = arr[j - d];
            }
            arr[j] = t;
        }
    }
}




bool proverka(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++ ) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "rus");
    std::vector<int> arr = { 12, 34, 54, 2, 3, 11, 7, 89, 45, 67 };

    std::cout << "Исходный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    shell(arr);

    std::cout << "Отсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    if (proverka(arr)) {
        std::cout << "Массив отсортирован" << std::endl;
    }
    else {
        std::cout << "Массив не отсортирован" << std::endl;
    } 

    return 0;
}