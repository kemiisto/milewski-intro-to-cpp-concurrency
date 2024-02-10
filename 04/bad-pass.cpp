#include <future>
#include <iostream>
#include <memory>
#include <thread>

struct counter {
    explicit counter(int k) : n{k} {}
    int n;
};

int main() {
    auto* p_count = new counter{10};
    auto pu_count = std::unique_ptr<counter>{p_count};
    auto fut = std::async(
        [](std::unique_ptr<counter> p) { ++p->n; },
        std::move(pu_count)
    );
    fut.wait();
    std::cout << p_count->n << std::endl;
}
