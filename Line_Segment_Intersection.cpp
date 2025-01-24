#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to check orientation and determine if points are on opposite sides of a line
int fun(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    ll f1 = (y2 - y1) * (x3 - x1) - (x2 - x1) * (y3 - y1);
    ll f2 = (y2 - y1) * (x4 - x1) - (x2 - x1) * (y4 - y1);
    if ((f1 > 0 && f2 > 0) || (f1 < 0 && f2 < 0))
        return 0;
    return 1; // Intersects or collinear
}

bool onSegment(ll x1, ll y1, ll x2, ll y2, ll x, ll y) {
    return min(x1, x2) <= x && x <= max(x1, x2) && min(y1, y2) <= y && y <= max(y1, y2);
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        if (fun(x1, y1, x2, y2, x3, y3, x4, y4) && fun(x3, y3, x4, y4, x1, y1, x2, y2)) {
            // Check if the two line segments are collinear and overlap
            if ((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1)) {
                ll l = max(min(x1, x2), min(x3, x4)); // Overlap range for x
                ll r = min(max(x1, x2), max(x3, x4)); // Overlap range for x
                ll p = max(min(y1, y2), min(y3, y4)); // Overlap range for y
                ll q = min(max(y1, y2), max(y3, y4)); // Overlap range for y
                if (l > r || p > q) { // No overlap
                    cout << "NO\n";
                } else { // Overlapping segments
                    cout << "YES\n";
                }
            } else {
                // Intersects
                cout << "YES\n";
            }
        } else {
            cout << "NO\n"; // Do not intersect
        }
    }
    return 0;
}
