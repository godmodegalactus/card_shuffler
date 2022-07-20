cmake_minimum_required(VERSION 3.0.0)
project(random_card_shuffler VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(random_card_shuffler main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
