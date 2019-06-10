#include <iostream>
#include <climits>

int brute(int* arr, int n) {
    if (n == 0) return 0;
    int q = INT_MIN;
    for (int i = 0; i < n; ++i) {
        q = (q > arr[i] + brute(arr, n - 1)) ? q : arr[i] + brute(arr, n - 1);
    } return q;
}

int main(void) {
    int n; std::cin >> n;
    int* pricing = new int[n + 1];
    pricing[0] = 0;
    for (int i = 0; i < n; ++i) pricing[i + 1] = pricing[i] + rand() % n;
    std::cout << brute(pricing, n + 1);
 // std::cout << " ";
 // std::cout << finesse
    return 0;
}
