#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        // cout << par << endl;

        if (v[par].empty())
        {
            cout << "-1" << endl;
        }
        else
        {
            sort(v[par].begin(), v[par].end(), greater<int>());

            for (int i = 0; i < v[par].size(); i++)
            {
                int child = v[par][i];
                cout << child << " ";
            }

            cout << endl;
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

    int q;
    cin >> q;
    while (q--)
    {
        int src;
        cin >> src;

        memset(vis, false, sizeof(vis));

        bfs(src);
    }

    return 0;
}