#include <iostream>
#include <vector>
using namespace std;

bool perfect_score(int n, int m, vector<int> &v)
{

    if (m >= 1000)
        return true;

    int target = 1000 - m;

    vector<bool> dp(target + 1, false);

    dp[0] = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = target; j >= v[i]; --j)
        {
            dp[j] = dp[j] || dp[j - v[i]];
        }
    }

    return dp[target];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> v(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }

        if (perfect_score(n, m, v))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
