#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;cin>>n;
    set<ll> st;
    while(n--){
        ll a;
        cin >> a;
        st.insert(a);
    }

    cout << st.size() << "\n";
    return 0;
}
