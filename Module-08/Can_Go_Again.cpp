#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 1e18; // Updated INF

class Edge
{
public:
    int u, v;
    ll w;
    Edge(int u, int v, ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

vector<ll> dis;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edgeList;
    edgeList.reserve(e);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        edgeList.push_back(Edge(u, v, w));
    }

    dis.resize(n, INF);

    int src;
    cin >> src;
    src--;
    dis[src] = 0;

    bool updated;
    for (int i = 0; i < n - 1; i++)
    {
        updated = false;
        for (const Edge &ed : edgeList)
        {
            int u = ed.u, v = ed.v;
            ll w = ed.w;
            if (dis[u] < INF && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                updated = true;
            }
        }
        if (!updated)
            break;
    }

    bool negativeCycle = false;
    for (const Edge &ed : edgeList)
    {
        int u = ed.u, v = ed.v;
        ll w = ed.w;
        if (dis[u] < INF && dis[u] + w < dis[v])
        {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0; // Terminate if negative cycle is detected
    }

    int t;
    cin >> t;

    while (t--)
    {
        int d;
        cin >> d;
        d--;

        if (dis[d] == INF)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dis[d] << endl;
        }
    }

    return 0;
}
