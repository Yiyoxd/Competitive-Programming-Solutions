cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 26)

add_executable(untitled main.cpp
        "Graph Theory/Topological Sorting/Max Tree.cpp"
        Template.cpp
        "Graph Theory/Topological Sorting/Fox And Names.cpp"
        "Graph Theory/Topological Sorting/Course Schedule.cpp"
        "Graph Theory/Topological Sorting/Topological Sorting.cpp"
        "Math/Probabilities and Expected Values/Probabilities and Expected Values/Sakurako's Box.cpp")
