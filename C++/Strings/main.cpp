#include <iostream>
#include <string.h>
#include <bits/stdc++.h>


using namespace std;
void lowertoUpper(string a)
{
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]>=65 && a[i]<=90)
        {
            a[i]+=32;
        }
        else if(a[i]>=97 && a[i]<=122)
        {
            a[i]-=32;
        }
    }
    cout << a;
}

void countNoofwords(string a)
{
    int count=1;
    for(int i=0;a[i]!='\0';i++)
    {
        if((a[i]==' ')&&(a[i-1]!=' '))
        {
            count++;
        }
    }
    cout << count;
}

void reversing(string &a)
{
    int j;
    for(j=0;a[j]!='\0';j++)
    {

    }
    int i=0;
    j=j-1;
    while(i<j)
    {
        char temp;
        temp = a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }

}

void palindromeusinganothervar(string a)
{
    string b =a;
    reversing(b);
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]!=b[i])
        {
            cout << "Not Palindrome";
            return;

        }

    }
    cout << "Palindrome";

}
void Palindromewithoutanothervar(string a)
{
    int j;
    for(j=0;a[j]!='\0';j++)
    {

    }
    j=j-1;
    int i=0;
    while(i<=j)
    {
        if(a[i]!=a[j])
        {
            cout << "Not Palindrome";
            return;
        }
        i++;
        j--;

    }
    cout << "Palindrome";

}

void findduplicateslowercase(string a)
{
    int b[26]={};
    for(int i=0;a[i]!='\0';i++)
    {
        int num=a[i]-97;
        b[num]++;
    }
    for(int i=0;i<26;i++)
    {
        if(b[i]>1)
        {
            printf("%c is duplicated %d times",i+97,b[i]);
            cout << endl;
        }
    }

}

void checkforAnagramLowercase(string a,string b)
{
    int H[26]={};
    for(int i=0;a[i]!='\0';i++)
    {
        H[a[i]-97]++;
    }
    for(int i=0;b[i]!='\0';i++)
    {
        H[b[i]-97]--;
        if(H[i]<0)
        {
            cout << "Its is not Anagram";
            return;
        }
    }
    cout << "It is Anagram";
}
void swap(char &a,char &b)
{
    char temp;
    temp = a;
    a=b;
    b=temp;
}
void perm(string a,int l,int h)
{
    int i;
    if(l==h)
    {
        cout << a <<endl;
    }
    else
    {
        for(i=l;i<=h;i++)
        {
            swap(a[l],a[i]);
            perm(a,l+1,h);
            swap(a[l],a[i]);
        }
    }
}

void permDiffAppro(string s,int k)
{
    static int a[10]={};
    static char b[10];
    int i;
    if(s[k]=='\0')
    {
        b[k]='\0';
        cout << b << endl;
    }
    else
    {
        for(i=0;s[i]!='\0';i++)
        {
            if(a[i]==0)
            {
                b[k]=s[i];
                a[i]=1;
                permDiffAppro(s,k+1);
                a[i]=0;
            }
        }
    }
}



int main()
{
    string a;
    int i;
    getline(cin ,a);
    permDiffAppro(a,0);
    return 0;
}
