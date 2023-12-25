#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int findMinSquareSum(int n) {
	if (n == 0) {
		return 0;
	}

	int maxRoot = floor(sqrt(n));
	int min = n;

	for (int i = maxRoot; i > 1; i--) {
		int count = 1;
		count += findMinSquareSum(n - i * i);

		if (count < min) {
			min = count;
		}
	}

	return min;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int ans = findMinSquareSum(n);

		cout << ans << endl;
	}
}