#include <bits/stdc++.h>
using namespace std;
int main ()
{
  int t;
  cin >> t;
  while (t--)
    {
      float N;
      cin >> N;
      int y = N;
      if (y % 2 == 0)
	{
	  cout << "NO" << endl;
	}
      if (y % 2 != 0)
	{
	  float z = N - y;
	  if (z == 0.5)
	    {
	      cout << "YES" << endl;
	    }
	  else
	    {
	      cout << "NO" << endl;
	    }
	}
    }



  return 0;
}
