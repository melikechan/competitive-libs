/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Prim's algorithm for finding the minimum spanning tree of a graph.
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

// Prim's algorithm for finding the minimum spanning tree of a graph. This algorithm works like Dijkstra's algorithm with slight differences.
ll prim(vector<pair<int, ll>> adj[], int n)
{
    ll cost = 0, node_count = 0;
    vector<bool> visited(n, false);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push(pair<ll, int>{0, 0});

    while (!pq.empty() && node_count < n)
    {
        auto [w, u] = pq.top();
        pq.pop();

        if (visited[u])
        {
            continue;
        }
        visited[u] = true;

        cost += w;
        node_count++;

        for (auto [v, w] : adj[u])
        {
            if (!visited[v])
            {
                pq.push(pair<ll, int>{w, v});
            }
        }
    }

    if (node_count < n)
    {
        // There is no MST.
        return -1;
    }
    return cost;
}