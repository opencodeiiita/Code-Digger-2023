#include<bits/stdc++.h>
// status : 
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define in insert
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pii pair<int ,int>
#define vi vector<long long>


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
string destCity(vector<pair<string,string>>& paths) {
        unordered_map<string,int>indeg,outdeg;
        vector<string>node;
        set<string>s;
        for(int i=0;i<paths.size();i++){
            pair<string,string>v=paths[i];
            indeg[v.second]++;
            outdeg[v.first]++;
            node.push_back(v.second);
            node.push_back(v.first);


        }

        for(int i=0;i<node.size();i++){
            s.insert(node[i]);
        }
        for(auto i:s){
            if(!outdeg[i])
            return i;
        }
        
        return "not-found";
    }
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();

    int t = 1;
    cin >> t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<string,string>>v;
        for(int i=0;i<n;i++){
            string a,b;
            cin>>a>>b;
            v.push_back({a,b});

        }
        string girlfriend_house=destCity(v);
        cout<<girlfriend_house<<endl;
      
    }
    
}