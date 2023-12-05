/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Greatest common divisor (GCD)
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

// GCD of all numbers in a vector.
ll gcd_of_all(vector<ll> &integers)
{
    ll overall_gcd = integers[0];
    for (ll &i : integers)
    {
        overall_gcd = __gcd(overall_gcd, i);
    }
    return overall_gcd;
}