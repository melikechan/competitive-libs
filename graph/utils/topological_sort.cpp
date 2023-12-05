/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Topological sort using DFS.
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

// Example question: https://cses.fi/problemset/task/1679

vector<int> toposort;

// Depth-first search for topological sort.
void dfs_toposort(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = true;
    for (int i : adj[node])
    {
        if (!visited[i])
            dfs_toposort(i, adj, visited);
    }
    toposort.push_back(node);
}

// Example usage:
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    vector<bool> visited(n, false);
    toposort.clear();

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u - 1].push_back(v - 1);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs_toposort(i, adj, visited);
    }

    reverse(toposort.begin(), toposort.end());
}