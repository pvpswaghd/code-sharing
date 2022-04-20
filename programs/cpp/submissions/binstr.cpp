#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
  
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string a;
        set<string> occurence;
        string s, sc;
        cin >> a >> s;
        sc = s;
        s.erase(std::unique(s.begin(), s.end()), s.end());
        cout << s.length() << endl;
        /*for(string::size_type i = 0; i < sc.length(); i++){
            s = sc;
            string tmp = s;
            tmp.erase(i, 1);
            //for (int j = i; j < n-1; j++){
                //swap(s[j], s[j+1]);
            //}
            cout << tmp << endl;
            occurence.insert(tmp);
        }*/
        //cout << occurence.size() << endl;
    }
}

