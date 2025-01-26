#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to check if a point lies on the boundary of a polygon
bool check(const vector<pair<ll, ll>>& polygon, pair<ll, ll> p) {
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        ll x1 = polygon[i].first, y1 = polygon[i].second;
        ll x2 = polygon[(i + 1) % n].first, y2 = polygon[(i + 1) % n].second;
        ll x3 = p.first, y3 = p.second;

        ll crossProduct = (y2 - y1) * (x3 - x1) - (x2 - x1) * (y3 - y1);
        ll dotProduct = (x3 - x1) * (x2 - x1) + (y3 - y1) * (y2 - y1);
        ll squaredLength = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

        if (crossProduct == 0 && dotProduct >= 0 && dotProduct <= squaredLength) {
            return true; // Point lies on the boundary
        }
    }
    return false;
}

// Function to check if a point is inside the polygon using the ray-casting algorithm
string fun(const vector<pair<ll, ll>>& polygon, pair<ll, ll> p) {
    int n = polygon.size();
    ll x = p.first, y = p.second;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        ll x1 = polygon[i].first, y1 = polygon[i].second;
        ll x2 = polygon[(i + 1) % n].first, y2 = polygon[(i + 1) % n].second;

        // Check if the ray crosses the edge
        if (y1 > y2) {
            swap(x1, x2);
            swap(y1, y2);
        }

        if (y > y1 && y <= y2 && (x2 - x1) * (y - y1) > (x - x1) * (y2 - y1)) {
            cnt++;
        }
    }

    return (cnt % 2 == 1) ? "INSIDE\n" : "OUTSIDE\n";
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> polygon(n);
    vector<pair<ll, ll>> points(m);

    // Input polygon vertices
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        polygon[i] = {x, y};
    }

    // Input points to check
    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    // Check each point
    for (int i = 0; i < m; i++) {
        if (check(polygon, points[i])) {
            cout << "BOUNDARY\n";
        } else {
            cout << fun(polygon, points[i]);
        }
    }

    return 0;
}
