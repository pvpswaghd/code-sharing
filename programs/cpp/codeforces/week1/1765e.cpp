#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    
    cin >> t;

    while(t--){
        int n, a, b;

        cin >> n >> a >> b;

        int r = (a > b) ? 1 : (n+a-1) / a;

        cout << r << endl;

    }

}
