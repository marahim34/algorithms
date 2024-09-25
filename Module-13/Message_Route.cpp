#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> v[N];
int vis[N];
int dis[N];
int par[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);

    vis[src] = true;
    dis[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child : v[parent])
        {
            if (!vis[child])
            {
                vis[child] = true;
                q.push(child);
                dis[child] = dis[parent] + 1;
                par[child] = parent;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    memset(par, -1, sizeof(par));
    bfs(1);

    if (dis[n] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        int x = n;
        vector<int> path;

        while (x != -1)
        {
            path.push_back(x);
            x = par[x];
        }

        reverse(path.begin(), path.end());

        cout << path.size() << endl;

        for (int val : path)
        {
            cout << val << " ";
        }
    }

    return 0;
}