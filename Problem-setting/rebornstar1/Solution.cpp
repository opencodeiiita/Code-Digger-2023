// Template for CP 

#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...) /*All the isuues which were raised during all the time were quite impressive. what should I tell you now*/
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9; 

set<ll>primes;

void SieveOfEratosthenes(ll n) 
{ 
    bool prime[n + 1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (ll p = 2; p * p <= n; p++) {  
        if (prime[p] == true) { 
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false; 
        } 
    }  
    for (int p = 2; p <= n; p++) 
        if (prime[p]) 
            primes.insert(p); 
} 

bool isPrime(ll n)
{
    // Check from 2 to n-1
    for (ll i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}

long long gcd(long long int a, long long int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
// Function to return LCM of two numbers  
long long lcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b; 
} 

ll func(ll m,string s){
    ll temp=1,ans=0;
   for(int i=(s.size()-1);i>=0;i--){
     ans+=((s[i]-'0')*temp);
     temp*=m;
   }
   return ans;
}

ll lnary(ll a,string p){
     ll s=0,e=100,m=-1;
     while(s<=e){
      m=((s+e)/2);
      if(func(m,p)>a){
       e=(m-1);
      } else if(func(m,p)<a){
       s=(m+1);
      } else{
        return m;
        break;
      }
    }
    return s;
}

ll rnary(ll b,string p){
    ll s=0,e=100,m=-1;
    while(s<=e){
        m=((s+e)/2);
        if(func(m,p)<b){
            s=(m+1);
        } else if(func(m,p)>b){
            e=(m-1);
        } else{
            return m;
            break;
        }
    }
    return e;
}

void solve(){
   ll t;
   cin>>t;
   while(t--){
    string p; // length of s is <=10;
    cin>>p;
    ll a,b;
    cin>>a>>b;
    // To find out the lower Range of L-nary Number
    cout<<lnary(a,p)<<" "<<rnary(b,p)<<endl;
   }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    vector<int>edit;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
