#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t; cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int ans=0;
        while(n>0){
            ans++;
            n/=2;
        }
        cout<<ans<<endl;
    }}