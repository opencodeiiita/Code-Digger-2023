#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"Yes"
#define no cout<<"No"
const int M = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        map<char,int> m;
        int mx = -1;
        for(int i=0;i<n;i++){
            m[s[i]]++;
            mx = max(mx,m[s[i]]);
        }
        int rem = n-mx;
        if(mx<=n/2){
            if(n&1){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }else{
            cout<<mx-rem<<endl;
        }
    }
    return 0;
}