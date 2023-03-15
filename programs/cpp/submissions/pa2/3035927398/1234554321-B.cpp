#include <stdio.h>
#include <assert.h>
#include <algorithm>

struct node
{
    int key;
    int height;
    int size;
    node *left, *right;
    node(int k)
    {
        key = k;
        height = 1;
        size = 1;
        left = right = 0;
    }
};

int height(node* r)
{
    return r ? r->height : 0;
}

void update_height(node* root)
{
    if(root == 0) return;
    int hl = height(root->left), hr = height(root->right);
    root->height = std::max(hl, hr) + 1;
}

int sizeOfTree(node* root){
    return root == NULL? 0 : root->size;
}

void right_rotate(node*& ref_root)
{
    assert(ref_root && ref_root->left);
    node *a = ref_root, *b = ref_root->left;
    int treeSize = a->size;
    int rightSize = treeSize - 1 - sizeOfTree(b->left);
    ref_root = b;
    a->left = b->right;
    b->right = a;
    a->size = rightSize;
    ref_root->size = treeSize;
    update_height(ref_root->right);
    update_height(ref_root);
}

void left_rotate(node*& ref_root)
{
    assert(ref_root && ref_root->right);
    node *a = ref_root, *b = ref_root->right;
    int treeSize = a->size;
    int leftSize = treeSize - 1 - sizeOfTree(b->right);
    ref_root = b;
    a->right = b->left;
    b->left = a;
    a->size = leftSize;
    ref_root->size = treeSize;
    update_height(ref_root->left);
    update_height(ref_root);
}

void maintain(node*& ref_root)
{
    if(ref_root == 0) return;
    update_height(ref_root);
    if(height(ref_root->left) > height(ref_root->right) + 1)
    {
        node*& p = ref_root->left;
        if( height(p->left) < height(p->right) )
            left_rotate(p);
        right_rotate(ref_root);
    }
    else if(height(ref_root->right) > height(ref_root->left) + 1)
    {
        node*& p = ref_root->right;
        if( height(p->left) > height(p->right) )
            right_rotate(p);
        left_rotate(ref_root);
    }
}

void insert_key(int key, node*& ref_root)
{
    if(ref_root == 0)
    {
        ref_root = new node(key);
        return;
    }
    if(key < ref_root->key){
        ++ref_root->size;
        insert_key(key, ref_root->left);
    }
    else if(key > ref_root->key){
        ++ref_root->size;
        insert_key(key, ref_root->right);
    }
    else
        assert(0);
    maintain(ref_root);
}

void delete_key(int key, node*& ref_root)
{
    if(ref_root == 0)
        assert(0); // or return; if non-existent key is allowed.
    if(key < ref_root->key){
        --ref_root->size;
        delete_key(key, ref_root->left);
    }
    else if(key > ref_root->key){
        --ref_root->size;
        delete_key(key, ref_root->right);
    }
    else
    {
        if(ref_root->left && ref_root->right)
        {
            node* p = ref_root->right;
            while(p->left)
                p = p->left;
            std::swap(ref_root->key, p->key);
            --ref_root->size;
            delete_key(key, ref_root->right);
        }
        else
        {
            node *p = ref_root->left ? ref_root->left : ref_root->right;
            delete ref_root;
            ref_root = p;
        }
    }
    maintain(ref_root);
}

int KthMin(node * root, int k){
    if(root == 0 || k < 1 || k > root->size){
        printf("root %d, k %d\n", root->size, k);
        assert(0);
    }
    int lsize =  sizeOfTree(root->left);
    if(k == lsize + 1)
        return root->key;
    if(k <= lsize)
        return KthMin(root->left, k);
    return KthMin(root->right, k - lsize - 1);
}

int main()
{
    node *root = 0;
    char op[10] = "";
    int k;
    while(true)
    {
        scanf("%s", op);
        if(op[0] == 'E') break;
        switch(op[0])
        {
            case 'A': scanf("%d", &k); insert_key(k, root); break;
            case 'D': scanf("%d", &k); delete_key(k, root); break;
            case 'M': scanf("%d", &k); printf("%d\n", KthMin(root, k));break;
            default: assert(0);
        }
    }
    return 0;
}
