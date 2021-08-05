#include <bits/stdc++.h>


using namespace std;

class node
{
public:
    int data;
    node *next;
};


node *sortedInsert(node **H,int key)
{
    node *p=*H,*t,*q;
    if(*H==nullptr)
    {
        t=new node;
        t->data=key;
        t->next=nullptr;
        *H=t;
    }
    else
    {
        while(p && p->data < key)
        {
            q=p;
            p=p->next;
        }
        if(p==nullptr)
        {
            t=new node;
            t->data=key;
            t->next=nullptr;
            q->next=t;
        }
        else
        {
            if(*H==p)
            {
                t=new node;
                t->data=key;
                *H=t;
                t->next=p;
            }
            else
            {
                t=new node;
                t->data=key;
                q->next=t;
                t->next=p;
            }
        }
    }
}

void Search(node *h,int key)
{
    while(h!=nullptr)
    {
        if(h->data == key)
        {
            cout << "Element Found" << " " << key;
            return;
        }
        h=h->next;
    }
    cout << "Element not Found";
}
int hashFunc(int key)
{
    return key%10;
}

void Insert(node *H[],int key)
{
    int index = hashFunc(key);
    sortedInsert(&H[index],key);
}

int main()
{
    node *HT[10];
    for(int i=0;i<10;i++)
    {
        HT[i]=nullptr;
    }
    Insert(HT,22);
    Insert(HT,32);
    Insert(HT,42);
    Search(HT[hashFunc(23)],23);
    return 0;
}
