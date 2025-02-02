#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void startBFS(ll i, ll j, ll n, ll m, vector<string> &grid) {
    queue<pair<ll, ll>> q;
    q.push({i, j});

    vector<vector<char>> parent(n, vector<char>(m, ' '));  // Store path directions
    vector<vector<pair<ll, ll>>> previous(n, vector<pair<ll, ll>>(m, {-1, -1})); // Store parent cells
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    visited[i][j] = true;
    
    vector<pair<ll, ll>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<char> dirSymbol = {'R', 'L', 'D', 'U'}; // Right, Left, Down, Up

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int d = 0; d < 4; d++) {
            ll nx = x + directions[d].first;
            ll ny = y + directions[d].second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                if (grid[nx][ny] == 'B') {
                    cout << "YES" << endl;

                    // Store the last move
                    parent[nx][ny] = dirSymbol[d];
                    previous[nx][ny] = {x, y};

                    // Reconstruct path
                    string ans = "";
                    ll cx = nx, cy = ny;
                    while (cx != i || cy != j) {
                        ans += parent[cx][cy];
                        tie(cx, cy) = previous[cx][cy];
                    }
                    reverse(ans.begin(), ans.end());

                    cout << ans.size() << endl;
                    cout << ans << endl;
                    return;
                }

                if (grid[nx][ny] == '.') {
                    visited[nx][ny] = true;
                    parent[nx][ny] = dirSymbol[d]; // Store movement direction
                    previous[nx][ny] = {x, y};  // Store parent cell
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << "NO" << endl; // If 'B' is not found
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<string> grid(n);
    
    ll start_x = -1, start_y = -1;
    for (ll i = 0; i < n; i++) {
        cin >> grid[i];
        for (ll j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                start_x = i;
                start_y = j;
            }
        }
    }

    if (start_x != -1 && start_y != -1) {
        startBFS(start_x, start_y, n, m, grid);
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
