#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool flag = true;

//The following struct is modifed from the original one.
struct TreeNode
{
    int val;
    int max;
    int min;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), max(0), min(0), left(NULL), right(NULL) {}
    TreeNode(): val(0), max(0), min(0), left(NULL), right(NULL) {}
};

bool validate(int min, int max, int val){
    return ((max != 0 && min != 0) ? (!(val<max && val > min)) : (max == 0) ? (min > val) : (max < val));
}

//The concept is to reduce the interval by finding the maximum and minimum, and once the number falls out of the interval, then it means the subtree is not valid.

void solve(){
    int n,m; 
    cin >> n;
    if(n == 0) {
        cout << "true";
        return;
    }
    cin >> m;
    vector<TreeNode> tree(n);
    tree[0] = TreeNode(m);
    if(n == 1) {
        cout << "true";
        return;
    }
    for (int i = 1; i < n; i++){
       cin >> m; 
       tree[i] = TreeNode(m);
       if(m != 0){
            int parent = (i-1)/2;
            if (i%2 == 0) { //check right node
               tree[parent].right = &(tree[i]);
               tree[i].min = tree[parent].val;
               tree[i].max = (tree[parent].max != 0) ? tree[parent].max : tree[i].max;
            }
            
            else{ //check left node
               tree[parent].left = &tree[i]; //find the parent and assign
               tree[i].max = tree[parent].val;
               tree[i].min = (tree[parent].min == 0) ? tree[i].min : tree[parent].min;
            }

            if(validate(tree[i].min, tree[i].max, tree[i].val)){
                cout << "false";
                return;
            }

       }
    }
    cout << "true";
}

int main(){

    //int n;
    //cin >> n;
    //vector<int> tree(n); 
    solve();
    /*
    for(int i = 0; i < n; i++){ 
        int m;
        cin >> m;
        tree[i] = m;
    }
    */

    //solve();
    //
    /*
    for(int i = 0; i < tree.size()-1; i++){
        if(tree[i+1] <= tree[i]){
            flag = false;
            break;
        } 
    }
    */
    
    //if(flag) cout << "true";
    //else cout << "false";

}
