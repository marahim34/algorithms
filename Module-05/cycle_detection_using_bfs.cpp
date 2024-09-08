#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
vector<int> adj[N];
int parentArray[N];
bool ans;

void bfs(int src)
{
    queue<int> q;
    q.push(src);

    vis[src] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        cout << parent << endl;

        for (int child : adj[parent])
        {
            if (vis[child] && parentArray[parent] != child)
            {
                ans = true;
            }

            if (!vis[child])
            {
                vis[child] = true;
                parentArray[child] = parent;
                q.push(child);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    ans = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }

    if (ans == true)
    {
        cout << "Cycle found" << endl;
    }
    else
    {
        cout << "Cycle not found" << endl;
    }

    return 0;
}