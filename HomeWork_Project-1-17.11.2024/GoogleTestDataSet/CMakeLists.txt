cmake_minimum_required(VERSION 3.0)
project(DataSet)

include_directories(${CMAKE_SOURCE_DIR}/../src)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/../src/BiNode.cpp
    ${CMAKE_SOURCE_DIR}/../src/BiLinkedList.cpp
    ${CMAKE_SOURCE_DIR}/../src/Dataset.cpp
)

add_executable(test
    main.cpp
    ${SOURCES}
)

target_link_libraries(test gtest gmock pthread)
