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
        int n,k;
        cin>>n>>k;
        int e[n],d[n];
        int b[n];
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
            cin>>e[i];
        }
        for(int i=0;i<n;i++){
            cin>>d[i];
        }

        for(int i=0;i<n;i++){
            if(b[i]==1){
                e[i]++;
            }else{
                d[i]++;
            }
        }
        for(int i=0;i<n;i++){
            if(e[i]>d[i]){
                k--;
            }
        }
        if(k>0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }

    }
    return 0;
}