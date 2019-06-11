#include <iostream>
#include <climits>

int brute(int* price, int n) {
    if (n <= 0) return 0;
    int q = INT_MIN;
    for (int i = 0; i < n; ++i) {
        q = std::max(q, price[i] + brute(price, n - i - 1));
    } return q;
}

int topdown(int* price, int n, int* memo) {
   if (memo[n] >= 0) return memo[n];
   int q = INT_MIN;
   if (n == 0) q = 0;
   else {
       for (int i = 1; i <= n; ++i) {
           q = std::max(q, price[i] + topdown(price, n - i, memo));
       }
   } memo[n] = q;
   return q;
}

int bottomup(int* price, int n) {
    int val[n + 1];
    val[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int q = INT_MIN;
        for (int j = 0; j < i; ++j) {
            q = std::max(q, price[j] + val[i - j - 1]);
        } val[i] = q;
    } return val[n];
}

int main(int argc, char *argv[]) {
    int n; std::cin >> n;
    int* pricing = new int[n + 1];
    pricing[0] = 0;
    for (int i = 0; i < n; ++i) pricing[i + 1] = pricing[i] + rand() % n;
    std::cout << bottomup(pricing, n + 1);
    std::cout << " ";
    int* arr = new int[n + 1];
    for (int i = 0; i <= n; ++i) {
        arr[i] = INT_MIN;
    } std::cout << topdown(pricing, n, arr);
    std::cout << " ";
    std::cout << brute(pricing, n + 1);
    return 0;
}
