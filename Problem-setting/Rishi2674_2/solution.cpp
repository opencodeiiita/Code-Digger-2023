#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> v;
        for(int i=0;i<8;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }

        int max_profit = 0;
        int min_stock = v[0];
        for(int i=1 ; i<8 ; i++){
            min_stock = min(min_stock,v[i]);
            int curr_profit = v[i]-min_stock;
            max_profit = max(max_profit,curr_profit);
        }
        cout<<max_profit<<endl;

    }
}