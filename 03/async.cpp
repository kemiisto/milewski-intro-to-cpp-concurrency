#include <future>
#include <iostream>
#include <string>
#include <thread>

std::string fun(bool flag) {
    if (flag) {
        std::cout << "Worker returning.\n";
        return "Message from worker.";
    } else {
        std::cout << "Worker throwing.\n";
        throw std::exception{"Exception from thread."};
    }
}

int main() {
    auto fut = std::async(fun, true);
    std::cout << "Main receiving:\n";
    try {
        auto const str = fut.get();
        std::cout << str << std::endl;
    } catch (std::exception const& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}
