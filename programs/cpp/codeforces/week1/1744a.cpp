#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    cin >> x;
    while(x--){
        string s;
        cin >> y >> s;
        int a = (int)s[0]-48;
        for (int i = 1; i < y; i++){
            int b = (int)s[i]-48;
            bool result = (abs(a-b) >= abs(a+b)) ? true : false;
            if(result){
                a+=b;   
                cout << "+";
            }
            else{
                a-=b;
                cout << "-";
            }
        }
        cout << endl;
    }
}


