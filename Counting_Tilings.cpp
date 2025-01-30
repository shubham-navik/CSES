#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// ll ans;

ll solve(ll a,ll b){
    if(a==0 && b==0){
        return 1;
    }

    if(a<0 || b<0){
        return 0;
    }

    ll first = solve(a-1,b-2);
    ll second = solve(a-2,b-1);

    return first+second;

}
int main(){
    ll a, b;
    cin >> a >> b;
    // ans = 0;
    cout << solve(a, b)<<"\n";

    return 0;
}