#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int weight[n], value[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int W;
    cin >> W;

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (weight[i - 1] <= j)
            {
                int opt1 = dp[i - 1][j - weight[i - 1]] + value[i - 1];
                int opt2 = dp[i - 1][j];

                dp[i][j] = max(opt1, opt2);
            }
            else
            {
                int opt2 = dp[i - 1][j];

                dp[i][j] = opt2;
            }
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= W; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][W];

    return 0;
}