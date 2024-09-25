#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int parent[N];
int group_size[N];

void dsu_initialization(int n)
{
    for (int i = 0; i < n; i++)
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

void dsu_union_by_size(int nodeA, int nodeB)
{
    int leaderA = dsu_find(nodeA);
    int leaderB = dsu_find(nodeB);

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
}

class Edge
{
public:
    int u, v, c;

    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}

int main()
{
    int n, e;
    cin >> n >> e;

    dsu_initialization(n);

    vector<Edge> edgeList;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;

        edgeList.push_back(Edge(u, v, c));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);

    int total_cost = 0;
    for (Edge edge : edgeList)
    {
        int leaderU = dsu_find(edge.u);
        int leaderV = dsu_find(edge.v);

        if (leaderU == leaderV)
        {
            continue;
        }
        else
        {
            dsu_union_by_size(edge.u, edge.v);
            total_cost += edge.c;
        }
    }

    cout << total_cost << endl;

    return 0;
}