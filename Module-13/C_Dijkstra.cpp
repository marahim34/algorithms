#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>

const ll N = 1e5 + 5;
vector<pi> v[N];
ll par[N];
ll dis[N];

class cmp
{
public:
    bool operator()(pi a, pi b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src)
{
    priority_queue<pi, vector<pi>, cmp> pq;
    pq.push({src, 0});

    dis[src] = 0;

    while (!pq.empty())
    {
        pi parent = pq.top();
        pq.pop();

        ll parentNode = parent.first;
        ll parentCost = parent.second;

        for (pi child : v[parentNode])
        {
            ll childNode = child.first;
            ll childCost = child.second;

            if (parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                pq.push({childNode, dis[childNode]});
                par[childNode] = parentNode;
            }
        }
    }
}

int main()
{
    ll n, e;
    cin >> n >> e;

    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for (ll i = 0; i <= n; i++)
    {
        dis[i] = 1e18;
        par[i] = -1;
    }

    dijkstra(1);

    if (dis[n] == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        ll x = n;

        vector<ll> v;

        while (x != -1)
        {
            v.push_back(x);
            x = par[x];
        }

        reverse(v.begin(), v.end());

        for (ll val : v)
        {
            cout << val << " ";
        }
    }

    return 0;
}