#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k; ll a[n],b[n];
        for (ll i = 0; i < n; i++){
            cin>>a[i];   
        }
        for (ll i = 0; i < n; i++){
            cin>>b[i];   
        }
        bool f=0;
        for (ll i = 0; i < n; i++){
            if ((a[i]+b[i])>=k) {f=1; break;}
            if (i==0) {
                ll m=max(b[i],b[i+1]);
                if ((k-(m+1))<a[i]) {f=1; break;} 
            }  
            else if (i==n-1){
                ll m=max(b[i],b[i-1]);
                if ((k-(m+1))<a[i]) {f=1; break;}  
            }
            else {
                ll m=max(b[i],b[i-1]);
                m=max(m,b[i+1]);
                if ((k-(m+1))<a[i]) {f=1; break;} 
            }
        }
        if (f) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}