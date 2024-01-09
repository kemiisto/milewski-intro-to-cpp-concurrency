#include <iostream>
#include <thread>
#include <vector>

class fun_obj {
public:
    explicit fun_obj(int i) : i_{i} {}
    void operator()() {
        std::cout << "Hello from thread!\n";
    }
private:
    int i_;
};

int main() {
    auto threads = std::vector<std::thread>{};
    for (int i = 0; i < 16; ++i) {
        threads.emplace_back(fun_obj{i});
    }
    std::cout << "Hello from main!\n";
    for (auto& t : threads) {
        t.join();
    }
}
