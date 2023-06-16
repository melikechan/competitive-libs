/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Inverse factorial algorithm.
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

// Inverse factorial.
vector<__int128_t> inverse_factorials(N, 1);

void generate_inverse_factorials(ll n)
{
    next = n - 1;
    inverse_factorials[next] = modular_inverse_fast(factorials[next]);

    for (ll i = next - 1; i >= 0; i--)
    {
        inverse_factorials[i] = (inverse_factorials[i + 1] * (i + 1)) % mod;
    }
}