#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;
    int ans = 1;

    int j = 0, i = 1;
    while(i<s.size()){
        if(s[i] == s[j]){
            i++;
            // continue;
            ans = max(ans, i - j);
        }else{
            j = i;
        }
    }
    if(j == 0 && i == s.size())
        cout << s.size() << "\n";
        else
    cout << ans << "\n";
}