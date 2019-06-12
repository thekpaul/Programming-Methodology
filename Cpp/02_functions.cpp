#include <iostream>

int SumofThree(int a, int b, int c) {
    return a + b + c; // Returns the sum of three integers, an integer
}

void SwapTwo(int &a, int &b) {
    int temp = a;
    a = b; b = temp;
    // No return values
}

int main(void) {
    SumofThree(3, 4, 5); // Result: 12
    int a = 3, b = 4;
    SwapTwo(a, b); // No return values, therefore no result
    std::cout << a << " " << b << std::endl; // Result: 4 3
    return 0;
}
