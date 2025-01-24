#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void dfs(vector<vector<char>>& v,int i,int j,int n,int m){
    if(i>= n ||i < 0 || j>=m||j<0 || v[i][j] == '#')
        return;

    v[i][j] = '#';

    for(auto d : dir){
        int x = i + d[0];
        int y = j + d[1];
        dfs(v, x, y, n, m);
    }

}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n,vector<char>(m));
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++)
            cin >> v[i][j];
    

        int cnt = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if(v[i][j] == '.'){
                cnt++;
                dfs(v,i, j, n, m);
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}