#include<bits/stdc++.h>

using namespace std;


class myhash{

private:
    int cap;
    int siz;
    int *arr;
public:
    myhash(int c)
    {
        cap = c;
        siz = 0;
        arr = new int[cap];
        for(int i=0;i<cap;i++)
        {
            arr[i]=-1;
        }
    }

    // Hash Function
    int myhashFun(int key)
    {
        return key%cap;
    }

    // insert function
    bool insertEle(int key)
    {
        if(siz == cap)
            return false;
        int i = myhashFun(key);
        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key)
        {
            i = (i+1)%cap;
        }
        if(arr[i] == key)
            return false;
        arr[i] = key;
        siz++;
        return true;
    }

    // search function
    bool searchEle(int key)
    {
        int h = myhashFun(key);
        int i=h;
        while(arr[i]!=-1)
        {
            if(arr[i]==key)
            {
                return true;
            }
            i=(i+1)%cap;
            if(i==h)
                return false;
        }
        return false;
    }

    // erase function
    bool eraseEle(int key)
    {
        int h = myhashFun(key);
        int i=h;
        while(arr[i]!=-1)
        {
            if(arr[i] == key)
            {
                arr[i] = -2;
                return true;
            }
            i=(i+1)%cap;
            if(i==h)
                return false;
        }
        return false;
    }

};

int main()
{
    myhash obj(7);
    obj.insertEle(49);
    obj.insertEle(56);
    obj.insertEle(72);

    if(obj.searchEle(56) == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


    obj.eraseEle(56);

    if(obj.searchEle(56) == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
