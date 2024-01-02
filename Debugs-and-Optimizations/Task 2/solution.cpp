#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define int long long
#define pb push_back
#define ppb pop_back
#define MOD 1000000007;

const int N=1e5;


void solve(){
    int n;
    cin >> n;
    std::vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    vector<int> small(n);
    for(int i=0;i<n;i++){
        cout << *lower_bound(b.begin(),b.end(),a[i]) - a[i] << " ";
    }
    cout << endl;

    for(int i=n-1;i>=0;i--){
        small[i] = (b[b.size()-1] - a[i]);
        if(i==(lower_bound(b.begin(), b.end(), a[i]) - b.begin())){
            b.erase(b.begin()+i, b.end());
        }
    }
    for(int i=0;i<n;i++) cout<< small[i] <<" ";
    cout << endl;     
}

signed main() {
    fastio();

    int t = 1;
    cin >> t;
    while(t--){
        solve();       
       }
    return 0;
}
