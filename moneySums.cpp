#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int total = accumulate(v.begin(), v.end(), 0);
    vector<bool> dp(total + 1, false);  // DP array to track reachable sums
    dp[0] = true;  // Sum 0 is always achievable (by taking no elements)

    // Process each number in the vector
    for (int num : v) {
        // Update reachable sums in reverse to avoid reuse within the same loop
        for (int j = total; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    // Collect all reachable sums from 1 to total
    vector<int> ans;
    for (int i = 1; i <= total; i++) {
        if (dp[i]) {
            ans.push_back(i);
        }
    }

    // Output the result
    cout << ans.size() << endl;
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}






// #include <bits/stdc++.h>
// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
// #define ll long long
// #define pii pair<int, int>
// #define pll pair<ll, ll>
// #define vi vector<int>
// #define vll vector<ll>
// #define vpii vector<pair<int, int>>
// #define vpll vector<pair<ll, ll>>
// #define pb push_back
// #define mp make_pair
// #define all(x) (x).begin(), (x).end()
// #define fi first
// #define se second
// #define INF 1e9
// #define MOD 1000000007
// #define PI 3.14159265358979323846

// bool t[101][100001];
// bool sol(int i ,int sum,int n,vector<int>&v){
//     if(sum==0)
//         return true;
//     if(i>=n || sum < 0){
//         // if(sum!=0)
//         return false;
//         // return true;
//         // st.insert(sum);
//     }

//     if(t[i][sum]){
//         return t[i][sum];
//     }

//     bool take = sol(i + 1, sum - v[i], n, v);
//     bool skip = sol(i + 1, sum , n, v);
//     return t[i][sum] = (take || skip);
// }
// void solve() {
//     // Your solution code goes here
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for (int i = 0; i < n;i++)
//         cin >> v[i];

//     int total = accumulate(v.begin(), v.end(), 0);
//     vector<int> ans;
//     memset(t, false, sizeof(t));
//     for (int i = 1; i <= total;i++){
//         if(sol(0,i,n,v)){
//             ans.push_back(i);
//         }
//     }

//         cout << ans.size() << endl;
//     for(auto num:ans){
//         cout << num << " ";
//     }
//     cout <<endl;
// }

// int main() {
//     fastio; // for faster input/output

//     int t=1;
//     // cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }