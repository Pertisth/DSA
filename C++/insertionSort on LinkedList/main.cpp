#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
};

//Global Pointers

node *root=nullptr;
node *sorted=nullptr;


void insertionSort(node *ins);
void Sort(node *root)
{
    while(root!=nullptr)
    {
        insertionSort(root);
        root=root->next;
    }
}

void insertionSort(node *ins)
{
    node *p=sorted;
    node *q=nullptr;
    node *t;
   if(sorted==nullptr)
   {
       t=new node;
       t->data=ins->data;
       t->next=nullptr;
       sorted =t;
   }
   else
   {
       while(p&&p->data < ins->data)
       {
           q=p;
           p=p->next;
       }
       t=new node;
       t->data = ins->data;
       t->next=nullptr;
       if(p==sorted)
       {
           t->next=sorted;
           sorted=t;
       }
       else
       {
           t->next = q->next;
           q->next=t;
       }

   }

}
void insertion(int key)
{
    node *t;
    node *q;
    node *p;
    if(root==nullptr)
    {
       t=new node;
       t->data = key;
       t->next=nullptr;
       root=t;
       q=t;
    }
    else
    {
       p= new node;
       p->data=key;
       p->next=nullptr;
       q->next=p;
       q=q->next;
    }
}

void printLL(node *root)
{
    while(root!=nullptr)
    {
        cout << "->" << root->data;
        root=root->next;
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
        insertion(key);
    }
    Sort(root);
    printLL(sorted);

    return 0;
}

