#include <iostream>

int main(int argc, char *argv[]) {
    std::cout << "Hello World!" << std::endl;
    enum list { a1 = 1, a2 = 2, a3 = 3, a4 };
    const int a = 3; // a cannot be altered.
    std::cout << 5 + 3 << " " << 5 - 3 << " " << 5 * 3 << " " << 5 / 3 << " " <<
        5 % 3 << std::endl; // Result: 8 2 15 1 2
    std::cout << (5 == 3) << (5 != 3) << (5 < 3) << (5 > 3) << (5 <= 3) <<
        (5 >= 3) << std::endl; // Result: 010101
    if (1 >= 0 && true) std::cout << "True" << std::endl;
    else std::cout << "False" << std::endl; // Result: True
    switch(a) {
        case 1:  std::cout << "a is " << 1 << std::endl; break;
        case 3:  std::cout << "a is " << 3 << std::endl; break;
        default: std::cout << "a is something else" << std::endl;
    } // Result: a is 3
    std::cout << 5 << (5 < 3 ? " is greater than " : " is less than ") << 3 <<
        std::endl; // Result: 5 is less than 3
    return 0;
}
