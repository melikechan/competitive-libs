/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Lowest common multiple without modulo (LCM)
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

// LCM of all numbers in a vector without modulo.
ll lcm_of_all(vector<ll> &integers)
{
    ll overall_lcm = integers[0];

    for (ll &i : integers)
    {
        overall_lcm = overall_lcm / __gcd(overall_lcm, i) * i;
    }

    return overall_lcm;
}