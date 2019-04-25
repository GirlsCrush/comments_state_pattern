cmake_minimum_required(VERSION 3.1.0)

include(gTest.cmake)

add_executable(comments_gTest
    "project/comments_remover.cpp"
    "project/comments.cpp"
    "project/states.cpp"
    "test/comments_gTest.cpp"
)
target_include_directories(comments_gTest PRIVATE
    "project"
)
set_target_properties(comments_gTest PROPERTIES
    CXX_STANDARD 14
)

add_gTest(comments_gTest)
