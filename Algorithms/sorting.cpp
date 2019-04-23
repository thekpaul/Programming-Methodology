#include <iostream>
#include "Sort.h"

using namespace std;

bool check_quick(QuickSort *quick_sort) {
    int check = 0;
    for (int i = 1; i < quick_sort->size; i++) {
        if (quick_sort->arr[i - 1] > quick_sort->arr[i]) ++check;
    } if (check > 0) return false;
    else return true;
}

bool check_merge(MergeSort *merge_sort) {
    int check = 0;
    for (int i = 1; i < merge_sort->size; i++) {
        if (merge_sort->arr[i - 1] > merge_sort->arr[i]) ++check;
    } if (check > 0) return false;
    else return true;
}

bool check_insertion(InsertionSort *insertion_sort) {
    int check = 0;
    for (int i = 1; i < insertion_sort->size; i++) {
        if (insertion_sort->arr[i - 1] > insertion_sort->arr[i]) ++check;
    } if (check > 0) return false;
    else return true;
}

bool check_stooge(StoogeSort *stooge_sort) {
    int check = 0;
    for (int i = 1; i < stooge_sort->size; i++) {
        if (stooge_sort->arr[i - 1] > stooge_sort->arr[i]) ++check;
    } if (check > 0) return false;
    else return true;
}

bool check_heap(HeapSort *heap_sort) {
    int check = 0;
    for (int i = 2; i < heap_sort->size; i++) {
        if (heap_sort->arr[i - 1] > heap_sort->arr[i]) ++check;
    } if (check > 0) return false;
    else return true;
}

int main(int argc, char *argv[]) {
    int n; cin >> n;
    double *input_array = new double[n];
    for (int i = 0; i < n; i++) input_array[i] = double(rand() % n);

    // QuickSort
    QuickSort *quick_sort = new QuickSort();
    quick_sort->set(input_array, n);
    quick_sort->run();
    if (quick_sort->timer()) quick_sort->print_time();
    if (check_quick(quick_sort)) {
        cout << "QuickSort is validated" << endl << endl;
    } delete quick_sort;

    // MergeSort
    MergeSort *merge_sort = new MergeSort();
    merge_sort->set(input_array, n);
    merge_sort->run();
    if (merge_sort->timer()) merge_sort->print_time();
    if (check_merge(merge_sort)) {
        cout << "MergeSort is validated" << endl << endl;
    } delete merge_sort;

    // InsertionSort
    InsertionSort *insertion_sort = new InsertionSort();
    // implement here
    insertion_sort->set(input_array, n);
    insertion_sort->run();
    if (insertion_sort->timer()) insertion_sort->print_time();
    if (check_insertion(insertion_sort)) {
        cout << "InsertionSort is validated" << endl << endl;
    } delete insertion_sort;

    // StoogeSort
    StoogeSort *stooge_sort = new StoogeSort();
    // implement here
    stooge_sort->set(input_array, n);
    stooge_sort->run();
    if (stooge_sort->timer()) stooge_sort->print_time();
    if (check_stooge(stooge_sort)) {
        cout << "StoogeSort is validated" << endl << endl;
    } delete stooge_sort;

    // HeapSort
    HeapSort *heap_sort = new HeapSort();
    heap_sort->set(input_array, n);
    heap_sort->run();
    if (heap_sort->timer()) heap_sort->print_time();
    if (heap_sort->timer()) cout << "Time" ;
    if (check_heap(heap_sort)) {
        cout << "HeapSort is validated" << endl << endl;
    } delete heap_sort;

    return 0;
}
