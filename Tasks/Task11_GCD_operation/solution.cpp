#include <bits/stdc++.h>
using namespace std;

const int N = 500;
int n;
int a[N];

int check(int d)
{
    vector<int> v;
    for (int i = 0; i < n; ++i)
        if (a[i] % d) v.push_back(a[i] % d);
    sort(v.begin(), v.end());

    int l = 0, r = (int)v.size() - 1;
    int res = 0;
    while(l < r)
    {

        if (v[l] < d - v[r])
        {
            res += v[l];
            v[r] += v[l];
            ++l;
        }
        else if (v[l] > d - v[r])
        {
            res += d - v[r];
            v[l] -= d - v[r];
            --r;
        }
        else
        {
            res += v[l];
            ++l;
            --r;
        }
    }

    return res;
}

int main()
{
    int k;
    cin>>n>>k;

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    int ans = 1;
    for (int x = 1; x * x <= sum; ++x)
    {
        if (sum % x) continue;
        if (check(x) <= k) ans = max(ans, x);
        if (check(sum / x) <= k) ans = max(ans, sum / x);
    }

    cout<<ans;
}
