#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int N = 1e5 + 5;
int value[N];
int andValues[N];
vector<int> vec[N];


int otherChild(int child, int parent, int superParent) {
    for (int other : vec[parent]) {
        if (other == child || other == superParent) {
            continue;
        }

        return other;
    }

    return -1;
}


int Xdfs(int currAnd, int node, int parent) {
    int maxAnd = currAnd + andValues[node];

    switch (vec[node].size())
    {
    case 1:
        return maxAnd;
    case 2:
        return max(maxAnd, Xdfs(currAnd & value[node], otherChild(-1, node, parent), node));
    }

    for (int child: vec[node]) {
        if (child == parent) {
            continue;
        }
        // int _and = (currAnd & andValues[otherChild(child, node, parent)]) + andValues[child];
        int commingAnd = (currAnd & andValues[otherChild(child, node, parent)]);
        maxAnd = max(Xdfs(commingAnd, child, node), maxAnd);
    }

    return maxAnd;
}


void dfs(int curr, int parent) {
    andValues[curr] = value[curr];

    for (int child : vec[curr]) {
        if (child == parent) {
            continue;
        }

        dfs(child, curr);
        andValues[curr] &= andValues[child];
    }
}


void solve(int n) {
    switch (n)
    {
    case 1:
        cout << value[1] << endl;
        return;
    case 2:
        cout << value[1] + value[2] << endl;
        return;
    }

    dfs(1, -1);
    int maxAnd = -1;

    for (int child : vec[1]) {
        int _and = (value[1] & andValues[otherChild(child, 1, -1)]) + andValues[child];
        maxAnd = max(_and, maxAnd);
        int commingAnd = Xdfs(value[1] & andValues[otherChild(child, 1, -1)], child, 1);
        maxAnd = max(commingAnd, maxAnd);
    }

    cout << maxAnd << endl;
}


int main() {
    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i) {
            cin >> value[i];
            vec[i].clear();
        }

        for (int i = 1; i <= n - 1; ++i) {
            int u, v;
            cin >> u >> v;

            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        solve(n);
    }
}