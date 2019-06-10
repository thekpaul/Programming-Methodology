#include <iostream>
#include <ctime>

int main(int argc, char *argv[]) {
    int n; std::cin >> n;
    srand((unsigned int)time(NULL));
    int* a1 = new int[n]; int* a2 = new int[n];
    int* t1 = new int[n]; int* t2 = new int[n];
    for (int i = 0; i < n; i++) {
        a1[i] = rand() % n; a2[i] = rand() % n;
        t1[i] = rand() % n; t2[i] = rand() % n;
    } int e1 = rand() % n, e2 = rand() % n;
    int x1 = rand() % n, x2 = rand() % n;
    int way1 = e1 + a1[0];
    int way2 = e2 + a2[0];
    for (int i = 1; i < n; i++) {
        int temp = way1;
        way1 = a1[i] + (way1 < way2 + t2[i - 1]) ? way1 : way2 + t2[i - 1];
        way2 = a2[i] + (way2 < temp + t1[i - 1]) ? way2 : temp + t1[i - 1];
    } std::cout << (way1 + x1 < way2 + x2) ? way1 + x1 : way2 + x2;
    return 0;
}
