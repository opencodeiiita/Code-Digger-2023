#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
	int s, x;
	cin >> s >> x;

	int len = 0;
	vector<int> digits;

	while (s) {
		int digit = s % 10;
		digits.push_back(digit);
		s /= 10;
		len++;
	}

	sort(digits.begin(), digits.end());

	int count = 0;

	int num;
    for (int mask = 1; mask < (1 << len); ++mask) {
    	num = 0;
        for (int i = 0; i < len; ++i) {
            if (mask & (1 << i)) {
            	num = num * 10 + digits[i];
                // cout << digits[i] << ' ';
            }
        }

        // cout << num << endl;

        count += (num % x) ? 0 : 1;
    }

	cout << count << endl;
}