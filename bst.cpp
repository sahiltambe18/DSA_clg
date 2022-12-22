#include <iostream>
using namespace std;
/*
insert
display
delete
copy
mirror
search
*/
struct node
{
    int data;
    node *left;
    node *right;
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
        root = new node(val);
        return root;
    }
    else
    {
        if (val < root->data)
        {
            root->left = insert(root->left, val);
        }
        else
        { // val > data
            root->right = insert(root->right, val);
        }
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

node *inorder_next(node *root)
{
    node *current = root;
    while (current && current->left != NULL) //-------------expt
    {
        current = current->left;
    }
    return current;
}

node *deletion(node *root, int key)
{
    if (key > root->data)
    {
        root->right = deletion(root->right, key);
    }
    else if (key < root->data)
    {
        root->left = deletion(root->left, key);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else
        { // case 3
            node *temp = inorder_next(root->right);
            root->data = temp->data;
            root->right = deletion(root->right, temp->data);
        }
    }
    return root;
}
node *mirror(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    node *temp = root->left;
    root->left = mirror(root->right);
    root->right = mirror(temp);
    return root;
}
node *copy(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    node *p = new node(root->data);
    p->left = copy(root->left);
    p->right = copy(root->right);
    return p;
}

bool search(node *root, int key)
{
    if (root != NULL)
    {
        if (root->data == key)
        {
            return 1;
        }

        if (root->data > key)
        {
            return search(root->left, key);
        }
        else if (root->data < key)
        {
            return search(root->right, key);
        }
    }
    return 0;
}

int main()
{
    node *head = NULL;
    int arr[5] = {6, 8, 4, 5, 7};
    for (int i = 0; i < 5; i++)
    {
        head = insert(head, arr[i]);
    }

    inorder(head);
    /*
          6
        /   \
       5     7
     /        \
    4          8
    */
    cout << endl;
    head = deletion(head, 5);
    inorder(head);
    cout << endl;
    cout << search(head, 4);

    return 0;
}