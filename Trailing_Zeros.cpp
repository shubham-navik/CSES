#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    ll f = 5;
    while(n/f>0){
        ans += (n / f);
        f = f * 5;
    }
    cout << ans << "\n";
    return 0;
}