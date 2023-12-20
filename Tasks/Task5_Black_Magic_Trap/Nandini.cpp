#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

const int MAX = 20;

struct Move {
    int cell;
    vector<int> diceSides;
    vector<int> path;
};

bool isValid(int cell, int n, int m) {
    return cell >= 1 && cell <= n * m;
}

void printPath(const vector<int>& path) {
    for (int move : path) {
        cout << move << " ";
    }
    cout << endl;
}

vector<int> getAdjacentCells(int cell, int n, int m) {
    vector<int> adjCells;
    for (int i = 1; i <= 6; ++i) {
        int nextCell = cell + i;
        if (isValid(nextCell, n, m)) {
            adjCells.push_back(nextCell);
        }
    }
    return adjCells;
}

vector<int> findMinMoves(int n, int m, const vector<vector<int>>& board, int k, const vector<int>& blockedSides) {
    int dest = n * m;

    vector<vector<int>> blocked(MAX, vector<int>(MAX, 0));
    for (int side : blockedSides) {
        blocked[1][side] = 1;
    }

    queue<Move> q;
    Move start = {1, {1, 2, 3, 4, 5, 6}, {1}};
    q.push(start);

    unordered_set<int> visited;
    visited.insert(1);

    while (!q.empty()) {
        Move current = q.front();
        q.pop();

        if (current.cell == dest) {
            return current.path;
        }

        for (int i = 1; i <= 6; ++i) {
            if (find(current.diceSides.begin(), current.diceSides.end(), i) != current.diceSides.end() && !blocked[current.cell][i]) {
                int nextCell = current.cell + i;
                if (!visited.count(nextCell)) {
                    visited.insert(nextCell);
                    Move nextMove = {nextCell, {1, 2, 3, 4, 5, 6}, current.path};
                    nextMove.path.push_back(i);
                    q.push(nextMove);
                }
            }
        }
    }

    return {}; // Return empty vector if no path found
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(MAX, vector<int>(MAX, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
        }
    }

    int k;
    cin >> k;

    vector<int> blockedSides(k);
    for (int i = 0; i < k; ++i) {
        cin >> blockedSides[i];
    }

    vector<int> result = findMinMoves(n, m, board, k, blockedSides);

    if (result.empty()) {
        cout << -1 << endl;
    } else {
        printPath(result);
    }

    return 0;
}
