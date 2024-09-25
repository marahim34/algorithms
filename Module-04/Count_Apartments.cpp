#include <bits/stdc++.h>
using namespace std;

const int limit = 1005;

char a[limit][limit];
bool vis[limit][limit];
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

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + dis[i].first;
        int cj = sj + dis[i].second;

        if (valid(ci, cj))
        {
            dfs(ci, cj);
        }
    }
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

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.' && !vis[i][j])
            {
                dfs(i, j);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
