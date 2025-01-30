#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n;i++){
        cin >> v[i];
    }

    ll ans = v[0];
    ll sum = 0;
    for (int i = 0; i < n;i++){
        sum += v[i];
        sum = max(sum, v[i]);
        ans = max(ans, sum);
    }

    cout << ans << "\n";
        return 0;
}