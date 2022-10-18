#include <bits/stdc++.h>

using namespace std;

void solve(string a, string b){
    int state = 0;
    //-1: smaller 0: equal 1: greater
    if(a[a.length()-1] == b[b.length()-1]){
        if(a.length() > b.length()){
            if(a[a.length()-1] == 'S') state = -1;
            else state = 1;
        }         
        if (a.length() < b.length()){
            if(a[a.length()-1] == 'S') state = 1;
            else state = -1;
        } 
        if (a.length() == b.length()) state = 0;
    }
    else if(a[a.length()-1] == 'M' && b[b.length()-1] == 'L' || a[a.length()-1] == 'S'&& b[b.length()-1] == 'M' || a[a.length()-1] == 'S' && b[b.length()-1] == 'L') state = -1;
    else state = 1; 
    
    switch(state){
        case -1:
            cout << "<\n";
            break;
        case 0:
            cout << "=\n";
            break;
        case 1:
            cout << ">\n";
            break;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        solve(a, b);
    }

}
