#include <iostream>
#include<cstring>
using namespace std;
int n;
int t;
int x[101];
int dp[105][10100];

int rec(int level,int left){
    if(left<0) return 0;
    if(level==n+1){
        if(left==0){
            return 1;
        }else{
            return 0;
        }
    }
    
    if(dp[level][left]!=-1){
        return dp[level][left];
    }
    
    int ans=0;
    if(rec(level+1,left)==1){
        ans=1;
    }else if(rec(level+1,left-x[level])){
        ans=1;
    }
     
     return dp[level][left]=ans;
    
}
    void printset(int level,int left){
        if(level==n+1){
            return;
        }
        if(rec(level+1,left)==1){
            printset(level+1,left);
        }else if(rec(level+1,left-x[level])){
            cout<<x[level]<<" ";
            printset(level+1,left-x[level]);
        }
    }
   
   void solve(){
       
       cin>>n;
       for(int i=1;i<=n;++i){
           cin>>x[i];
       }
       memset(dp,-1,sizeof(dp));
       
       int q;
       cin>>q;
       while(q--){
           cin>>t;
           if(rec(1,t)){
               printset(1,t);
               cout<<endl;
           }else{
               cout<<"no solution"<<endl;
           }
       }
       
   }
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;++i){
        solve();
    }
    
    return 0;
}
