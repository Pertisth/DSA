#include <iostream>

using namespace std;


class kStacks{
    int *arr,*next,*top;
    int freetop;
    int cap;
public:
    kStacks(int n,int k)
    {
        cap = n;
        arr = new int[n];
        next = new int[n];
        top = new int[k];
        freetop = 0;
        for(int i=0;i<n-1;i++)
        {
            next[i] = i+1;
        }
        next[n-1] = -1;
        for(int i=0;i<k;i++)
        {
            top[i] = -1;
        }
    }
    bool isFull()
    {
        return (freetop == -1);
    }
    bool isEmpty(int stackNumber)
    {
        return (top[stackNumber] == -1);
    }
    void push(int data,int stackNumber)
    {
        if(isFull())
        {
            cout << "Stack Overflow" <<endl;
            return;
        }
        int i = freetop;
        arr[i] = data;
        freetop = next[i];
        next[i] = top[stackNumber];
        top[stackNumber] = i;
        //cout << "FreeTop : " << freetop <<endl;
    }

    int pop(int stackNumber)
    {
        if(isEmpty(stackNumber))
        {
            cout << "Stack UnderFlow" << endl;
            return -1;
        }
        int i=top[stackNumber];
        top[stackNumber] = next[i];
        next[i] = freetop;
        freetop = i;
        return arr[i];
    }


};


int main()
{
    kStacks st(6,3);
    st.push(100,0);
    st.push(200,0);
    st.push(300,0);
    st.push(400,1);
    st.push(500,1);
    st.push(600,1);
    st.push(700,0);



    cout << st.pop(0);
    return 0;
}
