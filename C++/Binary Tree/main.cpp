#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node
{
public:

    node *left;
    int data;
    node *right;
};

node *root= NULL;

void create()
{
    queue<node*> qu;
    node *p;
    node *t;
    int x;
    cout << "Enter the value of root node :  ";
    cin >> x;
    root = new node;
    root->data=x;
    root->left=root->right=NULL;
    qu.push(root);
    while(!qu.empty())
    {
        p=qu.front();
        qu.pop();
        cout << "Enter the left child of " <<p->data<<": ";
        cin >> x;
        if(x!=-1)
        {
            t=new node;
            t->left=t->right=NULL;
            t->data=x;
            p->left=t;
            qu.push(t);
        }
        cout << "Enter the right child of " << p->data <<": ";
        cin >> x;
        if(x!=-1)
        {
            t=new node;
            t->left=t->right=NULL;
            t->data=x;
            p->right=t;
            qu.push(t);
        }
    }


}

void preOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);

}

void levelOrder(node *root)
{
    queue <node*> q;
    cout << root->data << " ";
    q.push(root);
    while(!q.empty())
    {
        node *p;
        p=q.front();
        q.pop();
        if(p->left)
        {
            cout << p->left->data << " ";
            q.push(p->left);
        }
        if(p->right)
        {
            cout << p->right->data << " ";
            q.push(p->right);
        }
    }

}
int main()
{
    create();
    levelOrder(root);
    return 0;
}
