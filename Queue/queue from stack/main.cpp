#include <bits/stdc++.h>


using namespace std;

class que{

    stack<int>st1;
    stack<int>st2;

public:
    void push(int key)
    {
        st1.push(key);
    }
    int pop()
    {
        if(st1.empty() && st2.empty())
        {
            return -1;
        }
        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }

        }
        int val = st2.top();
        st2.pop();
        return val;
    }

    bool isEmpty()
    {
        if(st1.empty() && st2.empty())
        {
            return true;
        }
        return false;
    }

};

int main()
{
    que q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    cout << q1.pop() << endl;
    cout << q1.isEmpty();
    return 0;
}
