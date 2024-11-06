#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define INF 1e9
#define MOD 1000000007
#define PI 3.14159265358979323846



void solve() {
    // Your solution code goes here
    // cout << "hello";
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }

    vector<int> x;

        int i = 0, j = 0;
    while(j<n){
        x.push_back(v[j]);
        if((j-i+1)==k){
            vector<int> p = x;
            sort(p.begin(), p.end());
        if(p.size()&1)
            cout << p[k / 2] << " ";
        else{
            cout << p[k / 2 - 1] << " ";
        }
        x.erase(x.begin());
        i++;
        }
        j++;
    }

    // for (int i = 0; i < n - k+1;i++){
    //     vector<int> p;
    //     for (int j = 0; j < k;j++){
    //         p.push_back(v[i + j]);
    //     }
    //     sort(p.begin(), p.end());
    //     if(p.size()&1)
    //         cout << p[k / 2] << " ";
    //     else{
    //         cout << p[k / 2 - 1] << " ";
    //     }
    // }


    // for(auto c:x){
    //     cout << c << " ";
    // }
}

int main() {
    fastio; // for faster input/output

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}