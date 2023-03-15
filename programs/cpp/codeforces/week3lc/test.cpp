#include <bits/stdc++.h>
#define ll long long

using namespace std;

void backtrack(vector<vector<int>>& ans, vector<int> nums, int target, vector<int> s, bool h){
        int size = nums.size();
        int val;
        if(s.size() == 4){
            if(target == 0){
                vector<int> s1;
                s1 = s;
                sort(s1.begin(), s1.end());
                ans.push_back(s1);
            }
        }
        else{
            for (int i = 0; i < size; i++){
                val = nums[0];
                s.push_back(val);
                nums.erase(nums.begin());
                backtrack(ans, nums, target-val, s, false);
                s.pop_back();
                nums.push_back(val);
            }
        }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums;
    vector<int> s;
    vector<vector<int>> num;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(-2);
    nums.push_back(2);
    backtrack(num, nums, 0, s, true);
    cout << "done";
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    cout << num.size() << endl;
    for(int i = 0; i < num.size(); i++){
        cout << "[";
        for(int j = 0; j < 4; j++){
            cout << num[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;

}
