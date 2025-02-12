#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int n, unordered_map<ll, vector<pair<ll, ll>>> &g) {
    vector<ll> d(n + 1, LLONG_MIN);
    d[1] = 0;

    // Bellman-Ford Relaxation for longest path detection
    for (int i = 1; i < n; i++) {
        for (auto node : g) {
            int src = node.first;
            for (auto nbr : node.second) {
                if (d[src] != LLONG_MIN && d[src] + nbr.second > d[nbr.first])
                    d[nbr.first] = d[src] + nbr.second;
            }
        }
    }

    ll temp = d[n];

    // Check for a positive weight cycle in the n-th iteration
    for (auto node : g) {
        int src = node.first;
        for (auto nbr : node.second) {
            if (d[src] != LLONG_MIN && d[src] + nbr.second > d[nbr.first]) {
                return true; // Positive cycle detected
            }
        }
    }

    return false;
}

int main() {
    ll n, m;
    cin >> n >> m;
    unordered_map<ll, vector<pair<ll, ll>>> g;

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    // Check for positive weight cycle
    if (check(n, g)) {
        cout << "IMPOSSIBLE\n";
        return 1;
    }

    // Dijkstra-like approach for longest path
    vector<ll> D(n + 1, LLONG_MIN);
    priority_queue<pair<ll, ll>> pq; // Max-heap for longest path
    D[1] = 0;
    pq.push({0, 1}); // {distance, node}

    while (!pq.empty()) {
        auto [d, src] = pq.top();
        pq.pop(); // Remove the element from the queue

        for (auto nbr : g[src]) {
            auto [node, dist] = nbr;

            // Relaxation step: update if a longer path is found
            if (D[src] + dist > D[node]) {
                D[node] = D[src] + dist;
                pq.push({D[node], node});  // Push updated value
            }
        }
    }

    cout << (D[n] == LLONG_MIN ? -1 : D[n]) << "\n";

    return 0;
}
