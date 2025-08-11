#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

int main() {
    auto threads = std::vector<std::thread>{};
    for (std::size_t i = 0; i < 16; ++i) {
        threads.emplace_back([&] {
            std::this_thread::sleep_for(std::chrono::milliseconds{10*i});
            std::cout << "Hello from thread " << i << std::endl;
        });
    }
    std::cout << "Hello from main!\n";
    for (auto& t : threads) {
        t.join();
    }
}
