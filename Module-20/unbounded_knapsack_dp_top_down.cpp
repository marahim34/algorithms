#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int unbounded_knapsack(int n, int s, int val[], int weight[])
{
    if (n == 0 || s == 0)
    {
        return 0;
    }

    if (dp[n][s] != -1)
    {
        return dp[n][s];
    }

    if (weight[n - 1] <= s)
    {
        int ch1 = val[n - 1] + unbounded_knapsack(n, s - weight[n - 1], val, weight);
        int ch2 = unbounded_knapsack(n - 1, s, val, weight);
        return dp[n][s] = max(ch1, ch2);
    }

    else
    {
        return dp[n][s] = unbounded_knapsack(n - 1, s, val, weight);
    }
}

int main()
{
    int n, s;
    cin >> n >> s;

    int val[n], weight[n];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    int ans = unbounded_knapsack(n, s, val, weight);

    cout << ans << endl;

    return 0;
}