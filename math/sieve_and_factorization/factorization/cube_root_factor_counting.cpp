/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file:
    - Check if a number is square. (O(sqrt(n)) time)
    - O(n^(1/3)) factor counting algorithm.
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

// Is square root check
vector<bool> is_sqrt(N, false);

void sqrt_check(ll n)
{
    for (ll i = 1; i * i <= n; i++)
    {
        is_sqrt[i * i] = true;
    }
}

// WIP: O(N^(1/3)) divisor counting algorithm
ll div_count(ll num)
{
    sqrt_check(num);

    ll fact_count = 1;
    ll temp = 0, n = num;
    for (ll p : primes)
    {
        while (!(num % p))
        {
            temp++;
            num /= p;
        }
        fact_count *= (temp + 1);
        temp = 0;
        if (num == 1 || p * p * p > n)
            break;
    }

    if (is_prime[num])
        fact_count *= 2;
    else if (is_sqrt[num] && num != 1)
        fact_count *= 3;
    else if (num != 1)
        fact_count *= 4;

    return fact_count;
}