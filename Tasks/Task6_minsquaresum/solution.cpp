#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    if(n<=3) {cout<<n<<endl; return;}

    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i=4; i<=n; ++i){
        dp[i] = i;
        for(int j=1; j<=sqrt(i); ++j){
            int sq = j*j;
            if(sq>i) break;
            dp[i] = min(dp[i], 1+dp[i-sq]);
        }
    }
    cout<<dp[n]<<endl;
}
signed main(){
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
}
