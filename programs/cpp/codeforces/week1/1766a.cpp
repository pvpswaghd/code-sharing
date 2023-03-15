#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while(t--){
        int x;
        cin >> x;

        if(x <= 9){
            cout << x << endl;
        }

        else{
            int d = 1; //check number of digits
            int y = x;

            while(y >= 10){ //power
                d++;
                y/=10;
            }
            
            int p = pow(10, d-1);
            int a = x / p; //take the initial digit
            int b = (d >= 2) ? 9 * (d-1) : 0;
            int r = a + b;

            cout << r << endl;

            }
            
        }


}
