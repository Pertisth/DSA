#include <iostream>

using namespace std;
class node{
    public: int data;
    node* right;
    node* left;
    node(int d)
    {
        data=d;
        right=NULL;
        left=NULL;

    }
};
node* buildtree()
{
   int d;
   cin>>d;
   if( d== -1)
        return NULL;
   node* root=new node(d);
   root->left=buildtree();
   root->right=buildtree();
   return root;
}

void printtree(node* root)
{ if(root==NULL)
 {
   return;
 }
  printtree(root->left);
  cout<<root->data<<",";
  printtree(root->right);
}
 void revtree(node *root)
 {
     if(root==NULL)
        return;
     node* temp;
     temp->right=root->left;
     temp->left=root->right;
     root->right=temp->right;
     root->left=temp->left;
 }

int main()
{
   node *root =buildtree();
   printtree(root);
   return 0;
}
