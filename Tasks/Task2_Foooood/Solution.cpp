#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> vec;
        for (int i = 0; i < n; i++) {
        	int temp;
        	cin >> temp;
        	vec.push_back(temp);
        }

        sort(vec.begin(), vec.end());

        int out = 0;

        int i;
        for (i = n - 1; i >= 0 && i > n - k - 1; i--) {
        	out += vec[i];
        }

        // Assuming that after eating all the dishes once
        // Ravi can eat any dish he wants
        if (k > n) {
        	out += (k - n) * vec[n - 1];
        }

        cout << out << "\n";
    }
    return 0;
}
