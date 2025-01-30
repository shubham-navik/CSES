#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n;i++){
        cin>>a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end(),[](pair<ll, ll> a, pair<ll, ll> b){
        return a.first < b.first;
    });
    ll i = 0;ll j = n - 1;
while(i<j){
    if(a[i].first + a[j].first == x){
        if(a[i].second > a[j].second) swap(a[i].second, a[j].second);
        cout<<a[i].second<<" "<<a[j].second;
        return 0;
}
if(a[i].first + a[j].first < x){
    i++;

}
else{   
    j--;
}
}

cout<<"IMPOSSIBLE\n";
    return 0;


}