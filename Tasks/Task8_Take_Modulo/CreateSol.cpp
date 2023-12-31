#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
bool checkset(set<long long> &st1,long long n){
	bool flag=1;
	if(*st1.begin()!=1)flag=0;
	if(*--st1.end()!=n)flag=0;
	if(st1.size()!=n)flag=0;
	return flag;
}
void solve(){
	long long n;
	cin>>n;
	vector<long long> arr(n),orig(n);
	for(long long i=0;i<n;i++){
		cin>>arr[i];
		orig[i]=arr[i];
	}
	set<long long> st1;
	multiset<long long> st2;
	for(long long i=n+1;i>=2;i--){
		for(long long j=0;j<n;j++)
			arr[j]%=i;
		for(long long j=0;j<i-1;j++){
			st1.insert(arr[j]);
			st2.insert(arr[j]);
		}
		if(checkset(st1,i-1)){
			cout<<i-1<<'\n';
			return;
		}
		for(long long j=i-1;j<n;j++){
			long long rem=arr[j-i+1];
			if(st2.count(rem)>1){
				st2.erase(st2.find(rem));
			}
			else{
				st2.erase(st2.find(rem));
				st1.erase(st1.find(rem));
			}
			st1.insert(arr[j]);
			st2.insert(arr[j]);
			if(checkset(st1,i-1)){
				cout<<i-1<<'\n';
				return;
			}
		}
		arr=orig;
		st1.clear();
		st2.clear();
	}
	cout<<0<<'\n';

}	
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   	#ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin); 
       freopen("output.txt","w",stdout); 
       freopen("Error.txt","w",stderr);
       auto start_time = chrono::steady_clock::now();
 	#endif
       long long zz=1;
       cin>>zz;
       while(zz--){
       	solve();
       }

   	#ifndef ONLINE_JUDGE
    	auto end_time = chrono::steady_clock::now();
    	auto diff_time = end_time - start_time;
    	cout << "Execution time : " << fixed << setprecision(5) <<  chrono::duration <double, milli> (diff_time).count() << " ms" << endl;
	#endif

   return 0;
}
