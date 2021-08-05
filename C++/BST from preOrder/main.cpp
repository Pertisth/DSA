#include <bits/stdc++.h>
using namespace std;

class node
{
public:

    node *left;
    int data;
    node *right;
};
node *root =NULL;

void createbst(int pre[],int size)
{
    node* p;
    node* t;
    int i=0;
    root = new node;
    root->data = pre[i++];
    root->left=root->right=NULL;
    p=root;

    stack<node*>s;
    while(i<size)
    {
      if(pre[i]<p->data)
      {
          t=new node;
          t->data=pre[i++];
          t->left=t->right=NULL;
          s.push(p);
          p->left=t;
          p=t;
      }
      else
      {
          if(pre[i]>p->data && pre[i]<(s.empty()?INT_MAX:s.top()->data))
          {
              t=new node;
              t->data=pre[i++];
              t->left=t->right=NULL;
              p->right=t;
              p=t;

          }
          else
          {
              p=s.top();
              s.pop();
          }
      }

    }
}

void inorder(node* root)
{
    if(root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main()
{
    int pre[] = {10,5,1,7,40,50};
    int size = sizeof(pre)/sizeof(pre[0]);
    createbst(pre,size);
    inorder(root);
    return 0;

}
