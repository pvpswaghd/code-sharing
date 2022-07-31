#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x; 
    cin >> x;

    int dp[100001];
    dp[6] = 3;
    for(int i = 7; i < 100002; i=i+3){
        dp[i] = dp[i-1]+1;
        dp[i+1] = dp[i-1]+1;
        dp[i+2] = dp[i-1]+1;

    }
    while(x--){
        int i, a;
        int t[4];
        cin >> a;
        t[1] = dp[a];
        t[2] = dp[a]-1;
        t[3] = a - t[1] - t[2];
        
        if (t[3] == 0){
            t[3] += 1;
            t[2] -= 1;
        }
        if (t[3] > t[2]) swap(t[2], t[3]);

        cout << t[2] << " " << t[1] << " " << t[3] << "\n";

    }

    return 0;
}
