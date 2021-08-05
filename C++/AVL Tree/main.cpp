#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class node
{
public:
    node *left;
    int data;
    int height;
    node *right;
};

node *root= nullptr;

int nodeHeight(node* p)
{
    int hl,hr;
    hl = p &&p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height:0;
    return hl>hr?hl+1:hr+1;
}

int BalanceFactor(node* p)
{
    int hl,hr;
    hl=p && p->left ? p->left->height:0;
    hr=p && p->right ? p->right->height:0;
    return hl-hr;

}

node* LLRotation(node* p)
{
    node* pl=p->left;
    node* plr=pl->right;
    pl->right=p;
    p->left=plr;
    if(root==p)
        root=pl;
    return pl;
}
node* LRRotation(node* p)
{
    node *pl=p->left;
    node *plr=pl->right;



    pl->right=plr->left;
    p->left=plr->right;
    plr->left=pl;
    plr->right=p;

    p->height=nodeHeight(p);
    pl->height=nodeHeight(pl);
    plr->height=nodeHeight(plr);
    if(p==root)
        root=plr;
    return plr;

}
node* RRRotation(node* p)
{
    node* pr=p->right;
    node* prl=pr->left;
    pr->left = p;
    p->right = prl;

    p->height=nodeHeight(p);
    pr->height=nodeHeight(pr);
    if(p=root)
        root=pr;
    return pr;


}
node* RLRotation(node* p)
{
    node *pr=p->right;
    node *prl=pr->left;
    p->right=prl;
    pr->left=p;
    p->height=nodeHeight(p);
    pr->height=nodeHeight(pr);
    if(p==root)
        root=pr;
    return pr;
}

int Height(node *p)
{
    int x,y;
    if(p==nullptr)
        return 0;
    x=Height(p->left);
    y=Height(p->right);
    return x>y?x+1:y+1;

}
node* Insert(node* p,int key)
{
    node *t;
    if(p==nullptr)
    {
        t=new node;
        t->left=t->right=nullptr;
        t->data=key;
        t->height=1;
        return t;

    }
    if(key < p->data)
    {
        p->left = Insert(p->left,key);
    }
    else if(key > p->data)
    {
        p->right = Insert(p->right,key);
    }
    p->height = nodeHeight(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1)
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1)
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1)
        return RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1)
        return RLRotation(p);
    return p;
}

node *InPre(node *p)
{
    while(p && p->right!=nullptr)
        p=p->right;
    return p;
}

node *InSucc(node *p)
{
    while(p && p->left)
        p=p->left;
    return p;
}

node *Delete(int key,node* p)
{
    node *q;
    if(p==nullptr)
        return p;
    else if(p->left==nullptr && p->right==nullptr)
    {
        if(p==root)
            root=nullptr;
        delete(p);
        return nullptr;
    }
    else if(key < p->data)
        p->left=Delete(key,p->left);
    else if(key > p->data)
        p->right=Delete(key,p->right);
    else
    {
        if(Height(p->left) > Height(p->right))
        {
           q=InPre(p->left);
           p->data=q->data;
           p->left=Delete(q->data,p->left);
        }
        else
        {
            q=InSucc(p->right);
            p->data=q->data;
            p->right=Delete(q->data,p->left);
        }
    }
    p->height=nodeHeight(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1)
    {
        return LLRotation(p);
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1)
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1)
        return RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1)
        return RLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1)
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->right)==-1)
        return RRRotation(p);
    return p;

}

void Levelorder(node *p)
{
    if(!p)
        return;
    queue <node*> q;
    cout << p->data << " ";
    q.push(p);
    node *temp;
    while(!q.empty())
    {
       temp = q.front();
       q.pop();
       if(temp->left)
       {
           cout << temp->left->data << " ";
           q.push(temp->left);
       }
       if(temp->right)
       {
           cout << temp->right->data << " ";
           q.push(temp->right);
       }
    }
}

void Inorder(node *p)
{
    if(p)
    {
        Inorder(p->left);
        cout << p->data << " ";
        Inorder(p->right);
    }
}
int main()
{
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        int key;
        cin >> key;
        if(i==0)
            root =Insert(root,key);
        Insert(root,key);
    }
    Delete(28,root);
    Levelorder(root);
    return 0;
}
