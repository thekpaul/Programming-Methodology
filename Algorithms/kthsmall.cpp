#include <iostream>

int quickselect(int* a, int k, int l, int r) {
    if (l == r) return a[l];
    int x = a[r], i = l;
    for (int j = l; j < r; ++j) {
        if (a[j] <= a[r]) {
            std::swap(a[i], a[j]);
            ++i;
        }
    } std::swap(a[i], a[r]);
    if (k == i - l + 1) return a[i];
    else if (k < i - l + 1) return quickselect(a, k, l, i - 1);
    else return quickselect(a, k - i + l - 1, i + 1, r);
}

int main(int argc, char *argv[]) {
    int n; std::cin >> n;
    int* input_array = new int[n];
    for (int i = 0; i < n; ++i) input_array[i] = int(rand() % n);
    int k; std::cin >> k;
    std::cout << quickselect(input_array, k, 0, n - 1);
    return 0;
}
