#include <iostream>
#include <thread>

void thread_fun() {
    std::cout << "Hello from thread!\n";
}

int main() {
    auto t = std::thread{thread_fun};
    std::cout << "Hello from main!\n";
    t.join();
}
