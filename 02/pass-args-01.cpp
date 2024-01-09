#include <iostream>
#include <string>
#include <thread>

void repeat(std::string str, int n) {
    if (n > 0) {
        std::cout << str << std::endl;
        repeat(str, n-1);
    }
}

int main() {
    auto str = std::string{"blah"};
    auto t = std::thread{repeat, str, 3};
    std::cout << "Hello from main!\n";
    t.join();
    std::cout << "After join: " << str << std::endl;
}
