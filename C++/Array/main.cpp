#include <iostream>

using namespace std;
int size = 10;
int length = 7;
int *q;
void append(int x)
{
    if(length<size)
    {
        q[length++]=x;
    }

}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void insert(int index,int key)
{
    if(length<size)
    {
        for(int i=length;i>index;i--)
        {
            q[i]=q[i-1];
        }
        q[index]=key;
        length++;
    }
}

void del(int index)
{
    if(index<length && index>0)
    {
        for(int i=index;i<length;i++)
        {
            q[i]=q[i+1];
        }
        length--;
    }
}
void display()
{
    for(int i=0;i<length;i++)
    {
        cout << q[i] << " ";
    }
}

void rev(int *a)
{

    for(int i=0,j=length-1;i<j;i++,j--)
    {
        int temp;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}

void posneg(int *a)
{
    int i=0;
    int j=length-1;
    while(i<j)
    {
        while(a[i]<0)
        {
            i++;
        }
        while(a[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
           swap(a[i],a[j]);
        }
    }
}




int main()
{


    q = new int[10];
    for(int i=0;i<length;i++)
    {
        q[i] = i;
    }
    posneg(q);
    display();



    return 0;
}
