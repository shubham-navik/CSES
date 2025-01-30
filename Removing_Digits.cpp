#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    while(n){
        ll m = n;
        ll mx = 0;
        while(m>0){
            mx = max(mx, m % 10);
            m /= 10;
        }
        n -= mx;
        ans++;
    }

    cout << ans << "\n";
    return 0;
}