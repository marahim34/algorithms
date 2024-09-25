#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool visit[1005];
int level[1005];
int parent[1005];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visit[source] = true;

    level[source] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << endl;

        for (int child : v[par])
        {
            if (visit[child] == false)
            {
                q.push(child);
                visit[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
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

        v[a].push_back(b);
        v[b].push_back(a);
    }

    int source, destination;
    cin >> source >> destination;

    memset(visit, false, sizeof(visit));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    bfs(source);

    int x = destination;

    vector<int> path;

    while (x != -1)
    {
        //     cout << x << " ";
        //     x = parent[x];
        path.push_back(x);
        x = parent[x];
    }

    reverse(path.begin(), path.end());

    for (int i : path)
    {
        cout << i << " ";
    }

    return 0;
}