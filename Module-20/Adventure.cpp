#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 5;
const int maxW = 1e5 + 5;

int dp[maxN][maxW];

int knapsack(int n, int weight[], int val[], int W)
{
    if (n < 0 || W < 0)
    {
        return 0;
    }

    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    else
    {
    }

    if (weight[n] <= W)
    {
        int opt1 = knapsack(n - 1, weight, val, W - weight[n]) + val[n];
        int opt2 = knapsack(n - 1, weight, val, W);

        return dp[n][W] = max(opt1, opt2);
    }
    else
    {
        return dp[n][W] = knapsack(n - 1, weight, val, W);
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

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                dp[i][j] = -1;
            }
        }

        int ans = knapsack(n - 1, weight, val, W);

        cout << ans << endl;
    }

    return 0;
}