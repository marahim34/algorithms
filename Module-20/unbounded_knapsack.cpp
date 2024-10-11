#include <bits/stdc++.h>
using namespace std;

int unbounded_knapsack(int n, int s, int val[], int weight[])
{
    if (n == 0 || s == 0)
    {
        return 0;
    }

    if (weight[n - 1] <= s)
    {
        int ch1 = val[n - 1] + unbounded_knapsack(n, s - weight[n - 1], val, weight);
        int ch2 = unbounded_knapsack(n - 1, s, val, weight);
        return max(ch1, ch2);
    }

    else
    {
        return unbounded_knapsack(n - 1, s, val, weight);
    }
}

int main()
{
    int n, s;
    cin >> n >> s;

    int val[n], weight[n];

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