#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){

    ll n;
    cin >> n;
    if(n==1){
        cout << 1 << "\n";
        return 0;
    }
    if(n<4){
        cout << "NO SOLUTION\n";
        return 0;
    }

    vector<ll> v(n);
    ll k = n;
    for (int i = 1; i < n;i+=2){
        v[i] = k;
        k--;
    }
    for (int i = 0; i < n;i+=2){
        v[i] = k;
        k--;
    }

    for(auto num:v)
        cout << num << " ";
    cout << "\n";
    return 0;
}