#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;
    unordered_map<ll, vector<ll>> g;
    for(int i = 0 ; i  <m;i++){
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> parent(n+1, -1);
    parent[1] = 1;
    queue<ll> q;
    q.push(1);
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        for(auto i:g[node]){
            if(parent[i] == -1){
                parent[i] = node;
                q.push(i);
            }
        }
    }

    if(parent[n] == -1){
        cout << "IMPOSSIBLE" << endl;
    }else{
        vector<ll> ans;
        ll node = n;
        while(node != 1){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(auto i:ans){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}