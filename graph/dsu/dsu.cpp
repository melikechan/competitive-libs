/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Union-find structure.
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

// Union-find structure.
vector<int> parent;
vector<int> set_size;

int n, m; // n -> number of nodes, m -> number of edges

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

void setup()
{
    parent.resize(n);
    set_size.resize(n);

    // Create n disjoint sets. We will union them later.
    for (int i = 0; i < n; i++)
    {
        construct(i);
    }

    // Union the sets.
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        union_set(u, v);
    }
}

void solve()
{
    cin >> n >> m;

    setup();
}