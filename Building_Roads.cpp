#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
void dfs(ll node,unordered_map<ll,vector<ll>> &adj,vector<bool> &visited){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,adj,visited);
        }
    }
}
int main(){

    ll l,m;
    cin >> l >> m;
    vector<pair<ll, ll>> edge(m);
    for(int i =0;i<m;i++){
        cin >> edge[i].first >> edge[i].second;
    }
    vector<bool> visited(l+1, false);
    vector<ll> nodes;
    unordered_map<ll,vector<ll>> adj;
    for(auto p:edge){
        adj[p.first].push_back(p.second);
        adj[p.second].push_back(p.first);
    }

    for(int i = 1;i<=l;i++){
        if(!visited[i]){
            nodes.push_back(i);
            dfs(i,adj,visited);
        }
    }

    cout<<nodes.size()-1<<endl;
    for(int i = 0;i<nodes.size()-1;i++){
        cout<<nodes[i]<<" "<<nodes[i+1]<<endl;
    }
    return 0;
}