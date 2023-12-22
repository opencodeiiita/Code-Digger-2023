
#include <iostream>
#include<cmath>
using namespace std;

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
        a[l]+=A;
        a[r+1]+=(-A*pow(k,r-l+1));
      
        
    }
    for(int i=2;i<=n;++i){
        a[i]=(a[i]+(a[i-1]*k));
        
    }
    
    for(int i=1;i<=n;++i){
        cout<<a[i]<<" ";
    }
    

    return 0;
}

(modulus lgana rh gya ...i think ...time nhi h)
