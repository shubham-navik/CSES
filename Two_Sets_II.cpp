#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const ll INV_2 = 500000004;  // Modular inverse of 2 under MOD

ll t[501][125251];

ll solve(ll n, ll i, ll sum) {
    if (sum == 0) return 1;
    if (sum < 0 || i > n) return 0;
    if (t[i][sum] != -1) return t[i][sum];

    ll ans = (solve(n, i + 1, sum) + solve(n, i + 1, sum - i)) % MOD;
    return t[i][sum] = ans;
}

int main() {
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;

    if (sum % 2) {
        cout << 0 << "\n";
        return 0;
    }

    sum /= 2;
    memset(t, -1, sizeof(t));

    ll ans = solve(n, 1, sum);
    cout << (ans * INV_2) % MOD << "\n";  // Using modular division by 2
    return 0;
}
