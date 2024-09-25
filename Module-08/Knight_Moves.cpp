#include <bits/stdc++.h>
using namespace std;

int dis[105][105];
bool vis[105][105];
vector<pair<int, int>> moves = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

int n, m;

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        for (auto &move : moves)
        {
            int ci = par.first + move.first;
            int cj = par.second + move.second;

            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[par.first][par.second] + 1;

                if (ci == di && cj == dj)
                    return;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;

        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj, di, dj);

        cout << dis[di][dj] << endl;
    }

    return 0;
}
