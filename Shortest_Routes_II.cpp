// #include<bits/stdc++.h>
// using namespace std;

// typedef long long int ll;
// ll N;

// vector<ll> 
//  solve(ll s,unordered_map < ll, vector < pair < ll, ll >>> g){
//     vector<ll> v(N + 1, LLONG_MAX);
//     v[s] = 0;
//     priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
//     pq.push({0, s});
//     // d[1] = 0;
//     while(!pq.empty()){
//         pair<ll, ll> p = pq.top();
//         pq.pop();
//         ll dist = p.first;
//         ll node = p.second;

//         if(v[node] < dist)continue;

//         for(auto nbrinfo : g[node]){
//             ll nbr = nbrinfo.first;
//             ll nbrDist = nbrinfo.second;
            
//             if(dist + nbrDist < v[nbr]){
//                 v[nbr] = dist + nbrDist;
//                 pq.push({dist + nbrDist, nbr});
//             }
//         }
//     }

//     return v;
// }


// int main(){
//     ll n, e,q;
//     cin >> n >> e>>q;
//     N = n;
//     unordered_map < ll, vector < pair < ll, ll >>> g;
//     for (int i = 0; i < e;i++){
//         ll u, v, w;
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }

//     vector<vector<ll>> d;
//     d.push_back({});

//     for (int i = 1; i <= n;i++){
//         d.push_back(solve(i, g));
//     }

//     for (int i = 0; i < q;i++){
//         ll s, p;
//         cin >> s >> p;
//         if(d[s][p] == LLONG_MAX)
//             cout << "-1\n";else
//             cout << d[s][p] << "\n";
//     }
//         return 0;
// }


#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll INF = LLONG_MAX / 2; // Prevent overflow in addition

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, e, q;
    cin >> n >> e >> q;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));

    // Initialize self-distances
    for (ll i = 1; i <= n; i++) 
        dist[i][i] = 0;

    // Read edges
    for (ll i = 0; i < e; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w); // Assuming an undirected graph
    }

    // **Floyd-Warshall Algorithm (O(N³))**
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) { // Avoid overflow
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Answer Queries in O(1)
    while (q--) {
        ll s, p;
        cin >> s >> p;
        cout << (dist[s][p] == INF ? -1 : dist[s][p]) << "\n";
    }

    return 0;
}
