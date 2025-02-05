#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N;
// vector<ll> parent;
pair<vector<ll>,vector<ll>> solve(ll s ,unordered_map<ll, vector<pair<ll, ll>>> g){
    vector<ll> d(N + 1, LLONG_MAX);
    d[s] = 0;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
pq.push({0, s});
vector<ll> parent(N + 1, -1);

while(!pq.empty()){
        pair<ll, ll> p = pq.top();
        pq.pop();
        ll dist = p.first;
        ll node = p.second;

        if(d[node] < dist)continue;

        for(auto nbrinfo : g[node]){
            ll nbr = nbrinfo.first;
            ll nbrDist = nbrinfo.second;
            
            if(dist + nbrDist < d[nbr]){
                d[nbr] = dist + nbrDist;
                pq.push({dist + nbrDist, nbr});
                parent[nbr] = node;
            }
        }
    }

    return {d,parent};
}


int main(){
    ll n, m;
    cin >> n >> m;
    N = n;
    // vector<ll> parent(N + 1, -1);
    vector<vector<ll>> e(m, vector<ll>(3));
    for (int i = 0; i < m;i++){
        cin >> e[i][0] >> e[i][1] >> e[i][2];
    }
    unordered_map<ll, vector<pair<ll, ll>>> g;
    for (int i = 0; i < m;i++){
        g[e[i][0]].push_back({e[i][1], e[i][2]});
        // g[e[i][1]].push_back({e[i][0], e[i][2]});
    }

    auto [f,parent]  = solve(1,g);
    // vector<ll> parent = solve(1, g).second;

    priority_queue<ll, vector<ll>> pq;

ll temp = n;  // ✅ Use a temporary variable to traverse the path
while (parent[temp] != -1) {
    pq.push(f[temp] - f[parent[temp]]);
    temp = parent[temp];  // ✅ Traverse correctly without overwriting `n`
}
for(auto x:f){
    cout << x << endl;
}
ll ans = 0;
ans += pq.top() / 2;
pq.pop();

while(!pq.empty()){
    ans += pq.top();
    pq.pop();
}

cout << ans << "\n";

return 0;
}