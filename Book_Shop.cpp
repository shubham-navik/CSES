// #include<bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// ll t[100002][1002];
// ll solve( vector<ll>& price , vector<ll>& pages,ll n,ll x,ll i){
//     if(i >= n)
//         return 0;
//     if(x < 0)
//         return LLONG_MIN;
//     if(x==0)
//         return 0;
//     if(t[x][i] != -1)
//         return t[x][i];

//     ll take = 0, skip = 0;
    
//     if(x-price[i]>=0)
//      take = pages[i] + solve(price,pages,n,x-price[i],i+1);

//     skip = solve(price, pages, n, x, i + 1);

//     return t[x][i] = max({take, skip});
// }


// int main(){
//     ll n, x;
//     cin >> n >> x;
//     vector<ll> price(n), pages(n);
//     for(int i =0;i<n;i++){
//         cin >> price[i];
//     }
//     for(int i =0;i<n;i++){
//         cin >> pages[i];
//     }
//     memset(t, -1, sizeof(t));
//     cout<<solve(price, pages, n, x,0)<<"\n";
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, x;
    cin >> n >> x;
    vector<int> price(n), page(n);
    for (int &p : price) cin >> p;
    for (int &pg : page) cin >> pg;
 
    // Initialize a 2D DP table
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
 
    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            dp[i][j] = dp[i - 1][j];  // Do not take the current item
            if (j >= price[i - 1]) {
                // Take the current item
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + page[i - 1]);
            }
        }
    }
 
    cout << dp[n][x] << "\n";
    return 0;
}