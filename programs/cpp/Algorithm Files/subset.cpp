#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

void search(int k){ //recursive method to find all the subset 
    if (k == n){
        //process subset
    }
    else{
        search(k+1);
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
    }
}

int main(){
    for (int b = 0; b < (1<<n); b++){ //iterative way to solve the q
        vector<int> subset;
        for (int i = 0; i < n; i++){
            if (b&(1<<i)) subset.push_back(i);
        }
    }    
}
