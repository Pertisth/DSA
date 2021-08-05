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
node *root = NULL;

void insert(int key)
{
    node *p;
    node *t=root;
    node *r;
    if(root==NULL)
    {
       p = new node;
       p->right=p->left=NULL;
       p->data = key;
       root = p;
       return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
        {
            t=t->left;
        }
        else if(key>t->data)
        {
            t=t->right;
        }
        else
        {
            return;
        }

    }
    p=new node;
    p->left=p->right=NULL;
    p->data = key;
    if(key<r->data)
    {
        r->left = p;
    }
    else
    {
        r->right=p;
    }

}

void search(int key)
{
    node *t=root;
    while(t!=NULL)
    {
        if(key==t->data)
        {
            cout << "Element Found.";
            return;
        }
        else if(key<t->data)
        {
            t=t->left;
        }
        else
        {
            t=t->right;
        }
    }
    cout << "Element not found.";
}

void inOrder(node *root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int height(node* p)
{
    if(p==NULL)
        return 0;
    int x,y;
    x=height(p->left);
    y=height(p->right);
    if(x>y)
        return x+1;
    else
        return y+1;
}

node* inPre(node* p)
{
    while(p && p->right!=NULL)
        p=p->right;
    return p;
}

node* inSucc(node* p)
{
    while(p && p->left!=NULL)
    {
        p= p->left;
    }
    return p;
}

node * Delete(node* p,int key)
{
    node *q;
    if(p==NULL)
        return p;
    else if(p->left==NULL && p->right==NULL)
    {
        if(p==root)
        {
            root = NULL;
        }
        delete(p);
        return NULL;

    }

    else if(key < p->data)
    {
        p->left = Delete(p->left,key);
    }
    else if(key > p->data)
    {
        p->right = Delete(p->right,key);
    }
    else
    {
        if(height(p->left) > height(p->right))
        {
            q = inPre(p->left);
            p->data = q->data;
            p->left = Delete(p->left,q->data);
        }
        else
        {
            q=inSucc(p->right);
            p->data =q->data;
            p->right=Delete(p->right,q->data);
        }
    }
    return p;
}


int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int key;
        cin >> key;
        insert(key);
    }


    Delete(root,20);
    inOrder(root);
    cout << endl;
    return 0;
}
