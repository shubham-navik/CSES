#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll t[1000001];

ll solve( ll n){
    if(n==0)
        return 1;
        if(n<0)
            return 0;

    if(t[n]!=-1)
        return t[n];
        ll ans = 0;

        for (int i = 1; i <= 6;i++){
            ans += solve(n - i);
            ans%=1000000007;
        }

        return t[n] =  ans;
}


int main(){
    ll n;
    cin >> n;
    memset(t, -1, sizeof(t));
    ll ans = solve(n);
    cout<<ans<<"\n";
    return 0;
}