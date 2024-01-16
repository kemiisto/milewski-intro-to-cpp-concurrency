#include <future>
#include <iostream>
#include <thread>

struct counter {
    explicit counter(int k) : n{k} {}
    int n;
};

struct holder {
    explicit holder(int n) : c{new counter{n}} {}
    counter* c;
};

int main() {
    auto const h = holder{10};
    auto fut = std::async([](holder const& h) { ++h.c->n; }, h);
    std::cout << h.c->n << std::endl;
    fut.wait();
    std::cout << h.c->n << std::endl;
}
