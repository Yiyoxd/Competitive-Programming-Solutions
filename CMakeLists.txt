cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 26)

add_executable(untitled main.cpp
        "Graph Theory/Graph Traversal/Topological Sorting/Max Tree.cpp"
        Template.cpp
        "Graph Theory/Graph Traversal/Topological Sorting/Fox And Names.cpp"
        "Graph Theory/Graph Traversal/Topological Sorting/Course Schedule.cpp"
        "Graph Theory/Graph Traversal/Topological Sorting/Topological Sorting.cpp"
        "Math/Probabilities and Expected Values/Probabilities and Expected Values/Sakurako's Box.cpp"
        "Number Theory/Number of Divisors, Sum of Divisors, Sigma Function/Sum of Divisors.cpp"
        "Math/Probabilities and Expected Values/Probabilities and Expected Values/Journey.cpp"
        "Graph Theory/Graph Traversal/Breadth First Search (BFS)/Maze.cpp"
        "Graph Theory/Graph Traversal/Breadth First Search (BFS)/Message Route.cpp"
        "Graph Theory/Graph Traversal/Breadth First Search (BFS)/Labyrinth.cpp"
        "Graph Theory/Graph Traversal/Breadth First Search (BFS)/Cycle In Maze.cpp")
