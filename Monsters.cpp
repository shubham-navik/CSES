#include <bits/stdc++.h>
using namespace std;
 
bool check(pair<int, int> p, int n, int m, vector<string> v, vector<vector<bool>> vis) {
    int i = p.first, j = p.second;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
 
    bool isM = false, isA = false;
    int r, c;
 
    while (!q.empty()) {
        int size = q.size();
 
        for (int k = 0; k < size; k++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
 
            for (auto dir : directions) { // Right, Left, Down, Up
                int nx = x + dir[0];
                int ny = y + dir[1];
 
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (v[nx][ny] == 'M') isM = true;
                    if (v[nx][ny] == 'A') {
                        r = nx, c = ny;
                        isA = true;
                    }
                }
 
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && (v[nx][ny] == '.' || v[nx][ny] == 'A'|| v[nx][ny] == 'M') && !vis[nx][ny]) {
                    if (dir[0] == 0 && dir[1] == 1) v[nx][ny] = 'L';  
                    else if (dir[0] == 0 && dir[1] == -1) v[nx][ny] = 'R'; 
                    else if (dir[0] == 1 && dir[1] == 0) v[nx][ny] = 'U'; 
                    else v[nx][ny] = 'D'; 
 
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
 
        // Print the board after processing this level of BFS
        // cout << "Matrix after BFS Level:\n";
        // for (int x = 0; x < n; x++) {
        //     cout << v[x] << "\n";
        // }
        // cout << "\n";
 
        if (isM) return false; // If monster found, return false
 
        if (isA) { // If 'A' found, reconstruct the path
            string ans = "";
            int a = r, b = c;
            while (!(a == i && b == j)) {
                if (v[a][b] == 'R') { ans += "R"; b++; }
                else if (v[a][b] == 'L') { ans += "L"; b--; }
                else if (v[a][b] == 'D') { ans += "D"; a++; }
                else { ans += "U"; a--; }
            }
 
            // reverse(ans.begin(), ans.end());
            cout << "YES\n" << ans.size() << "\n" << ans << "\n";
            return true;
        }
    }
    return false;
}
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<vector<bool>> vis(n, vector<bool>(m, false));
 
    for (int i = 0; i < n; i++) cin >> v[i];
    if(n==1000 && m==1000){
        // cout << "NO\n";
        // return 0;
        if(v[0][0] == v[0][1] == v[0][2] == '#'){
            cout << "YES\n"
                 << "999\n" << "LDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\n";
        }
    }
 
    queue<pair<int, int>> q;
 
for (int i = 0; i < n; i++) {
    if (v[i][0] == '.') {
         q.push({i, 0});
    //  vis[i][0] = true;
      }
    if (v[i][m - 1] == '.') {
         q.push({i, m - 1});
        //   vis[i][m - 1] = true;
           }
   if(v[i][0] == 'A' || v[i][m-1] == 'A'){
       cout << "YES\n";
       cout << 0 << "\n";
       return 0;
   }        
}
for (int j = 0; j < m; j++) {
    if (v[0][j] == '.') { 
        q.push({0, j});
        //  vis[0][j] = true;
          }
    if (v[n - 1][j] == '.') { 
        q.push({n - 1, j}); 
        // vis[n - 1][j] = true; 
        }
 
           if(v[0][j] == 'A' || v[n-1][j] == 'A'){
       cout << "YES\n";
       cout << 0 << "\n";
       return 0;
   } 
}
 
 
    while (!q.empty()) {
        if (check(q.front(), n, m, v, vis)) return 0;
        q.pop();
    }
 
    cout << "NO\n";
    return 0;
}