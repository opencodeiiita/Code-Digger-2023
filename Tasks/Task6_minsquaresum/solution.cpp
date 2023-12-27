#include<bits/stdc++.h>
using namespace std;
int solve(int n , vector<int>&dp){
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int temp=i*i;
            ans=min(ans,1+solve(n-temp,dp));
        }
        return dp[n]=ans;
    }
int minimum(int n) {
    vector<int>dp(n+1,-1);
    return solve( n,dp);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        cout<<minimum(n)<<endl;
    }
    return 0;
}
