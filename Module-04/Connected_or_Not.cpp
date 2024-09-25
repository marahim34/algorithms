#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> v(n);

    while (e--)
    {

        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        if (a == b)
        {
            cout << "YES" << endl;
            continue;
        }

        bool found = false;
        for (int n : v[a])
        {
            if (n == b)
            {
                found = true;
                break;
            }
        }
        if (found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
