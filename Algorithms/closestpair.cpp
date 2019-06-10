#include <iostream>
#include <ctime>
#include <climits>
#include <cmath>

class Point {
private:
    int x, y;
public:
    Point() {};
    ~Point() {};
    void set(int a, int b) {
        x = a;
        y = b;
    }
    int getx() { return x; };
    int gety() { return y; };
};

inline double dist(Point a, Point b) {
    return sqrt(pow(a.getx() - b.getx(), 2) + pow(a.gety() - b.gety(), 2));
}

double minimum(double x, double y) { return (x < y) ? x : y; }

double naive(Point* arr, int size) {
    double min = dist(arr[0], arr[1]);
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (min > dist(arr[i], arr[j])) min = dist(arr[i], arr[j]);
        }
    } return min;
}

double closest(Point* arr, int l, int r) {
    double min = (double)INT_MAX;
    if (l < r) {
        int m = l + (r - l) / 2;
        int n1 = m - l + 1, n2 = r - m;
        Point* L = new Point[n1 + 1];
        Point* R = new Point[n2 + 1];
        for (int i = 0; i < n1 ; i++) L[i] = arr[l + i];
        for (int j = 0; j < n2 ; j++) R[j] = arr[m + j + 1];
        L[n1].set((double)INT_MAX, (double)INT_MAX);
        R[n2].set((double)INT_MAX, (double)INT_MAX);
        int a = 0, b = 0;
        for (int k = l; k <= r; k++) {
            if (L[a].getx() <= R[b].getx()) arr[k] = L[a++];
            else arr[k] = R[b++];
        } delete[] L; delete[] R;
        min = minimum(closest(arr, l, m), closest(arr, m + 1 , r));
        double compare = min;
        for (int i = l; i <= r; ++i) {
            for (int j = r; j > i; --j) {
                if (arr[j].getx() - arr[i].getx() <= min &&
                    arr[i].getx() - arr[j].getx() <= min &&
                    arr[j].gety() - arr[i].gety() <= min &&
                    arr[i].gety() - arr[j].gety() <= min) {
                    compare = minimum(compare, dist(arr[i], arr[j]));
                }
            }
        } min = compare;
    } return min;
}

int main() {
    int n; std::cin >> n;
    Point* arr = new Point[n];

    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; ++i) {
        int x = rand() % (n);
        int y = rand() % (n);
        arr[i].set(x, y);
    }

    std::cout << naive(arr, n);
    std::cout << " ";
    std::cout << closest(arr, 0, n - 1);
}
