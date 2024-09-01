#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int mat[n][n] = {0};
    memset(mat, 0, sizeof(mat));

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << endl;

    if (mat[3][1] == 1)
    {
        cout << "They have connections" << endl;
    }
    else
    {
        cout << "The don't have any connections" << endl;
    }

    return 0;
}