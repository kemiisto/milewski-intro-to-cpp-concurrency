#include <future>
#include <iostream>
#include <string>
#include <thread>

void fun(std::promise<std::string>&& pr) {
    std::cout << "Worker sending.\n";
    pr.set_value("Message from thread.");
}

int main() {
    auto pr = std::promise<std::string>{};
    auto fut = pr.get_future();
    auto th = std::thread{fun, std::move(pr)};
    std::cout << "Main receiving:\n";
    auto const str = fut.get();
    std::cout << str << std::endl;
    th.join();
}
