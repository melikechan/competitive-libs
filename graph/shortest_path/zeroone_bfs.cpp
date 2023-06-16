/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - 0-1 BFS to find shortest path in an undirected graph.
*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

using ll = long long;
using ld = long double;

constexpr ll mod = ll(1e9) + 7;
constexpr ll inf = LLONG_MAX - ll(1e6); // think that 1e6 like calculation window, for preventing overflow

// 0-1 Breadth-first search (BFS) to find shortest path in an undirected graph.
vector<int> bfs(int node, vector<pair<int, int>> adj[]) // adj[node] = {node, weight}
{
    vector<int> dist(adj->size(), inf);
    dist[node] = 0;
    deque<int> q;
    q.push_front(node);
    while (!q.empty())
    {
        int node = q.front();
        q.pop_front();
        for (auto i : adj[node])
        {
            if (dist[node] + i.second < dist[i.first])
            {
                dist[i.first] = dist[node] + i.second;
                if (i.second == 0)
                {
                    q.push_front(i.first);
                }
                else
                {
                    q.push_back(i.first);
                }
            }
        }
    }
    return dist;
}
