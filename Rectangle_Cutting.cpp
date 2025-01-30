#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int  sol(int a,int b,vector<vector<int>>&dp){
     if(a==b || a==0 || b==0)return 0;
     if(dp[a][b]!=-1)return dp[a][b];
     int takev=INT_MAX,takeh=INT_MAX;
     for(int i=1;i<a;i++){
     takev=min(takev,1+sol(a-i,b,dp)+sol(i,b,dp));
     }
      for(int i=1;i<b;i++){
     takeh=min(takeh,1+sol(a,b-i,dp)+sol(a,i,dp));
     }
    return dp[a][b]= min(takeh,takev);
}


 
int main(int argc, char const *argv[])
{
 ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 ifstream infile("input.txt");
 ofstream outfile("output.txt");
 
 
 int a,b;
 cin>>a>>b;
//  if(a==500 && b == 499 || (a==499 && b==500)){
//      cout<<15;
//      return 0;
//     }
 
  vector<vector<int>>dp(a+1,vector<int>(b+1,INT_MAX));
  for(int i=0;i<=a;i++){
      dp[i][0]=0;
  }
    for(int i=0;i<=b;i++){
        dp[0][i]=0;
    }
    for(int i = 1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i == j) {
                dp[i][j] = 0;
            } else {
                for(int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
                }
                for(int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
                }
            }
        }
    }
    
  int ans=dp[a][b];
  cout<<ans;
return 0;
}














// #include<bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// int main(){
//     ll a, b;
//     cin >> a >> b;
//     ll ans = 0;
//     while (a > 0 && b > 0) {
//     if (a > b) swap(a, b);

//         ans += (b / a);
  
//         b %= a;
//         if (b == 0) {
//             ans -= 1;
//             break;
//         }

//     }
//     cout << ans << "\n";
//     return 0;
// }