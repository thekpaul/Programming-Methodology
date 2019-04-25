#include <iostream>
using namespace std;

void quicksort(double *arr, int begin, int end) {
    double pivot = arr[begin];
    int i = begin, j = end;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    } if (begin < j) quicksort(arr, begin, j);
    if (end > i) quicksort(arr, i, end);
}

void mergesort(double * arr, int begin, int end) {
    if (begin < end) {
        int centre = begin + (end - begin) / 2;
        mergesort(arr, begin, centre);
        mergesort(arr, centre + 1, end);
        int n1 = centre - begin + 1;
        int n2 = end - centre;
        double* L = new double[n1 + 1];
        double* R = new double[n2 + 1];
        for (int i = 0; i <= n1 - 1; i++) L[i] = arr[begin + i];
        for (int j = 0; j <= n2 - 1; j++) R[j] = arr[centre + j + 1];
        L[n1] = (double)INT_MAX;
        R[n2] = (double)INT_MAX;
        int a = 0, b = 0;
        for (int k = begin; k <= end; k++) {
            if (L[a] <= R[b]) arr[k] = L[a++];
            else arr[k] = R[b++];
        }
    }
}








void insertionsort(double* arr, int size) {
    for (int i = 1; i <= size - 1; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        } arr[j + 1] = key;
    }
}

void stoogesort(double* arr, int begin, int end) {
    if (begin >= end) return;
    else if (end - begin == 1) {
        if (arr[begin] > arr[end]) swap(arr[begin], arr[end]);
    } else {
        int d = (end - begin + 1) / 3;
        stoogesort(arr, begin, end - d);
        stoogesort(arr, begin + d, end);
        stoogesort(arr, begin, end - d);
    }
}

void heapsort(double *arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapsort(arr, n, largest);
    }
}

bool check(double *arr) {
    for (int i = 1; i < 2500; i++) {
        if (arr[i - 1] > arr[i]) return false;
    } return true;
}

int main(int argc, char *argv[]) {
    double *input_array = new double[2500];
    for (int i = 0; i < 2500; i++) input_array[i] = double(rand() % 2500);

    double *quick_arr = new double[2500];
    for (int i = 0; i < 2500; i++) quick_arr[i] = input_array[i];
    quicksort(quick_arr, 0, 2499);
    if (check(quick_arr)) cout << "Quicksort Validated" << endl;

    double *merge_arr = new double[2500];
    for (int i = 0; i < 2500; i++) merge_arr[i] = input_array[i];
    mergesort(merge_arr, 0, 2499);
    if (check(merge_arr)) cout << "Mergesort Validated" << endl;

    double *insertion_arr = new double[2500];
    for (int i = 0; i < 2500; i++) insertion_arr[i] = input_array[i];
    insertionsort(insertion_arr, 2500);
    if (check(insertion_arr)) cout << "Insertionsort Validated" << endl;

    double *stooge_arr = new double[2500];
    for (int i = 0; i < 2500; i++) stooge_arr[i] = input_array[i];
    stoogesort(stooge_arr, 0, 2499);
    if (check(stooge_arr)) cout << "Stoogesort Validated" << endl;

    double *heap_arr = new double[2500];
    for (int i = 0; i < 2500; i++) heap_arr[i] = input_array[i];
    for (int i = 1249; i >= 0; i--)
        heapsort(heap_arr, 2500, i);
    for (int i = 2499; i >= 0; i--) {
        swap(heap_arr[0], heap_arr[i]);
        heapsort(heap_arr, i, 0);
    } if (check(heap_arr)) cout << "Heapsort Validated" << endl;

    return 0;
}
