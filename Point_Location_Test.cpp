#include<bits/stdc++.h>
using namespace std;

int main(){

 
    int t;
    cin >> t;
 
    while(t--){
 
    
 
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    long long f = (y2 - y1) * x3 - (x2 - x1) * y3 + y1 * (x2 - x1) - x1 * (y2 - y1);
    if(f==0)
        cout << "TOUCH\n";
    else if(f>0){
        cout << "RIGHT\n";
    }else{
        cout << "LEFT\n";
    }    
 
 
    }
 
    return 0;

}