#include <filesystem>
#include <future>
#include <iostream>
#include <string>
#include <vector>

using namespace std::filesystem;

auto list_dir(path const& dir) {
    auto files = std::vector<std::string>{};
    for (directory_iterator it{dir}; it != directory_iterator{}; ++it) {
        if (is_regular_file(it->status())) {
            files.push_back(it->path().filename().string());
        }
    }
    return files;
}

auto list_dirs(std::vector<path> const& paths) {
    std::vector<std::future<std::vector<std::string>>> futures;
    for (auto const& pth : paths) {
        std::cout << pth << std::endl;
        futures.emplace_back(std::async(list_dir, pth));
    }
    auto all_files = std::vector<std::string>{};
    for (auto& fut : futures) {
        auto files = fut.get();
        std::move(files.begin(), files.end(), std::back_inserter(all_files));
    }
    return all_files;
}

int main() {
    auto paths = std::vector<path>{};
    auto const root = R"(c:\Users\wildcat\Downloads)";
    for (directory_iterator it{root}; it != directory_iterator{}; ++it) {
        if (is_directory(it->status())) {
            paths.push_back(it->path());
        }
    }
    for (auto const& name : list_dirs(paths)) {
        std::cout << name << std::endl;
    }
}
