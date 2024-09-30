#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int group_size[N];

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

void dsu_initialize(int n)
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
    return leader;
}

void dsu_union_by_size(int nodeA, int nodeB)
{
    int leaderA = dsu_find(nodeA);
    int leaderB = dsu_find(nodeB);

    if (parent[leaderA] > parent[leaderB])
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

bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}

int main()
{
    int n, e;
    cin >> n >> e;

    dsu_initialize(n);

    vector<Edge> edgeList;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;

        edgeList.push_back(Edge(u, v, c));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);

    int totalCost = 0;
    int edgeCount = 0;

    for (Edge ed : edgeList)
    {
        int leaderU = dsu_find(ed.u);
        int leaderV = dsu_find(ed.v);

        if (leaderU != leaderV)
        {
            dsu_union_by_size(ed.u, ed.v);
            totalCost += ed.c;
            edgeCount++;

            if (edgeCount == n - 1)
            {
                break;
            }
        }
    }

    if (edgeCount != n - 1)
    {
        cout << -1 << endl;
    }
    else
    {

        cout << totalCost << endl;
    }

    return 0;
}