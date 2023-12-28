#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int solve(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int start = 1;
        int end = sqrt(n);
        int result = INT_MAX;
        for (int j = start; j <= end; j++)
        {
            int numSquare = j * j;
            if (i - numSquare >= 0)
            {
                int ans = 1 + dp[i - numSquare];
                result = min(ans, result);
            }
        }
        dp[i] = result;
    }

    return dp[n];
}
signed main()
{
    fastio();
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = solve(n);
        cout << ans - 1 << endl;
    }
    return 0;
}
