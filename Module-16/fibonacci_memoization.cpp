#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e6 + 5;

ll dp[N];

ll fibonacci(ll n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    ll ans = fibonacci(n - 1) + fibonacci(n - 2);
    dp[n] = ans;
    return ans;
}

int main()
{
    ll n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << fibonacci(n) << endl;

    return 0;
}