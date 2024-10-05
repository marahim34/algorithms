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

    bool dp[n + 1][sum + 1];

    dp[0][0] = true;

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                bool opt1 = dp[i - 1][j - arr[i - 1]];
                bool opt2 = dp[i - 1][j];

                dp[i][j] = opt1 || opt2;
            }
            else
            {
                bool opt2 = dp[i - 1][j];
                dp[i][j] = opt2;
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (dp[i][j])
            {
                cout << "T" << " ";
            }
            else
            {
                cout << "F" << " ";
            }
        }
        cout << endl;
    }

    if (dp[n][sum])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}