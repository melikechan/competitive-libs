/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Cycle check in a graph using DFS.
*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

using ll = long long;
using ld = long double;

constexpr ll mod = ll(1e9) + 7;
constexpr ll inf = LLONG_MAX - ll(1e6); // think that 1e6 like calculation window, for preventing overflow

// Question: https://cses.fi/problemset/task/1678

int cycle_start = -1, cycle_end = -1; // start and endpoints of the cycle

/*
    In this modified DFS, we keep track of the parent of each node.
    If we find a node that is already visited and not the parent of the current node,
    then we have found a cycle.

    First, we mark node as visited. If the node is already visited, then we have found a cycle.
    To find intermediate nodes of the cycle, we keep track of the parent of each node.
*/
bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &parent)
{
    vis[node] = 1;

    for (int i : adj[node])
    {
        if (vis[i] == 1)
        {
            cycle_start = i;
            cycle_end = node;
            return true;
        }
        else if (vis[i] == 0)
        {
            parent[i] = node;
            if (dfs(i, adj, vis, parent)) // we can find a cycle
                return true;
        }
    }

    vis[node] = 2;
    return false;
}

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
    }

    vector<int> vis(n, 0); // 0 -> not visited, 1 -> visited, 2 -> finished
    vector<int> parent(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0 && dfs(i, adj, vis, parent))
            break;
    }

    if (cycle_start == -1)
        cout << "IMPOSSIBLE\n";
    else
    {
        vector<int> cycle;

        // Construct the cycle
        cycle.push_back(cycle_start);
        for (int i = cycle_end; i != cycle_start; i = parent[i])
            cycle.push_back(i);
        cycle.push_back(cycle_start);

        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (int i : cycle)
            cout << i + 1 << " ";
        cout << "\n";
    }
}