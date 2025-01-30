#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n;i++){
        string s;
        cin >> s;
        v.push_back(s);
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    dp[0][0] = 1;
// cout<<dp[0][0];
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(v[i][j]=='*')
                dp[i][j] = 0;

            else{

                if(i>0)
                    dp[i][j] += dp[i - 1][j];
                if(j>0)
                    dp[i][j] += dp[i][j - 1];

                dp[i][j] %= 1000000007ll;
            }    

        }
    }

    cout<<dp[n-1][n-1]<<"\n";
        return 0;
}