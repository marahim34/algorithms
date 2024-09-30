#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
char arr[N][N];
bool vis[N][N];
int n, m;

vector<pair<int, int>> dis = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int area = 1;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + dis[i].first;
        int cj = sj + dis[i].second;

        if (ci >= 0 && ci < n && cj >= 0 && cj < m && !vis[ci][cj] && arr[ci][cj] == '.')
        {
            area += dfs(ci, cj);
        }
    }
    return area;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int minArea = INT_MAX;
    bool foundComponent = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.' && !vis[i][j])
            {
                foundComponent = true;
                int area = dfs(i, j);
                minArea = min(minArea, area);
            }
        }
    }

    if (foundComponent)
    {
        cout << minArea << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
