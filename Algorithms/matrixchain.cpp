#include <iostream>
#include <climits>

int func(int* p, int size) {
    int n = size - 1;
    int** m = new int*[size + 1];
    for (int i = 0; i <= size; ++i){
        m[i] = new int[n];
        if (i % size != 0) m[i][i] = 0; // i != 0 and i != size
    } for (int l = 2; l < size; ++l) {
        for (int i = 1; i <= size - l; ++i) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    } return m[1][n];
}

int main() {
    int n; std::cin >> n;
    int* p = new int[n + 1];
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i] >> p[i + 1];
    } std::cout << func(p, n + 1);
    delete[] p;
    return 0;
}
