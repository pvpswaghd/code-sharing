#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void backtrack (vector<vector<int> >& res, vector<int>& nums, vector<int>& permutations, vector<bool>& used){
    if(permutations.size() == nums.size()){
        res.push_back(permutations);
    }
    for(int i = 0; i < nums.size(); i++){
        if(!used[i]){
            used[i] = true;
            permutations.push_back(nums[i]);
            backtrack(res, nums, permutations, used);
            used[i] = false;
            permutations.pop_back();
        }
    }
}

int main(){
    vector<vector<int> >res;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    vector<int> permutations;
    vector<bool> used(nums.size(), false);
    backtrack(res, nums, permutations, used);
    for(auto i : res){
        cout << "[ ";
        for(auto j : i){
            cout << j << " ";
        }
        cout << "]\n" << endl;
    }
}