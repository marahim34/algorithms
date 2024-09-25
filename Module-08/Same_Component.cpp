#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
char arr[N][N];
bool vis[N][N];
int n, m;

vector<pair<int, int>> dis = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + dis[i].first;
        int cj = sj + dis[i].second;
        if (ci >= 0 && ci < n && cj >= 0 && cj < m && !vis[ci][cj] && arr[ci][cj] == '.')
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
            cin >> arr[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;

    memset(vis, false, sizeof(vis));

    dfs(si, sj);

    int di, dj;
    cin >> di >> dj;

    if (vis[di][dj])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}