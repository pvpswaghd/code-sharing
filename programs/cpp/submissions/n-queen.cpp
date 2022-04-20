#include <bits/stdc++.h>

using namespace std;

//existingQueen

bool checkCol(vector<vector<int> >& res, int& j){
    int count = 0;
    for(int i = 0; i < 4; i++){
        if(res[i][j] == 1) count+=1; 
    }
    return count;
}

bool checkDiag(vector<vector<int> >&res, vector<int>& existingQueen, int& row){
    
    return 0;
}
void backtrack(vector<vector<int> >& res, int& size, vector<int>& existingQueen, int& row){
    if(size == existingQueen.size()){
        for(auto i : res){
            for (auto j : i){
                if(j == 0) cout << j << " ";
            }
        }
        cout << endl;
        return;
    }
    for(int i = 0; i<4; i++){
        if (checkCol(res, i) || ) {}
        else{
            res[row][i] = 1;
            existingQueen.push_back(i);
            backtrack();
            res[row][i] = 0;
            existingQueen.pop_back();
        }
    }
}
int main(){
    vector<vector<int> > result(4);
    vector<int> existingQueen;
    for (int i = 0; i < 4; i++){
        existingQueen.push_back(0);
    }
    //for (int i = 0; i < 4; i++){
        //for (int j = 0; j < 4; j++) result[i].push_back(0);
    //} 
    for (auto i : result){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    int size = 0;
    return 0;
}	g++ main.o test.o -o hello

