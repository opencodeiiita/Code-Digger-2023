#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d;
    cin>>n;
    map<int,int> m;
    for(int i=0;i<n;i++){
        cin>>d;
        m[d]++;
    }
    int ans=m[4];
    if(m[3]>=m[1]){
        ans+=m[1];
        m[3]-=m[1];
        m[1]=0;
        ans+=m[3];
        ans+=ceil(m[2]/2.0);
    }
    else{
        ans+=m[3];
        m[1]-=m[3];
        ans+=m[2]/2;
        m[2]=m[2]&1;
        ans+=ceil((m[1]-2*m[2])/4.0)+m[2];
        m[2]=0;
    }
    cout<<ans;
}