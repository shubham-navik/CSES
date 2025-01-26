#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll ans=1;
    for (int i = 1; i <= n;i++){
        ans *= 2;
        ans = ans % MOD;
    }
    cout << ans << "\n";
    return 0;
}