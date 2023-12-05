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
constexpr ll maxn = 1e4;

// Problem: https://algoleague.com/problem/array-lcm/detail

// Sieve of Eratosthenes in O(N log log N) time
vector<bool> is_prime(maxn, true);
vector<ll> primes;

void check_primes(ll n)
{
    is_prime[0] = is_prime[1] = false;

    if (n >= 2)
        primes.push_back(2);

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

unordered_map<ll, ll> maximal;

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
        while (n % p == 0)
        {
            cnt++;
            n /= p;
        }
        if (cnt > 0)
        {
            maximal[p] = max(maximal[p], cnt);
        }
    }
    if (n > 1)
    {
        maximal[n] = max(maximal[n], 1LL);
    }
}

void solve()
{
    check_primes(maxn);
    ll n;
    cin >> n;
    ll ans = 1;
    for (ll i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        factorization(x);
    }
    for (auto &p : maximal)
    {
        ans = ans * bin_exp_mod(p.first, p.second, mod) % mod;
    }
    cout << ans;
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}