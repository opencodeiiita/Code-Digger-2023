#include<bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(unordered_multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define int long long

void solve(){
    char grid[3][3], winner = '.';
    debug(winner);

    for(int i = 0; i < 3; i++){
        bool row = 1;
        for(int j = 0; j < 3; j++){
            cin >> grid[i][j];
            if(grid[i][j] != grid[i][0])
                row = 0;
        }
        if((row)&&(grid[i][0] != '.'))
            winner = grid[i][0];
    }
    debug("1");

    for(int j = 0; j < 3; j++){
        bool col = 1;
        for(int i = 0; i < 3; i++){
            if(grid[i][j] != grid[0][j])
                col = 0;
        }
        if((col)&&(grid[0][j] != '.'))
            winner = grid[0][j];
    }

    bool diagonal = 1;
    for(int i = 0; i < 3; i++){
        if(grid[i][i] != grid[0][0])
            diagonal = 0;
    }
    if((diagonal)&&(grid[0][0] != '.'))
        winner = grid[0][0];

    debug("1");

    diagonal = 1;
    for(int i = 0; i < 3; i++){
        if(grid[i][2 - i] != grid[0][2])
            diagonal = 0;
    }
    if((diagonal)&&(grid[0][2] != '.'))
        winner = grid[0][2];

    debug("1");

    if(winner == '.')
        cout << "DRAW\n";
    else
        cout << winner << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    
    int t = 1;
    cin >> t;
    while(t--){
        solve();       
    }
    return 0;
}
