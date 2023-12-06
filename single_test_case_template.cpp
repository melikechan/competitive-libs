/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.
*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse4,avx,avx2,bmi,bmi2,popcnt,lzcnt") // default architechture flags, you can use below as fallback
// #pragma GCC target("sse4,bmi,bmi2,popcnt,lzcnt")

using namespace std;

using ll = long long;
using ld = long double;

// Loops
#define loopi($i, s, es, n, inc) for (ll $i = s; es < n; $i += inc)
#define loopieq($i, s, es, n, inc) for (ll $i = s; es <= n; $i += inc)
#define loopd($i, s, es, n, dec) for (ll $i = s; es > n; $i -= dec)
#define loopdeq($i, s, es, n, dec) for (ll $i = s; es >= n; $i -= dec)

/*
    Pairs and tuples
    i -> int (for every int, there is a corresponding i)
    l -> long long
*/
typedef pair<int, int> pii;
typedef tuple<int, int, int> piii;
typedef tuple<int, int, int, int> piiii;
typedef tuple<int, int, int, int, int> piiiii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> plll;
typedef tuple<ll, ll, ll, ll> pllll;
typedef tuple<ll, ll, ll, ll, ll> plllll;

/*
    Nested vectors
    v -> vector (for every level of nesting, there is a corresponding v)
    vi -> vector<int>
    vl -> vector<long long>
*/
/*
    Nested vectors
    v -> vector (for every level of nesting, there is a corresponding v)
    vi -> vector<int>
    vl -> vector<long long>
*/
/*
    Nested vectors
    v -> vector (for every level of nesting, there is a corresponding v)
    vi -> vector<int>
    vl -> vector<long long>
*/
// int -> vector<int>
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
// pair<int, int> -> vector<pair<int, int>>
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
// tuple<int, int, int> -> vector<tuple<int, int, int>>
typedef vector<piii> vpiii;
typedef vector<vpiii> vvpiii;
// tuple<int, int, int, int> -> vector<tuple<int, int, int, int>>
typedef vector<piiii> vpiiii;
typedef vector<vpiiii> vvpiiii;
// tuple<int, int, int, int, int> -> vector<tuple<int, int, int, int, int>>
typedef vector<piiiii> vpiiiii;
typedef vector<vpiiiii> vvpiiiii;
// long long -> vector<long long>
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
// pair<long long, long long> -> vector<pair<long long, long long>>
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
// tuple<long long, long long, long long> -> vector<tuple<long long, long long, long long>>
typedef vector<plll> vplll;
typedef vector<vplll> vvplll;
// tuple<long long, long long, long long, long long> -> vector<tuple<long long, long long, long long, long long>>
typedef vector<pllll> vpllll;
typedef vector<vpllll> vvpllll;
// tuple<long long, long long, long long, long long, long long> -> vector<tuple<long long, long long, long long, long long, long long>>
typedef vector<plllll> vplllll;
typedef vector<vplllll> vvplllll;

// Constants
constexpr ll mod = ll(1e9) + 7;
constexpr ll inf = 2e18;
constexpr int intinf = INT_MAX - 1e3;
constexpr ll mod = ll(1e9) + 7;
constexpr ll inf = 2e18;
constexpr int intinf = INT_MAX - 1e3;

inline ll lsb(ll x)
{
    return (x) & (-x);
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &i : v)
    {
        os << i << " ";
    }
    return os;
}

void solve()
{
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
