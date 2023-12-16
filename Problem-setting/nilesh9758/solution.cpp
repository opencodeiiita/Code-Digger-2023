#include <bits/stdc++.h>
using namespace std;

string alternate(string x, string y) {
    string result;
     int len_x = x.length();
     int len_y = y.length();
     int i = 0, j = 0;

    while (i < len_x && j < len_y) {
      if(len_x>len_y){
        result.push_back(x[i]);
        result.push_back(y[j]);
        i++;
        j++;
      }
      else{
        result.push_back(y[j]);
        result.push_back(x[i]);
        j++;
        i++;
      }
    }
    while (i < len_x) {
        result.push_back(x[i]);
        i++;
    }

    while (j < len_y) {
        result.push_back(y[j]);
        j++;
    }

    return result;
}

int main() {
    int t;
    cin>>t;
    while(t--){
      string x,y;
      cin>>x>>y;
    string result = alternate(x, y);
    cout << result << endl;
    }
     return 0;
}
