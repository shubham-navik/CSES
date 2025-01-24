#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    int k = n;
    while(k--){
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    v.push_back(v[0]);

    ll ans = 0;

    for (int i = 0; i < n;i++){
        pair<ll, ll> p1 = v[i];
        pair<ll, ll> p2 = v[i+1];
        ans += (p1.first * p2.second - p1.second * p2.first);
    }
    cout << abs(ans) << "\n";

    return 0;
}