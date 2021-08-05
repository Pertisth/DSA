#include <iostream>

using namespace std;

class node{
public:
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
node *head;
node *tail;
void insertAtTail(int key)
{
    node *temp = new node(key);
    if(head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = tail->next;

}


node* reverseGroupofSizeK(node *head,int k)
{
    node *curr =head;
    node *prevFirst = NULL;

    bool isFirst = true;
    while(curr != NULL)
    {
        node *first = curr;
        node *prev = NULL;
        int cnt = 0;
        while(curr!=NULL && cnt < k)
        {
            node *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            cnt++;
        }
        if(isFirst)
        {
            head = prev;
            isFirst = false;
        }
        else
        {
            prevFirst->next = prev;
        }
        prevFirst = first;

    }
    return head;

}

void printLL(node *head)
{
    while(head!=NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        head = NULL;
        tail = NULL;
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            int ele;
            cin >> ele;
            insertAtTail(ele);
        }
        cout << "Before Reverse : ";
        printLL(head);
        cout << endl;
        cout << "After Reverse : ";
        head = reverseGroupofSizeK(head,3);
        printLL(head);
    }

    return 0;
}
