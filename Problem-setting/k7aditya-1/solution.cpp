#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    int total_calorie_deficit = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total_calorie_deficit = total_calorie_deficit + (2500 - a[i]);
    }
    cout << total_calorie_deficit / 7000.0 << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}