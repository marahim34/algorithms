#include <bits/stdc++.h>
using namespace std;

const int limit = 1005;
char a[limit][limit];
bool vis[limit][limit];
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool bfs(int startRow, int startCol, int destRow, int destCol, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({startRow, startCol});
    vis[startRow][startCol] = true;

    while (!q.empty())
    {
        auto [row, col] = q.front();
        q.pop();

        if (row == destRow && col == destCol)
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dir[i].first;
            int newCol = col + dir[i].second;

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !vis[newRow][newCol] && a[newRow][newCol] != '#')
            {
                vis[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int startRow = -1, startCol = -1;
    int endRow = -1, endCol = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                startRow = i;
                startCol = j;
            }
            else if (a[i][j] == 'B')
            {
                endRow = i;
                endCol = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));

    if (startRow == -1 || endRow == -1)
    {
        cout << "NO" << endl;
        return 0;
    }

    if (bfs(startRow, startCol, endRow, endCol, n, m))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
