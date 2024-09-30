#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    // cout << n << " ";

    int newN = n - 1;

    return n * factorial(newN);
}

int main()
{
    int n;
    cin >> n;

    int resFact = factorial(n);

    cout << resFact << endl;

    return 0;
}