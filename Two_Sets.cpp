#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll r = (n * (n + 1)) / 2;
    if (r & 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";

        ll h = r / 2;
        vector<ll> v1, v2;

        for (ll i = n; i >= 1; i--) {
            if (h >= i) {
                v1.push_back(i);
                h -= i;
            } else {
                v2.push_back(i);
            }
        }

        cout << v1.size() << "\n";
        for (auto x : v1) {
            cout << x << " ";
        }
        cout << "\n";

        cout << v2.size() << "\n";
        for (auto x : v2) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
