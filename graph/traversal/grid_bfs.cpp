/*
    Author: Melike Vurucu (melikechan)
    I hope I won't get confused.

    About this file: BFS on a grid.
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

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &i : v)
    {
        os << i << " ";
    }
    return os;
}

// Question: https://cses.fi/problemset/task/1193
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid;
    vector<vector<bool>> visited;

    grid.assign(n, vector<char>(m, '.'));
    visited.assign(n, vector<bool>(m, false));
    pair<int, int> start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start = pair<int, int>{i, j};
            }
            else if (grid[i][j] == 'B')
            {
                end = pair<int, int>{i, j};
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, pair<int, int>{-1, -1}));
    vector<char> ans;
    q.push(start);
    parent[start.first][start.second] = pair<int, int>{start.first, start.second};

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int r = curr.first, c = curr.second;
        if (visited[r][c] || grid[r][c] == '#')
        {
            continue;
        }
        visited[r][c] = true;
        if (r + 1 < n && grid[r + 1][c] != '#' && !visited[r + 1][c])
        {
            q.push(pair<int, int>{r + 1, c});
            parent[r + 1][c] = pair<int, int>{r, c};
        }
        if (r - 1 >= 0 && grid[r - 1][c] != '#' && !visited[r - 1][c])
        {
            q.push(pair<int, int>{r - 1, c});
            parent[r - 1][c] = pair<int, int>{r, c};
        }
        if (c + 1 < m && grid[r][c + 1] != '#' && !visited[r][c + 1])
        {
            q.push(pair<int, int>{r, c + 1});
            parent[r][c + 1] = pair<int, int>{r, c};
        }
        if (c - 1 >= 0 && grid[r][c - 1] != '#' && !visited[r][c - 1])
        {
            q.push(pair<int, int>{r, c - 1});
            parent[r][c - 1] = pair<int, int>{r, c};
        }
    }

    if (!visited[end.first][end.second])
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n";
        pair<int, int> curr = end;
        while (curr != start)
        {
            auto prev = parent[curr.first][curr.second];
            if (prev.first == curr.first)
            {
                if (prev.second < curr.second)
                {
                    ans.push_back('R');
                }
                else
                {
                    ans.push_back('L');
                }
            }
            else
            {
                if (prev.first < curr.first)
                {
                    ans.push_back('D');
                }
                else
                {
                    ans.push_back('U');
                }
            }
            curr = prev;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto &i : ans)
        {
            cout << i;
        }
    }
}