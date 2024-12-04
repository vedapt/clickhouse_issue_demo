cmake_minimum_required(VERSION 3.10)

project(my_clickhouse_client)
find_package(clickhouse-cpp CONFIG REQUIRED)

add_executable(client main.cpp)

target_link_libraries(client PRIVATE clickhouse::clickhouse-cpp-lib)
