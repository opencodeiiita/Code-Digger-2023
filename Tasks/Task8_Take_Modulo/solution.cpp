#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int N = 1e3 + 5;
int arr[N];
int compArr[N];
int n;
bool check[N];

bool checkPermutation(int s, int x) {
	for (int i = 0; i < x; i++) {
		check[i] = false;
	}

	for (int i = s; i < s + x; i++) {
		if (check[compArr[i] - 1]) {
			return false;
		}

		check[compArr[i] - 1] = true;
	}


	for (int i = 0; i < x; i++) {
		if (!check[i]) {
			return false;
		}
	}

	return true;
}

bool checkForX(int x) {
	for (int i = 0; i <= n - x; i++) {
		if (checkPermutation(i, x)) {
			return true;
		}
	}
	return false;
}

int solve() {
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < n; j++) {
			compArr[j] = arr[j] % (i + 1);
		}

		if (checkForX(i)) {
			return i;
		}

		// for (int i = 0; i < n; i++) {
		// 	cout << compArr[i] << " ";
		// }
		// cout << endl;

	}
	return 1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		// solve();
		cout << solve() << endl;


		// for (int i = 0; i < n; i++) {
		// 	cout << arr[i] << " ";
		// }
		// cout << endl;


	}
}