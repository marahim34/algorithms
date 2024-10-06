#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int s = 0;

    int arr[n];

    // Reading array and calculating total sum
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s += arr[i];
    }

    // Check if total sum is even
    if (s % 2 == 0)
    {
        int sum = s / 2;
        bool dp[n + 1][sum + 1];

        // Initialize dp array
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
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Output the result
        if (dp[n][sum])
        {
            cout << "Yes, Possible" << endl;
        }
        else
        {
            cout << "Not Possible" << endl;
        }
    }
    else
    {
        cout << "Not Possible" << endl;
    }

    return 0;
}
