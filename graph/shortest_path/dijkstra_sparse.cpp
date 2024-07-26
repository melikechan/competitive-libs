/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Dijkstra's algorithm to find shortest path in a weighted graph.
*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse4,avx,avx2,bmi,bmi2,popcnt,lzcnt") // default architechture flags, you can use below as fallback
// #pragma GCC target("sse4,bmi,bmi2,popcnt,lzcnt")

using namespace std;

using ll = long long;
using ld = long double;

constexpr ll mod = ll(1e9) + 7;
constexpr ll inf = LLONG_MAX - ll(1e6); // think that 1e6 like calculation window, for preventing overflow
constexpr int intinf = INT_MAX - 1e3;

// Dijkstra's algorithm to find shortest path in a weighted graph.
// adj[node] = {node, weight}
void dijkstra(int source, vector<pair<int, ll>> adj[], vector<ll> &dist)
{
    dist.assign(adj->size(), inf);
    dist[source] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0LL, source});

    while (!pq.empty())
    {
        auto [backward_dist, node] = pq.top();
        pq.pop();

        if (backward_dist > dist[node])
        {
            continue;
        }

        for (auto neighbor : adj[node])
        {
            auto [to, weight] = neighbor;
            if (dist[node] + weight < dist[to])
            {
                dist[to] = dist[node] + weight;
                pq.push({dist[to], to});
            }
        }
    }
}