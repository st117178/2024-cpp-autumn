cmake_minimum_required(VERSION 3.0)
project(ProjectName)

include_directories(${CMAKE_SOURCE_DIR}/Bank_src ${CMAKE_SOURCE_DIR}/Text-editor_src)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/Bank_src/Bank.cpp
    ${CMAKE_SOURCE_DIR}/Bank_src/BankAccount.cpp
    ${CMAKE_SOURCE_DIR}/Text-editor_src/txt-editor.cpp
)

add_executable(test
    main.cpp
    ${SOURCES}
)

target_link_libraries(test gtest gmock pthread)
