#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ll t;
    cin >> t;
    while(t--){
        ll r, c;
        cin >> r >> c;
        if(r<c){
            if(c%2==0){
                cout << (c - 1) * (c - 1) + r << "\n";
            }else{
                cout << (c - 1) * (c - 1) + (2 * (c - 1) + 1) - r +1 << "\n";
            }
        }else{
            if(r%2==0){
                cout << (r - 1) * (r - 1) + (2 * (r - 1) + 1) - c + 1 << "\n";
            }else{
                cout << (r - 1) * (r - 1) + c << "\n";
            }
        }


    }
    return 0;
}