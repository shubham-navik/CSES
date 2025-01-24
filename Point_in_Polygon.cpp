#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
// Function to calculate the area of the polygon formed by a point and polygon edges
ll calculateArea(vector<pair<ll, ll>>& polygon, pair<ll, ll> point) {
    ll area = 0;
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        pair<ll, ll> p1 = polygon[i];
        pair<ll, ll> p2 = polygon[(i + 1) % n];
        area += abs((point.first * p1.second - p1.first * point.second) +
                    (p1.first * p2.second - p2.first * p1.second) +
                    (p2.first * point.second - point.first * p2.second));
    }
    return area;
}
 
// Function to calculate the area of the polygon itself
// ll polygonArea(vector<pair<ll, ll>>& polygon) {
//     ll area = 0;
//     int n = polygon.size();
//     for (int i = 0; i < n; i++) {
//         pair<ll, ll> p1 = polygon[i];
//         pair<ll, ll> p2 = polygon[(i + 1) % n];
//         area += (p1.first * p2.second - p2.first * p1.second);
//     }
//     return abs(area);
// }
 
bool check(vector<pair<ll,ll>>polygon,pair<ll,ll>p){
 
    polygon.push_back(polygon[0]);
 
    for (int i = 0; i < polygon.size() - 1;i++){
        ll x3 = p.first;
        ll y3 = p.second;
        ll x1 = polygon[i].first;
        ll y1 = polygon[i].second;
        ll x2 = polygon[i+1].first;
        ll y2 = polygon[i+1].second;
        ll f = (y2 - y1) * x3 - (x2 - x1) * y3 + y1 * (x2 - x1) - x1 * (y2 - y1);
 
        if(f==0)
            return true;
    }
 
        polygon.pop_back();
        return false;
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
 
    // Calculate the original polygon area
    ll originalArea = calculateArea(polygon, polygon[0]);
 
    // Check each point
    for (int i = 0; i < m; i++) {
        ll extendedArea = calculateArea(polygon, points[i]);
 
        if (extendedArea == originalArea) {
            if(check(polygon,points[i])){
                cout << "BOUNDARY\n";
            }else
            cout << "INSIDE\n";
        } else {
            cout << "OUTSIDE\n";
        }
    }
 
    return 0;
}