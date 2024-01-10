#include <future>
#include <iostream>
#include <string>
#include <thread>

void fun(std::promise<std::string>&& pr) {
    std::cout << "Worker throwing.\n";
    try {
        throw std::exception{"Exception from thread."};
    } catch (...) {
        pr.set_exception(std::current_exception());
    }
}

int main() {
    auto pr = std::promise<std::string>{};
    auto fut = pr.get_future();
    auto th = std::thread{fun, std::move(pr)};
    std::cout << "Main receiving:\n";
    try {
        auto const str = fut.get();
        std::cout << str << std::endl;
    } catch (std::exception const& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    th.join();
}
