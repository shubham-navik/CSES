#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void trace(vector<ll>&parent, ll st,vector<ll>&rout){

    ll temp = st;
    while(parent[temp]!= st){
        rout.push_back(temp);
        temp = parent[temp];
    }
    rout.push_back(st);
}

bool dfs(ll src,unordered_map<ll, vector<ll>>& g,vector<bool>& vis,vector<ll>& parent){
        if(vis[src] && parent[src] != src){
            vector<ll> rout;
            trace(parent, src,rout);
            if(rout.size()>2){
                cout << rout.size() << "\n";
                for(auto r:rout){
                    cout << r << " ";
                }
                return;
            }else{
                cout << "IMPOSSIBLE\n";
                return;
            }
        }

        if(vis[src])
            return;
    vis[src] = 1;

    for(auto nbr : g[src]){
        // if(vis[nbr] && parent[nbr] != src){
        //     vector<ll> rout;
        //     trace(parent, nbr,rout);
        //     if(rout.size()>2){
        //         cout << rout.size() << "\n";
        //         for(auto r:rout){
        //             cout << r << " ";
        //         }
        //         return;
        //     }else{
        //         cout << "IMPOSSIBLE\n";
        //         return;
        //     }
        // }else{
            // vis[src] = 1;
            parent[nbr] = src;
            dfs(nbr, g, vis, parent);
        // }
    }

}

int main(){
    ll n,m;cin>>n>>m;
    unordered_map<ll, vector<ll>> g;
    for (int i = 0; i < m;i++){
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> vis(n + 1, 0);
    vector<ll> parent(n + 1, -1);

   bool check =  dfs(1, g, vis, parent);

    return 0;
}