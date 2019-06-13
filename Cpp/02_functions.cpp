#include <iostream>

int SumofThree(int a, int b, int c) {
    return a + b + c;
    // Returns the sum of three integers
}

void SwapTwo(int &a, int &b) {
    int temp = a;
    a = b; b = temp;
    // No return values
}

int SumofFour(int a = 1, int b = 2, int c = 3, int d = 4) {
    return a + b + c + d;
    // Returns the sum of four integers
}

void SwapByValue(int a, int b) {
    int temp = a; // Save VALUE OF a
    a = b; b = temp; // Switch values
}
void SwapByReference(int& a, int& b) {
    int temp = a; // Save VALUE OF a
    a = b; b = temp; // Switch values
}
void SwapByPointer(int* a, int* b) {
    int temp = *a; // Save value at ADDRESS a
    *a = *b; *b = temp;
    // Switch address in pointer
}

inline int ProductThree(int a, int b, int c) {
    return a * b * c;
    // Returns the product of three integers.
}

int Factorial(int a) {
    if (a <= 0) return 1;
    // Return a terminating value
    else return a * Factorial(a - 1);
    // Provide decremental value for rescursion
}

int main(int argc, char* argv[]) {
    std::cout << SumofThree(3, 4, 5); // Result: 12
    std::cout << std::endl;
    int a = 3, b = 4;
    SwapTwo(a, b); // No return values, therefore no result
    std::cout << a << " " << b; // Result: 4 3
    std::cout << std::endl;
    std::cout << SumofFour(2, 3); // Result: 12
    std::cout << std::endl;
    int x = 5, y = 3;
    SwapByValue(x, y); // Provide values
    std::cout << x << " " << y << " ";
    // Result: 5 3 -> No change
    SwapByReference(x, y); // Provide variables
    std::cout << x << " " << y << " ";
    // Result: 3 5 -> Swap Variables
    SwapByPointer(&x, &y); // Provide addresses
    std::cout << x << " " << y << " ";
    // Result: 5 3 -> Swap Addresses
    std::cout << std::endl;
    std::cout << ProductThree(3, 4, 5); // Result: 60
    std::cout << std::endl;
    std::cout << Factorial(5); // Result: 60
    return 0;
}
