cmake_minimum_required(VERSION 3.10)

project(SecureAutoComplete LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Giúp VS Code gợi ý code thông minh hơn
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(SecureAutoComplete
    main.cpp
    trie.cpp
    hash_table.cpp
    universal_hash.cpp
)

configure_file(dictionary.txt ${CMAKE_CURRENT_BINARY_DIR}/dictionary.txt COPYONLY)