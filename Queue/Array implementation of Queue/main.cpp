#include <iostream>

using namespace std;

class Queue{
    int *arr;
    int front;
    int siz;
    int cap;
public:
    Queue(int x)
    {
        cap = x;
        arr = new int[cap];
        front = 0;
        siz = 0;
    }
    bool isFull()
    {
        return (siz == cap);
    }
    bool isEmpty()
    {
        return (siz == 0);
    }
    int getRear()
    {
        if(siz == 0)
        {
            return -1;
        }
        return (front + siz -1)%cap;
    }
    void enqueue(int x)
    {
        if(isFull())
        {
            cout << "Queue Full"<<endl;
            return;
        }
        int rear = getRear();
        rear = (rear+1)%cap;
        arr[rear] =x;
        siz++;
    }
    int dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue Empty "<<endl;
            return -1;
        }
        int val = arr[front];
        front = (front+1)%cap;
        siz--;
        return val;
    }
};

int main()
{
    Queue que(4);
    cout << "Empty: " <<que.isEmpty();
    que.enqueue(1);
    que.enqueue(2);
    cout << "Element Removed : " << que.dequeue();
    cout << "Element Removed : " << que.dequeue();
    return 0;
}
