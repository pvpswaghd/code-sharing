#include <iostream>
#include <assert.h>
#include <algorithm>

using namespace std;

//int size = 0;
int kth = 0;

struct TreeNode { //from the slides
    int value;
    int height;
    int size;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value){
        this->value = value;
        left = right = 0;
        height = 1;
        size = 1;
    }
};

void inorder(TreeNode *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    cout << root->value << " (" << root->size << " ) -> ";

    // Traverse right
    inorder(root->right);
  }
}

int update_height(TreeNode *r){
    if (r == 0)
        assert(0);
    int lh = (r->left) ? r->left->height : 0;
    int rh = (r->right) ? r->right->height : 0;
    return max(lh, rh) + 1;

}

int sizeTree(TreeNode* r){
    return (r == NULL) ? 0 : r->size;
}

TreeNode* leftRotate(TreeNode*& r){
    int treeSize = r->size;
    TreeNode *x = r->right;
    int leftSize = treeSize - 1 - sizeTree(x->right);
    TreeNode *y = x->left;
    
    x->left = r;
    r->right = y;
    
    x->size = treeSize;
    r->size = leftSize;
    x->left->height = update_height(x->left);
    x->height = update_height(x);

    return x;
}

TreeNode* rightRotate(TreeNode*& r){
    int treeSize = r->size;
    TreeNode *x = r->left;
    int rightSize = treeSize - 1 - sizeTree(x->left);
    TreeNode *y = x->right;

    x->right = r;
    r->left = y;
    
    r->size = rightSize;
    x->size = treeSize;
    x->right->height = update_height(x->right);
    x->height = update_height(x);
    return x;
}


int height(TreeNode *r){
    /*
    if (r == 0) //default case for a empty node
        return -1;
    else {
        int lh = height(r->left);
        int rh = height(r->right);
        return (max(lh, rh) + 1);
    } 
    */
    return (r==NULL) ? 0 : r->height;
}


int getBF (TreeNode* r){
    return (r == 0) ? -1 : (height(r->left) - height(r->right));
    /*
    if (r == 0) 
        return -1;
    else{
        if(r->left && r->right){
            return r->left->height - r->right->height;
        }
        else if (r->left) 
            return r->left->height+1;
        return -1-r->right->height;
    }
    */
}

void insert(TreeNode *&r, int value){
    if (r == 0){
        r = new TreeNode(value);
        return;
    }

    if (value > r->value){
        r->size += 1;
        insert(r->right, value);
    }

    else if (value < r->value){
        r->size += 1;
        insert(r->left, value);
    }

    int bf = getBF(r);

    if(bf < -1){
        bf = getBF(r->right);
        if(bf > 1){
            r->right = rightRotate(r->right);
        }
        r = leftRotate(r);
    }

    else if(bf > 1){
        bf = getBF(r->left);
        if (bf < -1){
            r->left = leftRotate(r->left); 
        }
        r = rightRotate(r);
    }
    
    /*
    if (bf > 1 && newNode->value < r->left->value) //LL imbalance
        return rightRotate(r);

    if (bf < -1 && newNode->value > r->right->value) //RR imbalance
        return leftRotate(r);

    if (bf > 1 && newNode->value > r->left->value){
        r->left = leftRotate(r->left);
        return rightRotate(r);
    } //LR imbalance
    
    if (bf < -1 && newNode->value < r->right->value){
        r->right = rightRotate(r->right);
        return leftRotate(r);
    } //RR imbalance
    */

}

TreeNode* deleteNode(TreeNode *r, int value){
    if (r == 0) {
        return NULL;
    }

    else if (value < r->value){
        r->size -= 1;
        r->left = deleteNode(r->left, value);
    }

    else if (value > r->value){
        r->size -= 1;
        r->right = deleteNode(r->right, value);
    }

    else{
        if (!(r->left && r->right)){
            TreeNode *remainingRoot = (r->right) ? r->right : r->left;
            delete r;
            r = remainingRoot;
        }
        else{
            TreeNode *rightR = r->right;
            while(rightR->left){
                rightR = rightR->left;
            }
            swap(r->value, rightR->value);
            r->size -= 1;
            r->right = deleteNode(r->right, value);
        }
    }
    
    int bf = getBF(r);

    if(bf < -1){
        bf = getBF(r->right);
        if(bf > 1){
            r->right = rightRotate(r->right);
        }
        r = leftRotate(r);
    }

    else if(bf > 1){
        bf = getBF(r->left);
        if (bf < -1){
            r->left = leftRotate(r->left); 
        }
        r = rightRotate(r);
    }
    return r;
}

int findMin(TreeNode* r, int k){ //, int& count
    /*
    if (r == NULL)
        return;
    findMin(r->left, k, count);
    count++;
    if (count == k)
        kth = r->value;  
    else
        findMin(r->right, k, count);
    */

    if(r == 0 || k < 1 || k > r->size)
    {
        if (r == 0)
            assert(0);
        if (k > r->size)
            assert(1);
    }
    int lsize = sizeTree(r->left);
    if(k == lsize + 1)
        return r->value;
    if(k > lsize)
        return findMin(r->right, k-lsize-1);
    return findMin(r->left, k);

}

int main(){
    TreeNode *root = 0;        
    char input[10];
    int value;
    bool flag = true;
    while(flag){
        scanf("%s", input);
        if(input[0] == 'E' && input[1] == 'N' && input[2] == 'D') {
            flag = false;
            break;
        }
        switch(input[0]){
            case 'A':
                cin >> value;
                insert(root, value);
                //cout << endl << "Root now is: " << root->value << endl;
                break;
            case 'D':
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 'M':
                cin >> value;
                int count = 0;
                cout << findMin(root, value) << endl;
                //cout << kth << endl;
                break;  


        }
    }

}

