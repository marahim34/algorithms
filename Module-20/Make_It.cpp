#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

bool vis[N];

bool bfs(int src)
{
    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (current == src)
        {
            return true;
        }

        if (current + 3 <= src && !vis[current + 3])
        {
            q.push(current + 3);
            vis[current + 3] = true;
        }

        if (current * 2 <= src && !vis[current * 2])
        {
            q.push(current * 2);
            vis[current * 2] = true;
        }
    }

    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        memset(vis, false, sizeof(vis));

        if (bfs(n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
