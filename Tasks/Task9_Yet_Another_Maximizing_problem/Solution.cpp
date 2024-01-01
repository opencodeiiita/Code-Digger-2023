#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N = 1e5 + 5;

vector<int> adj[MAX_N];
int v[MAX_N];

ll bitwiseAND(int node, int parent = -1) {
    ll res = v[node];
    for (ll child : adj[node]) {
        if (child != parent) {
            res &= bitwiseAND(child, node);
        }
    }
    return res;
}
ll solve(ll n) {
    ll maxValue = 0;

    for (ll u = 0; u < n; u++) {
        for (ll v : adj[u]) {
            ll component1 = bitwiseAND(u);
            ll component2 = bitwiseAND(v, u);
            maxValue = max(maxValue, component1 + component2);
        }
    }

    return maxValue;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        ll n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            adj[i].clear();
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ll result = solve(n);
        cout << result << endl;
    }

    return 0;
}
