#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool Arepair(char opening , char closing)
{
    if(opening == '{' && closing == '}')
        {
            return true;
        }
        else if(opening == '[' && closing == ']')
        {
            return true;
        }
    else if(opening == '(' && closing == ')')
    {
        return true;
    }
    return false;

}

bool checkingforpair(string exp)
{
    stack <char> s;
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
            {
                s.push(exp[i]);
            }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            {
                if(s.empty() || !Arepair(s.top(),exp[i]))
                {
                    return false;
                }
                else
                {
                    s.pop();
                }
            }
    }
    return s.empty() ? true : false;
}
int main()
{
    string exp;
    cin >> exp;
    if(checkingforpair(exp))
    {
        cout << "Balanced" ;
    }
    else
    {
        cout << "Not Balanced";
    }
}
