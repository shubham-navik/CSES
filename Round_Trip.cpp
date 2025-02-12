#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
unordered_map<ll, vector<ll>> g;
vector<ll> parent;
vector<bool> vis;
bool cf = false; // Global flag to stop DFS after finding one cyc

void solve(int src, int end) {
    vector<int> cyc;
    cyc.push_back(end);
    while (src != end) {
        cyc.push_back(src);
        src = parent[src];
    }
    cyc.push_back(end); // Complete the cyc
    reverse(cyc.begin(), cyc.end()); // To print in correct order
    
    cout <<cyc.size()<< "\n";
    for (int node : cyc) {
        cout << node << " ";
    }
    cout << endl;
}

void check(int src) {
    if (cf) return; // Stop DFS if cyc is already found

    vis[src] = true;

    for (ll nbr : g[src]) {
        if (cf) return; // Stop further execution if a cyc is found
        
        if (vis[nbr] && parent[src] != nbr) { // cyc detected
            solve(src, nbr);
            cf = true; // Set flag to stop further recursion
            return;
        }

        if (!vis[nbr]) {
            parent[nbr] = src;
            check(nbr);
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;

    g.clear();
    parent.assign(n + 1, -1);
    vis.assign(n + 1, false);
    cf = false;

    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (ll i = 1; i <= n; i++) { // Handle disconnected components
        if (!vis[i]) {
            check(i);
            if (cf) break; // Stop searching if a cyc is found
        }
    }

    if (!cf)
        cout << "IMPOSSIBLE\n";

    return 0;
}
