#include <bits/stdc++.h>
using namespace std;

void solve(int W)
{
    float protein_need = 1.2 * W;
    int e, c, p;
    cin >> e >> c >> p;
    float protein_consumed = 30 + e * 6 + 30 * c / 100.0 + 20 * p / 100.0;
    if (protein_consumed < protein_need)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        cout << "YES" << endl;
        return;
    }
}

int main()
{
    int t;
    cin >> t;
    int W;
    cin>>W;
    while (t--)
    {
        solve(W);
    }
}