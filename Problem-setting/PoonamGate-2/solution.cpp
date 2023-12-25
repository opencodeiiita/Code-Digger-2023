#include <iostream>
#include<cmath>
using namespace std;

const int mod = 1e9 + 7;

int power(int a, int p) {
    if(p == 0) return 1;
    if(p % 2 == 1) {
        return (a * 1ll * power(a, p - 1)) % mod;
    }
    int half = power(a, p / 2);
    return (half * 1ll * half) % mod;
}

int main()
{
    int n,q,k;
    cin>>n>>q>>k;
    int a[n];
    for(int i=1;i<=n;++i){
        a[i]=0;
    }
     
    while(q--){
        int A,l,r;
        cin>>A>>l>>r;
        a[l] += A % mod;
        int num = (A * 1ll * power(k, r - l + 1)) % mod;
        int negative_modulo = (mod - num) % mod;
        a[r+1] += negative_modulo;        
    }
    for(int i=2;i<=n;++i){
        a[i] = (a[i] + (a[i-1] * 1ll * k) % mod) % mod ;
        
    }
    
    for(int i=1;i<=n;++i){
        cout<<a[i]<<" ";
    }
    

    return 0;
}

        
        
