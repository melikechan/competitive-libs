/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - DFS in a graph.
*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

using ll = long long;
using ld = long double;

constexpr ll mod = ll(1e9) + 7;
constexpr ll inf = LLONG_MAX - ll(1e6); // think that 1e6 like calculation window, for preventing overflow
constexpr int intinf = INT_MAX - 1e3;

// Depth-first search (DFS).
void dfs(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = true;
    for (int i : adj[node])
    {
        if (!visited[i])
            dfs(i, adj, visited);
    }
}