#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int m = int(1e9 + 7);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int pairs = 3;
        for(int i=2;i<=n;i++)
        pairs = (pairs*3)%m;
        int ordered_pairs = (pairs - (1%m) + m)%m;
        int unordered_pairs =  ((ordered_pairs%m) * (500000004%m))%m; 
        int ans = (unordered_pairs + 1)%m;
        cout<<ans<<endl;
    }
    return 0;
}
