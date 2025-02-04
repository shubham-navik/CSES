#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    ll n, e;
    cin >> n >> e;
    unordered_map < ll, vector < pair < ll, ll >>> g;
    for (int i = 0; i < e;i++){
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        // g[v].push_back({u, w});
    }

    vector<ll> d(n + 1, LLONG_MAX);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0, 1});
    d[1] = 0;
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
            }
        }
    }

    for (int i = 1; i <= n;i++){
        cout << d[i] << " ";
    }
        cout << "\n";
    return 0;
}