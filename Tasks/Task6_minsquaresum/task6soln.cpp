#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int dp[10010];
int rec(int level){
      if(level==0) return 0;
     if(level==2) return 2;
      if(level==3) return 3;
      if(dp[level]!=-1) return dp[level];
      int ms=INT_MAX;
      int r=sqrt(level);
     
   for(int i=1;i<=r;++i){
      if(level-i*i>=0){
          ms=min(ms,1+rec(level-i*i));
      }
   }
      return dp[level]= ms;
}
void solve(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(n)<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
