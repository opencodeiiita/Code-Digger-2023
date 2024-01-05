// by Kushal Bansal

#include <bits/stdc++.h>
using namespace std;

int reverse(int n){
    int reversed_number = 0, remainder;

  while(n != 0) {
    remainder = n % 10;
    reversed_number = reversed_number * 10 + remainder;
    n /= 10;
  }

  return reversed_number;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    int sum = reverse(a)+reverse(b);
	    cout<<reverse(sum)<<endl;
	}

}
