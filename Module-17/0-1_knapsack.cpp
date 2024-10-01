#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int weight[], int value[], int W)
{
    if (n < 0 || W == 0)
        return 0;

    if (weight[n] <= W)
    {
        // Two options: either we have to take it or consider it without taking it
        // দুটি বিকল্প: হয় নিয়ে দেখতে হবে বা না নিয়ে দেখতে হবে
        int opt1 = knapsack(n - 1, weight, value, W - weight[n]) + value[n];
        int opt2 = knapsack(n - 1, weight, value, W);

        return max(opt1, opt2);
    }
    else
    {
        // One option
        // We have to consider it without taking it
        // একটি বিকল্প
        // না নিয়ে দেখতে হবে
        int opt2 = knapsack(n - 1, weight, value, W);
        return opt2;
    }
}

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

    cout << knapsack(n - 1, weight, value, W);

    return 0;
}