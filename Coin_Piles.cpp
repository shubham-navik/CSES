#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ll t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        if(a<b){
            if(b> 2*a){
                cout << "NO\n";
            }else{
                a = a % 3;
                b = b % 3;

                if((a==1 && b==2) || (a==2&&b==1)||a ==0 && b==0 )
                    cout << "YES\n";
                else{
                        cout << "NO\n";
                    }
            }
        }else{
            swap(a, b);
             if(b> 2*a){
                cout << "NO\n";
            }else{
                a = a % 3;
                b = b % 3;

                if((a==1 && b==2) || (a==2&&b==1)||a ==0 && b==0 )
                    cout << "YES\n";
                else{
                        cout << "NO\n";
                    }
            }
        }

    }
    return 0;
}