
#include <bits/stdc++.h>
using namespace std;


//returning the minimum count 
    long long  getmincount(long long  n)
    {
	//for base case
	if(n<=3)
	return n;
	
//dp to store squares
	long long * dp= new long long [n + 1];

	// getMinSquares table 
	// for base case entries
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;

	//using the recursion 
	for(long long i = 4; i <= n; i++) 
	{dp[i] = i;
for (long long  x = 1; x <= ceil(sqrt(i)); x++) 
		{
			long long temp = x * x;
			if (temp > i)
				break;
			else
				dp[i] = min(dp[i], 1 + 
								dp[i - temp]);
		}
	}
long long  res = dp[n];
	delete[] dp;  //storing the result and removing the dp

	return res;
}
int main()
{
    long long  t;
    cin>>t;
    while(t--){
        long long  n;
        cin>>n;
    
	cout << getmincount(n);}
	return 0;
}
