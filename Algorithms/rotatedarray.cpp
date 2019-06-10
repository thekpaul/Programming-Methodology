#include <iostream>

int Searcher(int* a, int l, int r) {
    int m = l + (r - l) / 2; // Prevents overflow
    if (l == r) return a[l];
    else if (a[l] < a[r]) return a[l];
    else if (a[m] < a[r]) {
        if (a[m - 1] <= a[m]) return Searcher(a, l, m - 1);
        else return a[m];
    } else return Searcher(a, m + 1, r);
}

void sort(int *arr, int begin, int end) {
    int pivot = arr[begin];
    int i = begin, j = end;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++; j--;
        }
    } if (begin < j) sort(arr, begin, j);
    if (end > i) sort(arr, i, end);
}

bool check(int* a, int size) {
    int min = Searcher(a, 0, size - 1);
    for (int i = 0; i < size; ++i) {
        if (min > a[i]) return false;
    } return true;
}

int main(int argc, char *argv[]) {
    int n; std::cin >> n;
    int* input_array = new int[n];
    for (int i = 0; i < n; ++i) input_array[i] = int(rand() % n);
    sort(input_array, 0, n - 1); // See Previous Chapter
    std::cout << Searcher(input_array, 0, n - 1);
    if (check(input_array, n)) std::cout << "\nValid!";
    else std::cout << "\nCheck Again!";
    return 0;
}
