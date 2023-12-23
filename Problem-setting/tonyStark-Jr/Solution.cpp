#include <bits/stdc++.h>

using namespace std;

#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = 0, nn7 = 0;
    bool f = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] >= 7)
        {
            f = 1;
        }
        if (f && v[i] != 7)
            nn7++;

        if (v[i] > v[i + 1])
        {
            if (f == 1)
            {
                ans += nn7;
                if (v[i + 1] < 7)
                {
                    ans++;
                    v[i + 1] = 7;
                }
                nn7 = 0;
            }
            else
            {
                f = 1;
                v[i + 1] = 7;
                ans++;
            }
        }
    }

    cout << ans << endl;
}
signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
