/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.
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

int edit(string s, string t)
{
    if (s.length() == 0 || t.length() == 0)
    {
        return 0;
    }

    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, intinf));

    dp[0][0] = 0;

    for (int i = 0; i <= s.length(); i++)
    {
        for (int j = 0; j <= t.length(); j++)
        {
            if (i > 0)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); // delete
            }
            if (j > 0)
            {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1); // insert
            }
            if (i > 0 && j > 0)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1])); // replace
            }
        }
    }

    return dp[s.length()][t.length()];
}

void solve()
{
    string s, t;
    cin >> s >> t;

    cout << edit(s, t);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
