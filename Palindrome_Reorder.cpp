#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    string s;
    cin >> s;
    vector<ll> v(26, 0);
    for (int i = 0; i < s.size();i++){
        v[s[i] - 'A']++;
    }

    ll cnt = 0;
    ll pos = -1;
    for (int i = 0; i < 26;i++){
        if(v[i]%2!=0){
            pos = i;
            cnt++;
        }
    }
    if(cnt>1){

        cout << "NO SOLUTION\n";
        return 0;
    }
    string ans = "";
    for (int i = 0; i < 26;i++){
        for (int j = 1; j <= v[i] / 2;j++){
            ans += (i + 'A');
        }
            // ans += string(char('A' + i), v[i] / 2);
    }

    string p = ans;
    reverse(p.begin(), p.end());
    if(cnt==1){
        ans += (char('A' + pos));
    }
    ans = ans + p;
    cout << ans;
    cout << endl;
    return 0;
}