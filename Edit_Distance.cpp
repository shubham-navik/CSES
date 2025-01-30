#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int t[5001][5001];

int solve(string s1,string s2,int i,int j,int n,int m){

vector<vector<int>>dp(n+1,vector<int>(m+1,0));
for(int i=0;i<=n;i++){  
    for(int j=0;j<=m;j++){
        if(i==0){
            dp[i][j]=j;
        }
        else if(j==0){
            dp[i][j]=i;
        }
        else if(s1[i-1]==s2[j-1]){
            dp[i][j]=dp[i-1][j-1];
        }
        else{
            dp[i][j]=1+min({ dp[i-1][j-1] , dp[i-1][j] , dp[i][j-1] });
        }
    }
}
return dp[n][m];

    // if(i==n){
    //     return m-j;
    // }
    // if(j==m){
    //     return n-i;
    // }

    // if(t[i][j]!=-1){
    //     return t[i][j];
    // }

    // if(s1[i]==s2[j]){
    //     return solve(s1,s2,i+1,j+1,n,m);
    // }
    // int ins = 1 + solve(s1,s2,i,j+1,n,m);
    // int del = 1 + solve(s1,s2,i+1,j,n,m);
    // int rep = 1 + solve(s1,s2,i+1,j+1,n,m);

    // return t[i][j] = min(ins,min(del,rep));
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    memset(t,-1,sizeof(t));
    int res = solve(s1, s2, 0, 0, n, m);
    cout <<  ( res) << "\n";
    return 0;
}