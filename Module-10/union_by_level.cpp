#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int parent[N];
int groupSize[N];
int level[N];

void dsu_initialize(int n)
{

    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        groupSize[i] = 1;
        level[i] = 0;
    }
    // parent[1] = 2;
    // parent[2] = 3;
    // parent[5] = 6;
    // parent[6] = 7;
}

int dsu_find(int node)
{

    if (parent[node] == -1)
        return node;

    int leader = dsu_find(parent[node]);

    parent[node] = leader;

    return leader;
}

void dsu_union(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    parent[leaderA] = leaderB;
}

void dsu_union_by_level(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if (level[leaderA] > level[leaderB])
    {
        parent[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA])
    {
        parent[leaderA] = leaderB;
    }
    else
    {
        parent[leaderA] = leaderB;
        level[leaderB]++;
    }
}

void dsu_union_by_size(int node1, int node2)

{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (groupSize[leaderA] > groupSize[leaderB])
    {
        parent[leaderB] = leaderA;
        groupSize[leaderA] += groupSize[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        groupSize[leaderB] += groupSize[leaderA];
    }
}

int main()
{

    dsu_initialize(7);

    dsu_union_by_level(2, 3);
    dsu_union_by_level(4, 5);
    dsu_union_by_level(1, 2);
    dsu_union_by_level(5, 6);
    dsu_union_by_level(1, 4);

    cout << dsu_find(1) << endl;

    cout << dsu_find(4) << endl;

    // cout << dsu_find(2) << endl;

    // dsu_union(1, 5);

    // cout << dsu_find(1) << endl;

    // for (int i = 1; i <= 7; i++)
    // {
    //     cout << parent[i] << " ";
    // }

    return 0;
}