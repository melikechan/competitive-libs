/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Modular inverse.
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

// Binary exponentiation with modulo
ll bin_exp_mod(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Modular inverse finding.
ll modular_inverse(ll n)
{
    n %= mod;
    ll result = 1;
    ll power = mod - 2;

    while (power > 0)
    {
        if (power & 1)
        {
            result = (result * n) % mod;
        }
        n = (n * n) % mod;
        power >>= 1;
    }

    return result;
}

// Modular inverse finding with Fermat's little theorem.
// USE IF AND ONLY IF MOD IS PRIME.
ll modular_inverse_fast(ll n)
{
    return bin_exp_mod(n, mod - 2, mod);
}