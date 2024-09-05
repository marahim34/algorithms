#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> v[N];

bool vis[N];

void dfs(int source)
{
    cout << source << endl;
    vis[source] = true;
    for (int child : v[source])
    {
        if (vis[child] == false)
        {
            dfs(child);
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

    memset(vis, false, sizeof(vis));
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            count++;
        }
    }
    cout << "Component -" << count << endl;
    return 0;
}