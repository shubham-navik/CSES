#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool dfs(ll src,ll clr, vector<vector<ll>>& g,vector<ll>& color){

    if(color[src] != -1 && clr == (1- color[src]))
        return false;
    if(color[src]!=-1){
        return true;
    }    

    color[src] = clr;

    for(auto nbr :g[src]){
        if(!dfs(nbr,1-clr,g,color)){
            return false;
        }
    }

    return true;
}


int main(){
    ll n, m;
    cin >> n >> m;
    vector< vector<ll>> g(n+1);
    for (int i = 0; i < m;i++){
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<ll> color(n + 1, -1);
    for (int i = 1; i <= n;i++){
        if(color[i]==-1){
        bool check = dfs(i, 0, g, color);
        if(!check){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
        }

    }

    // cout << "YES\n";
    for (int i = 1; i <= n;i++){
        cout << color[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}