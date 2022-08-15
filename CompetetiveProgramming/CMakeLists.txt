set(execName App)

add_library(utility_interface INTERFACE)
add_library(leetcode_interface INTERFACE)
add_library(codeforces_interface INTERFACE)

target_include_directories(utility_interface INTERFACE Utility/)
target_include_directories(leetcode_interface INTERFACE LeetCode/)
target_include_directories(codeforces_interface INTERFACE CodeForces/)

add_executable(${execName} Main.cpp)


