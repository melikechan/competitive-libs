/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.
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
    Votes (1 from 9)
    Hüseyin Burak'cığım is the 1st candidate.
    There are several islands, if any two candidates have the same vote on the same island, island's votes are invalid.
    I hate flood fill.
*/

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &i : v)
    {
        os << i << " ";
    }
    return os;
}

vector<vector<ll>> grid;
vector<vector<bool>> vis;

// Election in Gurdalland (Incomplete)
void hatred(ll r, ll c, ll rc, ll cc, vector<ll> &islandvotes)
{
    if (r < 0 || r >= rc || c < 0 || c >= cc || vis[r][c] || grid[r][c] == 0)
    {
        return;
    }
    vis[r][c] = true;
    islandvotes[grid[r][c] - 1]++;
    hatred(r + 1, c, rc, cc, islandvotes);
    hatred(r - 1, c, rc, cc, islandvotes);
    hatred(r, c + 1, rc, cc, islandvotes);
    hatred(r, c - 1, rc, cc, islandvotes);
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    // ll ans = 0;
    grid.assign(n, vector<ll>(m, 0));
    vis.assign(n, vector<bool>(m, false));
    vector<vector<ll>> islands;
    vector<ll> total_votes(9, 0); // all candidates' votes
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] != 0)
            {
                vector<ll> island_votes(9, 0);
                hatred(i, j, n, m, island_votes);
                islands.push_back(island_votes);
            }
        }
    }
}