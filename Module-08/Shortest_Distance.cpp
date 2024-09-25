#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const ll INF = 1e18;

int main()
{
    int n, e;
    cin >> n >> e;

    ll adj[n + 5][n + 5];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = INF;
            if (i == j)
            {
                adj[i][j] = 0;
            }
        }
    }

    while (e--)
    {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a][b] = min(adj[a][b], w);
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (adj[i][k] < INF && adj[k][j] < INF)
                {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    int Q;
    cin >> Q;
    while (Q--)
    {
        int X, Y;
        cin >> X >> Y;
        if (adj[X][Y] == INF)
        {
            cout << "-1\n";
        }
        else
        {
            cout << adj[X][Y] << "\n";
        }
    }

    return 0;
}
