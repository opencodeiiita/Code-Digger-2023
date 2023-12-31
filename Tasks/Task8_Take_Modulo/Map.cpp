#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define debug(x) cout << #x << ' ' << x << endl;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define exe(k,n) for(int i=k;i<n;i++)
#define exec(n) for(int i=0;i<n;i++)
#define endl '\n'
#define ss second
#define ff first
#define pb push_back
#define hii cout << "Hi\n";
#define int long long int
const int N=2*1e5;
bool check(int sz,vector<int> v)
{
    int n=v.size();
    exec(n){v[i]=v[i]%(sz+1);}
    map<int,int> m;
    exec(sz){if(v[i]) m[v[i]]++;}
    if(m.size()==sz)return true;
    for(int i=sz;i<n;i++)
    {
        if(v[i-sz])m[v[i-sz]]--;
        if(!m[v[i-sz]])
        {
            m.erase(v[i-sz]);
        }
        if(m.size()==sz){return true;}
    }
    return false;
}
signed main() 
{   fastio();       
    int T=1;
    cin >>T;
    while(T--)
    {   
        int n;
        cin >> n;
        vector<int> v(n);
        exec(n)
        {
            cin >> v[i];
        }
        int ans=0;
        for(int i=n;i>=1;i--)
        {
            if(check(i,v))
            {
                ans=i;
                break;
            }
        }
        cout << ans << endl;
    }   
 return 0;   
}