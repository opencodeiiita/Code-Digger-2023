#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long ll;

#define debug(x) cout << #x << ": " << x << "\n";

const int N = 25;
int a[N*N];
bool visited[N*N] = {0};

int allowedMoves[7];

struct cell {
	int pos, distance, move;
	cell* prev;
};


int getDiceRolls(int finalDestination) {
	queue<cell> q;

	visited[0] = true;
	cell startCell = {0, 0, 0, NULL};

	q.push(startCell);

	cell* c;
	while (!q.empty()) {
		c = &(q.front());

		int pos = c -> pos;

		if (pos == finalDestination) {
			break;
		}

		q.pop();

		for (int move = 1; move <= 6; move++) {
			if (!allowedMoves[move]) {
				continue;
			}

			int nextPos = pos + move;

			if (nextPos > finalDestination)
				continue;

			if (!visited[nextPos]) {
				cell* newCell = new cell();
				newCell -> move = move;
				newCell -> prev = c;
				newCell -> distance = c -> distance + 1;
				visited[nextPos] = true;

				if (a[nextPos] != -1) {
					newCell -> pos = a[nextPos] - 1;
				} else {
					newCell -> pos = nextPos;
				}

				q.push(*newCell);
			}
			

		}


	}


	if (c -> pos != finalDestination) {
		return 1;
	}

	stack<int> _stack;
	while (c -> move != 0) {
		_stack.push(c -> move);
		c = c -> prev;
	}

	while (!_stack.empty()) {
		cout << _stack.top() << " ";
		_stack.pop();
	}

	cout << endl;

	return 0;
}

int m, n; // m is vertical (y) | n is horizontal (x)
int finalDestination;

int main() {

	for (int i = 1; i <= 6; i++) {
		allowedMoves[i] = 1;
	}

	cin >> n >> m;
	finalDestination = m * n - 1;

	for (int j = m - 1; j >= 0; j--) {
		if (j % 2) {
			for (int i = n - 1; i >= 0; i--) {
				cin >> a[j * n + i];
			}
		} else {
			for (int i = 0; i < n; i++) {
				cin >> a[j * n + i];
			}
		}
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int temp;
		cin >> temp;
		allowedMoves[temp] = 0;
	}

	// for (int i = 1; i <= 6; i++) {
	// 	if (allowedMoves[i]) {
	// 		cout << i << " ";
	// 	}
	// }
	// cout << endl;


	// for (int j = 0; j < m; j++) {
	// 	for (int i = 0; i < n; i++) {
	// 		cout << a[j * n + i] << " ";
	// 	}
	// 	cout << endl;
	// }

	if (getDiceRolls(finalDestination)) {
		cout << -1 << endl;
	}

	return 0;
}


