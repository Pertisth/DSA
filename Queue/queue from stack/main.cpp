#include <bits/stdc++.h>


using namespace std;

class que {

    stack<int>st1;
    stack<int>st2;

public:
    int pushCount = 0;
    int popCount = 0;
    void push(int key)
    {
        pushCount++;
        st1.push(key);
    }
    int pop()
    {
        if (st1.empty() && st2.empty())
        {
            return -1;
        }
        if (st2.empty())
        {
            while (!st1.empty())
            {
                pushCount++;
                st2.push(st1.top());
                st1.pop();
                popCount++;
            }

        }
        int val = st2.top();
        popCount++;
        st2.pop();
        return val;
    }

    bool isEmpty()
    {
        if (st1.empty() && st2.empty())
        {
            return true;
        }
        return false;
    }

};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    que q1;
    q1.push(1);
    q1.push(2);
    q1.pop();
    q1.push(3);
    q1.push(4);
    q1.pop();
    // cout << q1.pop() << endl;
    // cout << q1.isEmpty();
    cout << q1.pushCount << endl;
    cout << q1.popCount << endl;
    return 0;
}
