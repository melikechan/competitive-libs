/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Sieve of Eratosthenes in O(N log log N) time
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

// Sieve of Eratosthenes in O(N log log N) time
vector<bool> is_prime(N, true);
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