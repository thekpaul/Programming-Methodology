#include <iostream>
#include <climits>

int main() {
    int n; std::cin >> n;
    int* p = new int[n + 1]; int** m = new int*[n];
    for (int i = 0; i < n; ++i) std::cin >> p[i] >> p[i + 1];
    for (int i = 0; i < n; ++i) {
        m[i] = new int[n]; if (i != 0) m[i][i] = 0;
    } for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n + 1 - l; ++i) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) m[i][j] = q;
            }
        }
    } std::cout << m[1][n];
    delete[] p;
    return 0;
}
