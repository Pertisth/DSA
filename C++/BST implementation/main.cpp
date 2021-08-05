#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
struct node* root=NULL;

node* newnode(int key)
{
    node* temp = new node();
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;

}

node* insert(struct node* root,int key)
{
    if(root==NULL)
    {
        root = newnode(key);
    }
    else if(key<=root->data)
    {
        root->left = insert(root->left,key);
    }
    else
    {
        root->right = insert(root->right,key);
    }
    return root;
}

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int key;
        cin >> key;
        root = insert(root,key);
    }
    inorder(root);
    return 0;
}
