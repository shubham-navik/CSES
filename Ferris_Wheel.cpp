#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, x;
    cin >> n >> x;

    vector<ll> w(n);
    for (ll i = 0; i < n; i++){
        cin >> w[i];
    }
    sort(w.begin(), w.end());

    ll ans = 0;
    ll i = 0, j = n - 1;
    while(i<=j){
        if (w[i] + w[j] <= x){
            i++;
            j--;
        }else{
            j--;
        }
        ans++;
    }
    cout << ans << "\n";
    return 0;
}