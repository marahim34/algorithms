#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool visit[1005];
int level[1005];

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

    int source;
    cin >> source;

    memset(visit, false, sizeof(visit));
    memset(level, -1, sizeof(level));
    bfs(source);

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << level[i] << endl;
    }

    return 0;
}