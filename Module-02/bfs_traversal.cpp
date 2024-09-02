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

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << endl;
        level[source] = 0;

        // for (int i = 0; i < v[par].size(); i++)
        // {
        //     int child = v[par][i];
        //     cout << child << endl;
        // }

        for (int child : v[par])
        {
            // cout << child << endl;
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
    bfs(source);

    return 0;
}