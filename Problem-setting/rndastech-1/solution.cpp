#include<bits/stdc++.h>
using namespace std;

int sumd(int x){
    int s=0;
    while(x!=0){
        s+= x%10;
        x/=10;
    }
    return s;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int u;
        cin>>u;
        int arr[u+1]={0};
        for(int i = 1001; i<= (1001 + (7*u)); i+=7)
           arr[(i-1001)/7] = i;
        
       int digit_sum[u+1]={0};
       for(int i=0;i<=u;i++)
       digit_sum[i] = sumd(arr[i]);

       int N;
       cin>>N;
       int n[N];
       for(int i=0;i<N;i++)
       cin>>n[i];
       
       for(int i=0;i<N;i++){
           int ans=0;
           for(int j=1;j<=u;j++){
               if(digit_sum[j]%n[i]==0)
               ans++;}
           cout<<ans<<" ";}
           
       cout<<""<<endl;
    }
    return 0;
}
