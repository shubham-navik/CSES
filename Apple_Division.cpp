#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll totalsum;
void solve(vector<ll>& a,int i, ll sum, ll &ans){
    if(i == a.size()){
        ll remain = totalsum - sum;
        ans = min(ans, abs(remain-sum));
        return;
    }
    solve(a, i + 1, sum + a[i], ans);
    solve(a, i + 1, sum, ans);
}

int main(){

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    totalsum = accumulate(a.begin(), a.end(), 0LL);
    ll ans = LLONG_MAX;
    solve(a, 0, 0, ans);
    cout << ans << "\n";
    return 0;
}