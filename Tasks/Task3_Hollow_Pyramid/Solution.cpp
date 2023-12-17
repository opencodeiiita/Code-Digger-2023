#include <bits/stdc++.h>

using namespace std;

//Solved By - Prakhar Shukla

/*
    1
   1 2
  1   3
 1     4
1 2 3 4 5
*/

void rec(int i, int j, int n)
{
    if (i == n)
    {
        if (j == 2 * n)
        {
            cout << endl;
            return;
        }
        if (j % 2)
            cout << j / 2 + 1;
        else
            cout << " ";

        rec(i, j + 1, n);
    }
    else
    {
        if (j == n + i - 1)
        {
            cout << i << endl;
            rec(i + 1, 1, n);
        }
        else if (j == n - i + 1)
        {
            cout << 1;
            rec(i, j + 1, n);
        }
        else
        {
            cout << " ";
            rec(i, j + 1, n);
        }
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        rec(1, 1, n);
    }
    return 0;
}
