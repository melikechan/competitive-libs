/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - BFS in a graph.
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

// Breadth-first search (BFS).
void bfs(int node, vector<int> adj[], vector<bool> &visited)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i : adj[node])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
