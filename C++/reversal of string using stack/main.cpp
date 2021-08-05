#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

void reverse(char name[],int n)
{
    stack <char> s;
    for(int i=0;i<n;i++)
    {
        s.push(name[i]);
    }
    for(int i=0;i<n;i++)
    {
        name[i] = s.top();
        s.pop();
    }
}



int main()
{
    char name[101];
    cout << "Enter a string : ";
    cin >> name;

    reverse(name,strlen(name));
    cout << name;

}
