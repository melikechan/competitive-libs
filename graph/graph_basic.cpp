/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Graph structure.
*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

using ll = long long;
using ld = long double;

constexpr ll mod = ll(1e9) + 7;
constexpr ll inf = LLONG_MAX - ll(1e6); // think that 1e6 like calculation window, for preventing overflow

/*
    Adjacency list:
    Vector of vectors. (inside vector is for holding weights and some other information, but usually we use pair<int, int> for weights)
*/

vector<vector<int>> adj;

void setup()
{
    // n is number of nodes, m is number of edges.
    int n, m;
    cin >> n >> m;

    adj.resize(n);

    for (int i = 0; i < m; i++)
    {
        int u, v /*, w */;
        cin >> u >> v /* >> w */;

        // If graph is undirected, we add the edge to both nodes. Otherwise we add only to one node.
        // In the most cases, indices are 1-based, so we subtract 1 from them.
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);


        // If graph is weighted, we add the weight to the vector.
        // adj[u-1].push_back({v-1, w});
        // adj[v-1].push_back({u-1, w});
    }
}