/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Bipartite check using BFS.
*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

using ll = long long;
using ld = long double;

constexpr ll mod = ll(1e9) + 7;
constexpr ll inf = LLONG_MAX - ll(1e6); // think that 1e6 like calculation window, for preventing overflow

// Question: https://cses.fi/problemset/task/1668

// Check if the component is bipartite using BFS.
bool bfs_bipartite(int node, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(node);
    color[node] = 1;
    bool is_bipartite = true;
    while (!q.empty() && is_bipartite)
    {
        int node = q.front();
        q.pop();
        for (int i : adj[node])
        {
            if (color[i] == -1)
            {
                color[i] = 1 - color[node];
                q.push(i);
            }
            else if (color[i] == color[node])
            {
                is_bipartite = false;
                break;
            }
        }
    }
    return is_bipartite;
}

// Example usage:
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            if (!bfs_bipartite(i, adj, color))
            {
                cout << "IMPOSSIBLE";
                return;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << color[i] + 1 << " ";
    }
}