#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> v;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        // v.push_back(make_pair(a, b));
        v.push_back({a, b});
    }

    // Option: 1
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << endl;

    // Option: 2
    for (pair<int, int> p : v)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;

    // Option: 3
    for (auto p : v)
    {
        cout << p.first << " " << p.second << endl;
    }

    cout << endl;

    return 0;
}