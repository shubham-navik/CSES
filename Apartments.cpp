#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> N(n);
    vector<ll> M(m);
    for (int i = 0; i < n; i++) {
        cin >> N[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> M[i];
    }

    ll cnt = 0;

    sort(N.begin(), N.end());
    sort(M.begin(), M.end());

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (abs(N[i] - M[j]) <= k) {
            cnt++;
            i++;
            j++;
        } else if (N[i] < M[j]) {
            i++;
        } else {
            j++;
        }
    }

    cout << cnt << "\n";

    return 0;
}