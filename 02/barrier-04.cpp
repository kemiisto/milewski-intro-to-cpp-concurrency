#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

int main() {
    auto threads = std::vector<std::thread>{};
    for (std::size_t i = 0; i < 16; ++i) {
        threads.emplace_back([&] {
            std::this_thread::sleep_for(10ms * i);
            std::cout << "Hello from thread " << i << std::endl;
        });
    }
    std::cout << "Hello from main!\n";
    for (auto& t : threads) {
        t.join();
    }
}
