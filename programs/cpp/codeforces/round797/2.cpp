#include <bits/stdc++.h>

#define ll long long 

using namespace std;

void solve(const int n){
    ll a[n+1];
    ll b[n+1];

    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];

    int amax = *max_element(a+1, a+n+1);
    int amin = *min_element(a+1, a+n+1);
    int bmax = *max_element(b+1, b+n+1);
    int bmin = *min_element(b+1, b+n+1);

    if(bmax > amax || amax-amin > n) cout << "NO\n";
    else cout << "YES\n";
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        solve(n);
    }

}

