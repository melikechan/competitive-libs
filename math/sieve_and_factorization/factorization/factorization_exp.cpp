/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Factorization with exponents.
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

// Linear sieve in O(N) time.
vector<ll> lowest_prime_fact(N);
vector<ll> primes;
vector<bool> is_prime(N, true);

void linear_sieve(ll n)
{
    for (ll i = 2; i <= n; i++)
    {
        if (lowest_prime_fact[i] == 0)
        {
            lowest_prime_fact[i] = i;
            primes.push_back(i);
            is_prime[i] = true;
        }
        for (ll j = 0; j < primes.size() && primes[j] <= lowest_prime_fact[i] && i * primes[j] <= n; j++)
        {
            lowest_prime_fact[i * primes[j]] = primes[j];
        }
    }
}

// Factorization with exponents.
unordered_map<ll, int> factorization(ll n)
{
    unordered_map<ll, int> res;
    while (n > 1)
    {
        res[lowest_prime_fact[n]]++;
        n /= lowest_prime_fact[n];
    }
    return res;
}