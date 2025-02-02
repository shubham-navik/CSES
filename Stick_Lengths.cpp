#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n;i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    ll l = n / 2 - 1;
    ll r = n / 2;
    ll ans1 = 0, ans2 = 0;
    for(int i = 0 ; i<n;i++){
        ans1 += abs(v[l] - v[i]);
    }
    for(int i = 0 ; i<n;i++){
        ans2+= abs(v[r] - v[i]);       
    }

    cout<<min(ans1,ans2)<<endl;
    return 0;
}