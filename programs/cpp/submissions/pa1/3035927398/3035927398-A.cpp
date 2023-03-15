#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> s;

void solve(vector<int> pushseq, vector<int> popseq, int newSize, bool repeat){
    int pushseq_first = 0, popseq_first = 0;
    for(int i = 0; i < 2*newSize; i++){
        if(s.empty()){
            s.push(pushseq[pushseq_first]);
            if(repeat)
                cout << "push " << pushseq[pushseq_first] << endl;
            pushseq_first++;
        }
            
        else if(s.top() != popseq[popseq_first]){
            s.push(pushseq[pushseq_first]);
            if(repeat)
                cout << "push " << pushseq[pushseq_first] << endl;
            pushseq_first++;
        }        
        else{
            s.pop();
            popseq_first++;
            if(repeat)
                cout << "pop" << endl;
            }
    }
    if(s.empty()){
        if(!repeat)
            solve(pushseq, popseq, newSize, !repeat); 
    }
    else{
        if(!repeat)
            cout << "NO";
    }
}
int main(){
    //task input
    string task; 
    cin >> task;
    //size of sequence input
    int size;
    cin >> size;
    //creating new stack and size
    const int newSize = size;
    //sequence 
    vector<int> pushseq(newSize+1);
    vector<int> popseq(newSize+1);
    //reading input for pushseq
    while(size--){
        int t;
        cin >> t;
        pushseq[newSize-size-1] = t;
    }
    size = newSize;
    //reading input for popseq
    while(size--){
        int t;
        cin >> t;
        popseq[newSize-size-1] = t;
    }
    //single recursive function if it is pushseq is able to create popseq
    //*/ 
    bool repeat = false;
    solve(pushseq, popseq, newSize, repeat);
    return 0;


}
