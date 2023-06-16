# melikechan's competitive programming library

My competitive programming library, written in _mostly C++._

## Contents

### Algorithms

- [Math](libs/math)
  - [Combinatorics](libs/math/combinatorics)
  - [Modular Arithmetic](libs/math/modular_arithmetic)
  - [Sieve and Prime Factorization](libs/math/sieve_and_factorization)
    - [Factorization](libs/math/sieve_and_factorization/factorization)
    - [Sieve](libs/math/sieve_and_factorization/sieve)
  - [Factorial](libs/math/factorial.cpp)
  - [Fast Exponentiation](libs/math/fast_exponentiation.cpp)

- [Graph Algorithms](libs/graph)
  - [Traversal](libs/graph/traversal)
    - [Breadth-First Search](libs/graph/traversal/bfs.cpp)
    - [Depth-First Search](libs/graph/traversal/dfs.cpp)
    - [Flood Fill](libs/graph/traversal/flood_fill.cpp)
    - [BFS in a Grid](libs/graph/traversal/grid_bfs.cpp)
  - [Shortest Path](libs/graph/shortest_path)
    - [0-1 BFS](libs/graph/shortest_path/zeroone_bfs.cpp)
  - [Minimum Spanning Tree](libs/graph/mst)
    - [Kruskal's Algorithm](libs/graph/mst/kruskal.cpp)
    - [Prim's Algorithm](libs/graph/mst/prim.cpp)
  - [Utilities](libs/graph/utils)
    - [Bipartite Check](libs/graph/utils/bipartite.cpp)
    - [Cycle Check in an Undirected Graph](libs/graph/utils/cycle_check.cpp)
    - [Cycle Check in a Directed Graph](libs/graph/utils/cycle_check_directed.cpp)
    - [Topological Sort](libs/graph/utils/topological_sort.cpp)

### Data Structures

- [Graphs](libs/graph)
  - [Graph Representation](libs/graph/graph_basic.cpp)
  - [Disjoint Set Union](libs/graph/dsu)
    - [DSU (regular implementation)](libs/graph/dsu/dsu.cpp)
    - [DSU with one array](libs/graph/dsu/dsu_one_array.cpp)

## Contributing

If you spot a bug or want to see another algorithm/data structure added, feel free to open an issue or a pull request. I'm always open to suggestions!
