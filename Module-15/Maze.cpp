#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
int dis[MAX][MAX];
bool vis[MAX][MAX];
pair<int, int> parent[MAX][MAX];
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char a[MAX][MAX];

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    if (vis[i][j] == true || a[i][j] == '#')
    {
        return false;
    }
    if (a[i][j] != '.' && a[i][j] != 'D')
    {
        return false;
    }
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    parent[si][sj] = {-1, -1};

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int x = par.first;
        int y = par.second;

        if (a[x][y] == 'D')
        {

            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int ci = x + v[i].first;
            int cj = y + v[i].second;

            if (valid(ci, cj))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[x][y] + 1;
                parent[ci][cj] = {x, y};
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    int si = -1, sj = -1;
    int ei = -1, ej = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            parent[i][j] = {-1, -1};
        }
    }

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            a[i][j] = s[j];
            if (a[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (a[i][j] == 'D')
            {
                ei = i;
                ej = j;
            }
        }
    }

    if (si == -1 || sj == -1 || ei == -1 || ej == -1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
        return 0;
    }

    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    bfs(si, sj);

    if (vis[ei][ej])
    {
        int x = ei;
        int y = ej;
        while (!(x == si && y == sj))
        {
            int px = parent[x][y].first;
            int py = parent[x][y].second;
            if (px == -1 && py == -1)
            {
                break;
            }
            if (a[x][y] != 'R' && a[x][y] != 'D')
            {
                a[x][y] = 'X';
            }
            x = px;
            y = py;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
    }

    return 0;
}
