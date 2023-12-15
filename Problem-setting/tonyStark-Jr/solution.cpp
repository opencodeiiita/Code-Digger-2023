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
    int pt = -1, ans = 0;
    int g7i = INT64_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] >= 7)
        {
            g7i = min(i, g7i);
        }
        if (v[i] > v[i + 1])
        {
            pt = i;
            break;
        }
    }
    if (pt == -1)
    {
        cout << 0 << endl;
        return;
    }
    if (v[pt] > 7)
    {
        for (int i = g7i; i < n; i++)
        {
            if (v[i] != 7)
                ans++;
        }
    }
    else
    {
        if (v[pt + 1] != 7)
        {
            v[pt + 1] = 7;
            ans++;
        }
        bool b = 0;
        for (int i = pt; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                b = 1;
                break;
            }
        }
        if (b)
        {
            for (int i = pt; i < n; i++)
            {
                if (v[i] != 7)
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
