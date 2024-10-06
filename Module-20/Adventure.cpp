#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int weight[], int val[], int W)
{
    if (n < 0 || W < 0)
    {
        return 0;
    }

    if (weight[n] <= W)
    {
        int opt1 = knapsack(n - 1, weight, val, W - weight[n]) + val[n];
        int opt2 = knapsack(n - 1, weight, val, W);

        return max(opt1, opt2);
    }
    else
    {
        return knapsack(n - 1, weight, val, W);
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, W;
        cin >> n >> W;

        int weight[n], val[n];

        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }

        int ans = knapsack(n - 1, weight, val, W);

        cout << ans << endl;
    }

    return 0;
}