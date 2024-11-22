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

    ll a, b;
    cin >> a >> b;
 ll result = 1;
    a = a % MOD;   

    while (b > 0) {
        if (b & 1) {          
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;     
        b = b >> 1;            
    }
    cout << result << "\n";
}

int main() {
    fastio; // for faster input/output

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}