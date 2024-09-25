#include <bits/stdc++.h>
using namespace std;

const int limit = 1005;
bool vis[1005][1005];
char a[1005][1005];
vector<pair<int, int>> dis = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int n, m;

bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= n || cj < 0 || cj >= m || a[ci][cj] == '#' || vis[ci][cj])
    {
        return false;
    }
    return true;
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int size = 1;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + dis[i].first;
        int cj = sj + dis[i].second;

        if (valid(ci, cj))
        {
            int new_size = dfs(ci, cj);
            size = new_size + size;
        }
    }
    return size;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    vector<int> total_size;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.' && !vis[i][j])
            {
                int apt_size = dfs(i, j);
                total_size.push_back(apt_size);
            }
        }
    }

    sort(total_size.begin(), total_size.end());

    for (int size : total_size)
    {
        cout << size << " ";
    }

    if (total_size.empty())
    {
        cout << 0;
    }

    cout << endl;

    return 0;
}
