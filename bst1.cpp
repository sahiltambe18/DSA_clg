#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class bst
{
public:
    // bst(int val)
    // {
    //     node(val);
    // }
     node* insert(node * root, int val);
    void inorder(node *root);
};

node* bst ::insert(node * root, int val)
{
    node *n = new node(val);
    node *temp = root;

    if (root == NULL)
    {
        return n;
    }
    
    while (temp != NULL){
        if (temp->data > val)
        {
            temp = temp->left;
        }
        if (temp->data < val)
        {
            temp = temp->right;
        }
    }
    temp = n;
    return temp;
    
}

void bst ::inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node* root = NULL;
    bst tr;
    int arr[] = {5,4,6,7,9,8,3,1,2};
    // for (int i = 0; i < 9; i++)
    // {
    //     root =  tr.insert(root , arr[i]);
    // }
    root = root =  tr.insert(root , arr[0]);
    // root = root =  tr.insert(root , arr[1]);
    tr.inorder(root);

    return 0;
}