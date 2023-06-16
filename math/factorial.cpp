/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Factorial algorithm.
*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

using ll = long long;
using ld = long double;

constexpr ll mod = ll(1e9) + 7;
constexpr ll inf = LLONG_MAX - ll(1e6); // think that 1e6 like calculation window, for preventing overflow
constexpr ll N = ll(1e7) + 1;

// Factorial.
vector<__int128_t> factorials(N, 1);
__int128_t next = 1;

void generate_factorials(ll n)
{
    for (ll i = next; i <= n; i++)
    {
        factorials[i] = (factorials[i - 1] * i);
        next++;
    }
}