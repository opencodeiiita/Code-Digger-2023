#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
vector<int> dp(10000 + 1, -1);

signed main()
{
    fastio();
    int t = 1;
    cin >> t;
    dp[0] = 1;

    for (int i = 1; i <= 10000; i++)
    {
        int start = 1;
        int end = sqrt(10000);
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
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] - 1 << '\n';
    }
    return 0;
}
