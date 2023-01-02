 #include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

node *insert(node *root, int val)
{
    if (root == NULL)
    {
        node *n = new node(val);
        return n;
    }
    if (root->data < val)
    {
        root->right = insert(root->right, val);
        return root;
    }
    else
    {
        root->left = insert(root->left, val);
        return root;
    }
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

node *succrssor(node *root)
{
    node *temp = root;
    while (temp && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node *del(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > key)
    {
        root->left = del(root->left, key);
        return root;
    }
    if (root->data < key)
    {
        root->right = del(root->right, key);
        return root;
    }
    else
    { // key found
        node *temp;
        if (root->left == NULL and root->right == NULL) // no child ie.leaf node
        {
            temp = root;
            delete temp;
            return NULL;
        }

        // 1 child only
        if (root->left != NULL && root->right == NULL)
        {
            temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        if (root->right != NULL && root->left == NULL)
        {
            temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        // both childs present

        temp = succrssor(root->right);
        root->data = temp->data;
        root->right = del(root->right, temp->data);
        return root;
    }
    return root;
}

bool search(node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (key == root->data)
    {
        return 1;
    }
    if (key > root->data)
    {
        return search(root->right, key);
    }
    else
    {
        return search(root->left, key);
    }
}

node* mirror(node* root){
    if (root == NULL)
    {
        return NULL;
    }
    node* temp = root->left;
    root->left = mirror(root->right);
    root->right = mirror(temp);
    return root;
}

void leaf(node* root){
    if (root == NULL)
    {
        return;
    }
    leaf(root->left);
    if (root->left == NULL && root->right == NULL)
    {
        cout<<root->data<<" ";
    }
    leaf(root->right);
    
    
}

node* copy(node* root){
    if (root == NULL)
    {
        return NULL;
    }
    node* temp = new node(root->data);
    temp->left = copy(root->left);
    temp->right = copy(root->right);
    return temp;
}

/*
        5
      /    \
     3      7
    / \    /  \
   2   4   6   8
*/

int main()
{
    node *root = NULL;
    int arr[7] = {5, 3, 2, 4, 7, 6, 8};
    for (int i = 0; i < 7; i++)
    {
        root = insert(root, arr[i]);
    }
    // inorder(root);
    // root = del(root, 5);

    inorder(root);
    // cout<<search(root ,1);
    // root = mirror(root);
    cout<<endl;
    // inorder(root);
    // leaf(root);
    node* temp = copy(root);
    inorder(temp);
    
    return 0;
}