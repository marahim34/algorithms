#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int mat[n][n];

    memset(mat, 0, sizeof(mat));

    cout << "Before" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    cout << "After" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Find Connection" << endl;
    if (mat[3][4] == 1)
    {
        cout << "They have connections" << endl;
    }
    else
    {
        cout << "They don't have connections" << endl;
    }

    return 0;
}