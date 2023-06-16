/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Linear sieve in O(N) time.
    - Möbius function using linear sieve.
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

/*
    Möbius function using linear sieve.

    Values:

    if mobius[i] == 0, i has a squared prime factor.
    if mobius[i] == 1, i is square-free and has an even number of prime factors.
    if mobius[i] == -1, i is square-free and has an odd number of prime factors.
*/
vector<ll> mobius(N, 1);
vector<bool> is_composite(N, false);

void mobius_func(ll n)
{
    linear_sieve(n);

    for (ll i = 2; i <= n; i++)
    {
        if (!is_composite[i])
        {
            mobius[i] = -1;
        }

        for (ll j = 0; j < primes.size() && primes[j] * i <= n; j++)
        {
            is_composite[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                mobius[primes[j] * i] = 0;
                break;
            }
            else
            {
                mobius[primes[j] * i] = mobius[i] * mobius[primes[j]];
            }
        }
    }
}