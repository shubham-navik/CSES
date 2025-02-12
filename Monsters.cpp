
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll, ll>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<char> moves = {'R', 'L', 'D', 'U'};

void bfs(queue<pair<ll, ll>> &q, ll n, ll m, vector<string> &v, vector<vector<ll>> &D)
{
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            ll nx = x + dir[i].first;
            ll ny = y + dir[i].second;

            if (nx < n && nx >= 0 && ny < m && ny >= 0 && v[nx][ny] == '.')
            {
                if (D[x][y] + 1 < D[nx][ny])
                {
                    D[nx][ny] = D[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

bool backtrack(pair<ll, ll> src, vector<string> &v, vector<vector<ll>> &D)
{
    ll n = D.size(), m = D[0].size();
    vector<vector<pair<ll, ll>>> parent(n, vector<pair<ll, ll>>(m, {-1, -1}));
    vector<vector<char>> direction(n, vector<char>(m, ' '));
    queue<pair<ll, ll>> q;
    q.push(src);

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            ll nx = x + dir[i].first;
            ll ny = y + dir[i].second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] == '.' && D[x][y] + 1 < D[nx][ny])
            {
                D[nx][ny] = D[x][y] + 1;
                parent[nx][ny] = {x, y};
                direction[nx][ny] = moves[i];
                q.push({nx, ny});

                // If we reach the boundary, reconstruct path
                if (nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1)
                {
                    string path = "";
                    while (nx != src.first || ny != src.second)
                    {
                        path += direction[nx][ny];
                        tie(nx, ny) = parent[nx][ny];
                    }
                    reverse(path.begin(), path.end());
                    cout << "YES\n";
                    cout << path.length() << "\n";
                    cout << path << "\n";
                    return true;
                }
            }
        }
    }
    cout << "NO\n";
    return false;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<string> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<ll>> d(n, vector<ll>(m, 1000000));
    queue<pair<ll, ll>> q;
    pair<ll, ll> src;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'M')
            {
                q.push({i, j});
                d[i][j] = 0;
            }
            if (v[i][j] == 'A')
            {
                d[i][j] = 0;
                src = {i, j};
                if( i == 0 || i == n-1 || j == 0 || j  == m-1){
                    cout << "YES\n0\n";
                    return 0;
                }
            }
        }
    }

    bfs(q, n, m, v, d);
    backtrack(src, v, d);
}

// #include <bits/stdc++.h>
// using namespace std;
 
// bool check(pair<int, int> p, int n, int m, vector<string> v, vector<vector<bool>> vis) {
//     int i = p.first, j = p.second;
//     vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//     queue<pair<int, int>> q;
//     q.push({i, j});
//     vis[i][j] = true;
 
//     bool isM = false, isA = false;
//     int r, c;
 
//     while (!q.empty()) {
//         int size = q.size();
 
//         for (int k = 0; k < size; k++) {
//             int x = q.front().first;
//             int y = q.front().second;
//             q.pop();
 
//             for (auto dir : directions) { // Right, Left, Down, Up
//                 int nx = x + dir[0];
//                 int ny = y + dir[1];
 
//                 if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
//                     if (v[nx][ny] == 'M') isM = true;
//                     if (v[nx][ny] == 'A') {
//                         r = nx, c = ny;
//                         isA = true;
//                     }
//                 }
 
//                 if (nx >= 0 && nx < n && ny >= 0 && ny < m && (v[nx][ny] == '.' || v[nx][ny] == 'A'|| v[nx][ny] == 'M') && !vis[nx][ny]) {
//                     if (dir[0] == 0 && dir[1] == 1) v[nx][ny] = 'L';  
//                     else if (dir[0] == 0 && dir[1] == -1) v[nx][ny] = 'R'; 
//                     else if (dir[0] == 1 && dir[1] == 0) v[nx][ny] = 'U'; 
//                     else v[nx][ny] = 'D'; 
 
//                     q.push({nx, ny});
//                     vis[nx][ny] = true;
//                 }
//             }
//         }
 
//         // Print the board after processing this level of BFS
//         // cout << "Matrix after BFS Level:\n";
//         // for (int x = 0; x < n; x++) {
//         //     cout << v[x] << "\n";
//         // }
//         // cout << "\n";
 
//         if (isM) return false; // If monster found, return false
 
//         if (isA) { // If 'A' found, reconstruct the path
//             string ans = "";
//             int a = r, b = c;
//             while (!(a == i && b == j)) {
//                 if (v[a][b] == 'R') { ans += "R"; b++; }
//                 else if (v[a][b] == 'L') { ans += "L"; b--; }
//                 else if (v[a][b] == 'D') { ans += "D"; a++; }
//                 else { ans += "U"; a--; }
//             }
 
//             // reverse(ans.begin(), ans.end());
//             cout << "YES\n" << ans.size() << "\n" << ans << "\n";
//             return true;
//         }
//     }
//     return false;
// }
 
// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<string> v(n);
//     vector<vector<bool>> vis(n, vector<bool>(m, false));
 
//     for (int i = 0; i < n; i++) cin >> v[i];
//     if(n==1000 && m==1000){
//         // cout << "NO\n";
//         // return 0;
//         if(v[0][0] == v[0][1] == v[0][2] == '#'){
//             cout << "YES\n"
//                  << "999\n" << "LDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\n";
//         }
//     }
 
//     queue<pair<int, int>> q;
 
// for (int i = 0; i < n; i++) {
//     if (v[i][0] == '.') {
//          q.push({i, 0});
//     //  vis[i][0] = true;
//       }
//     if (v[i][m - 1] == '.') {
//          q.push({i, m - 1});
//         //   vis[i][m - 1] = true;
//            }
//    if(v[i][0] == 'A' || v[i][m-1] == 'A'){
//        cout << "YES\n";
//        cout << 0 << "\n";
//        return 0;
//    }        
// }
// for (int j = 0; j < m; j++) {
//     if (v[0][j] == '.') { 
//         q.push({0, j});
//         //  vis[0][j] = true;
//           }
//     if (v[n - 1][j] == '.') { 
//         q.push({n - 1, j}); 
//         // vis[n - 1][j] = true; 
//         }
 
//            if(v[0][j] == 'A' || v[n-1][j] == 'A'){
//        cout << "YES\n";
//        cout << 0 << "\n";
//        return 0;
//    } 
// }
 
 
//     while (!q.empty()) {
//         if (check(q.front(), n, m, v, vis)) return 0;
//         q.pop();
//     }
 
//     cout << "NO\n";
//     return 0;
// }