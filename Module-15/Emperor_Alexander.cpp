#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int group_size[N];

class Edge
{
public:
    int u, v;
    long long c;

    Edge(int u, int v, long long c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

void dsu_initialization(int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

int dsu_find(int node)
{
    if (parent[node] == -1)
    {
        return node;
    }
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}

bool dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if (leaderA != leaderB)
    {
        if (group_size[leaderA] > group_size[leaderB])
        {
            parent[leaderB] = leaderA;
            group_size[leaderA] += group_size[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            group_size[leaderB] += group_size[leaderA];
        }
        return true;
    }
    return false;
}

bool compareEdges(Edge a, Edge b)
{
    return a.c < b.c;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;

    while (e--)
    {
        int u, v;
        long long cost;
        cin >> u >> v >> cost;

        edges.push_back(Edge(u, v, cost));
    }

    sort(edges.begin(), edges.end(), compareEdges);

    dsu_initialization(n);

    long long total_cost = 0;
    int cycle_edges = 0;
    int edges_used = 0;

    for (Edge edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        long long cost = edge.c;

        int leaderU = dsu_find(u);
        int leaderV = dsu_find(v);

        if (leaderU == leaderV)
        {
            cycle_edges++;
        }
        else
        {
            dsu_union_by_size(u, v);
            total_cost += cost;
            edges_used++;
        }
    }

    if (edges_used == n - 1)
    {
        cout << cycle_edges << " " << total_cost << endl;
    }
    else
    {
        cout << "Not Possible" << endl;
    }

    return 0;
}
