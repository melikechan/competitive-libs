/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Lowest common multiple with modulo (LCM)
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
constexpr ll maxn = ll(1e7) + 1;

// Binary exponentiation with modulo
ll bin_exp_mod(ll a, ll b, ll m)
{
    a %= m; // if a >= m
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Sieve of Eratosthenes in O(N log log N) time
vector<bool> is_prime(maxn, true);
vector<ll> primes;

void check_primes(ll n)
{
    is_prime[0] = is_prime[1] = false;

    if (n >= 2)
    {
        primes.push_back(2);
    }

    for (ll i = 4; i <= n; i += 2)
    {
        is_prime[i] = false;
    }
    for (ll i = 3; i <= n; i += 2)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

unordered_map<ll, ll> all_maximal_factors;

// Factorization with exponents.
void factorization(ll n)
{
    for (ll p : primes)
    {
        if (p * p > n)
        {
            break;
        }
        ll cnt = 0;
        while (!(n % p))
        {
            n /= p;
            cnt++;
        }
        if (cnt > 0)
        {
            all_maximal_factors[p] = max(all_maximal_factors[p], cnt);
        }
    }
    if (n > 1)
    {
        all_maximal_factors[n] = max(all_maximal_factors[n], 1LL);
    }
}

// LCM of all numbers in a vector. As using lcm operator with modulo gives incorrect results, use factorization.
ll lcm_of_all(vector<ll> &integers)
{
    ll overall_lcm = 1;
    for (ll &i : integers)
    {
        factorization(i);
    }

    for (auto &i : all_maximal_factors)
    {
        overall_lcm *= bin_exp_mod(i.first, i.second, mod);
        overall_lcm %= mod;
    }

    return overall_lcm % mod;
}