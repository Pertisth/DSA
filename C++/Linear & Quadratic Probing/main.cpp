#include <iostream>
#define SIZE 10

using namespace std;

int Hash(int key)
{
    return key%SIZE;
}

int LinearProbing(int H[],int key)
{
    int index = Hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0)
    {
        i++;
    }
    return (index+i)%SIZE;
}

int QuadraticProbe(int H[],int key)
{
    int index=Hash(key);
    int i=0;
    while(H[(index+i*i)%SIZE]!=0)
    {
        i++;
    }
    return (index+i*i)%SIZE;
    //Change Search for Quadratic Probe Function
}
void Insert(int H[],int key)
{
    int index=Hash(key);
    if(H[index]!=0)
    {
        index=QuadraticProbe(H,key);
    }
    H[index]=key;
}
int Search(int H[],int key)
{
    int index=Hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=key)
    {
        i++;
    }
    return (index+i)%SIZE;
}
int main()
{
    int H[10]={0};
    Insert(H,22);
    Insert(H,23);
    Insert(H,33);
    int index=Search(H,33);
    cout << "Element found at : "<< index;
    return 0;
}
