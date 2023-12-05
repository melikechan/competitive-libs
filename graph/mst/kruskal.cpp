/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Kruskal's algorithm for finding the minimum spanning tree of a graph using DSU.
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

// Problem: https://cses.fi/problemset/task/1675

// Union-find structure.
vector<int> parent;
vector<int> set_size;

void construct(int v)
{
    parent[v] = v;
    set_size[v] = 1;
}

int find(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    // Path compression
    return parent[v] = find(parent[v]);
}

void union_set(int u, int v)
{
    // We want to find the parents, because the parent represents the set.
    u = find(u);
    v = find(v);

    if (u != v)
    {
        // Merge the smaller set into the bigger set.
        if (set_size[u] < set_size[v])
        {
            swap(u, v);
        }
        parent[v] = u;
        set_size[u] += set_size[v];
    }
}

void setup_dsu_kruskal(int n)
{
    parent.resize(n);
    set_size.resize(n);

    // Create n disjoint sets. We will union them later.
    for (int i = 0; i < n; i++)
    {
        construct(i);
    }
}

// Kruskal's algorithm for finding minimum spanning tree.
ll kruskal(int n, int m)
{
    ll total_cost = 0;
    vector<tuple<ll, int, int>> edgelist;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edgelist.push_back({w, u - 1, v - 1});
    }

    // In order to find the minimum span tree, we need to sort edges.
    sort(edgelist.begin(), edgelist.end());

    // In Kruskal, we use DSU to merge sets. If the nodes are in the same set, we don't add the edge.
    int edge_count = 0;

    // As the edges are sorted, we can iterate over them.
    for (auto &[w, u, v] : edgelist)
    {
        if (find(u) != find(v))
        {
            union_set(u, v);
            total_cost += w;
            edge_count++;
        }
    }

    if (edge_count != n - 1)
    {
        // There is no MST.
        return -1;
    }
    return total_cost;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    setup_dsu_kruskal(n);
    ll ans = kruskal(n, m);
    if (ans == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << ans;
    }
}