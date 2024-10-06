#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum;
    cin >> sum;

    int dp[n + 1][sum + 1];

    dp[0][0] = 1;

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                int opt1 = dp[i - 1][j - arr[i - 1]];
                int opt2 = dp[i - 1][j];

                dp[i][j] = opt1 + opt2;
            }
            else
            {
                int opt2 = dp[i - 1][j];
                dp[i][j] = opt2;
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}