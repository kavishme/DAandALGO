//https://www.hackerrank.com/challenges/self-balancing-tree
/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

node* getNewNode(int val){
    node* newNode = new node();
    
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->ht = 0;
    return newNode;
}

int height(node* n){
    if(n == NULL) return -1;
    return n->ht;
}

int getBalance(node* n){
    if(n==NULL) return 0;
    return height(n->left) - height(n->right);
}

int max(int a, int b){
    return a>b?a:b;
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->ht = max(height(y->left), height(y->right))+1;
    x->ht = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->ht = max(height(x->left), height(x->right))+1;
    y->ht = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 

node * insert(node * root, int val)
{
    if(root == NULL)
       return getNewNode(val);

    if(root->val < val)
        root->right = insert(root->right, val);
    else
        root->left = insert(root->left, val);

    root->ht = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && val < root->left->val)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && val > root->right->val)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && val > root->left->val)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && val < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}
