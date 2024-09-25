#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 1003;
const ll INF = 1e9 + 5;

vector<pair<int, int>> adj[N];
ll dist[N];

class Comparator
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src)
{
    for (int i = 0; i < N; ++i)
    {
        dist[i] = INF;
    }
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> pq;
    pq.push({src, 0});

    while (!pq.empty())
    {
        int node = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if (cost > dist[node])
            continue;

        for (auto &edge : adj[node])
        {
            int nextNode = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[nextNode])
            {
                dist[nextNode] = dist[node] + weight;
                pq.push({nextNode, dist[nextNode]});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    int src;
    cin >> src;
    dijkstra(src);

    int t;
    cin >> t;
    while (t--)
    {
        int d;
        ll dw;
        cin >> d >> dw;

        if (dist[d] == INF)
        {
            cout << "NO\n";
        }
        else if (dist[d] <= dw)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
