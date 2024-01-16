cmake_minimum_required(VERSION 3.27)

project(milewski_intro_to_cpp_concurrency LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(02-thread 02/thread.cpp)
add_executable(02-barrier-01 02/barrier-01.cpp)
add_executable(02-barrier-02 02/barrier-02.cpp)
add_executable(02-barrier-03 02/barrier-03.cpp)
add_executable(02-barrier-04 02/barrier-04.cpp)
add_executable(02-barrier-05 02/barrier-05.cpp)
add_executable(02-function-object 02/function-object.cpp)
add_executable(02-pass-args-01 02/pass-args-01.cpp)
add_executable(02-pass-args-02 02/pass-args-02.cpp)

add_executable(03-future 03/future.cpp)
add_executable(03-future-exception 03/future-exception.cpp)
add_executable(03-async 03/async.cpp)

add_executable(04-bad-pass 04/bad-pass.cpp)
add_executable(04-bad-const 04/bad-const.cpp)
add_executable(04-file-list 04/file-list.cpp)
