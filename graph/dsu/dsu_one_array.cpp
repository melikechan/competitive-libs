/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Union-find structure with another implementation.
*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

using ll = long long;
using ld = long double;

constexpr ll mod = ll(1e9) + 7;
constexpr ll inf = LLONG_MAX - ll(1e6); // think that 1e6 like calculation window, for preventing overflow

// Union-find structure.
vector<int> unionfind;

/*
    if unionfind[v] < 0, then v is a root and -unionfind[v] is the size of the set.
    if unionfind[v] >= 0, then v is not a root and unionfind[v] is the parent of v.
*/
void construct(int v)
{
    unionfind[v] = -1;
}

int find(int v)
{
    if (v < 0)
    {
        return v;
    }
    // Path compression
    return unionfind[v] = find(unionfind[v]);
}

void union_set(int u, int v)
{
    // We want to find the parents, because the parent represents the set.
    u = find(u);
    v = find(v);

    int set_size_u = -unionfind[u], set_size_v = -unionfind[v];
    if (u != v)
    {
        // Merge the smaller set into the bigger set.
        if (set_size_u < set_size_v)
        {
            swap(u, v);
        }
        unionfind[v] = u;
        unionfind[u] = -(set_size_u + set_size_v);
    }
}

void setup()
{
    // n is number of nodes, m is number of edges.
    int n, m;
    cin >> n >> m;

    unionfind.resize(n);

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

        union_set(u, v);
    }
}