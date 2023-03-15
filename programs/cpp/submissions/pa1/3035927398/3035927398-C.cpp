#include <iostream>
#include <algorithm>

using namespace std;

int solve(string s, int left, int right){
    int score = 0, bonus = 0;
    if(s[left] == '(' && s[right] == ')' && abs(right-left)==1){
        return 1;
    }
    else if (s[left] == '(' && s[right] == ')'){
        if(s[left+1] == ')'){
            bonus++;
            left+=2;
        } 
        else if(s[right-1] == '('){
            bonus++;
            right-=2;
        }
        else{
            left+=1;
            right-=1;
        }
    }
    else{
        return 0;
    }
    int calculated = solve(s, left, right);
    score = (bonus!=0) ? bonus + calculated : bonus + 2 * calculated;
    /*
    if(bonus == 0)
        cout << bonus << " + " << calculated << " * 2 = " << bonus + calculated * 2 << endl;
    else
        cout << bonus << " + " << calculated << " = " << bonus + calculated << endl;
    */
    return score;
}
int main(){
    string s;
    cin >> s;
    int count[2] = {0, 0};
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            count[0]+=1;
        }
        else{
            count[1]+=1;
        }
    }
    int left = 0, right = s.length()-1;
    if(count[0] == count[1]){
        cout << solve(s, left, right);
    }
    else{
        cout << "0";
    }

}
