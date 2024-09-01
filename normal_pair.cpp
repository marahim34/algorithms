#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int first, second;
    void make_pair(int a, int b)
    {
        first = a;
        second = b;
    }
};

int main()
{
    Pair p;
    p.make_pair(10, 20);

    // p.first = 10;
    // p.second = 20;

    cout << p.first << " " << p.second << endl;

    return 0;
}